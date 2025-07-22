//
// Created by rafas on 18/07/2025.
//

#include "SDL.h"

#ifndef LTEXTURE_H
#define LTEXTURE_H

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} LTexture;

void LTexture_Init(LTexture *lt);
void LTexture_Free(LTexture *lt);
void LTexture_setColor(LTexture *lt, Uint8 red, Uint8 green, Uint8 blue);

void LTexture_Renderer(LTexture *lt, SDL_Renderer *renderer, SDL_Rect *rect, int x, int y);
bool LTexture_LoadFromFile(LTexture *lt, SDL_Renderer *renderer,  char path[]);

#endif //LTEXTURE_H
