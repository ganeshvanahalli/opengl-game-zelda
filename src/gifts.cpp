#include "gifts.h"
#include "main.h"


Gifts::Gifts(float x, float y, float z, float lt, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    length = lt;
    GLfloat vertex_buffer_data[18];
    // z=0;
    // x=0;
    // y=0;
    float k = lt/2;
    //  rect1
    vertex_buffer_data[0] = k;
    vertex_buffer_data[2] = k;
    vertex_buffer_data[1] = k;
    vertex_buffer_data[3] = k;
    vertex_buffer_data[5] = k;
    vertex_buffer_data[4] = -k;
    vertex_buffer_data[6] = -k;
    vertex_buffer_data[8] = k;
    vertex_buffer_data[7] = -k;

    vertex_buffer_data[9] = k;
    vertex_buffer_data[11] = k;
    vertex_buffer_data[10] = k;
    vertex_buffer_data[12] = -k;
    vertex_buffer_data[14] =  k;
    vertex_buffer_data[13] = -k;
    vertex_buffer_data[15] = -k;
    vertex_buffer_data[17] =  k;
    vertex_buffer_data[16] = k;

    this->object[0] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = k;
    vertex_buffer_data[2] = -k;
    vertex_buffer_data[1] = k;
    vertex_buffer_data[3] = k;
    vertex_buffer_data[5] = -k;
    vertex_buffer_data[4] = -k;
    vertex_buffer_data[6] = -k;
    vertex_buffer_data[8] = -k;
    vertex_buffer_data[7] = -k;

    vertex_buffer_data[9] = k;
    vertex_buffer_data[11] = -k;
    vertex_buffer_data[10] = k;
    vertex_buffer_data[12] = -k;
    vertex_buffer_data[14] =  -k;
    vertex_buffer_data[13] = -k;
    vertex_buffer_data[15] = -k;
    vertex_buffer_data[17] =  -k;
    vertex_buffer_data[16] = k;

    this->object[2] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = k;
    vertex_buffer_data[2] = k;
    vertex_buffer_data[1] = k;
    vertex_buffer_data[3] = k;
    vertex_buffer_data[5] = -k;
    vertex_buffer_data[4] = k;
    vertex_buffer_data[6] = -k;
    vertex_buffer_data[8] = k;
    vertex_buffer_data[7] = k;

    vertex_buffer_data[9] = k;
    vertex_buffer_data[11] = -k;
    vertex_buffer_data[10] = k;
    vertex_buffer_data[12] = -k;
    vertex_buffer_data[14] =  k;
    vertex_buffer_data[13] = k;
    vertex_buffer_data[15] = -k;
    vertex_buffer_data[17] =  -k;
    vertex_buffer_data[16] = k;

    this->object[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = k;
    vertex_buffer_data[2] = -k;
    vertex_buffer_data[1] = -k;
    vertex_buffer_data[3] = k;
    vertex_buffer_data[5] = k;
    vertex_buffer_data[4] = -k;
    vertex_buffer_data[6] = -k;
    vertex_buffer_data[8] = k;
    vertex_buffer_data[7] = -k;

    vertex_buffer_data[9] = k;
    vertex_buffer_data[11] = -k;
    vertex_buffer_data[10] = -k;
    vertex_buffer_data[12] = -k;
    vertex_buffer_data[14] =  k;
    vertex_buffer_data[13] = -k;
    vertex_buffer_data[15] = -k;
    vertex_buffer_data[17] =  -k;
    vertex_buffer_data[16] = -k;

    this->object[3] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = k;
    vertex_buffer_data[2] = k;
    vertex_buffer_data[1] = k;
    vertex_buffer_data[3] = k;
    vertex_buffer_data[5] = -k;
    vertex_buffer_data[4] = k;
    vertex_buffer_data[6] = k;
    vertex_buffer_data[8] = -k;
    vertex_buffer_data[7] = -k;

    vertex_buffer_data[9] = k;
    vertex_buffer_data[11] = k;
    vertex_buffer_data[10] = k;
    vertex_buffer_data[12] = k;
    vertex_buffer_data[14] =  -k;
    vertex_buffer_data[13] = -k;
    vertex_buffer_data[15] = k;
    vertex_buffer_data[17] = k;
    vertex_buffer_data[16] = -k;


    this->object[4] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = -k;
    vertex_buffer_data[2] = k;
    vertex_buffer_data[1] = k;
    vertex_buffer_data[3] = -k;
    vertex_buffer_data[5] = -k;
    vertex_buffer_data[4] = k;
    vertex_buffer_data[6] = -k;
    vertex_buffer_data[8] = -k;
    vertex_buffer_data[7] = -k;

    vertex_buffer_data[9] = -k;
    vertex_buffer_data[11] = k;
    vertex_buffer_data[10] = k;
    vertex_buffer_data[12] = -k;
    vertex_buffer_data[14] =  -k;
    vertex_buffer_data[13] = -k;
    vertex_buffer_data[15] = -k;
    vertex_buffer_data[17] = k;
    vertex_buffer_data[16] = -k;

    this->object[5] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);    
}

void Gifts::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
    draw3DObject(this->object[2]);
    draw3DObject(this->object[3]);
    draw3DObject(this->object[4]);
    draw3DObject(this->object[5]);}

void Gifts::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Gifts::tick() {
    // this->position.x -= speed;
    this->position.y -= speed;
}

bounding_box_t Gifts::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, length, length };
    return bbox;
}
