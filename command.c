#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "command.h"
#include "menu.h"
#include "area.h"
#include "shapes.h"

Command *create_command()
{
    Command* cmd = malloc(sizeof(Command));

    cmd->name = malloc(STR_MAX * sizeof(char));

    cmd->int_size = 0;
    cmd->int_params = calloc(PARA_MAX, sizeof(int));

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
    if (strcmp(cmd->name, "clear") == 0)
    {
        system("cls");
    }
    else if (strcmp(cmd->name, "exit") == 0)
    {
        // Free everything
        exit(0);
    }
    else if (strcmp(cmd->name, "point") == 0)
    {
        Shape *p = create_point_shape(cmd->int_params[0], cmd->int_params[1]);
        add_shape_to_area(area, p);
    }
    else if (strcmp(cmd->name, "line") == 0)
    {
        printf("create line\n");
    }
    else if (strcmp(cmd->name, "circle") == 0)
    {
        printf("create circle\n");
    }
    else if (strcmp(cmd->name, "square") == 0)
    {
        printf("create square\n");
    }
    else if (strcmp(cmd->name, "rectangle") == 0)
    {
        printf("create rectangle\n");
    }
    else if (strcmp(cmd->name, "polygon") == 0)
    {
        printf("create polygon\n");
    }
    else if (strcmp(cmd->name, "plot") == 0)
    {
        draw_shapes_to_area(area);
        print_area(area);
    }
    else if (strcmp(cmd->name, "list") == 0)
    {
        list_shapes(area);
    }
    else if (strcmp(cmd->name, "delete") == 0)
    {
        printf("delete a shape by id\n");
    }
    else if (strcmp(cmd->name, "erase") == 0)
    {
        initialize_area(area);
        delete_all_shpaes(area);
    }
    else if (strcmp(cmd->name, "help") == 0)
    {
        printf("ああああああああああああああああああああああああああああ\n");
    }
    else
    {
        printf("Unknown command.");
    }
    return 0;
}

// TO FIX: After using erase, creating a point make the program crash

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
        {   
            add_int_param(cmd, atoi(token));
        }

        else add_str_param(cmd, token);
    }
}

void clear_command(Command *cmd)
{
    cmd->name = NULL;
    cmd->int_size = 0;
    cmd->int_params = NULL;
    
    cmd->str_size = 0;
    cmd->str_params = NULL;
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
