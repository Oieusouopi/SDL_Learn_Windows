//
// Created by rafas on 17/06/2025.
//
#include "headers/LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

void LTexture_Init(LTexture* lt) {
    lt->height = 0;
    lt->width = 0;
    lt->texture = NULL;
}

void LTexture_Free(LTexture* lt) {
    if (lt->texture) {
        SDL_DestroyTexture(lt);
        lt->width = 0;
        lt->height = 0;
        lt->texture = NULL;
    }
}

int LTexture_GetWidth(LTexture* lt) {
    return lt->width;
}

int LTexture_GetHeight(LTexture* lt) {
    return lt->height;
}

bool LTexture_loadFromFile(LTexture* lt, SDL_Renderer* renderer, const char* path) {

    LTexture_Free(lt);

    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        fprintf(stderr, "Erro ao carregar a imagem: %s\n", IMG_GetError());
        return true;
    }

    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
        printf("Não foi possivel criar a textura de %s! Erro SDL: %s\n", path, SDL_GetError());
        return true;
    }

    lt->width = loadedSurface->w;
    lt->height = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);

    lt->texture = newTexture;

    return false;
}