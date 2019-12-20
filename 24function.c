#include"header.h"

int find(node* root,node** parent,node** location,char* item)
{
	if(NULL == root)
	{
		*location = NULL;
		*parent = NULL;
		return failure;
	}
	if(0 == strcmp(item,root->name))
	{
		*parent = NULL;
		*location = root;
		return success;
	}
	node* ptr;
	*parent = root;
	if(0 > strcmp(item,root->name))
		ptr = root->left;
	else
		ptr = root->right;
	while(NULL != ptr)
	{
		if(0 == strcmp(item,ptr->name))
		{
			*location = ptr;
			return success;
		}
		*parent = ptr;
		if(0 > strcmp(item,ptr->name))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*location = NULL;
	return failure;
}

int insert(node** root,char* item)
{
	node* location = NULL,*parent = NULL;
	find(*root,&parent,&location,item);
	if(NULL != location)
	{
		printf("\nDuplicate Entry : %s\n",item);
		return failure;
	}
	node* new;
	new = (node*)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("\nMemory Allocation Faliure !\n");
		return failure;
	}
	new->name = (char*)malloc(sizeof(char)*strlen(item));
	strcpy(new->name,item);
	new->left = NULL;
	new->right= NULL;
	if(NULL == parent)		//Tree is Empty
		*root = new;
	else
	{
		if(0 > strcmp(item,parent->name))
			parent->left = new;
		else
			parent->right = new;
	}
	return success;
}

int insert_file(node* root,FILE *fp)
{
	if(NULL == root)
		return failure;
	insert_file(root->left,fp);
	fputs(root->name,fp);
	fputs("\n",fp);
	insert_file(root->right,fp);
}

int free_mem(node* root)
{
	node* ptr = root;
	if(NULL == ptr)
		return failure;
	free_mem(ptr->left);
	free_mem(ptr->right);
	free(ptr->name);
	free(ptr);
	ptr = NULL;	
}

