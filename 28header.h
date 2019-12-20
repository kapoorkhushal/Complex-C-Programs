#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

typedef struct device
{
	int device_id;
	char* device_type;
}device;

typedef struct presence
{
	int p_id;
	char *name;
	struct presence* next;
	device d;
}presence;

int getdata(presence*);
void insert(presence*,int,presence**);
void display(presence**);
void free_arr(presence*[]);
int free_chain(presence*);

