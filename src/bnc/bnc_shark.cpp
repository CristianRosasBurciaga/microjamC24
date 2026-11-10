#include "bnc/bnc_shark.h"
#include "bn_sprite_items_shark.h"
#include "mj/mj_game_result.h"
#include <bn_log.h>
#include "bnc/bnc_minnow.h"


namespace bnc{

    Shark::Shark(bn::fixed_point starting_position, bn::fixed speed) :
    _shark(bn::sprite_items::shark.create_sprite(starting_position)), 
    _shark_speed(speed)
    {

    }

    void Shark::update(Minnow& minnow) {
        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);

        if(_shark_hit_box.intersects(minnow.minnow_hit_box)){
            // bool lose mj::game_result::exit = true;
            BN_LOG("caught");
        }

        if(_shark.x() < minnow._sprite.x()){
            _shark.set_x(_shark.x() + _shark_speed);
        }

        if(_shark.x() > minnow._sprite.x()){
            _shark.set_x(_shark.x() - _shark_speed);
        }

        if(_shark.y() > minnow._sprite.y()){
            _shark.set_y(_shark.y() - _shark_speed);
        }

        if(_shark.y() < minnow._sprite.y()){
            _shark.set_y(_shark.y() + _shark_speed);
        }
    }
}