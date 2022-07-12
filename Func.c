#include "Func.h"
int Add_to_list(node_river** node, const char* riverName, const char* riverCountry, int riverDepth, float length)
{
	int id = 0;
	node_river* new_node;
	node_river* indicator;
	// Create the first element of the linked list
	if (*node == NULL)
	{
		new_node = (node_river*)malloc(sizeof(node_river));
		// If memory allocation failed
		if (!new_node) {
			printf("Error! Not enough memory");
			exit(1);
		}
		// If the memory is allocated successfully, copy the entered data to the node
		new_node->id = 0;
		strncpy(new_node->riverName, riverName, 20);
		strncpy(new_node->riverCountry, riverCountry, 30);
		new_node->riverDepth = riverDepth;
		new_node->length = length;
		new_node->next = NULL;
		*node = new_node;
	}
	indicator = *node;
	while (indicator->next)
	{
		indicator = indicator->next;
		id++;
	}
	// Create the following nodes
	new_node = (node_river*)malloc(sizeof(node_river));
	if (!new_node) exit(1);
	new_node->id = id + 1;
	strncpy(new_node->riverName, riverName, 20);
	strncpy(new_node->riverCountry, riverCountry, 30);
	new_node->riverDepth = riverDepth;
	new_node->length = length;
	new_node->next = NULL;
	indicator->next = new_node;
	return length;
}

bool Write_data_to_file(node_river** node, const char* file)
{
	FILE* flp;
	if (!(flp = fopen(file, "w")))
		return false;
	node_river* indicator = *node;
	fprintf(flp, "River Name Country Depth Length\n");
	while (indicator)
	{
		fprintf(flp, "%d %s %s %d %f\n",
			indicator->id, indicator->riverName, indicator->riverCountry, indicator->riverDepth, indicator->length);
		indicator = indicator->next;
	}

}

// Clear stdin
int clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}