#pragma once

typedef struct character* CharacterPtr;

typedef struct acolyte* AcolytePtr;
typedef struct ancient* AncientPtr;
typedef struct astral* AstralPtr;
typedef struct fighter* FighterPtr;
typedef struct sorcerer* SorcererPtr;

/*
    ? How do we handle observable handlers and separation of concerns?
    */
typedef void (*Draw)(struct __point*, struct SDL_Surface);

CharacterPtr character_init(Draw draw);