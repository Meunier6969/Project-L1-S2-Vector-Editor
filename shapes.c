#include <stdlib.h>
#include <stdio.h>
#include "shapes.h"

// SHAPE
Shape* create_empty_shape(Shape_Type shapeType)
{
    Shape* shp = (Shape*) malloc(sizeof(Shape));

    shp->id = 0; // plus tard on appelera get_next_id();
    shp->shapeType = shapeType;
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

Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *origin = create_point(py, px);

    Rectangle *r = create_rectangle(origin, width, height);
    shp->ptrShape = r;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Point *origin = create_point(py, px);

    Circle *c = create_circle(origin, radius);
    shp->ptrShape = c;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n)
{   
    if (n%2 == 1)
    {
        printf("Number of points must be a multiple of 2.");
        return NULL;
    }

    n /= 2; // n becomes the number of Points

    Shape *shp = create_empty_shape(POLYGON);
    Polygon *p = create_polygon(n);

    p->num_of_points = n;
    for (size_t i = 0; i < n; i++)
    {
        p->points[i] = create_point(lst[2*i], lst[2*i + 1]);
    }

    shp->ptrShape = p;
    return shp;
}

void print_shape(Shape *shape)
{
    switch (shape->shapeType)
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

        case RECTANGLE:
            print_rectangle(shape->ptrShape);
            break;

        case CIRCLE:
            print_circle(shape->ptrShape);
            break;
        
        case POLYGON:
            print_polygon(shape->ptrShape);
            break;
        
        default:
            break;
    }
}

void delete_shape(Shape *shape)
{
    switch (shape->shapeType)
    {
        case POINT:
            delete_point(shape->ptrShape);
            break;

        case LINE:
            delete_line(shape->ptrShape);
            break;

        case SQUARE:
            delete_square(shape->ptrShape);
            break;

        case RECTANGLE:
            delete_rectangle(shape->ptrShape);
            break;

        case CIRCLE:
            delete_circle(shape->ptrShape);
            break;
        
        case POLYGON:
            delete_polygon(shape->ptrShape);
            break;
        
        default:
            break;
    }
    free(shape);
}

// POINTS
Point *create_point(int py, int px) 
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
Line *create_line(Point *p1, Point *p2) 
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
Square *create_square(Point *origin, int length)
{
    Square* sqr = malloc(sizeof(Square));

    sqr->origin = origin;
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

// RECTANGLE
Rectangle *create_rectangle(Point *origin, int width, int height)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    rect->origin = origin;
    rect->width = width;
    rect->height = height;

    return rect;
}

void delete_rectangle(Rectangle *rect)
{
    free(rect);
}

void print_rectangle(Rectangle *rect)
{
    printf("RECTANGLE %d %d %d %d\n", rect->origin->point_x, rect->origin->point_y, rect->width, rect->height);
}

// CIRCLE
Circle *create_circle(Point *origin, int radius)
{
    Circle *circ = malloc(sizeof(Circle));

    circ->origin = origin;
    circ->radius = radius;

    return circ;
}

void delete_circle(Circle *circ)
{
    free(circ);
}

void print_circle(Circle *circ)
{
    printf("CIRCLE %d %d %d\n", circ->origin->point_x, circ->origin->point_y, circ->radius);
}

// POLYGON
Polygon *create_polygon(int num_of_points)
{
    Polygon *poly = malloc(sizeof(Polygon));
    Point **points = malloc(num_of_points * sizeof(Point*));

    poly->num_of_points = num_of_points;
    poly->points = points;

    return poly;
}

void delete_polygon(Polygon *poly)
{
    for (size_t i = 0; i < poly->num_of_points; i++)
    {
        free(poly->points[i]);
    }
    free(poly->points);
    free(poly);
}

void print_polygon(Polygon *poly)
{
    printf("POLYGON ");
    for (size_t i = 0; i < poly->num_of_points; i++)
    {
        printf("%d %d ", poly->points[i]->point_y, poly->points[i]->point_x);
    }
    printf("\n");
}
