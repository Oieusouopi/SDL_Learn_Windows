//
// Created by rafas on 11/06/2025.
//
#include <stdio.h>
#include <SDL.h>

#define TITLE "Primeira tela SDL feita por mim"
#define WIDTH 1000
#define HEIGHT 600

struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} typedef Game;

int sdl_initialize(Game *game);
void cleanup_game(Game *game, int status);

int main(void) {

    Game game = {
        .window = NULL,
        .renderer = NULL,
    };

    if (sdl_initialize(&game)) {
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

        SDL_RenderPresent(game.renderer);

        SDL_Delay(16);
    }


    cleanup_game(&game, EXIT_SUCCESS);

    return 0;
}

void cleanup_game(Game *game, int status) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
    exit(status);
}

int sdl_initialize(Game *game) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Erro ao iniciar o SDL: %s\n", SDL_GetError());
        return 1;
    }

    game->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    if (!game->window) {
        fprintf(stderr, "Erro ao iniciar a janela: %s\n", SDL_GetError());
        return 1;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, 0);

    if (!game->renderer) {
        fprintf(stderr, "Erro ao iniciar o renderizador: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}