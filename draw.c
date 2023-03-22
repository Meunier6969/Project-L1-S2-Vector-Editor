#include <stdio.h>
#include <math.h>
#include "shapes.h"
#include "draw.h"

void initialize_buffer(int **buffer, int width, int height)
{
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            buffer[i][j] = 0;
}

void print_buffer(int **buffer, int height, int width)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (buffer[i][j] == 0) 
                printf(". ");
            else
                printf("# ");
        }
        printf("\n");
    }    
}

void print_shape_to_buffer(int **buffer, Shape *shape)
{
    switch (shape->shape_type)
    {
    case POINT:
        print_point_to_buffer(buffer, shape->ptrShape);
        break;

    case LINE:
        print_line_to_buffer(buffer, shape->ptrShape);
        break;

    case SQUARE:
        /* code */
        break;

    case RECTANGLE:
        /* code */
        break;

    case CIRCLE:
        /* code */
        break;

    case POLYGON:
        /* code */
        break;
    
    default:
        break;
    }
}

void print_point_to_buffer(int **buffer, Point *p)
{
    int x, y;
    y = p->point_y;
    x = p->point_x;

    buffer[y][x] = 1;
}

void print_line_to_buffer(int **buffer, Line *l)
{
    float y;
    int y_to_print;

    float x1, y1;
    float x2, y2;
    x1 = (float) l->point_1->point_x;
    y1 = (float) l->point_1->point_y;
    x2 = (float) l->point_2->point_x;
    y2 = (float) l->point_2->point_y;

    float slope = (y2-y1) / (x2-x1);

    for (size_t x = x1; x <= x2; x++)
    {
        y = slope * x + y1 + 0.5;
        y_to_print = y; // Conversion from float to int

        buffer[y_to_print][x] = 1;
    }
}