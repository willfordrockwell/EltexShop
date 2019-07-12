#include "Shop.h"

void *Loader_Thread (void *args)
{
    extern int Shops[SHOPS_NUM];
    extern pthread_mutex_t Mutex[SHOPS_NUM];
    int Choose;
    while (1) {
        Choose = rand() % SHOPS_NUM;
        if(pthread_mutex_trylock(&Mutex[Choose]) == 0) {
            Loading(&Shops[Choose]);
            pthread_mutex_unlock(&Mutex[Choose]);
            printf("Loader loaded in %d's shop\n", Choose);
            sleep(3);
        }
    }
}
