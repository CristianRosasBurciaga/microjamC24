#include "bnc/shark.h"
#include "bn_sprite_items_shark.h"
#include "mj/mj_game_result.h"
#include <bn_log.h>


namespace bnc{

    Shark::Shark(bn::fixed x, bn::fixed y) :
    _shark(bn::sprite_items::shark.create_sprite(x, y)){

    }
    bn::random random;

    void Shark::update(Minnow& minnow) {

        if(_sharks.size() < _sharks.max_size()) {
            x = random.get_unbiased_fixed(MIN_X, MAX_X);
            y = random.get_unbiased_fixed(MIN_Y, MAX_Y);
            _sharks.push_back(Shark(x, y));
              }
        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);

        if(_shark_hit_box.intersects(minnow.minnow_hit_box)){
            // bool lose mj::game_result::exit = true;
            BN_LOG("caught");
        }
    }
}