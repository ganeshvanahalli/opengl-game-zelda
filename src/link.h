#include "main.h"

#ifndef LINK_H
#define LINK_H


class Link {
public:
    Link() {}
    Link(float x, float y, float z, float lt, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object[42];
};

#endif // Link_H
