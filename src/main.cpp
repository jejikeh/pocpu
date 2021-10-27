#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( int argc , char** argv) {

    float x = 20.0;

    SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
        printf("Error", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT,0);
    if(!window){
        printf("Error",SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , 0);
    if(!renderer ){
        printf("Error",SDL_GetError());
    }

    bool running = true;

    SDL_Event event;

    while(running){

        x += 0.01;
        while(SDL_PollEvent(& event)){

            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, x,255,100,255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}