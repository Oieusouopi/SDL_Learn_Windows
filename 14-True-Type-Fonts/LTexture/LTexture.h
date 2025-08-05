//
// Created by rafas on 30/07/2025.
//

#include <SDL.h>
#include <SDL_ttf.h>

#ifndef LTEXTURE_H
#define LTEXTURE_H

typedef struct {
    SDL_Texture *texture;
    int width;
    int height;
} LTexture;

void LTexture_init(LTexture *lt);
void LTexture_Free(LTexture *lt);

bool LTexture_LoadFromFile(LTexture *lt, SDL_Renderer *renderer, const char path[]);
bool LTexture_LoadFromRenderedText(LTexture* lt, SDL_Renderer* renderer, TTF_Font* font, const char text[], SDL_Color textColor);
void LTexture_Renderer(LTexture *lt, SDL_Renderer *renderer, SDL_Rect* clip, int x, int y, double angle, SDL_Point* center, SDL_RendererFlip flip);

void LTexture_SetColor(LTexture *lt, Uint8 r, Uint8 g, Uint8 b);

void LTexture_SetBlendMode(LTexture *lt, SDL_BlendMode blending);
void LTexture_SetAlpha(LTexture *lt, Uint8 alpha);

#endif //LTEXTURE_H
