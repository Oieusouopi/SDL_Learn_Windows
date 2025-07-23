#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "LTexture/LTexture.h"
//
// Created by rafas on 23/07/2025.
//
#define HEIGHT 500
#define WIDTH 400

bool init();
bool loadMedia();
void close(int status);

SDL_Texture *generateTexture(char path[]);

SDL_Window *window;

SDL_Renderer *renderer;

LTexture *texture;

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

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture->texture, NULL, NULL);

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


    return true;
}

void close(int status) {
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

    if (!LTexture_LoadFromFile(texture,renderer, "../Images/jpg/background_1.jpg")) {
        return false;
    }

    return true;
}

SDL_Texture *generateTexture(char path[]) {

}