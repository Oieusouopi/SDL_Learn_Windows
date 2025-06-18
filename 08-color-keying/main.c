//
// Created by rafas on 17/06/2025.
//
#include <SDL.h>
#include <stdio.h>
#include "./headers/LTexture.h"

#define WIDTH 800
#define HEIGHT 600

SDL_Window *gWindow = NULL;

SDL_Renderer *gRenderer = NULL;

LTexture gFooTexture;
LTexture backTexture;

// Inicializador SDL
bool init();

// Fechar SDL
void closeSDL(int status);

int main() {

    if (init()) {
        fprintf(stderr, "Deu algo errado\n");
        closeSDL(EXIT_FAILURE);
    }

    while (true) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                closeSDL(EXIT_SUCCESS);
            }
        }

        LTexture_Init(&gFooTexture);
    }

}
bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Erro ao iniciar o SDL: %s\n", SDL_GetError());
        return true;
    }

    gWindow = SDL_CreateWindow("08 Color Keying", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        fprintf(stderr, "Erro ao iniciar a janela SDL: %s\n", SDL_GetError());
        return true;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        fprintf(stderr, "Erro ao iniciar o renderizador SDL: %s\n", SDL_GetError());
        return true;
    }

    return false;
}

void closeSDL(int status) {

    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    gWindow = NULL;

    exit(status);
}