//
// Created by rafas on 18/07/2025.
//


#include <SDL.h>
#include <stdio.h>
#define HEIGHT 200
#define WIDTH 200

SDL_Window *window;

bool init();
void close(int status);

int main() {

    if (!init()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    while ( true ) {
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

    window = SDL_CreateWindow("10-Color-Modulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro janela nao inicializada com sucesso: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void close(int status) {
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    exit(status);
}