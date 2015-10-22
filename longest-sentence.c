#include <string.h>
#include <stdio.h>

typedef struct node{
	char word[34];
	int len;
    struct node *left, *right;
}Node;


