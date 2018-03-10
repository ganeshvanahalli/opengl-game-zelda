#include "link.h"
#include "main.h"

Link::Link(float x, float y, float z, float lt, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.0;
    GLfloat vertex_buffer_data[18];
    z=0;
    x=0;
    y=0;
    float k;
    float length = lt; 

    ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    /////////////////////////////////////   FACE    ///////////////////////////////////// ///////////////////////////////////// 
    ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = 3*length/4;
    
    x = 0;
    y = 7*length/4;
    z = 0;

    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[0] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[2] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[3] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[4] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[5] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// CHEST //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length/2;
    
    x = 0;
    y = length/2;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[6] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[7] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[8] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[9] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[10] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[11] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_R, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// STOMACH //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length/2;
    
    x = 0;
    y = -length/2;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[12] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[13] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[14] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[15] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[16] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[17] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// RIGHTY HAND //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length/2;
    
    x = length;
    y = length/2;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[18] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[19] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[20] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[21] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[22] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[23] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// LEFTY HAND //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length/2;
    
    x = -length;
    y = length/2;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[24] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[25] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[26] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[27] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[28] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[29] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_V, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// RIGHTY LEG //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length;
    
    x = 5*length/4;
    y = -2*length;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[30] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[32] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[31] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[33] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[34] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[35] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);    

///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    ////////////////////////////////////////////////// LEFTY LEG //////////////////////// ///////////////////////////////////// 
///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// ///////////////////////////////////// 
    k = length;
    
    x = -5*length/4;
    y = -2*length;
    z = 0;
    
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z + k;
    vertex_buffer_data[16] = y +k;

    this->object[36] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect3
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[37] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);
 
    // rect2
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y +k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y +k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y +k;

    this->object[38] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);
 
    //  rect4
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z -k;
    vertex_buffer_data[1] = y -k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z +k;
    vertex_buffer_data[4] = y -k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z +k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z -k;
    vertex_buffer_data[10] = y -k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z + k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z -k;
    vertex_buffer_data[16] = y -k;

    this->object[39] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect5
    vertex_buffer_data[0] = x +k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x +k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x +k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x +k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x +k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x +k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;


    this->object[40] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);

    //  rect6
    vertex_buffer_data[0] = x -k;
    vertex_buffer_data[2] = z +k;
    vertex_buffer_data[1] = y +k;
    vertex_buffer_data[3] = x -k;
    vertex_buffer_data[5] = z -k;
    vertex_buffer_data[4] = y +k;
    vertex_buffer_data[6] = x -k;
    vertex_buffer_data[8] = z -k;
    vertex_buffer_data[7] = y -k;

    vertex_buffer_data[9] = x -k;
    vertex_buffer_data[11] = z +k;
    vertex_buffer_data[10] = y +k;
    vertex_buffer_data[12] = x -k;
    vertex_buffer_data[14] = z -k;
    vertex_buffer_data[13] = y -k;
    vertex_buffer_data[15] = x -k;
    vertex_buffer_data[17] = z +k;
    vertex_buffer_data[16] = y -k;

    this->object[41] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_Y, GL_FILL);    


}

void Link::draw(glm::mat4 VP) {
    int i;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    // rotate          = rotate * glm::translate(-this->position);
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(i=0;i<42;i++){
    draw3DObject(this->object[i]);   
    }
}

void Link::set_position(float x, float y) {
    // this->position = glm::vec3(x, y, 0);
}

void Link::tick() {
    // this->position.x -= speed;
    this->position.y -= speed;
}

bounding_box_t Link::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 1, 1 };
    return bbox;
}
