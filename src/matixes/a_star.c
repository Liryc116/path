#include "a_star.h"

#include "point.h"
#include "../utils/heap.h"
#include "../utils/matrix.h"

#include <stddef.h>
#include <stdlib.h>

struct cell
{
    struct point *parent;
    double gcost;
    double hcost;
    //int visited;
};

static double fcost(double g, double h)
{
    return g+h;
}

static int cmp_cell(void *cell1, void *cell2)
{
    struct cell *c1 = cell1;
    struct cell *c2 = cell2;
    double diff = fcost(c1->gcost, c1->hcost) - fcost(c2->gcost, c2->hcost);

    if(diff==0)
        return c1->hcost - c2->hcost;

    return diff;
}

static struct vector *get_path(struct matrix *mat, struct point *end)
{
    struct vector *res = vector_new();

    struct cell *c = matrix_get(mat, end->x, end->y);

    if(c->parent == NULL)
        return res; // No path to the start

    vector_push(res, end, sizeof(struct point));
    while(c->parent != NULL)
    {
        vector_push(res, c->parent, sizeof(struct point));
        c = matrix_get(mat, c->parent->x, c->parent->y);
    }

    // Reverse list
    for(size_t i = 0; i<res->size/2; i++)
    {
        void *tmp = res->data[i];
        res->data[i] = res->data[res->size-i-1];
        res->data[res->size-i] = tmp;
    }

    return res;
}

struct vector *a_star(struct map *map, struct point *start, struct point *end,
        size_t(*dist_fun)(struct point *, struct point *))
{
    struct heap *heap = heap_new(cmp_cell);
    struct matrix *mat = matrix_new(map->width, map->height);

    struct cell new_cell = {.parent=NULL, .gcost=0,
        .hcost=dist_fun(start, end),};
    heap_insert(heap, &new_cell, sizeof(struct cell));

    heap_insert(heap, start, sizeof(struct point));
    while(!heap_is_empty(heap))
    {
        struct point *p = heap_pop(heap);
        for(int i = 0; i<9; i++)
        {
            int dx = i%3 - 1;
            int dy = i/3 - 1;
            struct point tmp = {.x = dx+p->x, .y = dy+p->y};
            if((long long)p->x+dx>=0 && tmp.x<map->width
                    && (long long)p->y+dy>=0 && tmp.y<map->height)
            {
                if(map_get_at(map, tmp.x, tmp.y))
                {
                    size_t dist = dist_fun(start, &tmp);
                    struct cell *c = matrix_get(mat, tmp.x, tmp.y);
                    if(c==NULL)
                    {
                        new_cell.gcost = dist;
                        new_cell.hcost = dist_fun(&tmp, end);
                        new_cell.parent = p;
                    }
                    else if(c->gcost>dist)
                    {
                        c->gcost = dist;
                        c->parent = p;
                    }
                }
            }
        }

        point_free(p);
    }

    heap_free(heap, &free);

    return get_path(mat, end);
}
