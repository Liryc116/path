#include "map.h"

#include "../utils/xmalloc.h"

#include <stdlib.h>
#include <err.h>

struct map* map_new(size_t width, size_t height)
{
    struct map *map = xmalloc(sizeof(struct map));

    map->width = width;
    map->height = height;
    map->data_size = sizeof(int);
    map->data = xmalloc(width*height * sizeof(int));

    for(size_t i = 0; i < width*height; i++)
        map->data[i] = 0.0;

    return map;
}

void map_set_at(struct map *m, size_t x, size_t y, int n)
{
    if(x >= m->width || y >= m->height || n<0)
        return;
    m->data[x+y*m->width] = n;
}

int map_get_at(struct map *m, size_t x, size_t y)
{
    if(x >= m->width || y >= m->height)
        return -1;
    return m->data[x+y*m->width];
}

void map_free(struct map *m)
{
    free(m->data);
    free(m);
}
