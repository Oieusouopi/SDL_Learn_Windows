//
// Created by rafas on 28/07/2025.
//

#include <stdio.h>
#include "SDL.h"
#include "LTexture/LTexture.h"

#define WIDTH 500
#define HEIGHT 500

bool init();
void close(int status);

bool loadMedia();

SDL_Window *window;

SDL_Renderer *renderer;

LTexture *texture;

int main() {

    if (!init()) {
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
        close(EXIT_FAILURE);
    }

    double degrees = 0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    SDL_Event ev;
    while (true) {
        while (SDL_PollEvent(&ev) != 0) {

            if (ev.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            } else if (ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym) {
                    case SDLK_a:
                        degrees -= 60;
                        break;
                    case SDLK_d:
                        degrees += 60;
                        break;
                    case SDLK_q:
                        flipType = SDL_FLIP_HORIZONTAL;
                        break;
                    case SDLK_w:
                        flipType = SDL_FLIP_NONE;
                        break;
                    case SDLK_e:
                        flipType = SDL_FLIP_VERTICAL;
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        LTexture_Renderer(texture, renderer, NULL, (WIDTH - texture->width) / 2, (HEIGHT - texture->height) / 2, degrees, NULL, flipType);
        SDL_RenderPresent(renderer);

    }

}


bool init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("13-rotation-and-flipping", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Deu algum erro ao criar janela: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
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

    if (!LTexture_LoadFromFile(texture, renderer, "../Images/seta.png")) {
        printf("Erro ao carregar o arquivo: %s\n", SDL_GetError());
        return false;
    }

    return true;
}