//
// Created by rafas on 18/07/2025.
//


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "./LTexture/LTexture.h"
#define HEIGHT 480
#define WIDTH 640

SDL_Window *window;

SDL_Renderer *renderer;

LTexture *texture;

bool init();
void close(int status);
bool loadMedia();

int main() {

    if (!init()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;
    while ( true ) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_q:
                        r += 32;
                        break;
                    case SDLK_w:
                        g += 32;
                        break;
                    case SDLK_e:
                        b += 32;
                        break;
                    case SDLK_a:
                        r -= 32;
                        break;
                    case SDLK_s:
                        g -+ 32;
                        break;
                    case SDLK_d:
                        b -= 32;
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        LTexture_setColor(texture, r, g, b);
        LTexture_Renderer(texture, renderer, NULL, 0, 0);

        SDL_RenderPresent(renderer);
    }
}

bool init() {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("10-Color-Modulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro ao criar a janela: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        return false;
    }

    texture = malloc(sizeof(LTexture));
    LTexture_Init(texture);

    return true;
}

void close(int status) {
    LTexture_Free(texture);

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    exit(status);
}

bool loadMedia() {

    if (!LTexture_LoadFromFile(texture, renderer, "../Images/full.png")) {
        printf("Erro ao gerar a textura: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

