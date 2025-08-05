//
// Created by rafas on 05/08/2025.
//

#include "LTexture.h"

void LTexture_Init(LTexture *lt) {
    lt->texture = NULL;
    lt->width = 0;
    lt->height = 0;
}

void LTexture_Free(LTexture *lt) {
    if (lt->texture != NULL) {
        SDL_DestroyTexture(lt->texture);
        lt->texture = NULL;
        lt->width = 0;
        lt->height = 0;
    }
}

