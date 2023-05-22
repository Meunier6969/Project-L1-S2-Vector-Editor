#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "command.h"
#include "area.h"
#include "shapes.h"

Command *create_command()
{
    Command* cmd = malloc(sizeof(Command));

    cmd->name = malloc(STR_MAX * sizeof(char));

    cmd->int_size = 0;
    cmd->int_params = malloc(PARA_MAX * sizeof(int));
    cmd->str_size = 0; // i have ~~no~~ one (1) idea what is this
    cmd->str_params = malloc(PARA_MAX * sizeof(char));

    return cmd;
}

void add_str_param(Command *cmd, char *p)
{
    cmd->str_size++;
    // ???
}

void add_int_param(Command *cmd, int p)
{
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command *cmd)
{
    free(cmd->name);

    cmd->int_size = 0;
    free(cmd->int_params);

    cmd->str_size = 0;
    // for (size_t i = 0; i < PARA_MAX; i++)
    
    free(cmd->str_params);

    free(cmd);
}

int exec_command(Command *cmd, Area* area)
{
    // Return 1 in case of an unknown command,
    // return 0 otherwise

    if (cmd->name == NULL)
    {
        printf("Unknown command\n");
        return 1;
    } 
    else if (strcmp(cmd->name, "clear") == 0)
    {
        system("cls");
    }
    else if (strcmp(cmd->name, "exit") == 0)
    {
        delete_area(area);
        exit(0);
    }
    else if (strcmp(cmd->name, "point") == 0)
    {
        Shape *p = create_point_shape(cmd->int_params[0], cmd->int_params[1]);
        add_shape_to_area(area, p);
    }
    else if (strcmp(cmd->name, "line") == 0)
    {
        Shape *l = create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_area(area, l);
    }
    else if (strcmp(cmd->name, "circle") == 0)
    {
        Shape *c = create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
        add_shape_to_area(area, c);
    }
    else if (strcmp(cmd->name, "square") == 0)
    {
        Shape *s = create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
        add_shape_to_area(area, s);
    }
    else if (strcmp(cmd->name, "rectangle") == 0)
    {
        Shape *r = create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_area(area, r);
    }
    else if (strcmp(cmd->name, "polygon") == 0)
    {
        if (cmd->int_size % 2 == 1 || cmd->int_size == 0)
            printf("Not the right number of points\n");
        else
        {
            int *list = malloc(cmd->int_size * sizeof(int));

            for (size_t i = 0; i < cmd->int_size; i++)
            {
                list[i] = cmd->int_params[i];
            }

            Shape *pl = create_polygon_shape(list, cmd->int_size/2);
            add_shape_to_area(area, pl);
        }
    }
    else if (strcmp(cmd->name, "plot") == 0)
    {
        initialize_area(area);
        draw_shapes_to_area(area);
        print_area(area);
    }
    else if (strcmp(cmd->name, "list") == 0)
    {
        list_shapes(area);
    }
    else if (strcmp(cmd->name, "delete") == 0)
    {
        delete_shape_from_area(area, cmd->int_params[0]);
    }
    else if (strcmp(cmd->name, "erase") == 0)
    {
        initialize_area(area);
        delete_all_shapes(area);
    }
    else if (strcmp(cmd->name, "help") == 0)
    {
        printf("___ CLI Vector Editor ___\n");
        printf("help : Show this menu\n");
        printf("clear : Clear the screen\n");
        printf("exit : Exit the program\n");
        printf("plot : Print the drawing\n");
        printf("list : List all the shapes in the drawing\n");
        printf("delete id : Remove a shape from the drawing\n");
        printf("erase : Remove all shapes from the drawing\n");
        printf("___ Drawing Shapes ___\n");
        printf("point y x : Draw a point at coordinates y x\n");
        printf("line x1 y1 x2 y2 : Draw a line connecting (x1, y1) and (x2, y2)\n");
        printf("circle x y rad : Draw a circle of centre (x, y) and a rad\n");
        printf("square x y len : Draw a square at (x, y) and of side lenght len\n");
        printf("rectangle x y wid hei : Draw a rectangle at (x, y), whose width is wid and whose height is hei\n");
        printf("polygon x1 y1 x2 y2... ... : Draw a polygon with the list of given points\n");
    }
    else
    {
        printf("Unknown command\n");
        return 1;
    }

    return 0;
}

void read_from_stdin(Command *cmd)
{
    clear_command(cmd);

    char* command = malloc(STR_MAX * sizeof(char));
    printf("> ");
    fgets(command, STR_MAX, stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing '\n'

    // Get the name
    char *token = strtok(command, " -");
    cmd->name = token;

    while (token != NULL)
    {
        token = strtok(NULL, " -");
        if (token == NULL) break;

        if (is_number(token)) 
            add_int_param(cmd, atoi(token));
        else 
            add_str_param(cmd, token);
    }
}

void clear_command(Command *cmd)
{
    cmd->name = NULL;
    cmd->int_size = 0;
    // cmd->int_params = NULL;
    
    cmd->str_size = 0;
    // cmd->str_params = NULL;
}

int is_number(char* s)
{
    if (s == NULL)
        return 0;

    char c = s[0];
    if (!(isdigit(c) || c == '-'))
        return 0;

    int i = 1;
    c = s[1];
    while (c != '\0')
    {
        if (!isdigit(c))
            return 0;

        i++;
        c = s[i];
    }

    return 1;
}
