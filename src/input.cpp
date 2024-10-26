#include "input.h"

bool Input::IsDown(InputAction action) {
    // input is down if the bitpack bit is 1, found using bitwise AND
    unsigned int bit_grab = action_bitpack & action;

    // if the grabbed value is zero, the bitpack bit was zero,
    //   therefore false, else true
    return bit_grab != 0;
}

void Input::UpdateAction(InputAction action, bool is_down) {
    unsigned int modifier = action;

    if (!is_down) {
        // flip bit if setting to false
        action_bitpack = ~action_bitpack;
    }

    action_bitpack |= modifier;

    if (!is_down) {
        // flip bit again after setting to false
        action_bitpack = ~action_bitpack;
    }
}

vec2 Input::get_mouse_pos() {
    return mouse_pos;
}

void Input::set_mouse_pos(vec2 pos) {
    mouse_pos = pos;
}

vec2 Input::mouse_pos = vec2(0);
unsigned int Input::action_bitpack = 0;
