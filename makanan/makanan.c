#include "makanan.h"
#include <stdio.h>

void CreateMakanan(Makanan *m, int id, String name, Time expiry, String action)
{
  ID(*m) = id;
  NAME(*m) = name;
  EXPIRY(*m) = expiry;
  ACTION(*m) = action;
}