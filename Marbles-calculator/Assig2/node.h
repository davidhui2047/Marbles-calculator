// KIT107 Assignment 2
/*
* Specification for the node ADT
* Author Chiu Fan Hui, 497790
* Version 16/09/2019
*/

#ifndef NODE_H
#define NODE_H

struct node_int;
typedef struct node_int *node;

void init_node(node *nd, void *item);
void set_data(node nd, void *item);
void *get_data(node nd);
void set_next(node nd1, node nd2);
node get_next(node nd);

#endif 