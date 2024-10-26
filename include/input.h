#pragma once

#include <glm/glm.hpp>

using namespace glm;

enum InputAction {
    FORWARD = 0b00001,
    BACKWARD = 0b00010,
    LEFT = 0b00100,
    RIGHT = 0b01000,
    JUMP = 0b10000
};

class Input {
   private:
    static vec2 mouse_pos;
    static unsigned int action_bitpack;

   public:
    static bool IsDown(InputAction action);
    static void UpdateAction(InputAction action, bool is_down);

    static vec2 get_mouse_pos();
    static void set_mouse_pos(vec2 pos);
};
