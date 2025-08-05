//
// Created by rafas on 30/07/2025.
//

#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

void LTexture_Init(LTexture* lt) {
    lt->texture = NULL;
    lt->height = 0;
    lt->width = 0;
}

void LTexture_Free(LTexture* lt) {
    if (lt->texture != NULL) {
        SDL_DestroyTexture(lt->texture);
        lt->texture = NULL;
        lt->height = 0;
        lt->width = 0;
    }
}

bool LTexture_LoadFromFile(LTexture* lt, SDL_Renderer* renderer, const char path[]) {
    SDL_Texture* newTexture = NULL;

    SDL_Surface* surface = IMG_Load(path);
    if (surface == NULL) {
        return false;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, surface);

    lt->texture = newTexture;
    lt->height = surface->h;
    lt->width = surface->w;

    SDL_FreeSurface(surface);

    return true;
}

bool LTexture_LoadFromRenderedText(LTexture* lt, SDL_Renderer* renderer, TTF_Font* font, const char text[], SDL_Color textColor) {
    SDL_Texture* newTexture = NULL;

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, textColor);

    if (surface == NULL) {
        return false;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (newTexture == NULL) {
        return false;
    }

    lt->texture = newTexture;
    lt->height = surface->h;
    lt->width = surface->w;

    SDL_FreeSurface(surface);

    return true;
}

void LTexture_Renderer(LTexture* lt, SDL_Renderer* renderer, SDL_Rect* clip, int x, int y, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = { x, y, lt->width, lt->height };

    if (clip != NULL) {
        renderQuad.h = clip->h;
        renderQuad.w = clip->w;
    }

    SDL_RenderCopyEx(renderer, lt->texture, clip, &renderQuad, angle, center, flip );
}

void LTexture_SetColor(LTexture* lt, Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetTextureColorMod(lt->texture, r, g, b);
}

void LTexture_SetBlendMode(LTexture* lt, SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(lt->texture, blending);
}

void LTexture_SetAlpha(LTexture* lt, Uint8 alpha) {
    SDL_SetTextureAlphaMod(lt->texture, alpha);
}