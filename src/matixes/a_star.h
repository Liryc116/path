#ifndef A_STAR_H
#define A_STAR_H

#include "map.h"
#include "../utils/vector.h"
#include "point.h"

// A vecor of points to go from the start point to the end point
// with the shortest travel distance
// the result includes the start and end point
struct vector *a_star(struct map *map, struct point *start, struct point *end,
        size_t(*dist_fun)(struct point *, struct point *));

#endif /* ! A_STAR_H */
