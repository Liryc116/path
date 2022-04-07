#ifndef POINT_H
#define POINT_H

#include <stddef.h>

struct point
{
    size_t x, y;
};

struct point *point_new(size_t x, size_t y);

void point_free(void *point);

#endif /* ! POINT_H */
