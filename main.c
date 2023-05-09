#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "menu.h"

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);
    initialize_area(area);

    int list[12] = {1, 1, 2, 10, 10, 5, 12, 20, 18, 3, 1, 1};
    Shape *pppp = create_polygon_shape(list, 6);

    add_shape_to_area(area, pppp);


    list_shapes(area);

    draw_shapes_to_area(area);
    print_area(area);

    delete_area(area);

    return 0;
}
