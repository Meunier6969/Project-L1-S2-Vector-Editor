#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "draw.h"
#include "area.h"
#include "menu.h"

#define WIDTH 32
#define HEIGHT 20

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);

    initialize_area(area);

    Shape *pipi = create_point_shape(2, 4);
    Shape *pipi2 = create_point_shape(6, 9);
    add_shape_to_area(area, pipi);
    add_shape_to_area(area, pipi2);

    list_shapes(area);
    print_area(area);

    delete_area(area);

    list_shapes(area);
    // print_area(area);

    return 0;
}
