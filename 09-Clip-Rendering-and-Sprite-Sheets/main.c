//
// Created by rafas on 13/07/2025.
//

#include <SDL.h>
#include <SDL_video.h>
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 300

bool init();
void close(int status);

SDL_Window *window = NULL;

SDL_Renderer *renderer = NULL;

int main() {

    if (!init()) {
        printf("Aconteceu algum erro\n");
        close(EXIT_FAILURE);
    }

    while (true) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }
    }
}

bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        printf("Erro ao iniciar SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("09-Clip-Rendering-And-Sprite-Sheets", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro ao criar a janela: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void close(int status) {
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_Quit();

    exit(status);
}