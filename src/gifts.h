#include "main.h"

#ifndef GIFTS_H
#define GIFTS_H


class Gifts {
public:
    Gifts() {}
    Gifts(float x, float y, float z, float lt, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float length;
    bounding_box_t bounding_box();
private:
    VAO *object[6];
};

#endif // Gifts_H
