#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "draw.h"

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


    Shape* listShapes[100];
    int nodeList[6] = {2,3,5,7,11,13};
    int currentID = 0;

    int choice = -1;
    while (choice != 0)
    {
        printf("== CURRENT : %d ==\n", currentID);
        printf("0:Quit\n1:Point\n2:Line\n3:Square\n4:Rectangle\n5:Circle\n6:Polygon\n");
        printf("7:Show shapes\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Point
            listShapes[currentID] = create_point_shape(1, 2);
            currentID++;
            break;

        case 2: // Line
            listShapes[currentID] = create_line_shape(4,3,2,1);
            currentID++;
            break;

        case 3: // Square
            listShapes[currentID] = create_square_shape(4,2,0);
            currentID++;
            break;

        case 4: // Rectangle
            listShapes[currentID] = create_rectangle_shape(4,3,2,1);
            currentID++;
            break;

        case 5: // Circle
            listShapes[currentID] = create_circle_shape(3,1,4);
            currentID++;
            break;

        case 6: // Polygon
            listShapes[currentID] = create_polygon_shape(nodeList, 6);
            currentID++;
            break;
        
        case 7: // Show shapes
            printf("== SHAPES ==\n");
            for (size_t i = 0; i < currentID; i++)
            {
                printf("%d - ", i);
                print_shape(listShapes[i]);
            }
            break;

        default:
            break;
        }


        

    }
    
    
    //print_buffer(buffer, HEIGHT, WIDTH);
    
    return 0;
}
