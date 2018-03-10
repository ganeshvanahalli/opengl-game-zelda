#include "main.h"

#ifndef WAVES_H
#define WAVES_H


class Waves {
public:
    Waves() {}
    Waves(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object[2];
};

#endif // Waves_H
