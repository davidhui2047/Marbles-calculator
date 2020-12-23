// KIT107 Assignment 2
/*
* assig_two219
* Managing a club's collection of marbles,
* Analysing the data and illustrate various distributions
* Author Julian Dermoudy and <<Chiu Fan Hui, 497790>>
* Version <<16/09/2019>>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "marble.h"
#include "node.h"


// Symbols
#define NUM_MEMBERS 7 //total number of member


// Types
typedef node collection;

// structure of member
typedef struct {
	char *name; // name of member
	collection marbles; // marbles of member
} member;

// declare an array call member
typedef member members[NUM_MEMBERS];


// Constants
const char *MEMBERS[] = { "Scott", "Malcolm", "Tony", "Kevin", "Julia", "John", "Paul" }; // list of member
const int INVALID = -1; // invalid member


// Global Variables
members club; // store member's detail
int invalid = 0; // amount of invalid marbles 


/*
* get_member
* takes a member name, locates it in the MEMBERS array
* returns its index (or -1 if it is not present)
* @param member member's name
* @return i index of member
* @return INVALID invalid member
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
int get_member(char *member)
{

	// read all the member
	for (int i = 0; i < NUM_MEMBERS; i++)
	{
		// If the member is one of the list of member, then returns its index
		if (strcmp(member, MEMBERS[i]) == 0)
		{
			return i;
		}
	}

	return INVALID; // the person is not one of the member
}

/*
* add_existing
* adding marble to an non-empty collection of a particular member
* @param *l collection of marbles
* @param e an merble
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
void add_existing(collection *l, marble e)
{
	marble next_marble; // the next marble
	marble new_marble; // the new marble
	node pos_previous_marble; // position of previous marble
	node pos_next_marble; // position of next marble
	node pos_new_marble; // position of the new marble
	bool exit; // exit the loop

	init_node(&pos_new_marble, e);
	pos_next_marble = *l; // assign collection to position of next marble
	pos_previous_marble = NULL; // initilise position of previous marble
	exit = false; // initilise exit the loop
	new_marble = (marble)get_data(pos_new_marble); // initilise data of the new marble

	// determine new marble position depend on its diameter 
	while ((!exit) && (pos_next_marble != NULL))
	{
		next_marble = (marble)get_data(pos_next_marble);

		if (get_diameter(next_marble) < get_diameter(new_marble))
		{
			pos_previous_marble = pos_next_marble;
			pos_next_marble = get_next(pos_next_marble);
		}
		else
		{
			exit = true;
		}
	}

	// put the new marble into the correct position 
	if (pos_previous_marble == NULL)
	{
		*l = pos_new_marble;
		set_next(pos_new_marble, pos_next_marble);
	}
	else
	{
		set_next(pos_previous_marble, pos_new_marble);
		if (pos_next_marble != NULL)
		{
			set_next(pos_new_marble, pos_next_marble);
		}
	}

}


/*
* add_marble
* adding a marble to particular member
* @param member name of a member
* @param a_marble a marble
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
void add_marble(char *member, marble a_marble)
{
	node node; // create a new node
	int pos_member; // position of member

	pos_member = get_member(member); // initilise position of member

	// check how many marbles are invalid
	if (pos_member == INVALID)
	{
		invalid++;
	}
	// marble belongs to one of the member
	else
	{
		if (club[pos_member].name == NULL)
		{
			init_node(&node, a_marble);
			club[pos_member].name = member;
			club[pos_member].marbles = node;
		}
		else
		{
			add_existing(&(club[pos_member].marbles), a_marble);
		}
	}

}

/*
* read_in_data
* read the data in marbles.txt
* Author Julian Dermoudy
*/
void read_in_data()
{
	const char *FILENAME = "marbles.txt";

	char *member;
	double diameter;
	material made_of;
	content look;
	int new;

	FILE *fp;

	marble a_marble;
	//int limit = 10; // delete me
	//int count = 0;  // delete me

	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	else
	{
		//printf("no problem\n");
		member = (char *)malloc(30 * sizeof(char));
		while (fscanf(fp, "%[^,],%lf,%d,%d,%d\n", member, &diameter, &made_of, &look, &new) != EOF)
		{
			//printf("count is %d\n",count++);
			//count++;
			init_marble(&a_marble, diameter, made_of, look, (bool)new);
			//if (count<=limit)
			//{
				//printf("%s: %s\n", member, to_string(a_marble));
				//printf("calling add_marble\n");
			add_marble(member, a_marble);
			//printf("add_marble called\n");
		//}
		//printf("endif\n");
			member = (char *)malloc(30 * sizeof(char));
			//printf("new loop\n");
		}
	}
	fclose(fp);
}

/*
* process_category
* count the number of specified marble of each member
* @param head a collection of marbles for a particular member
* @param cat a letter indicating which category should be processed
* @param val an ‘int’ indicating which value in the category the processing should occur for
* @return data data of marble
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
int process_category(collection head, char cat, int val)
{
	node element; // one of the node of list
	int data; // data of marble

	element = head; // initilise one of the node of list
	data = 0; // initilise data of marble

	// calculate the data that user need
	while (element != NULL)
	{
		switch (cat)
		{
			case 't':	data++;
						break;
			case 'm':	if (get_material(get_data(element)) == val)
						{
							data++;
						}
						break;
			case 'c':	if (get_look(get_data(element)) == val)
						{
							data++;
						}
						break;
			default:	if (get_age(get_data(element)) == val)
						{
							data++;
						}
		}
		element = get_next(element);
	}

	return data;
}

/*
* show_graph
* show a final graph
* @param cat a letter
* @param desc a string description of the output to be displayed
* @param val a value for the category
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
void show_graph(char cat, char *desc, int val)
{
	int data; // data of marble
	char *champion_name = ""; // name of the champion
	int champion_data; // data of the champion

	printf("\t\t\t\t\tMarbles -- %s\n\n\n", desc);

	champion_data = 0; // Initialise data of the champion

	// print the result
	for (int i = 0; i < NUM_MEMBERS; i++)
	{
		data = process_category(club[i].marbles, cat, val);
		printf("%10s | ", club[i].name);

		for (int k = 0; k < data / 25; k++)
		{
			printf("*");
		}

		printf("\t\t%4d\n", data);

		if (data > champion_data)
		{
			champion_name = club[i].name;
			champion_data = data;
		}
	}

	printf("\nInvalid marbles: %d\n\n\n", invalid);
	printf("And the most common member for %s of marbles is......%s!\n\n\n", desc, champion_name);
}

/*
* main
* Entry Point
* Author Chiu Fan Hui, 497790
* Version <<16/09/2019>>
*/
int main(int argc, char *argv[])
{
	// Initialise club variable
	for (int i = 0; i <= NUM_MEMBERS; i++)
	{
		club[i].name = NULL; // assign the name of member to null
		club[i].marbles = NULL; // assign the marbles of member to null
	}

	// Read in collection
	read_in_data();

	// Display histograms
	show_graph('t', "total number of", INVALID);
	show_graph('m', "glass", glass);
	show_graph('m', "wooden", wooden);
	show_graph('m', "plastic", plastic);
	show_graph('c', "solid colour", plain);
	show_graph('c', "swirled colour", swirled);
	show_graph('c', "cats_eye pattern", cats_eye);
	show_graph('a', "old", false);
	show_graph('a', "new", true);
}