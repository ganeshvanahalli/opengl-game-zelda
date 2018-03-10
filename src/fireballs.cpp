
#include "fireballs.h"
#include "main.h"

Fireballs::Fireballs(float x, float y, float z, float lt,float ht, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    z=0;
    x=0;
    y=0;
    GLfloat vertex_buffer_data[63];
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

    vertex_buffer_data[36] = x;
    vertex_buffer_data[38] = z;
    vertex_buffer_data[37] = y - ht;
    vertex_buffer_data[39] = x;
    vertex_buffer_data[40] = z - lt;
    vertex_buffer_data[41] = y;
    vertex_buffer_data[42] = x + lt;
    vertex_buffer_data[44] = z + lt;
    vertex_buffer_data[43] = y;

    vertex_buffer_data[45] = x;
    vertex_buffer_data[47] = z;
    vertex_buffer_data[46] = y - ht;
    vertex_buffer_data[48] = x;
    vertex_buffer_data[50] = z - lt;
    vertex_buffer_data[49] = y;
    vertex_buffer_data[51] = x - lt;
    vertex_buffer_data[53] = z + lt;
    vertex_buffer_data[52] = y;

    vertex_buffer_data[54] = x;
    vertex_buffer_data[56] = z;
    vertex_buffer_data[55] = y - ht;
    vertex_buffer_data[57] = x - lt;
    vertex_buffer_data[59] = z + lt;
    vertex_buffer_data[58] = y;
    vertex_buffer_data[60] = x + lt;
    vertex_buffer_data[62] = z + lt;
    vertex_buffer_data[61] = y;


    this->object = create3DObject(GL_TRIANGLES, 21, vertex_buffer_data, color, GL_FILL);
}

void Fireballs::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Fireballs::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Fireballs::tick() {
    // this->position.x -= speed;
    this->position.y -= speed;
}

bounding_box_t Fireballs::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 2, 2 };
    return bbox;
}
