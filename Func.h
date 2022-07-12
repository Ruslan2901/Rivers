#ifndef FUNCTIONSDESCRIPTION_H
#define FUNCTIONSDESCRIPTION_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node {
	int id;
	char* riverName[20];
	char* riverCountry[30];
	int riverDepth;
	float length;
	struct node* next;
} node_river;

/**
* Add an entry to the list
*
* @param node node_river**
* @param riverName const char*
* @param riverRegion const char* 
* @param riverDepth int
* @param length float
*/
int Add_to_list(node_river** node, const char* riverName, const char* riverRegion, int riverDepth, float length);

/**
* Clear stdin
*
* @param none
* @return none
*/
int clear_stdin();

/**
* Write data to file
*
* @param node node_river**
* @param file const char*
* @return Óñï³õ îïåðàö³¿
*/
bool Write_data_to_file(node_river** node, const char* file);

#endif