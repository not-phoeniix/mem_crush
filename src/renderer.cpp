#include "renderer.h"

#include "glm/glm.hpp"

bool renderer_is_init = false;
int time_prev = 0;
float delta_time;
void (*update)(float);
void (*draw)();

unsigned int window_width;
unsigned int window_height;

float camera_angle;
float camera_dist = 30;
float camera_speed = 1;

void reshape(int w, int h) {
    // prevent divide by zero error
    if (h < 0) h = 0;

    window_width = w;
    window_height = h;

    // update model view matrix for camera position and look at position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float cam_x = cos(camera_angle) * camera_dist;
    float cam_z = sin(camera_angle) * camera_dist;
    gluLookAt(cam_x, 10, cam_z, 0, 0, 0, 0, 1, 0);

    // update perspective projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55, (float)w / h, 0.1f, 1000.0f);

    glViewport(0, 0, w, h);

    // mark window as should redisplay
    glutPostRedisplay();
}

void idle() {
    int time_now = glutGet(GLUT_ELAPSED_TIME);
    delta_time = (time_now - time_prev) / 1000.0f;
    time_prev = time_now;
    camera_angle += delta_time * camera_speed;
    update(delta_time);

    reshape(window_width, window_height);
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();

    glutSwapBuffers();
}

void renderer_init(int* argc, char** argv, void (*update_func)(float), void (*draw_func)()) {
    if (!renderer_is_init) {
        std::cout << "initializing renderer...\n";
    } else {
        std::cout << "ERROR: Cannot renderer already initialized!\n";
        return;
    }

    update = update_func;
    draw = draw_func;

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("the bit-er");

    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutDisplayFunc(display);

    glClearColor(0, 0, 0, 1);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    renderer_is_init = true;
    std::cout << "renderer initialized!\n";
}

void renderer_run() {
    glutMainLoop();
}

float get_dt() {
    return delta_time;
}