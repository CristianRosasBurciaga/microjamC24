#include "bnc/minnow.h"

#include <bn_keypad.h>
#include "bn_sprite_items_minnow_right.h"

namespace bnc {

    //player constructor

    Minnow::Minnow(bn::fixed_point starting_position, bn::fixed speed) :
        _sprite(bn::sprite_items::minnow_right.create_sprite(starting_position)),
        _sprite(bn::sprite_items::minnow_right.create_sprite()),
        _sprite(bn::sprite_items::minnow_right.create_sprite()),
        _sprite(bn::sprite_items::minnow_right.create_sprite()),
        _speed(SPEED)
        {}


}