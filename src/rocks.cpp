#include "rocks.h"
#include "main.h"

Rocks::Rocks(float x, float y, float z, float lt,float ht, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    z=0;
    x=0;
    y=0;
    GLfloat vertex_buffer_data[36];
    vertex_buffer_data[0] = x;
    vertex_buffer_data[2] = z;
    vertex_buffer_data[1] = y + ht;
    vertex_buffer_data[3] = x;
    vertex_buffer_data[5] = z - lt;
    vertex_buffer_data[4] = y;
    vertex_buffer_data[6] = x + lt;
    vertex_buffer_data[8] = z + lt;
    vertex_buffer_data[7] = y;

    vertex_buffer_data[9] = x;
    vertex_buffer_data[11] = z;
    vertex_buffer_data[10] = y + ht;
    vertex_buffer_data[12] = x;
    vertex_buffer_data[14] = z - lt;
    vertex_buffer_data[13] = y;
    vertex_buffer_data[15] = x - lt;
    vertex_buffer_data[17] = z + lt;
    vertex_buffer_data[16] = y;

    vertex_buffer_data[18] = x;
    vertex_buffer_data[20] = z;
    vertex_buffer_data[19] = y + ht;
    vertex_buffer_data[21] = x - lt;
    vertex_buffer_data[23] = z + lt;
    vertex_buffer_data[22] = y;
    vertex_buffer_data[24] = x + lt;
    vertex_buffer_data[26] = z + lt;
    vertex_buffer_data[25] = y;

    vertex_buffer_data[27] = x;
    vertex_buffer_data[29] = z - lt;
    vertex_buffer_data[28] = y;
    vertex_buffer_data[30] = x - lt;
    vertex_buffer_data[32] = z + lt;
    vertex_buffer_data[31] = y;
    vertex_buffer_data[33] = x + lt;
    vertex_buffer_data[35] = z + lt;
    vertex_buffer_data[34] = y;
    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color, GL_FILL);
}

void Rocks::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Rocks::set_position(float x, float y) {
    // this->position = glm::vec3(x, y, 0);
}

void Rocks::tick() {
    // this->position.x -= speed;
    this->position.y -= speed;
}

bounding_box_t Rocks::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 8, 8 };
    return bbox;
}
