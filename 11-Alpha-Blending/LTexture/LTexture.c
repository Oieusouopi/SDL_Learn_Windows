//
// Created by rafas on 23/07/2025.
//
#include "LTexture.h"

#include <SDL_image.h>
#include <stdio.h>

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

bool LTexture_LoadFromFile(LTexture *lt, SDL_Renderer *renderer, const char path[]) {
   SDL_Texture *newTexture = NULL;

   SDL_Surface *surface = IMG_Load(path);
   if (surface == NULL) {
      printf("Erro ao carregar surface: %s\n", IMG_GetError());
      return false;
   }

   newTexture = SDL_CreateTextureFromSurface(renderer, surface);
   if (newTexture == NULL) {
      printf("Erro ao criar textura\n");
      return false;
   }

   lt->width = surface->w;
   lt->height = surface->h;

   SDL_FreeSurface(surface);

   lt->texture = newTexture;

   return true;
}

void LTexture_Renderer(LTexture *lt, SDL_Renderer *renderer, SDL_Rect *clip, int x, int y) {
   SDL_Rect renderQuad = {x, y, lt->width, lt->height};

   if (clip != NULL) {
      renderQuad.w = clip->w;
      renderQuad.h = clip->h;
   }

   SDL_RenderCopy(renderer, lt->texture, clip, &renderQuad);
}

void LTexture_SetColor(LTexture *lt, Uint8 r, Uint8 g, Uint8 b) {
   SDL_SetTextureColorMod(lt->texture, r, g,b);
}

void LTexture_SetBlendMode(LTexture *lt, SDL_BlendMode blending) {
   SDL_SetTextureBlendMode(lt->texture, blending);
}

void LTexture_SetAlpha(LTexture *lt, Uint8 alpha) {
   SDL_SetTextureAlphaMod(lt->texture, alpha);
}
