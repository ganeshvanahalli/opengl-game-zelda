#include "main.h"

#ifndef FIREBALLS_H
#define FIREBALLS_H


class Fireballs {
public:
    Fireballs() {}
    Fireballs(float x, float y, float z, float lt, float ht, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // Fireballs_H
