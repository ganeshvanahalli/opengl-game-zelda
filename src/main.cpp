#include "main.h"
#include "signal.h"
#include "unistd.h"
#include "timer.h"
#include "ball.h"
#include "boat.h"
#include "rectangle.h"
#include "waves.h"
#include "rocks.h"
#include "gifts.h"
#include "fireballs.h"
#include "link.h"
#include <ao/ao.h>
#include <mpg123.h>

#define BITS 8

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;
pid_t pid = 0;

int wind =0;

/**************************
* Customizable functions *
**************************/

Link hero;
Ball ball1;
Boat player;
Waves waves[100];
Rectangle occean;
Rocks rocks[50];
Gifts cannon;
Gifts island;
Gifts isl_gift;

Fireballs fire_ball, mon_fireball;

float health = 100, score =0.0;
Gifts health_gift[20];
Gifts boost_gift[20];


Rocks monsters[3][10];

double xpos, ypos;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float camera_x = 2;
float camera_y = 5;
float camera_z = 9;
float verti = 0;
float monster_health[3] = {100.0 , 100.0, 100.0};

float fir_x,fir_y,fir_z,thrust;
int timerr = 0;
int jump = 0;
float u,a,dis,y_init;
int boost_count=0;
float limit = 0.4;
int fire = 0;
float x1,x2,z1,z2,temp;
int boost_time;
int where = -1;
int on_island = 0;
int mon_fire = 0;
float y_mon;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer


    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f) - 5, 5, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    if(on_island == 0 && health > 0){
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        int i,j;
        // use the loaded shader program
        // Don't change unless you know what you are doing
        glUseProgram (programID);
        glm::vec3 eye ( camera_x, camera_y, camera_z);

        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (player.position.x, 0.1,player.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);

        // Compute Camera matrix (view)
        Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
        // Don't change unless you are sure!!
        // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

        // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
        // Don't change unless you are sure!!
        glm::mat4 VP = Matrices.projection * Matrices.view;

        // Send our transformation to the currently bound shader, in the "MVP" uniform
        // For each model you render, since the MVP will be different (at least the M part)
        // Don't change unless you are sure!!
        glm::mat4 MVP;  // MVP = Projection * View * Model
            // Scene render
        // ball1.draw(VP);

        //occean_sheets render
        occean.draw(VP);
        
        //waves render
        for(i=0;i<100;i++)
            waves[i].draw(VP);

        //rocks render    
        for(i=0;i<50;i++)
            rocks[i].draw(VP);

        // monsters render
        for(j=0;j<3;j++){
            if(monster_health[j] > 0){
                for(i=0;i<10;i++)
                    monsters[j][i].draw(VP);
            }
        }

        // gifts render
        for(j=0;j<20;j++)
            health_gift[j].draw(VP);

        for(j=0;j<20;j++)
            boost_gift[j].draw(VP);        

        //player render
        if(camera_y != 3 && health > 0){
            player.draw(VP);
            // fireballs render
            // fire_ball.draw(VP);

            // //monster's fireball render
            // mon_fireball.draw(VP);

            // cannon render
            cannon.draw(VP);
            //  OUR HERO
            hero.draw(VP);            
        }
            fire_ball.draw(VP);

            //monster's fireball render
            mon_fireball.draw(VP);

        //  ISLAND render
        if(monster_health[0] <= 0 && monster_health[1] <= 0 && monster_health[2] <= 0)
            island.draw(VP);

    }
    else if(health>0){
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        int i,j;
        // use the loaded shader program
        // Don't change unless you know what you are doing
        glUseProgram (programID);
        glm::vec3 eye ( camera_x, camera_y, camera_z);

        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (hero.position.x, hero.position.y,hero.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);

        // Compute Camera matrix (view)
        Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
        // Don't change unless you are sure!!
        // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

        // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
        // Don't change unless you are sure!!
        glm::mat4 VP = Matrices.projection * Matrices.view;

        // Send our transformation to the currently bound shader, in the "MVP" uniform
        // For each model you render, since the MVP will be different (at least the M part)
        // Don't change unless you are sure!!
        glm::mat4 MVP;  // MVP = Projection * View * Model
            // Scene render
        // ball1.draw(VP);

        //occean_sheets render
        occean.draw(VP);
        
        //waves render
        for(i=0;i<100;i++)
            waves[i].draw(VP);

        //rocks render    
        for(i=0;i<50;i++)
            rocks[i].draw(VP);

        // monsters render
        for(j=0;j<3;j++){
            if(monster_health[j] > 0){
                for(i=0;i<10;i++)
                    monsters[j][i].draw(VP);
            }
        }

        // gifts render
        for(j=0;j<20;j++)
            health_gift[j].draw(VP);

        for(j=0;j<20;j++)
            boost_gift[j].draw(VP);        

        //player render
        if(camera_y != 3 && health > 0){
            player.draw(VP);
            // fireballs render
            // fire_ball.draw(VP);

            // // cannon render
            // cannon.draw(VP);
            //  OUR HERO
            hero.draw(VP);
        }
            fire_ball.draw(VP);

            //monster's fireball render
            mon_fireball.draw(VP);

        //  ISLAND render
        if(monster_health[0] <= 0 && monster_health[1] <= 0 && monster_health[2] <= 0)
            island.draw(VP);
    }

}

void tick_input(GLFWwindow *window) {
    int i,j;
    float distz = 3;
    float distx = 8;

    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int JUMP = glfwGetKey(window, GLFW_KEY_SPACE);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int A = glfwGetKey(window, GLFW_KEY_A);
    int D = glfwGetKey(window, GLFW_KEY_D);
    int S = glfwGetKey(window, GLFW_KEY_S);
    int W = glfwGetKey(window, GLFW_KEY_W);
    int charge = glfwGetKey(window, GLFW_KEY_F);
    int boost = glfwGetKey(window, GLFW_KEY_E);
    int embark = glfwGetKey(window, GLFW_KEY_I);

    int C = glfwGetKey(window, GLFW_KEY_C);
    int V = glfwGetKey(window, GLFW_KEY_V);
    int B = glfwGetKey(window, GLFW_KEY_B);
    int N = glfwGetKey(window, GLFW_KEY_N);
    int M = glfwGetKey(window, GLFW_KEY_M);

    timerr++;
    
    cannon.position.x = player.position.x;
    cannon.position.y = player.position.y + 1.25;
    cannon.position.z = player.position.z;

///////////////////////////////////////// MOTION //////////////////////////////////////////////////////////////////////////////////
    // waves motion
    if(timerr%4 == 0){
        for(i=0;i<100;i++)
            waves[i].speed *= -1;
    }

    // monsters motion
    if(timerr%20 == 0){
        for(j=0;j<3;j++)
            for(i=0;i<10;i++)
                monsters[j][i].speed *= -1;
    }

    //  Generarting waves
    if(timerr%100 == 0){
        for(i=0;i<10;i++){
            if(i%2)
                distx -= i*0.5;
            else
                distx += i*0.5;
            for(j=0;j<10;j++){
                waves[i*10 + j].position.x = -50 + distx*j + player.position.x;
                waves[i*10 + j].position.z = 2*i*distz -25 + player.position.z;
                waves[i*10 + j].position.y = 0.2;
            }
        }  
    }

    //  winding
    if(wind){
        wind--;
        player.position.x += (limit)*(((float) rand() / (RAND_MAX))*2 - 1);
        player.position.z += (limit)*(((float) rand() / (RAND_MAX))*2 - 1);        
    }

    if(timerr%2000 == 0 && wind == 0){
        wind = 10;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  Detecting collission now with any of the rocks
    x2 = player.position.x;
    z2 = player.position.z;
    for(i=0;i<50;i++){
        if(detect_collision(player.bounding_box(), rocks[i].bounding_box())){
            x1 = rocks[i].position.x;
            z1 = rocks[i].position.z;
            x2-=x1;
            z2-=z1;
            temp = sqrt(x2*x2 + z2*z2);
            x2/=temp;
            z2/=temp;
            player.position.x += 10*x2;
            player.position.z += 10*z2;
            health -= 5;
            camera_x += 10*x2;
            camera_z += 10*z2;
            // printf("collide \n");
        }
    }

///////////////////////////////////////// GIFTS //////////////////////////////////////////////////////////////////////////////////    
    // collission with health_gifts
    for(i=0;i<20;i++){
        if(detect_collision(player.bounding_box(), health_gift[i].bounding_box()) && health < 100){
            health_gift[i].position.y -= 20;
            health += 10;
            if(health > 100)
                health = 100;
            score += 5;
        }
    }

    // collission with boost_gifts
    for(i=0;i<20;i++){
        if(detect_collision(player.bounding_box(), boost_gift[i].bounding_box())){
            boost_gift[i].position.y -= 20;
            boost_count++;
            score += 5;
        }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////  BATTLE FEILD  //////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    //  if touched the monsters ur dead !!!
    for(i=0;i<3;i++){
        x2 = 0;
        for(j=0;j<10;j++){
            if(detect_collision(player.bounding_box(), monsters[i][j].bounding_box()) && monster_health[i] > 0){
                x2++;
            }
        }
        if(x2 > 0){
            health = 0;
        }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  player attack on BOSSES
    if(fire == 0){
        fire_ball.position = player.position;
        // fire_ball.position.z -=2.5;
        // fire_ball.position.x +=1; 
        fire_ball.position.y +=2.5; 
    }
    if(fire ==1){
        if(fire_ball.position.y <=0){
            // printf("done\n");
            fire = 0;
            fire_ball.position.y = -4;
            x1 = fire_ball.position.x;
            z1 = fire_ball.position.z;

            for(i=0;i<3;i++){
                x2 = 0;
                for(j=0;j<10;j++){
                    if(detect_collision(fire_ball.bounding_box(), monsters[i][j].bounding_box()) && monster_health[i] > 0){
                        x2++;
                    }
                }
                if(x2 > 0){
                    monster_health[i] -= 5;
                    score += 20;
                    // printf("monster!! %f", monster_health[i]);
                }
            }
        }
        fir_y -= 0.2;
        fire_ball.position.x += thrust*fir_x;
        fire_ball.position.y += thrust*fir_y;
        fire_ball.position.z += thrust*fir_z;
    }
    if(charge && fire == 0){
        fir_x = 5*where*limit*sin(player.rotation * M_PI / 180.0f);
        fir_y = 5;
        fir_z = 10*where*limit*cos(player.rotation * M_PI / 180.0f);
        temp = sqrt(fir_x*fir_x + fir_y*fir_y +fir_z*fir_z);
        fir_x /=temp;
        fir_y /=temp;
        fir_z /=temp;
        fire = 1;
        thrust = 5;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // BOSSES attacks on player
    for(i=0;i<3;i++){
        if(monster_health[i] > 0 && how_near(monsters[i][4].bounding_box(), player.bounding_box())){
            // printf("hula la la \n");

            if(mon_fire == 1){
                // printf("kukuku kakaka\n");
                if(mon_fireball.position.y<=0){
                    mon_fire = 0;
                    mon_fireball.position.y = -4;
                    if(detect_collision(mon_fireball.bounding_box(), player.bounding_box())){
                        // printf("done\n");
                        score -= 10;
                        health -= 10;
                    }
                }
                y_mon -= 0.008;
                mon_fireball.position.x += thrust*x2;
                mon_fireball.position.y += thrust*y_mon;
                mon_fireball.position.z += thrust*z2;
                
            }

            if(mon_fire == 0){
                // printf("im back \n");
                mon_fireball.position = monsters[i][4].position;
                mon_fireball.position.y =5;
                x2 = 15*where*limit*sin(player.rotation * M_PI / 180.0f);
                y_mon = 150;
                z2 = 20*where*limit*cos(player.rotation * M_PI / 180.0f);
                temp = sqrt(x2*x2 + y_mon*y_mon +z2*z2);
                x2 /= temp;
                y_mon /= temp;
                z2 /= temp;
                // printf(" %f %f %f \n", x2,y_mon,z2);
                mon_fire = 1;
                thrust = 15;
                // x2 = player.position.x;
                // z2 = player.position.z;
                // x1 = monsters[i][4].position.x;
                // y_mon = 5;                
                // z1 = monsters[i][4].position.z;
                // x2-=x1;
                // z2-=z1;
                // temp = sqrt(x2*x2 + z2*z2 + y_mon*y_mon);
                // x2/=temp;
                // z2/=temp;
                // y_mon/=temp;
                // mon_fire = 1;
                // thrust = 5;
            }
        }
    }










///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //  BOOST
    if(boost_time){
        boost_time--;
        if(boost_time == 0)
            limit = 0.4;
    }
    if(boost && boost_time == 0 && boost_count > 0){
        boost_count--;
        boost_time = 10;
        limit = 1.2;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////// HERO on occean for the SALE ////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(on_island == 0){
        y_init = 0.1;
        // limit = 0.4;
        if(detect_collision(player.bounding_box(), island.bounding_box())){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            x2 = hero.position.x;
            z2 = hero.position.z;
            x1 = island.position.x;
            z1 = island.position.z;
            x2-=x1;
            z2-=z1;
            temp = sqrt(x2*x2 + z2*z2);
            x2/=temp;
            z2/=temp;
            player.position.x += 0.2*x2;
            player.position.z += 0.2*z2;
            camera_x += 0.2*x2;
            camera_z += 0.2*z2;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            
            if(embark){
                on_island = 1;
                y_init = 4.6;
                camera_y = 6.5;
                jump = 0;
                limit = 0.2;
                hero.position.y = y_init;
                hero.position.x = island.position.x ;
                hero.position.z = island.position.z;
            }
        }

        hero.position.x = player.position.x;
        hero.position.y = player.position.y + 3;
        hero.position.z = player.position.z;
    
        if(jump ==1 ){
            u += a;
            dis = u + a;
            player.position.y += dis;
            if(player.position.y <= y_init){
                jump = 0;
                u=0;
                player.position.y = y_init;
            }
        }

        if (JUMP && jump == 0){
            u = 0.6;
            a = -0.05;
            jump =1;
        }

        if(C)
            camera_y = 5;
        if(V)
            camera_y = 18;
        if(B)
            camera_y = 3;
        if(N){
            camera_y = 8;
            camera_x = player.position.x + 38;
            camera_z = player.position.z;
        }

        if (W){
            where = -1;
            player.position.z -= limit*cos(player.rotation * M_PI / 180.0f);
            player.position.x -= limit*sin(player.rotation * M_PI / 180.0f);
            occean.position.z -= limit*cos(player.rotation * M_PI / 180.0f);
            occean.position.x -= limit*sin(player.rotation * M_PI / 180.0f);

            if(camera_y == 5){    
                if(camera_z - player.position.z > 12)
                    camera_z = player.position.z + 12;
            
                else if(player.position.z - camera_z > 12)
                    camera_z = player.position.z - 12;

                camera_x = player.position.x + 0.5;
            }
            else if(camera_y == 18){
                if(camera_z - player.position.z > 8)
                    camera_z = player.position.z + 8;
            
                else if(player.position.z - camera_z > 8)
                    camera_z = player.position.z - 8;

                camera_x = player.position.x + 0.5;
            }
            else if(camera_y == 3){
                if(camera_z - player.position.z > 12)
                    camera_z = player.position.z + 12;
            
                else if(player.position.z - camera_z > 12)
                    camera_z = player.position.z - 12;

                camera_x = player.position.x + 0.5;
            }
        }
        if (S){
            where = 1;
            player.position.z += limit*cos(player.rotation * M_PI / 180.0f);
            player.position.x += limit*sin(player.rotation * M_PI / 180.0f);
            occean.position.z += limit*cos(player.rotation * M_PI / 180.0f);
            occean.position.x += limit*sin(player.rotation * M_PI / 180.0f);
            
            if(camera_y == 5){
                camera_z = player.position.z + 12*abs(cos(player.rotation * M_PI / 180.0f))/cos(player.rotation * M_PI / 180.0f);
                camera_x = player.position.x + 0.5;
            }
            else if(camera_y == 18){
                camera_z = player.position.z + 8*abs(cos(player.rotation * M_PI / 180.0f))/cos(player.rotation * M_PI / 180.0f);
                camera_x = player.position.x + 0.5;
            }
            else if(camera_y == 3){
                camera_z = player.position.z + 12*abs(cos(player.rotation * M_PI / 180.0f))/cos(player.rotation * M_PI / 180.0f);
                camera_x = player.position.x + 0.5;
            }
        }
        if (A){   
            player.rotation += 1;
        }
        if (D){
            player.rotation -= 1;
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////// HERO on ISLAND////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else{
        if(detect_collision(player.bounding_box(), island.bounding_box())){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            x2 = player.position.x;
            z2 = player.position.z;
            x1 = island.position.x;
            z1 = island.position.z;
            x2-=x1;
            z2-=z1;
            temp = sqrt(x2*x2 + z2*z2);
            x2/=temp;
            z2/=temp;
            player.position.x += 0.2*x2;
            player.position.z += 0.2*z2;
            camera_x += 0.2*x2;
            camera_z += 0.2*z2;
        }
        limit = 0.2;
        if(detect_collision(hero.bounding_box(),isl_gift.bounding_box())){
            printf("youve got the princess YAY linko !!! :) :) :)\n");
            score += 1000;
            on_island = 2; // game over 
        }
        if(abs(hero.position.x - island.position.x) > 152 || abs(hero.position.z - island.position.z) > 152 ){
            on_island = 0;
            limit = 0.4;
        }

        if(jump ==1 ){
            u += a;
            dis = u + a;
            hero.position.y += dis;
            if(hero.position.y <= y_init){
                jump = 0;
                u=0;
                hero.position.y = y_init;
            }
        }

        if (JUMP && jump == 0){
            u = 0.6;
            a = -0.05;
            jump =1;
        }

        if(C)
            camera_y = 6.5;
        if(V)
            camera_y = 10;
        if(B)
            camera_y = 3;
        if(N){
            camera_y = 8;
            camera_x = hero.position.x + 10;
            camera_z = hero.position.z;
        }

        if (W){
            where = -1;
            hero.position.z -= limit*cos(hero.rotation * M_PI / 180.0f);
            hero.position.x -= limit*sin(hero.rotation * M_PI / 180.0f);
            occean.position.z -= limit*cos(hero.rotation * M_PI / 180.0f);
            occean.position.x -= limit*sin(hero.rotation * M_PI / 180.0f);

            if(camera_y == 6.5){    
                if(camera_z - hero.position.z > 3)
                    camera_z = hero.position.z + 3;
            
                else if(hero.position.z - camera_z > 3)
                    camera_z = hero.position.z - 3;

                camera_x = hero.position.x + 0.5;
            }
            else if(camera_y == 10){
                if(camera_z - hero.position.z > 8)
                    camera_z = hero.position.z + 8;
            
                else if(hero.position.z - camera_z > 8)
                    camera_z = hero.position.z - 8;

                camera_x = hero.position.x + 0.5;
            }
            else if(camera_y == 3){
                if(camera_z - hero.position.z > 6)
                    camera_z = hero.position.z + 6;
            
                else if(hero.position.z - camera_z > 6)
                    camera_z = hero.position.z - 6;

                camera_x = hero.position.x + 0.5;
            }
        }
        if (S){
            where = 1;
            hero.position.z += limit*cos(hero.rotation * M_PI / 180.0f);
            hero.position.x += limit*sin(hero.rotation * M_PI / 180.0f);
            occean.position.z += limit*cos(hero.rotation * M_PI / 180.0f);
            occean.position.x += limit*sin(hero.rotation * M_PI / 180.0f);
            
            if(camera_y == 6.5){
                camera_z = hero.position.z + 3*abs(cos(hero.rotation * M_PI / 180.0f))/cos(hero.rotation * M_PI / 180.0f);
                camera_x = hero.position.x + 0.5;
            }
            else if(camera_y == 10){
                camera_z = hero.position.z + 4*abs(cos(hero.rotation * M_PI / 180.0f))/cos(hero.rotation * M_PI / 180.0f);
                camera_x = hero.position.x + 0.5;
            }
            else if(camera_y == 3){
                camera_z = hero.position.z + 3*abs(cos(hero.rotation * M_PI / 180.0f))/cos(hero.rotation * M_PI / 180.0f);
                camera_x = hero.position.x + 0.5;
            }
        }
        if (A){   
            hero.rotation += 1;
        }
        if (D){
            hero.rotation -= 1;
        }

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if (left) {
        camera_rotation_angle -= 1;
    }
    if (right) {
        camera_rotation_angle += 1;
    }
    
    if (up) {
        camera_y += 0.1;
        // camera_z += 0.1;
        // Do something
    }
    if (down) {
        camera_y -= 0.1;
        // camera_z -= 0.1;
        // Do something
    }
    if (right) {
        camera_x += 0.1;
        // Do something
    }
    if (left) {
        camera_x -= 0.1;
        // Do something
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    int cx;
    char buffer[100];
    //PRINTING IN THE TITLE
    if(health > 0){
        cx = snprintf ( buffer, 100, "LINK'S HEALTH LEFT is %f", health);
        if (cx>=0 && cx<100)
            snprintf ( buffer+cx, 100-cx, ", and the SCORE is %f.", score );
        glfwSetWindowTitle (window, buffer);
    }
    else{
        cx = snprintf ( buffer, 100, "GAME OVER !!!");
        if (cx>=0 && cx<100)
            snprintf ( buffer+cx, 100-cx, ", and the SCORE is %d.", score );
        glfwSetWindowTitle (window, buffer);
    }

}

void tick_elements() {
    int i,j;
    player.tick();
    
    for(i=0;i<100;i++)
        waves[i].tick();
    
    for(j=0;j<3;j++)
        for(i=0;i<10;i++)
            monsters[j][i].tick();
    // ball1.tick();
    // camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    int i,j;
    float distz = 3;
    float distx = 8;
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    hero        = Link(0,4,0,0.2,COLOR_B);
    ball1       = Ball(0, 0, COLOR_RED);
    player      = Boat(0,0.01,0,6,3.3,2,COLOR_RED);
    occean      = Rectangle(0,0,0, 1600,1600,0, COLOR_BLUE);
    fire_ball = Fireballs(0,0,0,0.5,0.6,COLOR_R);
    mon_fireball = Fireballs(0,-5,0,0.5,0.6,COLOR_B);
    cannon      = Gifts(0,1.25,0,2,COLOR_B);
    island      = Gifts(0,-146,800,300,COLOR_G);
   
    isl_gift = Gifts((((float) rand() / (RAND_MAX))*2 - 1)*150 ,4.7,(((float) rand() / (RAND_MAX))*2 - 1)*150 + 1000,4,COLOR_GREY);

    for(j=0;j<20;j++)
        health_gift[j] = Gifts((((float) rand() / (RAND_MAX))*2 - 1)*1000 ,0,(((float) rand() / (RAND_MAX))*2 - 1)*1000,4,COLOR_GREY);

    for(j=0;j<20;j++)
        boost_gift[j] = Gifts((((float) rand() / (RAND_MAX))*2 - 1)*1000 ,0,(((float) rand() / (RAND_MAX))*2 - 1)*1000,4,COLOR_R);

    for(i=0;i<10;i++){
        if(i%2)
            distx -= i*0.5;
        else
            distx += i*0.5;
        // distz = ((float) rand() / (RAND_MAX) + 1)*6 + 2 ;
        for(j=0;j<10;j++){
            waves[i*10 + j] = Waves(-50 + distx*j,0.8,2*i*distz -25,COLOR_BACKGROUND);
        }
    }
    distx = 1;
    for(i=0;i<50;i++){
        if(i%2)
            distx *= -1;
        
        rocks[i] = Rocks((((float) rand() / (RAND_MAX))*2 - 1)*1000 ,0,(((float) rand() / (RAND_MAX))*2 - 1)*1000 , 4,4, COLOR_BLACK);
    }

    // RED monster :X
    for(i=0;i<3;i++){
        monsters[0][i] = Rocks(500 + 3*i,0,500,4,4,COLOR_R);
    }

    for(i=0;i<4;i++){
        monsters[0][i+3] = Rocks(498.5 + 3*i,0,503,4,4,COLOR_R);
    }

    for(i=0;i<3;i++){
        monsters[0][i+7] = Rocks(500 + 3*i,0,506,4,4,COLOR_R);
    }
    for(i=0;i<10;i++){
        monsters[0][i].speed = 0.3;
    }

    // INDIGO monster :X
    for(i=0;i<3;i++){
        monsters[1][i] = Rocks(0 + 3*i,0,-500,4,4,COLOR_I);
    }

    for(i=0;i<4;i++){
        monsters[1][i+3] = Rocks(-1.5 + 3*i,0,-503,4,4,COLOR_I);
    }

    for(i=0;i<3;i++){
        monsters[1][i+7] = Rocks(0 + 3*i,0,-506,4,4,COLOR_I);
    }
    for(i=0;i<10;i++){
        monsters[1][i].speed = 0.3;
    }

    // BLUE monster :X
    for(i=0;i<3;i++){
        monsters[2][i] = Rocks(-500 + 3*i,0,0,4,4,COLOR_B);
    }

    for(i=0;i<4;i++){
        monsters[2][i+3] = Rocks(-501.5 + 3*i,0,3,4,4,COLOR_B);
    }

    for(i=0;i<3;i++){
        monsters[2][i+7] = Rocks(-500 + 3*i,0,6,4,4,COLOR_B);
    }
    for(i=0;i<10;i++){
        monsters[2][i].speed = 0.3;
    }


    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);
        // printf("x %f y %f z %f", player.position.x, player.position.y,player.position.z);

    mpg123_handle *mh;
    unsigned char *buffer;
    size_t buffer_size;
    size_t done;
    int err;

    int driver;
    ao_device *dev;

    ao_sample_format format;
    int channels, encoding;
    long rate;

    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = 3000;
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    /* open the file and get the decoding format */
    mpg123_open(mh, "pirates.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    /* set the output format and open the output device */
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

        /* decode and play */
        if (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
            ao_play(dev, (char*)buffer, done);
        else mpg123_seek(mh, 0, SEEK_SET); // loop audio from start again if ended
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.z - b.z) * 2 < (a.length + b.length));
}
bool how_near(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width + 60)) &&
           (abs(a.z - b.z) * 2 < (a.length + b.length + 60));
}

