#include <stdlib.h>
#include <stdio.h>
#include "shapes.h"

// SHAPE
Shape* create_empty_shape(Shape_Type shape_type)
{
    Shape* shp = (Shape*) malloc(sizeof(Shape));

    shp->id = 0; // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    shp->ptrShape = NULL;

    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape* shp = create_empty_shape(POINT);
    Point* p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape* shp = create_empty_shape(LINE);

    Point* p1 = create_point(py1, px1);
    Point* p2 = create_point(py2, px2);

    Line* l = create_line(p1, p2);
    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length)
{
    Shape* shp = create_empty_shape(SQUARE);
    Point* origin = create_point(py, px);

    Square* s = create_square(origin, length); 
    shp->ptrShape = s;
    return shp;
}

void print_shape(Shape *shape)
{
    switch (shape->shape_type)
    {
        case POINT:
            print_point(shape->ptrShape);
            break;

        case LINE:
            print_line(shape->ptrShape);
            break;

        case SQUARE:
            print_square(shape->ptrShape);
            break;
        
        default:
            break;
    }
}

// POINTS
Point* create_point(int py, int px) 
{
    Point* point = malloc(sizeof(Point));

    point->point_y = py;
    point->point_x = px;

    return point;
}

void delete_point(Point *point) 
{
    free(point);
}

void print_point(Point *p) 
{
    printf("POINT %d %d\n", p->point_x, p->point_y);
}

// LINES
Line* create_line(Point *p1, Point *p2) 
{
    Line* line = malloc(sizeof(Line));

    line->point_1 = p1;
    line->point_2 = p2;

    return line;
}

void delete_line(Line *line)
{
    free(line);
}

void print_line(Line *line)
{
    printf("LINE %d %d %d %d\n", line->point_1->point_x, line->point_1->point_y, line->point_2->point_x, line->point_2->point_y);
}

// SQUARE
Square *create_square(Point *point, int length)
{
    Square* sqr = malloc(sizeof(Square));

    sqr->origin = point;
    sqr->lenght = length;

    return sqr;
}

void delete_square(Square *square)
{
    free(square);
}

void print_square(Square *square)
{
    printf("SQUARE %d %d %d\n", square->origin->point_x,square->origin->point_y, square->lenght);
}
