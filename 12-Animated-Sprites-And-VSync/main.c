#include <SDL.h>
#include <stdio.h>
#include "LTexture/LTexture.h"
//
// Created by rafas on 24/07/2025.
//

#define WIDTH 64
#define HEIGHT 205

SDL_Window *window;

SDL_Renderer *renderer;

LTexture *texture;

const int QUADRO_PASSOS = 4;

SDL_Rect gSprites[ 4 ];

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

    int quadros = 0;
    while (true) {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }

        SDL_Rect* currentClip = &gSprites[ quadros / 4 ];
        LTexture_Renderer(texture, renderer, currentClip, (WIDTH - currentClip->w) / 2,(HEIGHT - currentClip->h) / 2);

        SDL_RenderPresent(renderer);

        ++quadros;

        if (quadros / 6 >= QUADRO_PASSOS ) {
            quadros = 0;
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Erro ao iniciar renderizador: %s\n", SDL_GetError());
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

    exit(status);
}

bool loadMedia() {

    if (!LTexture_LoadFromFile(texture, renderer, "../Images/foo.png")) {
        printf("Erro ao carregar o arquivo: %s\n", SDL_GetError());
        return false;
    } else {
        gSprites[ 0 ].x = 0;
        gSprites[ 0 ].y = 0;
        gSprites[ 0 ].w = 64;
        gSprites[ 0 ].h = 205;

        gSprites[ 1 ].x = 64;
        gSprites[ 1 ].y = 0;
        gSprites[ 1 ].w = 64;
        gSprites[ 1 ].h = 205;

        gSprites[ 2 ].x = 128;
        gSprites[ 2 ].y = 0;
        gSprites[ 2 ].w = 64;
        gSprites[ 2 ].h = 205;

        gSprites[ 3 ].x = 192;
        gSprites[ 3 ].y = 0;
        gSprites[ 3 ].w = 64;
        gSprites[ 3 ].h = 205;
    }

    return true;
}