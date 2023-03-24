// BUFFER FUNCTION
void initialize_buffer(int **buffer, int width, int height);
void print_buffer(int **buffer, int height, int width);

// DRAW SHAPE TO BUFFER
void print_shape_to_buffer(int** buffer, Shape *shape);
void print_point_to_buffer(int **buffer, Point *p);
void print_line_to_buffer(int **buffer, Line *l);
void print_square_to_buffer(int **buffer, Square *s);
void print_rectangle_to_buffer(int **buffer, Rectangle *r);
void print_circle_to_buffer(int **buffer, Circle *c);
void print_polygon_to_buffer(int **buffer, Polygon *p);