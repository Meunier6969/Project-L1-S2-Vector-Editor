#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "draw.h"
#include "menu.h"

#define WIDTH 32
#define HEIGHT 20

int main(int argc, char const *argv[]) 
{
    /***** WILL BE DEFINED IN AREA.C *****/
    // Allocating the buffer
    int** buffer;

    buffer = malloc(HEIGHT * sizeof(int*));
    for (size_t i = 0; i < HEIGHT; i++)
        buffer[i] = malloc(WIDTH * sizeof(int));

    // Initializing the buffer, put in a separate function
    initialize_buffer(buffer, WIDTH, HEIGHT);
    /*************************************/

    // Menu

    //print_buffer(buffer, HEIGHT, WIDTH);
    
    return 0;
}
