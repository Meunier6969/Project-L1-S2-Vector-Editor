#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "draw.h"

#define WIDTH 32
#define HEIGHT 20

int main(int argc, char const *argv[]) 
{
    // Allocating the buffer
    int** buffer;

    buffer = malloc(HEIGHT * sizeof(int*));
    for (size_t i = 0; i < HEIGHT; i++)
        buffer[i] = malloc(WIDTH * sizeof(int));

    // Initializing the buffer, put in a seperate function
    initialize_buffer(buffer, WIDTH, HEIGHT);

    // Eyooooo amogus test
    Shape* p1 = create_point_shape(3, 6);
    Shape* s1 = create_square_shape(2, 4, 6);
    Shape* r1 = create_rectangle_shape(7, 8, 1, 9);
    Shape* c1 = create_circle_shape(3, 14, 15);
    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    Shape* p2 = create_polygon_shape(list, 10);

    print_shape(p1);
    print_shape(s1);
    print_shape(r1);
    print_shape(c1);
    print_shape(p2);

    delete_shape(p1);
    delete_shape(s1);
    delete_shape(r1);
    delete_shape(c1);
    delete_shape(p2);
    
    //print_buffer(buffer, HEIGHT, WIDTH);
    
    return 0;
}
