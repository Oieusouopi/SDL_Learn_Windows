//
// Created by rafas on 18/07/2025.
//
#include "LTexture.h"

#include <SDL_image.h>
#include <stdio.h>

#include "SDL.h"

void LTexture_Init(LTexture *lt) {
    lt->texture = NULL;
    lt->width = 0;
    lt->height = 0;
}

void LTexture_Free(LTexture *lt) {
    if (lt->texture) {
        SDL_DestroyTexture(lt->texture);
        lt->width = 0;
        lt->height = 0;
        lt->texture = NULL;
    }
}

void LTexture_Renderer(LTexture *lt, SDL_Renderer *renderer, SDL_Rect *clip, int x, int y) {
    SDL_Rect renderQuad = {x, y, lt->width, lt->height};

    if (clip != NULL) {
        renderQuad.h = clip->h;
        renderQuad.w = clip->w;
    }

    SDL_RenderCopy(renderer, lt->texture, clip, &renderQuad);
}

bool LTexture_LoadFromFile(LTexture *lt, SDL_Renderer *renderer, char path[]) {
    LTexture_Free(lt);

    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
        return false;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer ,loadedSurface);
    if (newTexture == NULL) {
        printf("Não foi possivel criar a textura de %s! Erro SDL: %s\n", path, SDL_GetError());
        return false;
    }

    lt->width = loadedSurface->w;
    lt->height = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);

    lt->texture = newTexture;

    return true;
}

