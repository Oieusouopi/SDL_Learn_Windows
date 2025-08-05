//
// Created by rafas on 05/08/2025.
//

#include <SDL.h>

#ifndef LTEXTURE_H
#define LTEXTURE_H

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} LTexture;

void LTexture_Init(LTexture* lt);
void LTexture_Free(LTexture* lt);

bool LTexture_LoadFromFile(LTexture* lt, const char path[]);

#endif //LTEXTURE_H
