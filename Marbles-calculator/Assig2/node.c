//KIT107 Assignment 2
/*
* Implementation for node
* Author Chiu Fan Hui, 497790
* Version 16/09/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node_int
{
	void *data;
	node next;
};

/*
* 'Constructor' for node
*/
void init_node(node *nd, void *item)
{
	*nd = (node)malloc(sizeof(struct node_int));
	(*nd)->data = item;
	(*nd)->next = NULL;
}

/*
* Setter for look
* Param item value to be placed into the node's data field
*/
void set_data(node nd, void *item)
{
	nd->data = item;
}

/*
* Getter for data
* Return data field
*/
void *get_data(node nd)
{
	return (nd->data);
}

/*
* Setter for next
* Param nd2 value to be placed into the node's next field
*/
void set_next(node nd1, node nd2)
{
	nd1->next = nd2;
}

/*
* Getter for next
* Return next field
*/
node get_next(node nd)
{
	return (nd->next);
}