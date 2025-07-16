//
// Created by rafas on 16/07/2025.
//
#include "LTexture.h"
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

int LTexture_GetWidth(LTexture *lt) {
  return lt->width;
}

int LTexture_GetHeight(LTexture *lt) {
  return lt->height;
}
