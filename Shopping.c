#include "Shop.h"

void Shopping (int *Shop, int *Load)
{
    if (*Shop < BUYER_LIMIT - *Load) {
        *Load += *Shop;
        *Shop = 0;
    }
    else {
        *Shop -= BUYER_LIMIT - *Load;
        *Load += BUYER_LIMIT - *Load;
    }
}
