//
// Created by rafas on 17/06/2025.
//

#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>
#include <stdbool.h>

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} LTexture;


void LTexture_Init(LTexture *lt);
void LTexture_Free(LTexture *lt);

int LTexture_GetWidth(LTexture *lt);
int LTexture_GetHeight(LTexture *lt);

bool LTexture_loadFromFile(LTexture* lt, SDL_Renderer* renderer, const char* path);
void LTexture_Render(LTexture *lt, SDL_Renderer* renderer, int x, int y);

#endif //LTEXTURE_H
