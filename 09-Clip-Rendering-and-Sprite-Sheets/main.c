//
// Created by rafas on 13/07/2025.
//

#include <SDL.h>
#include <SDL_video.h>
#include <stdio.h>
#include "LTexture/LTexture.h"

#define WIDTH 500
#define HEIGHT 300

bool init();
void close(int status);
bool loadMedia();

SDL_Window *window = NULL;

SDL_Renderer *renderer = NULL;

SDL_Rect gSpriteClips[ 4 ];
SDL_Texture *gSpriteSheetTexture;

LTexture *gTexture;

int main() {

    if (!init()) {
        printf("Aconteceu algum erro\n");
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
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

    gTexture = malloc(sizeof(LTexture));
    LTexture_Init(gTexture);

    return true;
}

void close(int status) {

    LTexture_Free(gTexture);

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_Quit();

    exit(status);
}

bool loadMedia() {

    if (!LTexture_LoadFromFile(gTexture, renderer, "../Images/sprites.png")) {
        printf("Falha ao carregar imagem de textura!\n");
        return true;
    }

    gSpriteClips[ 0 ].x = 0;
    gSpriteClips[ 0 ].y = 0;
    gSpriteClips[ 0 ].w = 100;
    gSpriteClips[ 0 ].h = 100;

    gSpriteClips[ 1 ].x = 100;
    gSpriteClips[ 1 ].y = 0;
    gSpriteClips[ 1 ].w = 100;
    gSpriteClips[ 1 ].h = 100;

    gSpriteClips[ 2 ].x = 0;
    gSpriteClips[ 2 ].y = 100;
    gSpriteClips[ 2 ].w = 100;
    gSpriteClips[ 2 ].h = 100;

    gSpriteClips[ 0 ].x = 100;
    gSpriteClips[ 0 ].y = 100;
    gSpriteClips[ 0 ].w = 100;
    gSpriteClips[ 0 ].h = 100;

    return false;
}