#include "shapes.h"

#define SHAPE_MAX 100

// AREA DEFINTION
typedef struct area
{
    unsigned int width;
    unsigned int height;

    int **mat;

    Shape **shapes; // List of pointers to Shapes
    int nb_shape;
} Area;

// AREA FUNCTIONS
Area *create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area *area, Shape *shape);
void initialize_area(Area *area);
void erase_area(Area *area);
void delete_area(Area *area);
void draw_shapes_to_area(Area *area);
void print_area(Area *area);

void list_shapes(Area *area);