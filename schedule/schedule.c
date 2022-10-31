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

    int length = LENGTH(NAME(accept));
    dequeue(&(Delv(simulator)), &accept);
    enqueue(&(Inv(simulator)), accept);
    char text[27 + length];
    sprintf(text, "%s sudah diterima oleh BNMO!", SBUFFER(NAME(accept)));
    String notif;
    CreateEmptyString(&notif, 27 + length);
    setLiteral(&notif, text);
    addNotif(&simulator, notif, false);

    char undoText[25 + length];
    sprintf(undoText, "%s dihapus dari inventory.", SBUFFER(NAME(accept)));
    String undoNotif;
    CreateEmptyString(&undoNotif, 25 + length);
    setLiteral(&undoNotif, undoText);
    addNotif(&simulator, undoNotif, true);
  }
  reduceAllTime(&(Proc(simulator)));
  while (!isQueueEmpty(Proc(simulator)) && isDurZero(DELIVERY(InfoHead(Proc(simulator)))))
  {
    Makanan accept;
    int length = LENGTH(NAME(accept));

    dequeue(&(Proc(simulator)), &accept);
    enqueue(&(Inv(simulator)), accept);
    char text[46 + length];
    sprintf(text, "%s selesai dibuat dan sudah masuk ke inventory!", SBUFFER(NAME(accept)));
    String notif;
    CreateEmptyString(&notif, 46 + length);
    setLiteral(&notif, text);
    addNotif(&simulator, notif, false);

    char undoText[29 + length];
    sprintf(undoText, "%s kembali ke fase pengolahan.", SBUFFER(NAME(accept)));
    String undoNotif;
    CreateEmptyString(&undoNotif, 29 + length);
    setLiteral(&undoNotif, undoText);
    addNotif(&simulator, undoNotif, true);
  }
  reduceAllTime(&(Inv(simulator)));
  while (!isQueueEmpty(Inv(simulator)) && isDurZero(EXPIRY(InfoHead(Inv(simulator)))))
  {
    Makanan expire;
    int length = LENGTH(NAME(expire));

    dequeue(&(Inv(simulator)), &expire);
    char text[18 + length];
    sprintf(text, "%s kedaluwarsa.. :(", SBUFFER(NAME(expire)));
    String notif;
    CreateEmptyString(&notif, 18 + length);
    setLiteral(&notif, text);
    addNotif(&simulator, notif, false);

    char undoText[21 + length];
    sprintf(undoText, "%s batal kedaluarsa :)", SBUFFER(NAME(expire)));
    String undoNotif;
    CreateEmptyString(&undoNotif, 21 + length);
    setLiteral(&undoNotif, undoText);
    addNotif(&simulator, undoNotif, true);
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