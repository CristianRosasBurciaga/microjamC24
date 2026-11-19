

namespace bnc {

    class Bubbles{


        public:
        Bubbles(bn::fixed bubble_x, bn::fixed bubble_y, bn::fixed bubble_speed);

        private:
        bn::sprite_ptr _bubble;
        bn::fixed _bubble_speed;

    }
}

