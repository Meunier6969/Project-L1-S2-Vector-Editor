#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "menu.h"

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);

    initialize_area(area);

    Shape *pipi = create_point_shape(2, 4);
    Shape *pipi2 = create_point_shape(6, 9);
    Shape *pipi3 = create_point_shape(-1, 69);
    add_shape_to_area(area, pipi);
    add_shape_to_area(area, pipi2);
    add_shape_to_area(area, pipi3);

    list_shapes(area);

    draw_shapes_to_area(area);

    print_area(area);

    delete_area(area);

    return 0;
}
