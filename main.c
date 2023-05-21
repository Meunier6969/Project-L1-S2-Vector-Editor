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

    Command* cmd = NULL;
    while (1)
    {
        cmd = create_command();

        read_from_stdin(cmd);
        exec_command(cmd, area);
    }

    // delete_area(area);

    return 0;
}
