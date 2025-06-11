#include <stdio.h>
#include <SDL.h>

#define TITLE "Primeira tela SDL"
#define WIDTH 800
#define HEIGHT 600

struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} typedef Game;

bool std_initialize(Game *game);
void clean_game(Game *game);

int main(void) {
    Game game = {
        .window = NULL,
        .renderer = NULL,
    };

    if (std_initialize(&game)) {
        clean_game(&game);
        exit(1);
    }

    SDL_RenderClear(game.renderer);
    SDL_RenderPresent(game.renderer);
    SDL_Delay(5000);

    return 0;
}

void clean_game(Game *game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

bool std_initialize(Game *game) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return true;
    }

    game->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    if (!game->window) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return true;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, 0);

    if (!game->renderer) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return true;
    }

    return false;
}