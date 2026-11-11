#pragma once

#include "bnc/minnow.h"
#include <bn_fixed.h>
#include <bn_random.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_display.h>
#include <bn_rect.h>
#include <bn_size.h>


namespace bnc {

static constexpr bn::size SHARK_SIZE = {8, 8};

//Starting position of the player
static constexpr int SHARK_X_START = 90;
static constexpr int SHARK_Y_START = 0;
static constexpr int MAX_SHARKS = 4;

bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size);

    class Shark {
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

        public:
        //constructor
        bn::fixed x;
        bn::fixed y;
        Shark(bn::fixed x, bn::fixed y);

        void update(Minnow& minnow);

        private:
        bn::sprite_ptr _shark;
        bn::rect _shark_hit_box;
        bn::vector<Shark, MAX_SHARKS> _sharks = {};
        bn::random random;
    };
}