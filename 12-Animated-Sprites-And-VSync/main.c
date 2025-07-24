#include <SDL.h>
#include <stdio.h>
//
// Created by rafas on 24/07/2025.
//

#define WIDTH 500
#define HEIGHT 500

SDL_Window *window;

SDL_Renderer *renderer;

bool init();
void close(int status);
bool loadMedia();

int main() {

    if (!init()) {
        printf("Deu algum erro");
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
        printf("Deu algum erro");
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

    window = SDL_CreateWindow("12-Animated-Sprited-And-Vsync", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Deu algum erro ao criar janela: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao iniciar renderizador: %s\n", SDL_GetError());
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

bool loadMedia() {

    return true;
}