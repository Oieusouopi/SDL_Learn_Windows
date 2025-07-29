//
// Created by rafas on 28/07/2025.
//
#include "SDL.h"

#ifndef LTEXTURE_H
#define LTEXTURE_H

typedef struct {
    SDL_Texture* texture;
    int width;
    int height;
} LTexture;

void LTexture_Init(LTexture* lt);
void LTexture_Free(LTexture* lt);

void LTexture_Renderer(LTexture* lt, SDL_Renderer* renderer, SDL_Rect* clip, int x, int y);
bool LTexture_LoadFromFile(LTexture* lt, SDL_Renderer* renderer, const char path[]);

void LTexture_SetColor(LTexture* lt, Uint8 r, Uint8 g, Uint8 b);

void LTexture_SetBlendMode(LTexture* lt, SDL_BlendMode blending);
void LTexture_SetAlpha(LTexture* lt, Uint8 alpha);

#endif //LTEXTURE_H
