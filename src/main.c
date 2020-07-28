#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "wce/wce.h"
#include "simulation/sim.h"

long seed=508;//max 8 digits

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
    GLuint shader_program_reference=sim_load_gl_shaders();
    
    GLuint triangle_array_reference;
    GLuint vertex_buffer_reference;
    glGenVertexArrays(1, &triangle_array_reference);
    glGenBuffers(1, &vertex_buffer_reference);
    
    static const GLfloat triangle_data[] = //a test square
    {
        //position          //color         //comment
        -0.5f,-0.5f,0.0f,   0.4f,0.4f,0.3f, //top left
        0.5f,-0.5f,0.0f,    0.2f,0.6f,0.2f, //top right
        -0.5f,0.5f,0.0f,    0.1f,0.3f,0.8f, //bottom left

        -0.5f,0.5f,0.0f,    0.9f,0.6f,0.4f, //bottom left
        0.5f,0.5f,0.0f,     0.1f,0.5f,0.8f, //bottom right
        0.5f,-0.5f,0.0f,    0.5f,0.5f,0.5f, //top right
        
    };
    
    glBindVertexArray(triangle_array_reference);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_reference);
    glBufferData(GL_ARRAY_BUFFER,sizeof(triangle_data),triangle_data,GL_STATIC_DRAW);
    
    //describing data for OpenGL for its interpretation
    glVertexAttribPointer
    (
        0,
        3,              //size
        GL_FLOAT,       //type
        GL_FALSE,       //normalized
        6*sizeof(float),//stride
        (void*)0        //array buffer offset
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer
    (
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6*sizeof(float),
        (void*)(3*sizeof(float))
    );
    glEnableVertexAttribArray(1);
    /*GLint vertex_color_reference=glGetUniformLocation(shader_program_reference, "in_color");
    
    float red=0.0f;*/
    
    //main loop
    while(1)
    {

    //change color;
    /*glUniform3f(vertex_color_reference,red, 0.1f,0.14f);
    red=red+0.00002f;
    if(red>0.999)
        red=0.0f;*/

    glDrawArrays(GL_TRIANGLES,0,6);
    
    sim_swap_buffer();
        
        //if window is being closed then the simulation ends
        SDL_PollEvent(&event);
        if(event.type==SDL_QUIT)
            break;
    }
    
    

    
    SDL_Quit();
    return 0;
}