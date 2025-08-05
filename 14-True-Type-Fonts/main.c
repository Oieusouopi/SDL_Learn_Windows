//
// Created by rafas on 30/07/2025.
//

#include <SDL.h>
#include <SDL_ttf.h>
#include "LTexture/LTexture.h"

#define WIDTH 300
#define HEIGHT 300

bool init();
void close(int status);

SDL_Window *window;
SDL_Renderer *renderer;

TTF_Font *font;

LTexture texture;

bool loadMedia();

int main() {

    if (!init()) {
        close(EXIT_FAILURE);
    }

    SDL_Event ev;
    while (true) {
        if (SDL_PollEvent(&ev) != 0) {
            if (ev.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }
    }
}

bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("14-True-Type-Fonts", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        return false;
    }

    return true;
}

void close(int status) {

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    exit(status);
}