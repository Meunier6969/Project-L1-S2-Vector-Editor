#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

    delete_all_shapes(area);
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
        
        case LINE:
            draw_line(area, currentShape->ptrShape);
            break;

        case SQUARE:
            draw_square(area, currentShape->ptrShape);
            break;

        case RECTANGLE:
            draw_rectangle(area, currentShape->ptrShape);
            break;

        case CIRCLE:
            draw_circle(area, currentShape->ptrShape);
            break;

        case POLYGON:
            draw_polygon(area, currentShape->ptrShape);
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

void delete_shape_from_area(Area *area, int id)
{
    if (id >= area->nb_shape)
        return;

    area->nb_shape--;

    for (size_t i = id; i < area->nb_shape; i++)
    {
        area->shapes[i] = area->shapes[i+1];
    }
    
}

void delete_all_shapes(Area *area)
{
    for (size_t i = 0; i < area->nb_shape; i++)
    {
        delete_shape(area->shapes[i]);
    }
    area->nb_shape = 0;
}

// DRAWING SHAPE FUNCTIONS
void draw_point(Area *area, Point *pnt)
{
    draw_pixel(area, pnt->point_y, pnt->point_x);
}

void draw_line(Area *area, Line *line)
{ // Using DDA [https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)]
    Point *p1 = line->point_1;
    Point *p2 = line->point_2;

    float dx, dy;
    dx = p2->point_x - p1->point_x;
    dy = p2->point_y - p1->point_y;

    int steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xInc, yInc;
    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    float x, y;
    x = p1->point_x;
    y = p1->point_y;

    int xD, yD;
    xD = x;
    yD = y;

    for (size_t i = 0; i < steps; i++)
    {
        draw_pixel(area, yD, xD);

        x = x + xInc;
        y = y + yInc;

        xD = round(x);
        yD = round(y);
    }
}

void draw_square(Area *area, Square *sqr)
{
    int Ox, Oy, len;
    Ox = sqr->origin->point_x;
    Oy = sqr->origin->point_y;
    len = sqr->lenght;

    for (size_t i = 0; i < len; i++)
    {
        draw_pixel(area, Oy + i, Ox); // Left and right side
        draw_pixel(area, Oy + i, Ox + len - 1);

        draw_pixel(area, Oy, Ox + i); // Top and bottom 
        draw_pixel(area, Oy + len - 1, Ox + i);
    }
}

void draw_rectangle(Area *area, Rectangle *rect)
{
    int Ox, Oy, width, height
    ;
    Ox = rect->origin->point_x;
    Oy = rect->origin->point_y;
    width = rect->width;
    height = rect->height;

    for (size_t i = 0; i < height; i++)
    {
        draw_pixel(area, Oy + i, Ox); // Left and right side
        draw_pixel(area, Oy + i, Ox + width - 1);
    }

    for (size_t i = 0; i < width; i++)
    {
        draw_pixel(area, Oy, Ox + i); // Top and bottom
        draw_pixel(area, Oy + height - 1, Ox + i);
    }

}

void draw_circle(Area *area, Circle *circ)
{
    int Ox, Oy;
    Ox = circ->origin->point_x;
    Oy = circ->origin->point_y;

    int x, y, d;
    x = 0;
    y = circ->radius;
    d = circ->radius - 1;

    while (y >= x)
    {
        draw_pixel(area, Oy + y, Ox + x);
        draw_pixel(area, Oy + x, Ox + y);
        draw_pixel(area, Oy - y, Ox + x);
        draw_pixel(area, Oy - x, Ox + y);
        draw_pixel(area, Oy + y, Ox - x);
        draw_pixel(area, Oy + x, Ox - y);
        draw_pixel(area, Oy - y, Ox - x);
        draw_pixel(area, Oy - x, Ox - y);

        if (d >= 2 * x)
        {
            d = d - 2*x - 1;
            x++;
        }
        else if (d < 2 * (circ->radius - y))
        {
            d = d + 2*x - 1;
            y--;
        }
        else
        {
            d = d + 2*(y-x-1);
            y--;
            x++;
        }
        
    }
}

void draw_polygon(Area *area, Polygon *plyg)
{
    Line *currentLine = NULL;
    Point *p1, *p2;
    p1 = NULL;
    p2 = NULL;

    for (size_t i = 0; i < plyg->num_of_points-1; i++)
    {

        p1 = plyg->points[i];
        p2 = plyg->points[i+1];
        
        currentLine = create_line(p1, p2);

        draw_line(area, currentLine);
    }
    
    free(p1);
    free(p2); 
    free(currentLine);
}

// UTILITARY
void draw_pixel(Area* area, int y, int x)
{
    int is_inbound = x >= 0 && x < area->width && y >= 0 && y < area->height;
    // Check if pixel is supposed to be drawn or not
    if (is_inbound)
        area->mat[y][x] = 1;
}