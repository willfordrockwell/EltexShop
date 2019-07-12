#include "Shop.h"

void *Buyer_Thread (void *args)
{
    time_t Time = time(NULL);
    extern int Shops[SHOPS_NUM];
    extern pthread_mutex_t Mutex[SHOPS_NUM];
    int Load = 0;
    int *Shopper = (int *)args;
    int Choose;
    int Gotcha = 0;
    while (Load < BUYER_LIMIT) {
        Choose = rand() % SHOPS_NUM;
        if(pthread_mutex_lock(&Mutex[Choose]) == 0) {
            if (Shops[Choose] > 0) {
                Gotcha = 1;
                Shopping(&Shops[Choose], &Load);
            }
            pthread_mutex_unlock(&Mutex[Choose]);
            if (Gotcha) {
                Gotcha = 0;
                printf("%d's Shopper out from %d shop and his load now %5d\n",
                       *Shopper, Choose, Load);
            }
            sleep(2);
        }
    }
    Time = time(NULL) - Time;
    pthread_exit((void*)(Time));
}
