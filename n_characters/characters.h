#pragma once

#include "SDL.h"

typedef struct character* CharacterPtr;

typedef struct acolyte* AcolytePtr;
typedef struct ancient* AncientPtr;
typedef struct astral* AstralPtr;
typedef struct fighter* FighterPtr;
typedef struct sorcerer* SorcererPtr;
typedef struct __point* Point;

typedef void (*Draw)(struct __point*, struct SDL_Surface);

CharacterPtr character_init(Draw draw);