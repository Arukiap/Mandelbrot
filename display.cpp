#include "display.h"
#define GLEW_STATIC
#include "GL/glew.h"
#include <iostream>

Display::Display(int width, int height, const std::string& title){

    SDL_Init(SDL_INIT_EVERYTHING);

    //Hide cursor and set it always at middle of screen
    SDL_ShowCursor(0);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    //32 bit color + transparency
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    //Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window =  SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
    
    //GPU connects directly to the window, instead of being the OS in complete command of the window
    glContext = SDL_GL_CreateContext(window);

    GLenum status = glewInit();

    if(status != GLEW_OK){
        std::cerr << "Glew failed to initialize." << std::endl;
    }

    isClosed = false;
}

Display::~Display(){
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::ListenInput(Mouse *mouse){
     SDL_Event e;
     while(SDL_PollEvent(&e)){
        switch( e.type ){
            case SDL_QUIT:
                isClosed = true;
                break;
            case SDL_MOUSEMOTION:
                mouse->moveMouse(e.motion.xrel,e.motion.yrel);
                break;
            default: break;
        }
    }
}

bool Display::IsClosed(){
    return isClosed;
}

void Display::Update(){
    SDL_GL_SwapWindow(window);
}



