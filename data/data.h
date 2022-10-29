#include "../adt/matriks/matriks.h"
#include "../adt/liststatik/liststatik.h"
#include "../adt/listdin/listdin.h"
#include "../adt/simulator/simulator.h"
#include <stdio.h>

extern Matrix map;
extern ListStatik foods;
extern ListDin recipesTrees;
extern ListDin recipes;
extern Sim simulator;

void initData(char *mapFile, char *foodsFile, char *recipesFile);

void readMapConfig(char *filename);

void readFoodsConfig(char *filename);

void readRecipesConfig(char *filename);

void initSimulator();