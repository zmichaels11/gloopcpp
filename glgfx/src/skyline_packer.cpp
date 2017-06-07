/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skyline_packer.hpp"

#include <iostream>
#include <limits>

namespace glgfx {
    double skyline_packer::getUsageRatio() const {
        auto total = _width * _height;
        
        if (total > 0) {
            return double(_usedSpace) / double(total);
        } else {
            return 0.0;
        }
    }
    
    skyline_packer::skyline_packer(unsigned int maxWidth, unsigned int maxHeight, int padding) {
        _width = 128;
        _height = 128;
        _maxWidth = maxWidth;
        _maxHeight = maxHeight;
        _padding = padding;        
        _skyline.push_back({1, 1, maxWidth - 2});
        _usedSpace = 0;
    }
    
    void skyline_packer::clear() {
        _skyline.clear();
        _usedSpace = 0;
        _skyline.push_back({1, 1, _maxWidth - 2});
    }
    
    int skyline_packer::fit(int index, unsigned int width, unsigned int height) {
        const auto& baseNode = _skyline[index];
        int x = baseNode.x;        
        int widthLeft = width;
        int i = index;
        
        if ((x + width) > (_width - 1)) {
            return -1;
        }
        
        int y = baseNode.y;                
        
        while (widthLeft > 0) {
            const auto& node = _skyline[i];
            
            if (node.y > y) {
                y = node.y;
            }
            
            if ((y + height) > (_height - 1)) {
                return -1;
            }
            
            widthLeft -= node.width;
            i++;
        }
        
        return y;
    }
    
    bool skyline_packer::addRectangle(unsigned int width, unsigned int height, rect& outRect) {
        auto region = rect{0,0, width, height};
        auto bestHeight = std::numeric_limits<unsigned int>::max();
        int bestIndex = -1;
        auto bestWidth = std::numeric_limits<unsigned int>::min();
        int i;
        int y;
        
        node * n;
        
        for (i = 0; i < _skyline.size(); i++) {
            y = fit(i, width, height);
            
            if (y >= 0) {
               n = _skyline.data() + i;
               
               if (((y + height) < bestHeight)
                       || (((y + height) == bestHeight) && (n->width < bestWidth))) {
                   
                   bestHeight = y + height;
                   bestIndex = i;
                   bestWidth = n->width;
                   region.x = n->x;
                   region.y = n->y;
               }
            }
        }
        
        if (bestIndex == -1) {
            return false;
        }
        
        node newNode{region.x, int(region.y + height), width};
        _skyline.insert(_skyline.begin() + bestIndex, newNode);
        
        node * prev;
        
        for (i = bestIndex + 1; i < _skyline.size(); i++) {
            n = _skyline.data() + i;
            prev = _skyline.data() + i - 1;
            
            if (n->x < (prev->x + prev->width)) {
                int shrink = prev->x + prev->width - n->x;
                
                n->x += shrink;
                n->width -= shrink;
                
                if (n->width <= 0) {
                    _skyline.erase(_skyline.begin() + i);
                    --i;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        
        merge();
        _usedSpace += width * height;
        outRect = region;
        return true;
    }
    
    void skyline_packer::merge() {        
        int i;
        
        for (i = 0; i < _skyline.size() - 1; i++) {
            node& n = _skyline[i];
            node& next = _skyline[i + 1];
            
            if (n.y == next.y) {
                n.width += next.width;
                _skyline.erase(_skyline.begin() + i + 1);
                i--;
            }
        }        
    }
    
    void skyline_packer::pack(rect* r, unsigned int count) {
        bool isDone = false;
                
        do {
            clear();
            isDone = doPack(r, count);
            auto oldWidth = _width;
            auto newWidth = _width * 2;
            auto newHeight = _height * 2;
            
            if (!isDone) {
                _width = newWidth;
                clear();
                isDone = doPack(r, count);
            }
            
            if (!isDone) {
                _width = oldWidth;
                _height = newHeight;
                clear();
                isDone = doPack(r, count);
            }
            
            if (!isDone) {
                _width = newWidth;
                _height = newHeight;
                clear();
                isDone = doPack(r, count);
            }
        } while (!isDone);                
    }
    
    bool skyline_packer::doPack(rect* r, unsigned int count) {                
        for (int i = 0; i < count; i++) {
            rect dest{0, 0, 0, 0};
            
            if (addRectangle(r[i].width + _padding, r[i].height + _padding, dest)) {
                r[i].x = dest.x;
                r[i].y = dest.y;                
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    unsigned int skyline_packer::getWidth() const {
        return _width;
    }
    
    unsigned int skyline_packer::getHeight() const {
        return _height;
    }
}