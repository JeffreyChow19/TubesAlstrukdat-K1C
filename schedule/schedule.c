#include "../adt/queue/prioqueue.h"
#include "../data/data.h"
#include "schedule.h"

void tick()
{
  reduceAllTime(&(Delv(simulator)));
  while (isDurZero(DELIVERY(InfoHead(Delv(simulator)))))
  {
    Makanan accept;
    dequeue(&(Delv(simulator)), &accept);
  }
  // cek yang 0, kalo ada masukin notif
  // if (head(0)) enqueue, addLast(notifs, string)

  // sama, buat delivery
  reduceAllTime(&(Inv(simulator)));

  incTime(&(Clock(simulator)));
}

void tickWithTime(int h, int m)
{
  Time tickTime;
  CreateTime(&tickTime, 0, h, m);

  while (!isDurZero(tickTime))
  {
    tick();
    decDuration(&tickTime);
  }
}