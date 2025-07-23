#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
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

SDL_Texture *texture;

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
        SDL_RenderCopy(renderer, texture , NULL, NULL);

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

bool loadMedia() {

    texture = generateTexture("../Images/jpg/background_1.jpg");
    if (texture == NULL) {
        printf("Erro ao iniciar a textura: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

SDL_Texture *generateTexture(char path[]) {
    SDL_Texture *newTexture = NULL;
    SDL_Surface *surface = IMG_Load(path);
    if (surface == NULL) {
        printf("Erro ao carregar surface: %s\n", IMG_GetError());
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (newTexture == NULL) {
        printf("Erro ao criar textura\n");
    }

    SDL_FreeSurface(surface);

    return newTexture;
}