#pragma once

#include "shapes.h"

#define SHAPE_MAX 100

// AREA DEFINTION
typedef struct area
{
    unsigned int width;
    unsigned int height;

    int **mat;

    Shape **shapes; // List of pointers to Shapes
    int nb_shape;
} Area;

// AREA FUNCTIONS
Area *create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area *area, Shape *shape);
void initialize_area(Area *area);
void erase_area(Area *area);
void delete_area(Area *area);
void draw_shapes_to_area(Area *area);
void print_area(Area *area);

void list_shapes(Area *area);
void delete_shape_from_area(Area *area, int id);
void delete_all_shapes(Area *area);

// DRAWING SHAPE FUNCTIONS
void draw_point(Area* area, Point* pnt);
void draw_line(Area* area, Line* line);
void draw_square(Area* area, Square* squr);
void draw_rectangle(Area* area, Rectangle* rect);
void draw_circle(Area* area, Circle* circ);
void draw_polygon(Area* area, Polygon* plyg);

// UTILITARY
void draw_pixel(Area *area, int y, int x);
