//
// Created by rafas on 05/08/2025.
//

#include "LTexture.h"

#include <SDL_image.h>
#include <stdio.h>

void LTexture_Init(LTexture* lt) {
    lt->texture = NULL;
    lt->width = 0;
    lt->height = 0;
}

void LTexture_Free(LTexture* lt) {
    if (lt->texture != NULL) {
        SDL_DestroyTexture(lt->texture);
        lt->texture = NULL;
        lt->width = 0;
        lt->height = 0;
    }
}

bool LTexture_LoadFromFile(LTexture* lt, SDL_Renderer* renderer, const char path[]) {
    SDL_Texture* newTexture;

    SDL_Surface* surface = IMG_Load(path);
    if (surface == NULL) {
        printf("Superficie não renderizada %s\n", IMG_GetError());
        return false;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (newTexture == NULL) {
        printf("Não foi possivel criar a textura %s\n", SDL_GetError());
        return false;
    }

    lt->width = surface->w;
    lt->height = surface->h;

    SDL_FreeSurface(surface);

    lt->texture = newTexture;

    return true;

}