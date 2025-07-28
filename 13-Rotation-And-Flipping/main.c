//
// Created by rafas on 28/07/2025.
//

#include <stdio.h>
#include "SDL.h"

#define WIDTH 500
#define HEIGHT 500

bool init();
void close(int status);

bool loadMedia();

SDL_Window *window;

SDL_Renderer *renderer;

int main() {

    if (!init()) {
        close(EXIT_FAILURE);
    }

    while (true) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev) != 0) {

            if (ev.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }
    }

}


bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("13-rotation-and-flipping", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (window == NULL) {
        return false;
    }

    return true;
}

void close(int status) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    exit(status);
}