#pragma once

#include <iostream>
#include <GL/freeglut.h>

void renderer_init(int* argc, char** argv, void (*update_func)(float), void (*draw_func)());

void renderer_run();

float get_dt();
