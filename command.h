#include "area.h"

#define PARA_MAX 20
#define STR_MAX  50

typedef struct command
{
    char *name;

    int int_size;
    int *int_params;

    int str_size;
    char *str_params;
} Command;

Command *create_command();

void add_str_param(Command *cmd, char *p);
void add_int_param(Command *cmd, int p);
void free_cmd(Command *cmd);


int exec_command(Command *cmd, Area *area);
void read_from_stdin(Command *cmd);
void clear_command(Command *cmd);

int is_number(char *s);