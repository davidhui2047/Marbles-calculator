// KIT107 Assignment 2
/*
* Specification for the marble ADT
* Author Julian Dermoudy
* Version 19/8/19
*
* THIS FILE IS COMPLETE
*/

#ifndef MARBLE_H
#define MARBLE_H

#include <stdbool.h>

typedef enum { plain, swirled, cats_eye } content;
typedef enum { glass, wooden, plastic } material;

struct marble_int;
typedef struct marble_int *marble;

void init_marble(marble *e, double d, content c, material m, bool n);
double get_diameter(marble e);
content get_look(marble e);
material get_material(marble e);
bool get_age(marble e);
void set_diameter(marble e, double d);
void set_look(marble e, content c);
void set_material(marble e, material m);
void set_age(marble e, bool n);
char *to_string(marble e);


#endif