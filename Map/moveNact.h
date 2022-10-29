#include "../adt/simulator/simulator.h"
#include "../adt/matriks/matriks.h"

#ifndef MOVENACT_H
#define MOVENACT_H

boolean isBlocked (Sim S, char dir, Matrix M);

boolean isOutOfBound(Sim S, char dir, Matrix M);

void setPos(Sim *S, char dir, Matrix M);

#endif