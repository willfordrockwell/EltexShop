#include "Shop.h"

int Shops[SHOPS_NUM];

pthread_mutex_t Mutex[SHOPS_NUM] = {PTHREAD_MUTEX_INITIALIZER};

int main (int argc, char **argv)
{
    pthread_t Buyer_TID[BUYER_NUM];
    pthread_t Loader_TID;
    int Thread_Return;
    void *Thread_Time[3];
    int id[BUYER_NUM];

    //Unlock all Mutexes and make shops full
    for (int i = 0; i < SHOPS_NUM; i++) {
        pthread_mutex_unlock(&Mutex[i]);
        Shops[i] = 1000;
        id[i] = i;
    }

    //Start Buyers
    for (int i = 0; i < BUYER_NUM; i++) {
        if ((Thread_Return = pthread_create(&Buyer_TID[i], NULL, Buyer_Thread,
                                            &id[i])) == 0) {
            printf ("%d's buyer has created\n", i);
        }
        else {
            printf("%d's buyer not created: %s\n", i, strerror(Thread_Return));
        }
    }

    //Start Loader
    if ((Thread_Return = pthread_create(&Loader_TID, NULL, Loader_Thread,
                                        NULL)) == 0) {
        printf ("Loader has created\n");
    }
    else {
        printf("Loader not created: %s\n", strerror(Thread_Return));
    }

    //Wait for stop buyers threads
    for (int i = 0; i < BUYER_NUM; i++) {
        pthread_join(Buyer_TID[i], &Thread_Time[i]);
    }

    for (int i = 0; i < BUYER_NUM; i++) {
        printf("%d's buyer shopped %d seconds\n", i, (int)(Thread_Time[i]));
    }

    //Stop Loader
    pthread_cancel(Loader_TID);
    printf("Loader ended\n");

    return 0;
}
