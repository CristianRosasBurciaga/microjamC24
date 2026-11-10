#include "bnc/shark.h"


namespace bnc{

    shark::shark(bn::fixed x_start, bn::fixed y_start) :
    _shark(bn::sprite_items::shark.create_sprite(x_start, y_start)){

    }
}