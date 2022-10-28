#ifndef COMMAND_H
#define COMMAND_H
#include "../adt/stack/stack.h"

void undo(Sim *sim, Stack *S1, Stack *S2);

void redo(Sim *sim, Stack *S1, Stack *S2);

#endif