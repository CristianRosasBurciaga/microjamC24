#pragma once

#include "bnc/bnc_squid.h"
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_display.h>
#include <bn_rect.h>
#include <bn_size.h>
#include <bn_random.h>
#include <bn_fixed.h>




namespace bnc {

static constexpr bn::size SHARK_SIZE = {8, 8};

static constexpr bn::fixed SHARK_SPEED = 0.5;

static constexpr int MAX_SHARKS = 4;

static constexpr int MAX_X = bn::display::width() / 2;
static constexpr int MIN_X = - bn::display::width() / 2;
static constexpr int MAX_Y = bn::display::height() / 2;
static constexpr int MIN_Y = - bn::display::height() / 2;

bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size);

class Shark {

    public:
    //constructor
    Shark(bn::fixed x, bn::fixed y, bn::fixed speed);

    void update(Squid& squid);
    bool collide(Squid& squid);
    bn::fixed random_X_Point(int min, int max);
    bn::fixed random_Y_Point(int min, int max);

    bool _shark_collision() const; //a get for the private bool

    private:
    bool shark_collision = false;
    bn::sprite_ptr _shark;
    bn::rect _shark_hit_box;
    bn::fixed _shark_speed;
    bn::size _shark_size;
};
}