#include "bnc_fish_escape.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "mj/mj_game_list.h"


namespace bnc
{
    bnc_fish_escape::bnc_fish_escape([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("bnc") 
    {

    }

    bn::string<16> bnc_fish_escape::title() const {
    return "Get to the other side";
}

int bnc_fish_escape::total_frames() const {
    return 600; // 300 frames at 60fps = 5 seconds
}

mj::game_result bnc_fish_escape::play([[maybe_unused]] const mj::game_data& data)
{
    // update the player position
    // _player.update();

    // Creates a game result indicating whether the game is finished and whether the title should be hidden early
    // For this game the game should end early if the player has won (if victory returns true)
    // The title is not hidden early (false is passed), so the title disappears at the default time
    mj::game_result result(victory(), false);
    return result;
}

bool bnc_fish_escape::victory() const {
    // return _player.out_of_bounds();
    return true;
}

void bnc_fish_escape::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

void bnc_fish_escape::fade_out([[maybe_unused]] const mj::game_data& data)
{
}



}