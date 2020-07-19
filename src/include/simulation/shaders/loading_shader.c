#include "../sim.h"

#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>


int sim_load_gl_shaders()

{
    //data used for the function
    int shader_size;
    FILE *shader_file;
    char *vertex_shader_string;

    
    //loading vertex shader
    printf("Loading Vertex Shader...");
    
    
    shader_file=fopen("src/include/simulation/shaders/vertex_shader.glsl","r");
    if(shader_file==NULL)//error message if there is an error while reading the vertex shader file
    {
        printf("\n[ERROR] error while readind vertex shader file\n");
        return 1;
    }

        //determining file size for memory allocation
        fseek(shader_file, 0, SEEK_END);
        shader_size=ftell(shader_file);
        fseek(shader_file, 0, SEEK_SET);
        
        //allocating memory
        vertex_shader_string=malloc(shader_size);
        fgets(vertex_shader_string, shader_size, shader_file);
        printf("done\n");


    
    return 0;
}