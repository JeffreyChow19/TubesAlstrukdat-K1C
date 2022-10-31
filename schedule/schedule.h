#ifndef SCHEDULE_H
#define SCHEDULE_H

/* Menambah satu menit waktu berjalannya simulator; */
/* Mengurangi satu menit waktu expiry, pengolahan, dan delivery makanan; */
void tick();

/* Menambah waktu berjalannya simulator sebanyak h jam dan m menit; */
/* Mengurangi waktu expiry, pengolahan, dan delivery makanan sebanyak h jam dan m menit; */
void tickWithTime(int h, int m);

#endif