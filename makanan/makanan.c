#include "makanan.h"
#include <stdio.h>

void CreateMakanan(Makanan *m, int id, String name, String action)
{
  ID(*m) = id;
  NAME(*m) = name;
  ACTION(*m) = action;
}