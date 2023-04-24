#include <stdlib.h>
#include <stdio.h>
#include "area.h"

Area *create_area(unsigned int width, unsigned int height)
{
    Area* area = malloc(sizeof(Area));

    area->height = height;
    area->width = width;
 
    area->mat = malloc(height * sizeof(int*));
    for (size_t i = 0; i < height; i++)
    {
        area->mat[i] = malloc(width * sizeof(int));
    }
    
    area->shapes = malloc(SHAPE_MAX * sizeof(Shape*));
    area->nb_shape = 0;

    return area;
}

void add_shape_to_area(Area *area, Shape *shape)
{
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

void initialize_area(Area *area)
{
    for (size_t y = 0; y < area->height; y++)
    {
        for (size_t x = 0; x < area->width; x++)
        {
            area->mat[y][x] = 0;
        }
    }
}

void erase_area(Area *area)
{
    for (size_t i = 0; i < area->nb_shape; i++)
    {
        delete_shape(area->shapes[i]);
    }
    area->nb_shape = 0;
}

void delete_area(Area *area)
{
    erase_area(area);
    free(area->shapes);

    for (size_t i = 0; i < area->height; i++)
        free(area->mat[i]);
    
    free(area->mat);

    free(area);
}

void draw_shapes_to_area(Area *area)
{
}

void print_area(Area *area)
{
    for (size_t y = 0; y < area->height; y++)
    {
        for (size_t x = 0; x < area->width; x++)
        {
            if (area->mat[y][x])
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void list_shapes(Area *area)
{
    for (size_t i = 0; i < area->nb_shape; i++)
    {
        printf("%d : ", i);
        print_shape(area->shapes[i]);
    }
    printf("\n");
}