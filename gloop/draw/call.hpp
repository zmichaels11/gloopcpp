/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

namespace gloop {
    namespace draw {
        struct draw_call {
            virtual void draw() const = 0;
            
            inline void operator()() const {
                draw();
            }
        };
        
        struct compute_call {
            virtual void execute() const = 0;
            
            inline void operator()() const {
                execute();
            }
        };
    }
}