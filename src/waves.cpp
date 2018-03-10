#include "waves.h"
#include "main.h"

Waves::Waves(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.05;
    GLfloat vertex_buffer_data[18];
    vertex_buffer_data[0] = x ;
    vertex_buffer_data[2] = z;
    vertex_buffer_data[1] = y;
    vertex_buffer_data[3] = x - 2;
    vertex_buffer_data[5] = z;
    vertex_buffer_data[4] = y - 0.2;
    vertex_buffer_data[6] = x - 2;
    vertex_buffer_data[8] = z;
    vertex_buffer_data[7] = y - 0.3;
    vertex_buffer_data[9] = x;
    vertex_buffer_data[11] = z;
    vertex_buffer_data[10] = y;
    vertex_buffer_data[12] = x - 2;
    vertex_buffer_data[14] = z;
    vertex_buffer_data[13] = y - 0.3;
    vertex_buffer_data[15] = x;
    vertex_buffer_data[17] = z;
    vertex_buffer_data[16] = y - 0.1;

    this->object[0] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
 
    vertex_buffer_data[0] = x ;
    vertex_buffer_data[2] = z;
    vertex_buffer_data[1] = y;
    vertex_buffer_data[3] = x + 2;
    vertex_buffer_data[5] = z;
    vertex_buffer_data[4] = y - 0.2;
    vertex_buffer_data[6] = x + 2;
    vertex_buffer_data[8] = z;
    vertex_buffer_data[7] = y - 0.3;
    vertex_buffer_data[9] = x;
    vertex_buffer_data[11] = z;
    vertex_buffer_data[10] = y;
    vertex_buffer_data[12] = x + 2;
    vertex_buffer_data[14] = z;
    vertex_buffer_data[13] = y - 0.3;
    vertex_buffer_data[15] = x;
    vertex_buffer_data[17] = z;
    vertex_buffer_data[16] = y - 0.1;
    

    this->object[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Waves::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
}

void Waves::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Waves::tick() {
    // this->position.x -= speed;
    this->position.y -= speed;
}

bounding_box_t Waves::bounding_box() {
    // float x = this->position.x, y = this->position.y + ht;
    // bounding_box_t bbox = { x, y, 0.4, 0.4 };
    // return bbox;
}
