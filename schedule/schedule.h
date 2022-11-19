#ifndef SCHEDULE_H
#define SCHEDULE_H

/* Menambah satu menit waktu berjalannya simulator; */
/* Mengurangi satu menit waktu expiry, pengolahan, dan delivery makanan; */
void tick();

/* Menambah waktu berjalannya simulator sebanyak m menit; */
/* Mengurangi waktu expiry, pengolahan, dan delivery makanan sebanyak m menit; */
void tickWithTime(int m);

#endif