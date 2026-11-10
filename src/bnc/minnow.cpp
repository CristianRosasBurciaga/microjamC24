#include "bnc/minnow.h"

#include <bn_keypad.h>
#include "bn_sprite_items_minnow_right.h"

namespace bnc {


    //player constructor

    Minnow::Minnow(bn::fixed_point starting_position, bn::fixed speed) :
        _sprite(bn::sprite_items::minnow_right.create_sprite(starting_position)),
        _speed(speed)
        {}

    void Minnow::update(){
        _update_position();
    }

    bool Minnow::out_of_bounds() const{
        if(_sprite.x() >= MAX_X){
            return true;
        } else {
            return false;
        }
    }


/**
 * Reads from the d-pad and moves the player by one frame accordingly.
 */
void bnc::Minnow::_update_position() {
    if(bn::keypad::left_held()) {
        _sprite.set_x(_sprite.x() - _speed);
    }
    if(bn::keypad::right_held()) {
        _sprite.set_x(_sprite.x() + _speed);
    }
    if(bn::keypad::up_held()) {
        _sprite.set_y(_sprite.y() - _speed);
    }
    if(bn::keypad::down_held()) {
        _sprite.set_y(_sprite.y() + _speed);
    }
}
}