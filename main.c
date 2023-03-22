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

    // Eyooooo
    Shape* p1 = create_point_shape(10, 15);
    Shape* l1 = create_line_shape(0, 0, 10, 15);
    Shape* s1 = create_square_shape(14,2,3);

    print_shape(s1);

    print_shape_to_buffer(buffer, p1);
    print_shape_to_buffer(buffer, l1);

    print_buffer(buffer, HEIGHT, WIDTH);
    
    return 0;
}
