//
// Created by rafas on 05/08/2025.
//

#include <SDL.h>
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 300

bool init();
bool loadMedia();
void close(int status);

SDL_Window *window;

SDL_Renderer *renderer;

int main() {

    if (!init()) {
        close(EXIT_FAILURE);
    }

    SDL_Event event;

    while ( true ) {

        while (SDL_PollEvent(&event) != 0) {

            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }

        }

    }

}

bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("15-mouse-events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro ao criar a janela: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderizador: %s", SDL_GetError());
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