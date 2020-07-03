#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>

int main()
{
    //Init SDL2
    printf("init SDL2...");
    SDL_Window *window = NULL;
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("WC-ENGINE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,640,SDL_WINDOW_OPENGL);
    printf("done\n");
    
    //init OpenGL3.2
    printf("init OpenGL 3.2...");
    SDL_GLContext context;
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    context = SDL_GL_CreateContext(window);
    //glewInit();
    printf("done\n");
    
    //test
    
    glClearColor(0.2f, 0.7f, 0.25f, 1.0f); //green background
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
  
    SDL_Delay(3000);

    
    SDL_Quit();
    return 0;
}