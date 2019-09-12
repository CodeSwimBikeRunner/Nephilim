#include "../characters.h"

typedef void (*Draw)();
typedef void (*Update)();
struct Sorcerer {
    Draw draw;
};

SorcererPtr character_init()