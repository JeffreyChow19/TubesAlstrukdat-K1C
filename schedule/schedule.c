#include "../adt/queue/prioqueue.h"
#include "../data/data.h"
#include "schedule.h"

void tick()
{
  reduceAllTime(&(Delv(simulator)));
  // cek yang 0, kalo ada masukin notif
  // if (head(0)) enqueue, addLast(notifs, string)

  // sama, buat delivery
  reduceAllTime(&(Inv(simulator)));
}

void tickWithTime(int h, int m);