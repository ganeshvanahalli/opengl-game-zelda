#include "rectangle.h"
#include "main.h"

Rectangle::Rectangle(float x, float y, float z, float lt, float br, float ht, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    // speed = 0.01;
    GLfloat vertex_buffer_data[18];
    z=0;
    x=0;
    y=0;
    vertex_buffer_data[0] = x - br/2;
    vertex_buffer_data[2] = z - lt/2;
    vertex_buffer_data[1] = y + ht;
    vertex_buffer_data[3] = x + br/2;
    vertex_buffer_data[5] = z- lt/2;
    vertex_buffer_data[4] = y + ht;
    vertex_buffer_data[6] = x + br/2;
    vertex_buffer_data[8] = z + lt/2;
    vertex_buffer_data[7] = y + ht;
    vertex_buffer_data[9] = x + br/2;
    vertex_buffer_data[11] = z + lt/2;
    vertex_buffer_data[10] = y + ht;
    vertex_buffer_data[12] = x - br/2;
    vertex_buffer_data[14] = z + lt/2;
    vertex_buffer_data[13] = y + ht;
    vertex_buffer_data[15] = x - br/2;
    vertex_buffer_data[17] = z - lt/2;
    vertex_buffer_data[16] = y + ht;

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Rectangle::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Rectangle::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Rectangle::tick() {
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Rectangle::bounding_box() {
    // float x = this->position.x, y = this->position.y + ht;
    // bounding_box_t bbox = { x, y, 0.4, 0.4 };
    // return bbox;
}
