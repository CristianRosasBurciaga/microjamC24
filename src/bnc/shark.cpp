#include "bnc/shark.h"
#include "bn_sprite_items_shark.h"
#include "mj/mj_game_result.h"
#include <bn_log.h>


namespace bnc{

    Shark::Shark(bn::fixed x, bn::fixed y) :
    _shark(bn::sprite_items::shark.create_sprite(x, y))
    {}
    bn::random random;
    bn::vector<Shark, MAX_SHARKS> _sharks = {};

    bn::fixed Shark::random_X_Point(int min, int max) {
        return random.get_unbiased_fixed(min, max);
    }  
    
    bn::fixed Shark::random_Y_Point(int min, int max) {
        return random.get_unbiased_fixed(min, max);
    }    

    void Shark::update(Minnow& minnow) {

        if(_sharks.size() < _sharks.max_size()) {
             _sharks.push_back(Shark(random_X_Point(MIN_X, MAX_X), random_Y_Point(MIN_Y, MAX_Y)));
            BN_LOG(random_X_Point(MIN_X, MAX_X), " ", random_Y_Point(MIN_Y, MAX_Y));
              }
        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);

        if(_shark_hit_box.intersects(minnow.minnow_hit_box)){
            // bool lose mj::game_result::exit = true;
            BN_LOG("caught");
        }
    }


}