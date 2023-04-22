#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"

int simple_menu(int currentId)
{
    printf("== CURRENT SHAPE : %d ==\n", currentId);
    printf("1 : Add Point\n");
    printf("2 : Add Line\n");
    printf("3 : Add Square\n");
    printf("4 : Add Rectangle\n");
    printf("5 : Add Circle\n");
    printf("6 : Add Polygon\n");
    printf("7 : Show Shapes\n");
    printf("0 : Quit\n");

    int choice = 0;
    scanf("%d", &choice);

    return choice;
}

Shape* enter_point()
{
    int x = 0, y = 0;

    printf("-- Point --\n");
    printf("> Enter the coordinate y x : \n");
    scanf("%d %d", &y, &x);

    Shape *point = create_point_shape(y, x);
    return point;
}

Shape* enter_line()
{
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;

    printf("-- Line --\n");
    printf("> Enter the coordinate y1 x1 : \n");
    scanf("%d %d", &y1, &x1);
    printf("> Enter the coordinate y2 x2 : \n");
    scanf("%d %d", &y2, &x2);

    Shape *line = create_line_shape(y1, x1, y2, x2);
    return line;
}

Shape* enter_square()
{
    int x = 0, y = 0;
    int len = 0;

    printf("-- Square --\n");
    printf("> Enter the coordinate y x : \n");
    scanf("%d %d", &y, &x);
    printf("> Enter the lenght :\n");
    scanf("%d", &len);

    Shape *square = create_square_shape(y, x, len);
    return square;
}

Shape* enter_rectangle()
{
    int x = 0, y = 0;
    int wid = 0, hei = 0;

    printf("-- Rectangle --\n");
    printf("> Enter the coordinate y x : \n");
    scanf("%d %d", &y, &x);
    printf("> Enter the width :\n");
    scanf("%d", &wid);
    printf("> Enter the height :\n");
    scanf("%d", &hei);

    Shape *rectangle = create_rectangle_shape(y, x, wid, hei);
    return rectangle;
}

Shape* enter_circle()
{
    int x = 0, y = 0;
    int rad = 0;

    printf("-- Circle --\n");
    printf("> Enter the coordinate y x : \n");
    scanf("%d %d", &y, &x);
    printf("> Enter the radius :\n");
    scanf("%d", &rad);

    Shape *circle = create_circle_shape(y, x, rad);
    return circle;
}

Shape* enter_polygon()
{
    int number_of_points = 0;

    printf("-- Polygon --\n");
    printf("> Enter the number of points : \n");
    scanf("%d", &number_of_points);

    int* list = (int*) malloc(2 * number_of_points * sizeof(int));

    for (size_t i = 0; i < number_of_points; i++)
    {
        printf("> Enter the coordinate y%d x%d : \n", i, i);
        scanf("%d %d", &list[2 * i], &list[2 * i + 1]);
    }
    
    Shape *polygon = create_polygon_shape(list, number_of_points);
    return polygon;
}

void show_shapes(Shape **listShapes, int size)
{
    printf("== SHAPES ==\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d - ", i);
        print_shape(listShapes[i]);
    }
}
