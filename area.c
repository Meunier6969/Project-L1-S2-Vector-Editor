#include <stdlib.h>
#include <stdio.h>
#include "area.h"

#define WIDTH 32
#define HEIGHT 20

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
    Shape* currentShape = NULL;

    for (size_t i = 0; i < area->nb_shape; i++)
    {
        currentShape = area->shapes[i];
        
        switch (currentShape->shapeType)
        {
        case POINT:
            draw_point(area, currentShape->ptrShape);
            break;
        
        default:
            break;
        }
    }
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

// DRAWING SHAPE FUNCTIONS
void draw_point(Area *area, Point *pnt)
{
    if (pnt->point_y >= 0 && pnt->point_y < HEIGHT && pnt->point_x >= 0 && pnt->point_x < WIDTH)
        area->mat[pnt->point_y][pnt->point_x] = 1;
}

void draw_line(Area *area, Line *line)
{

}

void draw_square(Area *area, Square *squr)
{

}

void draw_rectangle(Area *area, Rectangle *rect)
{

}

void draw_circle(Area *area, Circle *circ)
{

}

void draw_polygon(Area *area, Polygon *plyg)
{

}
