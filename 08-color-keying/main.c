//
// Created by rafas on 17/06/2025.
//
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "./headers/LTexture.h"

#define WIDTH 800
#define HEIGHT 600

SDL_Window *gWindow = NULL;

SDL_Renderer *gRenderer = NULL;

LTexture *gFooTexture;
LTexture *backTexture;

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

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        LTexture_Render(backTexture, gRenderer, 0, 0 );

        LTexture_Render(gFooTexture, gRenderer, 0, 190);

        SDL_RenderPresent(gRenderer);
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

    gFooTexture = malloc(sizeof(LTexture));;
    LTexture_Init(gFooTexture);
    if (LTexture_loadFromFile(gFooTexture, gRenderer, "../Images/foo.png")) {
        printf("Falha ao carregar imagem de textura!\n");
        return true;
    }

    backTexture = malloc(sizeof(LTexture));;
    LTexture_Init(backTexture);
    if (LTexture_loadFromFile(backTexture, gRenderer, "../Images/back.png")) {
        printf("Falha ao carregar a imagem de fundo!\n");
        return true;
    }

    return false;
}

void closeSDL(int status) {

    LTexture_Free(gFooTexture);
    LTexture_Free(backTexture);

    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();

    exit(status);
}