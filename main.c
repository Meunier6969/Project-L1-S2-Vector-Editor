#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "area.h"
#include "menu.h"
#include "command.h"

int main(int argc, char const *argv[]) 
{
    Area* area = create_area(32, 20);
    initialize_area(area);

    Command *cmd = create_command();
    while (1)
    {
        clear_command(cmd);

        read_from_stdin(cmd);
        exec_command(cmd, area);
    }

    // delete_area(area);

    return 0;
}
