#ifndef DISTANCE_H
#define DISTANCE_H

#include <stddef.h>

#include "point.h"

// Calculates the distance between two point with different distance methods
// The distance is based only on their coordinates

size_t manhattan_dist(struct point *p1, struct point *p2);

// The euclidian distance *10
size_t euclidian_dist(struct point *p1, struct point *p2);

size_t tchebychev_dist(struct point *p1, struct point *p2);

#endif /* ! DISTANCE_H */
