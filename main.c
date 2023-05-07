#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "menu.h"

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);
    initialize_area(area);

    Shape *p1 = create_point_shape(1, 2);
    Shape *p2 = create_point_shape(4, 8);
    add_shape_to_area(area, p1);
    add_shape_to_area(area, p2);

    Shape *line = create_line_shape(15, 9, 7, 20);
    add_shape_to_area(area, line);

    Shape *sqr = create_square_shape(7, 25, 5);
    add_shape_to_area(area, sqr);

    list_shapes(area);

    draw_shapes_to_area(area);
    print_area(area);

    delete_area(area);

    return 0;
}
