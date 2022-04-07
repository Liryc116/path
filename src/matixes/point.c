#include "point.h"

#include "../utils/xmalloc.h"

#include <stdlib.h>

struct point *point_new(size_t x, size_t y)
{
    struct point *p = xmalloc(sizeof(struct point));

    p->x = x;
    p->y = y;

    return p;
}

void point_free(void *point)
{
    free(point);
}
