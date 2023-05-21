#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "command.h"

Command *create_command()
{
    Command* cmd = malloc(sizeof(Command));

    cmd->name = malloc(STR_MAX * sizeof(char));

    cmd->int_size = 0;
    cmd->int_params = malloc(PARA_MAX * sizeof(int));

    cmd->str_size = 0; // i have no idea what is this
    cmd->str_params = malloc(PARA_MAX * sizeof(char));

    return cmd;
}

void add_str_param(Command *cmd, char *p)
{
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

int exec_command(Command *cmd)
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

    }
    else if (strcmp(cmd->name, "line") == 0)
    {
    }
    else if (strcmp(cmd->name, "circle") == 0)
    {
    }
    else if (strcmp(cmd->name, "square") == 0)
    {
    }
    else if (strcmp(cmd->name, "rectangle") == 0)
    {
    }
    else if (strcmp(cmd->name, "polygon") == 0)
    {
    }
    else if (strcmp(cmd->name, "plot") == 0)
    {
    }
    else if (strcmp(cmd->name, "list") == 0)
    {
    }
    else if (strcmp(cmd->name, "delete") == 0)
    {
    }
    else if (strcmp(cmd->name, "erase") == 0)
    {
    }
    else if (strcmp(cmd->name, "help") == 0)
    {
    }
    else
    {
        printf("Unknown command.");
    }
    return 0;
}

void read_from_stdin(Command *cmd)
{
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
        if (is_number(token)) add_int_param(cmd, atoi(token)); // convert token to int
        add_str_param(cmd, token); // the type is wwong D: nweed to fwix uwu
    }
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
