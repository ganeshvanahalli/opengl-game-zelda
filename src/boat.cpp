#include "boat.h"
#include "main.h"

Boat::Boat(float x, float y, float z, float lt, float br, float ht, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    z=-3;
    x=0;
    y=0;
    GLfloat vertex_buffer_data[36];
    vertex_buffer_data[0] = x;
    vertex_buffer_data[1] = y;
    vertex_buffer_data[2] = z;
    vertex_buffer_data[3] = x + br/2;
    vertex_buffer_data[4] = y;
    vertex_buffer_data[5] = z + lt/4;
    vertex_buffer_data[6] = x - br/2;
    vertex_buffer_data[7] = y;
    vertex_buffer_data[8] = z + lt/4;

    vertex_buffer_data[9] = x;
    vertex_buffer_data[10] = y;
    vertex_buffer_data[11] = z + lt;
    vertex_buffer_data[12] = x + br/2;
    vertex_buffer_data[13] = y;
    vertex_buffer_data[14] = z + 3*lt/4;
    vertex_buffer_data[15] = x - br/2;
    vertex_buffer_data[16] = y;
    vertex_buffer_data[17] = z + 3*lt/4;
    
    vertex_buffer_data[18] = x + br/2;
    vertex_buffer_data[19] = y;
    vertex_buffer_data[20] = z + 3*lt/4;
    vertex_buffer_data[21] = x + br/2;
    vertex_buffer_data[22] = y;
    vertex_buffer_data[23] = z + lt/4;
    vertex_buffer_data[24] = x - br/2;
    vertex_buffer_data[25] = y;
    vertex_buffer_data[26] = z + lt/4;
    
    vertex_buffer_data[27] = x - br/2;
    vertex_buffer_data[28] = y;
    vertex_buffer_data[29] = z + 3*lt/4;
    vertex_buffer_data[30] = x + br/2;
    vertex_buffer_data[31] = y;
    vertex_buffer_data[32] = z + 3*lt/4;
    vertex_buffer_data[33] = x - br/2;
    vertex_buffer_data[34] = y;
    vertex_buffer_data[35] = z + lt/4;
    

    this->object[0] = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color, GL_FILL);
    GLfloat vertex_buffer_data_a[18];
 
//  rect 1
    vertex_buffer_data_a[0] = x;
    vertex_buffer_data_a[1] = y;
    vertex_buffer_data_a[2] = z;
    vertex_buffer_data_a[3] = x - br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + lt/4;
    vertex_buffer_data_a[6] = x;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z;

    vertex_buffer_data_a[9] = x;
    vertex_buffer_data_a[10] = y + ht;
    vertex_buffer_data_a[11] = z;
    vertex_buffer_data_a[12] = x - br/2;
    vertex_buffer_data_a[13] = y;
    vertex_buffer_data_a[14] = z + lt/4;
    vertex_buffer_data_a[15] = x - br/2;
    vertex_buffer_data_a[16] = y + ht;
    vertex_buffer_data_a[17] = z + lt/4;

    this->object[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_V, GL_FILL);
  
//  rect2
    vertex_buffer_data_a[0] = x;
    vertex_buffer_data_a[1] = y + ht;
    vertex_buffer_data_a[2] = z;
    vertex_buffer_data_a[3] = x + br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + lt/4;
    vertex_buffer_data_a[6] = x + br/2;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z + lt/4;
 
    vertex_buffer_data_a[9] = x;
    vertex_buffer_data_a[10] = y;
    vertex_buffer_data_a[11] = z;
    vertex_buffer_data_a[12] = x + br/2;
    vertex_buffer_data_a[13] = y;
    vertex_buffer_data_a[14] = z + lt/4;
    vertex_buffer_data_a[15] = x;
    vertex_buffer_data_a[16] = y + ht;
    vertex_buffer_data_a[17] = z;

    this->object[2] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_I, GL_FILL);

//  rect 3
    vertex_buffer_data_a[0] = x;
    vertex_buffer_data_a[1] = y;
    vertex_buffer_data_a[2] = z + lt;
    vertex_buffer_data_a[3] = x - br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + 3*lt/4;
    vertex_buffer_data_a[6] = x;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z + lt;

    vertex_buffer_data_a[9] = x;
    vertex_buffer_data_a[10] = y + ht;
    vertex_buffer_data_a[11] = z + lt;
    vertex_buffer_data_a[12] = x - br/2;
    vertex_buffer_data_a[13] = y;
    vertex_buffer_data_a[14] = z + 3*lt/4;
    vertex_buffer_data_a[15] = x - br/2;
    vertex_buffer_data_a[16] = y + ht;
    vertex_buffer_data_a[17] = z + 3*lt/4;
  
    this->object[3] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_B, GL_FILL);

//  rect 4
    vertex_buffer_data_a[0] = x;
    vertex_buffer_data_a[1] = y + ht;
    vertex_buffer_data_a[2] = z + lt;
    vertex_buffer_data_a[3] = x + br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + 3*lt/4;
    vertex_buffer_data_a[6] = x + br/2;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z + 3*lt/4;
 
    vertex_buffer_data_a[9] = x;
    vertex_buffer_data_a[10] = y;
    vertex_buffer_data_a[11] = z + lt;
    vertex_buffer_data_a[12] = x + br/2;
    vertex_buffer_data_a[13] = y;
    vertex_buffer_data_a[14] = z + 3*lt/4;
    vertex_buffer_data_a[15] = x;
    vertex_buffer_data_a[16] = y + ht;
    vertex_buffer_data_a[17] = z + lt;

    this->object[4] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_G, GL_FILL);

//  rect 5
    vertex_buffer_data_a[0] = x - br/2;
    vertex_buffer_data_a[1] = y;
    vertex_buffer_data_a[2] = z + lt/4;
    vertex_buffer_data_a[3] = x - br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + 3*lt/4;
    vertex_buffer_data_a[6] = x - br/2;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z + lt/4;

    vertex_buffer_data_a[9] = x - br/2;
    vertex_buffer_data_a[10] = y + ht;
    vertex_buffer_data_a[11] = z + lt/4;
    vertex_buffer_data_a[12] = x - br/2;
    vertex_buffer_data_a[13] = y + ht;
    vertex_buffer_data_a[14] = z + 3*lt/4;
    vertex_buffer_data_a[15] = x - br/2;
    vertex_buffer_data_a[16] = y;
    vertex_buffer_data_a[17] = z + 3*lt/4;
  
    this->object[5] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_Y, GL_FILL);

//  rect 6
    vertex_buffer_data_a[0] = x + br/2;
    vertex_buffer_data_a[1] = y;
    vertex_buffer_data_a[2] = z + lt/4;
    vertex_buffer_data_a[3] = x + br/2;
    vertex_buffer_data_a[4] = y;
    vertex_buffer_data_a[5] = z + 3*lt/4;
    vertex_buffer_data_a[6] = x + br/2;
    vertex_buffer_data_a[7] = y + ht;
    vertex_buffer_data_a[8] = z + lt/4;

    vertex_buffer_data_a[9] = x + br/2;
    vertex_buffer_data_a[10] = y + ht;
    vertex_buffer_data_a[11] = z + lt/4;
    vertex_buffer_data_a[12] = x + br/2;
    vertex_buffer_data_a[13] = y + ht;
    vertex_buffer_data_a[14] = z + 3*lt/4;
    vertex_buffer_data_a[15] = x + br/2;
    vertex_buffer_data_a[16] = y;
    vertex_buffer_data_a[17] = z + 3*lt/4;
  
    this->object[6] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_BROWN, GL_FILL);
    br--;
//  mast
    vertex_buffer_data_a[0] = x - br;
    vertex_buffer_data_a[1] = y + 3*ht;
    vertex_buffer_data_a[2] = z + lt/2;
    vertex_buffer_data_a[3] = x + br;
    vertex_buffer_data_a[4] = y + 3*ht;
    vertex_buffer_data_a[5] = z + lt/2;
    vertex_buffer_data_a[6] = x - br;
    vertex_buffer_data_a[7] = y + 2*ht;
    vertex_buffer_data_a[8] = z + lt/2;

    vertex_buffer_data_a[9] = x + br;
    vertex_buffer_data_a[10] = y + 3*ht;
    vertex_buffer_data_a[11] = z + lt/2;
    vertex_buffer_data_a[12] = x + br;
    vertex_buffer_data_a[13] = y + 2*ht;
    vertex_buffer_data_a[14] = z + lt/2;
    vertex_buffer_data_a[15] = x - br;
    vertex_buffer_data_a[16] = y + 2*ht;
    vertex_buffer_data_a[17] = z + lt/2;
    
    this->object[7] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_BROWN, GL_FILL);
  
    br--;
    ht += 1.2;
    vertex_buffer_data_a[0] = x - br;
    vertex_buffer_data_a[1] = y + 3*ht;
    vertex_buffer_data_a[2] = z + lt/2;
    vertex_buffer_data_a[3] = x + br;
    vertex_buffer_data_a[4] = y + 3*ht;
    vertex_buffer_data_a[5] = z + lt/2;
    vertex_buffer_data_a[6] = x - br;
    vertex_buffer_data_a[7] = y + 2*ht;
    vertex_buffer_data_a[8] = z + lt/2;

    vertex_buffer_data_a[9] = x + br;
    vertex_buffer_data_a[10] = y + 3*ht;
    vertex_buffer_data_a[11] = z + lt/2;
    vertex_buffer_data_a[12] = x + br;
    vertex_buffer_data_a[13] = y + 2*ht;
    vertex_buffer_data_a[14] = z + lt/2;
    vertex_buffer_data_a[15] = x - br;
    vertex_buffer_data_a[16] = y + 2*ht;
    vertex_buffer_data_a[17] = z + lt/2;
    
    this->object[8] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_BROWN, GL_FILL);
    
    ht+=0.2;
    vertex_buffer_data_a[0] = x - 0.1;
    vertex_buffer_data_a[1] = y;
    vertex_buffer_data_a[2] = z + lt/2;
    vertex_buffer_data_a[3] = x;
    vertex_buffer_data_a[4] = y + 3*ht;
    vertex_buffer_data_a[5] = z + lt/2;
    vertex_buffer_data_a[6] = x + 0.1;
    vertex_buffer_data_a[7] = y + 3*ht;
    vertex_buffer_data_a[8] = z + lt/2;

    vertex_buffer_data_a[9] = x + 0.1;
    vertex_buffer_data_a[10] = y + 3*ht;
    vertex_buffer_data_a[11] = z + lt/2;
    vertex_buffer_data_a[12] = x + 0.1;
    vertex_buffer_data_a[13] = y;
    vertex_buffer_data_a[14] = z + lt/2;
    vertex_buffer_data_a[15] = x - 0.1;
    vertex_buffer_data_a[16] = y;
    vertex_buffer_data_a[17] = z + lt/2;
    
    this->object[9] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_a, COLOR_BLACK, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    // rotate          = rotate * glm::translate(-this->position);
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
    draw3DObject(this->object[2]);
    draw3DObject(this->object[3]);
    draw3DObject(this->object[4]);
    draw3DObject(this->object[5]);
    draw3DObject(this->object[6]);
    draw3DObject(this->object[7]);
    draw3DObject(this->object[8]);
    draw3DObject(this->object[9]);

}

void Boat::set_position(float x, float y) {
    // this->position = glm::vec3(x, y, 0);
}

void Boat::tick() {
    // this->position.x -= speed;
    // this->position.z -= speed;
}

bounding_box_t Boat::bounding_box() {
    float x = this->position.x, z = this->position.z ;
    bounding_box_t bbox = { x, z, 3, 6 };
    return bbox;
}
