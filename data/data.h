#include "../matriks/matriks.h"
#include "../liststatik/liststatik.h"
#include "../listdin/listdin.h"
#include <stdio.h>

extern Matrix map;
extern ListStatik foods;
extern ListDin recipes;

void initData(char *mapFile, char *foodsFile, char *recipesFile);

void readMapConfig(char *filename);

void readFoodsConfig(char *filename);

void readRecipesConfig(char *filename);