#ifndef COMMAND_H
#define COMMAND_H
#include "../adt/simulator/simulator.h"

void move(char dir);

boolean startCommand();

void enterToContinue();

void addToStack(boolean clearRedo);

void cancelAddToStack();

void processFoodCommand(String command, char action, char *name);

#endif
