//
// Created by rafas on 11/06/2025.
//
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#define TITLE "Aula 3 - Background"
#define WIDTH 1000
#define HEIGHT 600
#define IMAGE_FLAGS IMG_INIT_JPG

struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
} typedef Game;

bool sdl_initialize(Game *game);
bool load_media(Game *game);
void cleanup_game(Game *game, int status);

int main(void) {

    Game game = {
        .window = NULL,
        .renderer = NULL,
        .texture = NULL,
    };

    if (sdl_initialize(&game)) {
        cleanup_game(&game, EXIT_FAILURE);
    }

    if (load_media(&game)) {
        cleanup_game(&game, EXIT_FAILURE);
    }

    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT: {
                    cleanup_game(&game, EXIT_SUCCESS);
                }
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE: {
                            cleanup_game(&game, EXIT_SUCCESS);
                        }
                    }
                }
                default:
                    break;
            }
        }
        SDL_RenderClear(game.renderer);

        SDL_RenderCopy(game.renderer, game.texture, NULL, NULL);

        SDL_RenderPresent(game.renderer);

        SDL_Delay(16);
    }


    cleanup_game(&game, EXIT_SUCCESS);

    return 0;
}

void cleanup_game(Game *game, int status) {
    SDL_DestroyTexture(game->texture);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    IMG_Quit();
    SDL_Quit();
    exit(status);
}

bool sdl_initialize(Game *game) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Erro ao iniciar o SDL: %s\n", SDL_GetError());
        return true;
    }

    game->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    if (!game->window) {
        fprintf(stderr, "Erro ao iniciar a janela: %s\n", SDL_GetError());
        return true;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, 0);

    if (!game->renderer) {
        fprintf(stderr, "Erro ao iniciar o renderizador: %s\n", SDL_GetError());
        return true;
    }

    const int init = IMG_Init(IMAGE_FLAGS);
    if ((init & IMAGE_FLAGS) != IMAGE_FLAGS) {
        fprintf(stderr, "Erro ao iniciar o renderizador: %s\n", IMG_GetError());
        return true;
    }

    return false;
}

bool load_media(Game *game) {
    game->texture = IMG_LoadTexture(game->renderer, "../images/background.jpg");

    if (!game->texture) {
        fprintf(stderr, "Erro ao iniciar a textura: %s\n", IMG_GetError());
        return true;
    }

    return false;
}