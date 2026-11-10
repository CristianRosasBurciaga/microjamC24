#include "bnc/shark.h"
#include "bn_sprite_items_shark.h"


namespace bnc{

    Shark::Shark(bn::fixed_point (starting_position)) :
    _shark(bn::sprite_items::shark.create_sprite(starting_position)){

    }

    void Shark::update(Minnow& minnow) {
        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);

        if(_shark_hit_box.intersects(minnow.minnow_hit_box)){
            
        }
    }
}