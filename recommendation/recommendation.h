#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "../adt/boolean.h"
#include "../adt/simulator/simulator.h"
#include "../adt/multiset/multiset.h"

void showRecommendation();

boolean canBeMade(MultiSet inv, int id);

void addAllToSet(Sim s, MultiSet *set);

MultiSet getFoodBahan(int id);

#endif