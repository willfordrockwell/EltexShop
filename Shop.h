#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define SHOPS_NUM 5

#define BUYER_LIMIT 10000
#define BUYER_NUM 3

#define LOAD 500;

void *Buyer_Thread (void *args);

void *Loader_Thread (void *args);

void Shopping (int *Shop, int *Load);

void Loading (int *Shop);