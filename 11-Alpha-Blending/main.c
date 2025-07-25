#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "LTexture/LTexture.h"
//
// Created by rafas on 23/07/2025.
//
#define HEIGHT 500
#define WIDTH 700

bool init();
bool loadMedia();
void close(int status);

SDL_Window *window;

SDL_Renderer *renderer;

LTexture *texture;

LTexture *backTexture;

int main() {

    if (!init()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
        printf("Aconteceu algum erro ao carregar as midias");
        close(EXIT_FAILURE);
    }

    while (true) {
        SDL_Event event;
        Uint8 alpha;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_q) {
                    if (alpha + 32 > 255) {
                        alpha = 255;
                    } else {
                        alpha += 32;
                    }
                } else if (event.key.keysym.sym == SDLK_s) {
                    if (alpha - 32 < 0) {
                        alpha = 0;
                    } else {
                        alpha -= 32;
                    }
                }

            }
        }

        SDL_RenderClear(renderer);
        LTexture_SetAlpha(texture, alpha);
        LTexture_Renderer(backTexture, renderer, NULL, 0,0);
        LTexture_Renderer(texture, renderer, NULL, 0, 0);

        SDL_RenderPresent(renderer);
    }
}

bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("11-ALPLHA-BLEDING",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Aconteceu um erro ao criar a janela: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Aconteceu um erro ao criar o renderizador: %s\n", SDL_GetError());
        return false;
    }

    texture = malloc(sizeof(LTexture));
    LTexture_Init(texture);

    backTexture = malloc(sizeof(LTexture));
    LTexture_Init(backTexture);

    return true;
}

void close(int status) {
    LTexture_Free(backTexture);
    backTexture = NULL;

    LTexture_Free(texture);
    texture = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    exit(status);
}

bool loadMedia() {

    if (!LTexture_LoadFromFile(texture,renderer, "../Images/alpha100.png")) {
        return false;
    } else {
        LTexture_SetBlendMode(texture,SDL_BLENDMODE_BLEND);
    }

    if (!LTexture_LoadFromFile(backTexture, renderer, "../Images/background.png")) {
        return false;
    }

    return true;
}