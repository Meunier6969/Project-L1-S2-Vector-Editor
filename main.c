#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "command.h"

int main(int argc, char const *argv[]) 
{
    int width = 32, height = 20;

    printf("___ CLI Vector Editor ___\n");
    printf("Welcome to this CLI Vector Editor !\n");
    printf("Please enter the size of your canvas (width height): \n");
    scanf("%d %d", &width, &height);
    fflush(stdin);

    Area *area = create_area(width, height);
    initialize_area(area);

    printf("Type \"help\" to see the available commands !\n");

    Command *cmd = create_command();
    while (1)
    {
        read_from_stdin(cmd);
        exec_command(cmd, area);
        clear_command(cmd);
    }

    return 0;
}
