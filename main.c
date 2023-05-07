#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "menu.h"

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);
    initialize_area(area);

    /* FULLY INSIDE SHAPES */
    Shape *p1 = create_point_shape(1, 2);
    Shape *p2 = create_point_shape(4, 8);
    add_shape_to_area(area, p1);
    add_shape_to_area(area, p2);

    Shape *line = create_line_shape(15, 9, 7, 20);
    add_shape_to_area(area, line);

    Shape *sqr = create_square_shape(7, 25, 5);
    add_shape_to_area(area, sqr);

    Shape *rect = create_rectangle_shape(1, 10, 7, 4);
    add_shape_to_area(area, rect);

    Shape *cirque = create_circle_shape(10, 15, 5);
    add_shape_to_area(area, cirque);

    /* PARTLY OUTSIDE SHAPES */
    Shape *outside_line = create_line_shape(16, 16, 32, 64);
    add_shape_to_area(area, outside_line);

    Shape *outside_sqr = create_square_shape(10, -5, 12);
    add_shape_to_area(area, outside_sqr);

    Shape *outside_rect = create_rectangle_shape(3, 20, 16, 3);
    add_shape_to_area(area, outside_rect);

    Shape *outside_cirque = create_circle_shape(10, 15, 15);
    add_shape_to_area(area, outside_cirque);

    list_shapes(area);

    draw_shapes_to_area(area);
    print_area(area);

    delete_area(area);

    return 0;
}
