//
// Created by rafas on 16/07/2025.
//

#include <SDL.h>

#ifndef LTEXTURE_H
#define LTEXTURE_H

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} LTexture;

void LTexture_Init(LTexture *lt);
void LTexture_Free(LTexture *lt);

int LTexture_GetWidth(LTexture *lt);
int LTexture_GetHeight(LTexture *lt);

bool LTexture_LoadFromFile(LTexture *lt, SDL_Renderer *renderer, const char* path);
void LTexture_Renderer(LTexture *lt, SDL_Renderer *renderer, SDL_Rect *clip, int x, int y);

#endif //LTEXTURE_H
