#ifndef MAP_H
#define MAP_H

#include <stddef.h>

struct map
{
    size_t data_size;
    size_t width;
    size_t height;
    int *data;
};

/**
** Create a map
** 0 = not walkable (wall)
** !0 = walkable
*/
struct map* map_new(size_t width, size_t height);

void map_set_at(struct map *m, size_t x, size_t y, int n);

int map_get_at(struct map *m, size_t x, size_t y);

void map_free(struct map *m);

#endif /* ! MAP_H */
