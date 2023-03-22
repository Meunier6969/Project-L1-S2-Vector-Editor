// SHAPE DEFINITION
typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON } Shape_Type;

typedef struct Shape
{
    int id;
    Shape_Type shape_type;
    void* ptrShape;
} Shape;

typedef struct Point
{
    int point_x;
    int point_y;
} Point;

typedef struct Line
{
    Point* point_1;
    Point* point_2;
} Line;

typedef struct Square 
{
    Point* origin;
    int lenght;
} Square;

typedef struct Rectangle
{
    Point* origin;
    int lenght;
    int width;
} Rectangle;

typedef struct Circle 
{
    Point* origin;
    int radius;
} Circle;

typedef struct Polygon
{
    int num_of_points;
    Point** points;
} Polygon;

// SHAPE FUNCTIONS
Shape* create_empty_shape(Shape_Type shape_type);

Shape* create_point_shape(int px, int py);
Shape* create_line_shape(int px1, int py1, int px2, int py2);
Shape* create_square_shape(int px, int py, int length);
Shape* create_rectangle_shape(int px, int py, int width, int height);
Shape* create_circle_shape(int px, int py, int radus);
Shape* create_polygon_shape(int lst[], int n);

void delete_shape(Shape *shape);

// CIRCLE
Point* create_point(int px, int py);
void delete_point(Point *point);
void print_point(Point *p);

// LINE
Line* create_line(Point *p1, Point *p2);
void delete_line(Line *line);
void print_line(Line *line);
