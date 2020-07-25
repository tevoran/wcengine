#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "wce/wce.h"
#include "simulation/sim.h"

long seed=508;//max 8 digits

struct vec3{ //vector struct for Cartesian vectors
    GLfloat x;
    GLfloat y;
    GLfloat z;
};


int main()
{
    if(sim_init()!=0)
    {
        printf("Couldn't initialise the simulation\n");
        return 0;
    }
    
    printf("seed=%li\n",seed);
    
    //creating pseudorandomly the planet and its host star
    struct planet world=wce_create_planet(seed);
    
    //starting wce_time
    wce_time_start();

    //testing OpenGL

    //loading shaders
    sim_load_gl_shaders();
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    
    static const GLfloat g_vertex_buffer_data[] =
    {
        -1.0f,-1.0f,0.0f,
        1.0f,-1.0f,0.0f,
        0.0f,1.0f,0.0f,
    };
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data),g_vertex_buffer_data,GL_STATIC_DRAW);
    
    //show shit
    glVertexAttribPointer
    (
        0,
        3,          //size
        GL_FLOAT,   //type
        GL_FALSE,   //normalized
        0,          //stride
        (void*)0    //array buffer offset
    );
    
    glBindVertexArray(VertexArrayID);
    
    glDrawArrays(GL_TRIANGLES,0,3);
    
    sim_swap_buffer();
    SDL_Delay(3000);

    
    SDL_Quit();
    return 0;
}