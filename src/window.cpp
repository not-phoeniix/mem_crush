#include "window.h"

#include "glm/glm.hpp"
#include "input.h"

bool renderer_is_init = false;
int time_prev = 0;
float delta_time;
void (*update)(float);
void (*draw)();

unsigned int window_width;
unsigned int window_height;

Camera* camera;

void reshape(int w, int h) {
    // prevent divide by zero error
    if (h < 0) h = 0;

    window_width = w;
    window_height = h;

    // update model view matrix for camera position and look at position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    vec3 cam_pos = camera->get_position();
    vec3 look_at = camera->get_position() + camera->get_forward_dir();
    gluLookAt(cam_pos.x, cam_pos.y, cam_pos.z, look_at.x, look_at.y, look_at.z, 0, 1, 0);

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
    update(delta_time);

    reshape(window_width, window_height);
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            Input::UpdateAction(FORWARD, true);
            break;
        case 'a':
            Input::UpdateAction(LEFT, true);
            break;
        case 's':
            Input::UpdateAction(BACKWARD, true);
            break;
        case 'd':
            Input::UpdateAction(RIGHT, true);
            break;
        case ' ':
            Input::UpdateAction(JUMP, true);
            break;
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            Input::UpdateAction(FORWARD, false);
            break;
        case 'a':
            Input::UpdateAction(LEFT, false);
            break;
        case 's':
            Input::UpdateAction(BACKWARD, false);
            break;
        case 'd':
            Input::UpdateAction(RIGHT, false);
            break;
        case ' ':
            Input::UpdateAction(JUMP, false);
            break;
    }
}

void mouse_passive_motion(int x, int y) {
    Input::set_mouse_pos(vec2(x, y));
}

void window_init(int* argc, char** argv, void (*update_func)(float), void (*draw_func)(), Camera* cam) {
    if (!renderer_is_init) {
        std::cout << "initializing renderer...\n";
    } else {
        std::cout << "ERROR: Cannot renderer already initialized!\n";
        return;
    }

    camera = cam;
    update = update_func;
    draw = draw_func;

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("the bit-er");

    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutPassiveMotionFunc(mouse_passive_motion);

    glClearColor(0, 0, 0, 1);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    renderer_is_init = true;
    std::cout << "renderer initialized!\n";
}

void window_run() {
    glutMainLoop();
}

float get_dt() {
    return delta_time;
}
