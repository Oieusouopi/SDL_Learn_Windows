#include <SDL.h>
#include <stdio.h>
//
// Created by rafas on 23/07/2025.
//
#define HEIGHT 500
#define WIDTH 400

bool init();
bool loadMedia();
void close(int status);

SDL_Window *window;

SDL_Renderer *renderer;

int main() {

    if (!init()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    while (true) {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }
    }
}

bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("11-ALPLHA-BLEDING",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Aconteceu um erro ao criar a janela: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Aconteceu um erro ao criar o renderizador: %s", SDL_GetError());
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