#include "../adt/queue/prioqueue.h"
#include "../data/data.h"
#include "schedule.h"
#include <stdio.h>

void tick()
{
  reduceAllTime(&(Delv(simulator)));
  while (!isQueueEmpty(Delv(simulator)) && isDurZero(DELIVERY(InfoHead(Delv(simulator)))))
  {
    Makanan accept;
    dequeue(&(Delv(simulator)), &accept);
    enqueue(&(Inv(simulator)), accept);
    char text[27 + LENGTH(NAME(accept))];
    sprintf(text, "%s sudah diterima oleh BNMO!", SBUFFER(NAME(accept)));
    String notif;
    CreateEmptyString(&notif, 27 + LENGTH(NAME(accept)));
    setLiteral(&notif, text);
    insertLastString(&notifs, notif);
  }
  reduceAllTime(&(Proc(simulator)));
  while (!isQueueEmpty(Proc(simulator)) && isDurZero(DELIVERY(InfoHead(Proc(simulator)))))
  {
    Makanan accept;
    dequeue(&(Proc(simulator)), &accept);
    enqueue(&(Inv(simulator)), accept);
    char text[27 + LENGTH(NAME(accept))];
    sprintf(text, "%s sudah diterima oleh BNMO!", SBUFFER(NAME(accept)));
    String notif;
    CreateEmptyString(&notif, 27 + LENGTH(NAME(accept)));
    setLiteral(&notif, text);
    insertLastString(&notifs, notif);
  }
  reduceAllTime(&(Inv(simulator)));
  while (!isQueueEmpty(Inv(simulator)) && isDurZero(EXPIRY(InfoHead(Inv(simulator)))))
  {
    Makanan expire;
    dequeue(&(Inv(simulator)), &expire);
    char text[18 + LENGTH(NAME(expire))];
    sprintf(text, "%s kedaluwarsa.. :(", SBUFFER(NAME(expire)));
    String notif;
    CreateEmptyString(&notif, 18 + LENGTH(NAME(expire)));
    setLiteral(&notif, text);
    insertLastString(&notifs, notif);
  }
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