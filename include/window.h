#pragma once

#include <iostream>
#include <GL/freeglut.h>
#include "camera.h"

void window_init(int* argc, char** argv, void (*update_func)(float), void (*draw_func)(), Camera* camera);

void window_run();

float get_dt();
