#include "bnc/bnc_shark.h"
#include "bn_sprite_items_shark.h"
#include "mj/mj_game_data.h"
#include <bn_log.h>
#include "bnc/bnc_squid.h"
#include <bn_vector.h>
#include <bn_random.h>
#include <bn_rect.h>


namespace bnc{

    Shark::Shark(bn::fixed x, bn::fixed y, bn::fixed speed) :
    _shark(bn::sprite_items::shark.create_sprite(x, y)),
    _shark_speed(speed), _shark_size(SHARK_SIZE),
    _shark_hit_box(create_bounding_box(_shark, _shark_size))
    {}

    
    bn::vector<Shark, MAX_SHARKS> Shark::get_shark_vector() {
        return _shark_vector;
    }

    bn::fixed Shark::random_X_Point(int min, int max) {
        // return mj::mj_game_data::random.get_unbiased_fixed(min, max);
    }  
    
    bn::fixed Shark::random_Y_Point(int min, int max) {
        // return .get_unbiased_fixed(min, max);
    }  

    bool Shark::_shark_collision() const {
        return shark_collision;
    }


    void Shark::update(Squid& squid) {

        if(_shark_vector.size() < _shark_vector.max_size()) {
             _shark_vector.push_back(Shark(random_X_Point(MIN_X, MAX_X), random_Y_Point(MIN_Y, MAX_Y), SHARK_SPEED));
            BN_LOG(random_X_Point(MIN_X, MAX_X), " ", random_Y_Point(MIN_Y, MAX_Y));
              }

        if(_shark.x() < squid.get_sprite().x()){
            _shark.set_x(_shark.x() + _shark_speed);
        }

        if(_shark.x() > squid.get_sprite().x()){
            _shark.set_x(_shark.x() - _shark_speed);
        }

        if(_shark.y() > squid.get_sprite().y()){
            _shark.set_y(_shark.y() - _shark_speed);
        }

        if(_shark.y() < squid.get_sprite().y()){
            _shark.set_y(_shark.y() + _shark_speed);
        }

        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);
        
        if(_shark_hit_box.intersects(squid.get_squid_hit_box())){
            // bool lose mj::game_result::exit = true;
            shark_collision = true;
            BN_LOG("caught");
        }


    }
}