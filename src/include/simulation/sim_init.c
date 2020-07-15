#include "sim.h"

#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>

extern SDL_Window *window;
extern SDL_Event event;
extern SDL_GLContext context;


//the initialising function that checks if everything starts correctly
int sim_init()
{
    printf("Welcome to a WC-Engine simulation\n"); //greeting
    
    //Init SDL2
    printf("Init SDL2...");
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("\nSDL intern initialisation error\n");
        return 1;
    }
    window=SDL_CreateWindow("WC-ENGINE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,800,SDL_WINDOW_OPENGL);
    if(window==NULL)
    {
        printf("\nCouldn't create SDL window\n");
        return 1;
    }
    printf("done\n");
    
    //init OpenGL4.5
    printf("Init OpenGL 4.5...");

    //setting up the correct version of OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    
    context = SDL_GL_CreateContext(window);
    if(context==NULL)
    {
        printf("\nSDL couldn't create an OpenGL context\n");
        return 1;
    }
    
    printf("done\n");
    
    //setting up glew
    printf("Init GLEW...");
    GLenum status=glewInit();
    
    if(status!=GLEW_OK)
    {
        printf("[ERROR] couldn't initialise GLEW\n");
        return 1;
    }
    printf("done\n");

    //setting background color
    glClearColor(0.9f, 0.9f, 0.9f, 1); //black background
    glClear(GL_COLOR_BUFFER_BIT);
    sim_swap_buffer();

    
    return 0;
    
}