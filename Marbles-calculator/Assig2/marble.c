// KIT107 Assignment 2
/*
* Implementation for marble
* Author Julian Dermoudy
* Version 2/4/18
*
* THIS FILE IS COMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include "marble.h"


struct marble_int {
	double diameter;
	content look;
	material made_of;
	bool new;
};


/*
* 'Constructor' for marble
*/
void init_marble(marble *e, double d, content c, material m, bool n)
{
	*e = (marble)malloc(sizeof(struct marble_int));
	(*e)->diameter = d;
	(*e)->look = c;
	(*e)->made_of = m;
	(*e)->new = n;
}

/*
* Getter for diameter
* Return diameter field
*/
double get_diameter(marble e)
{
	return (e->diameter);
}

/*
* Getter for look
* Return look field
*/
content get_look(marble e)
{
	return (e->look);
}

/*
* Getter for made_of
* Return made_of field
*/
material get_material(marble e)
{
	return (e->made_of);
}

/*
* Getter for age
* Return new field
*/
bool get_age(marble e)
{
	return (e->new);
}

/*
* Setter for diameter
* Param v value to be placed into the marble's diameter field
*/
void set_diameter(marble e, double v)
{
	e->diameter = v;
}

/*
* Setter for look
* Param c value to be placed into the marble's look field
*/
void set_look(marble e, content c)
{
	e->look = c;
}

/*
* Setter for made_of
* Param m value to be placed into the marble's made_of field
*/
void set_material(marble e, material m)
{
	e->made_of = m;
}

/*
* Setter for age
* Param a value to be placed into the marble's new field
*/
void set_age(marble e, bool a)
{
	e->new = a;
}

/*
* Display function
* Param e marble to be displayed
* Return e formatted as a string
*/
char *to_string(marble e)
{
	const char *contents[] = { "plain", "swirled", "cats-eye" };
	const char *materials[] = { "glass", "wooden", "plastic" };
	const char *ages[] = { "old", "new" };

	char *r = (char *)malloc(100 * sizeof(char));

	sprintf(r, "a/n %s %s patterned %s marble of diameter %3.1lfcm", ages[e->new], contents[e->look], materials[e->made_of], e->diameter);
	return r;
}