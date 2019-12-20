#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

typedef struct hash
{
	char *name;
	struct hash *next;
}hash;

int string_add(char*);
void insert(char*,int,hash**);
void display(hash**);
void free_arr(hash*[]);
int free_chain(hash*);
