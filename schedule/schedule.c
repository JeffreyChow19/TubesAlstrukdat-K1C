#include "../adt/queue/prioqueue.h"
#include "../data/data.h"
#include "schedule.h"
#include <stdio.h>

void tick()
{
  reduceAllTime(&(Delv(simulator)));
  while (isDurZero(DELIVERY(InfoHead(Delv(simulator)))))
  {
    Makanan accept;
    dequeue(&(Delv(simulator)), &accept);
    char text[100];
    sprintf(text, "%s sudah diterima oleh BNMO!", SBUFFER(NAME(accept)));
    String notif;
    setLiteral(&notif, text);
    insertLastString(&notifs, notif);
  }

  reduceAllTime(&(Inv(simulator)));
  while (isDurZero(EXPIRY(InfoHead(Inv(simulator)))))
  {
    Makanan expire;
    dequeue(&(Inv(simulator)), &expire);
    char text[100];
    sprintf(text, "%s kedaluwarsa.. :(", SBUFFER(NAME(expire)));
    String notif;
    setLiteral(&notif, text);
    insertLastString(&notifs, notif);
  }

  reduceAllTime(&(Proc(simulator)));

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