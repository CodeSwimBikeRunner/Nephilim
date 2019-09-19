#pragma once

typedef struct Character* CharacterPtr;
typedef struct Acolyte* AcolytePtr;
typedef struct Ancient* AncientPtr;
typedef struct Astral* AstralPtr;
typedef struct Fighter* FighterPtr;
typedef struct Sorcerer* SorcererPtr;

typedef void (*Draw)();
typedef void (*LevelUp)();
typedef void (*Gear)();
typedef void (*Skills)();
CharacterPtr character_init(Draw draw, LevelUp level_up, Gear gear);