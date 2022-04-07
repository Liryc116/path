#include "distance.h"

#include "../utils/matrix.h"
#include "point.h"

#include <stddef.h>
#include <stdlib.h>
#include <math.h>

size_t manhattan_dist(struct point *p1, struct point *p2)
{
    return llabs((long long)p1->x - (long long)p2->x)
        + llabs((long long)p1->y - (long long)p2->y);
}

size_t euclidian_dist(struct point *p1, struct point *p2)
{
    size_t x = llabs((long long)p1->x - (long long)p2->x);
    size_t y = llabs((long long)p1->y - (long long)p2->y);

    return 10*sqrtl(x*x+y*y);
}

static size_t my_max(size_t a, size_t b)
{
    if(a>b)
        return a;
    return b;
}

size_t tchebychev_dist(struct point *p1, struct point *p2)
{
    size_t x = llabs((long long)p1->x - (long long)p2->x);
    size_t y = llabs((long long)p1->y - (long long)p2->y);

    return my_max(x, y);
}
