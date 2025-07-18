//
// Created by rafas on 18/07/2025.
//


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#define HEIGHT 200
#define WIDTH 200

SDL_Window *window;

SDL_Renderer *renderer;

SDL_Texture *texture;

bool init();
void close(int status);
bool loadMedia();

SDL_Texture *generateTexture(char path[]);

int main() {

    if (!init()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    if (!loadMedia()) {
        printf("Aconteceu algum erro");
        close(EXIT_FAILURE);
    }

    while ( true ) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                close(EXIT_SUCCESS);
            }
        }

        // Render texture to screen
        SDL_RenderCopy(renderer, texture, NULL, NULL);

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

    return true;
}

void close(int status) {
    SDL_DestroyTexture(texture);
    texture = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    exit(status);
}

bool loadMedia() {

    texture = generateTexture("../Images/full.png");
    if (texture == NULL) {
        printf("Erro ao gerar a textura: %s\n", IMG_GetError());
        return false;
    }

    return true;
}


SDL_Texture* generateTexture(char path[]) {
    SDL_Texture *newTexture = NULL;

    SDL_Surface *loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        fprintf(stderr, "Erro ao carregar a imagem: %s\n", IMG_GetError());
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
        fprintf(stderr, "Erro ao carregar a textura: %s\n", IMG_GetError());
    }

    SDL_FreeSurface(loadedSurface);

    return newTexture;
}