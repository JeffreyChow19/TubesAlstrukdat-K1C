#ifndef UNDOREDO_H
#define UNDOREDO_H
#include "../adt/stack/stack.h"

void undo(Sim *sim, Stack *utama, Stack *penampung);

void redo(Sim *sim, Stack *utama, Stack *penampung);

#endif