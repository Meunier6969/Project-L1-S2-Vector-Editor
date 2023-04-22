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
    Shape* shape_list[100];
    int currentId = 0;
    int choice = 0;

    while (1)
    {
        choice = simple_menu(currentId);

        switch (choice)
        {
        case 1:
            shape_list[currentId] = enter_point();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 2:
            shape_list[currentId] = enter_line();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 3:
            shape_list[currentId] = enter_square();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 4:
            shape_list[currentId] = enter_rectangle();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 5:
            shape_list[currentId] = enter_circle();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 6:
            shape_list[currentId] = enter_polygon();
            shape_list[currentId]->id = currentId;
            currentId++;
            break;
        
        case 7:
            show_shapes(shape_list, currentId);
            break;

        case 0:
            exit(0);
            break;

        default:
            break;
        }

    }


    //print_buffer(buffer, HEIGHT, WIDTH);
    
    return 0;
}
