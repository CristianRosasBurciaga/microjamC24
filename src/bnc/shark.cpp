#include "bnc/shark.h"
#include "bn_sprite_items_shark.h"


namespace bnc{

    Shark::Shark(bn::fixed_point (starting_position)) :
    _shark(bn::sprite_items::shark.create_sprite(starting_position)){

    }
}