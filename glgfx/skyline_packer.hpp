/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skyline_packer.hpp
 * Author: zmichaels
 *
 * Created on April 27, 2017, 1:23 PM
 */

#pragma once

#include <vector>

namespace glgfx {

    class skyline_packer {
    private:
        static constexpr int DEFAULT_PADDING = 1;

    public:

        struct rect {
            int x;
            int y;
            unsigned int width;
            unsigned int height;
        };

    private:

        int fit(int index, unsigned int width, unsigned int height);
        bool addRectangle(unsigned int width, unsigned int height, rect& outRect);
        void merge();
        bool doPack(rect * r, unsigned int count);

        struct node {
            int x;
            int y;
            unsigned int width;
        };

        unsigned int _width;
        unsigned int _height;
        unsigned int _maxWidth;
        unsigned int _maxHeight;
        int _padding;
        unsigned int _usedSpace;
        std::vector<node> _skyline;

        void clear();

    public:

        skyline_packer() : skyline_packer(4096, 4096) {
        }

        skyline_packer(unsigned int maxWidth, unsigned int maxHeight, int padding = DEFAULT_PADDING);

        void pack(rect * r, unsigned int count);
        
        double getUsageRatio() const;
        
        unsigned int getWidth() const;
        
        unsigned int getHeight() const;
    };
}