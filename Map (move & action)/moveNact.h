#include "../adt/simulator/simulator.h"
#include "../adt/matriks/matriks.h"

boolean isBlocked (Sim S, char dir, Matrix M);

boolean isOutOfBound(Sim S, char dir, Matrix M);

void setPos(Sim *S, char dir, Matrix M);

void action(Sim S, char act, Matrix M);