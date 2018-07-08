#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEENS_NUM (8)

#define PRINT_MAP(_map) \
    printf("[");\
    for (int __i = 0; __i < QUEENS_NUM; __i++) {\
    printf("%d ", _map.state[__i]);\
    }\
    printf("]\n");

typedef int bool;

#define true (1)
#define false (0)

typedef struct queens_map
{
    int state[QUEENS_NUM];
    int len;
}queens_map_t;


bool conflict(queens_map_t *map, int nextX)
{
    int i = 0;
    int nextY = map->len;
    for (i; i < map->len; i++)
    {
        int delta = abs(map->state[i] - nextX);
        if (delta == 0 || delta == (nextY - i))
        {
            return true;
        }
    }
    return false;
}


void queen_maps(queens_map_t *map)
{
    int i = 0;

    queens_map_t tmp_map;
    memcpy(&tmp_map, map, sizeof(queens_map_t));
    
    if ((tmp_map.len) == (QUEENS_NUM - 1))
    {
        for (i = 0; i < QUEENS_NUM; i++)
        {
            if (!conflict(&tmp_map, i))
            {
                tmp_map.state[tmp_map.len] = i;
                tmp_map.len++;

                PRINT_MAP(tmp_map);
                return;
            }
            
        }
    }

    for (i = 0; i < QUEENS_NUM; i++)
    {
        if (!conflict(&tmp_map, i))
        {
            tmp_map.state[tmp_map.len] = i;
            tmp_map.len++;
            queen_maps(&tmp_map);
            tmp_map.len--;
        }
    }

    return;
}

int main(void)
{
    queens_map_t map = {{-1}, 0};
    queen_maps(&map);
    
    return 0;
}
