#include"header.h"

qnode* front = NULL;
qnode* rear = NULL;

int find(node* root,node** parent,node** location,int item)
{
	if(NULL == root)
	{
		*location = NULL;
		*parent = NULL;
		return failure;
	}
	if(item == root->data)
	{
		*parent = NULL;
		*location = root;
		return success;
	}
	node* ptr;
	*parent = root;
	if(item < root->data)
		ptr = root->left;
	else
		ptr = root->right;
	while(NULL != ptr)
	{
		if(item == ptr->data)
		{
			*location = ptr;
			return success;
		}
		*parent = ptr;
		if(item < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*location = NULL;
	return failure;
}

int insert(node** root,int item)
{
	node* location = NULL,*parent = NULL;
	find(*root,&parent,&location,item);
	if(NULL != location)
	{
		printf("\nDuplicate Entry !\n");
		return failure;
	}
	node* new;
	new = (node*)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("\nMemory Allocation Faliure !\n");
		return failure;
	}
	new->data = item;
	new->left = NULL;
	new->right= NULL;
	if(NULL == parent)		//Tree is Empty
		*root = new;
	else
	{
		if(item < parent->data)
			parent->left = new;
		else
			parent->right = new;
	}
	return success;
}

int delete(node** root,int item)
{
	node* location = NULL, *parent = NULL;
	find(*root,&parent,&location,item);
	if(NULL == location)
	{
		printf("\nData does not Exist !\n");
		return failure;
	}
	if((NULL != location->left) && (NULL != location->right))
		delete_2_child(root,location,parent);
	else
		delete_1_child(root,location,parent);
	free(location);
	location = NULL;
	return success;
}

int delete_1_child(node** root,node* location,node* parent)
{
	node* child = NULL;
	if(NULL != location->left)
		child = location->left;
	else if(NULL != location->right)
		child = location->right;
	if(NULL == parent)		//If we're Deleting ROOt
		*root = child;
	else
	{
		if(location->data < parent->data)
			parent->left = child;
		else
			parent->right = child;
	}
	return success;
}

int delete_2_child(node** root,node* location,node* parent)
{
	node* successor,*parent_successor;
	parent_successor = location;
	successor = location->right;
	while(NULL != successor->left)
	{
		parent_successor = successor;
		successor = successor->left;
	}
	delete_1_child(root,successor,parent_successor);
	if(NULL == parent)
		*root = successor;
	else
	{
		if(location == parent->left)
			parent->left = successor;
		else
			parent->right = successor;
	}
	successor->left = location->left;
	successor->right = location->right;
}

int display(node* root,int space)
{
	if(NULL == root)
		return failure;
	space += 5;
	display(root->right,space);
	printf("\n");
	for(int i = 5;i<space;i++)
		printf(" ");
	printf("%d",root->data);
	display(root->left,space);
}

int preorder(node* root)		//NLR
{
	if(NULL == root)
		return failure;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

int inorder(node* root)			//LNR
{
	if(NULL == root)
		return failure;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

int postorder(node* root)		//LRN
{
	if(NULL == root)
		return failure;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);	
}

int levelorder(node* root)
{
	if(NULL == root)
		return failure;
	enque(&front,&rear,root);
	while(NULL != front)	
	{
		node* ptr;
		ptr = deque(&front,&rear);
		if(NULL != ptr->left)
			enque(&front,&rear,ptr->left);
		if(NULL != ptr->right)
			enque(&front,&rear,ptr->right);
	}		
}

int enque(qnode** front,qnode** rear,node* item)
{
	qnode *new;
	new = (qnode*) malloc(sizeof(qnode));
	if(NULL == new)
	{
		printf("\nMemory Allocation Faliure !\n");
		return failure;
	}
	new->element = item;
	new->next = NULL;
	if(NULL == *front)
	{
		*front = new;
		*rear = new;
	}
	else
	{
		(*rear)->next = new;
		*rear = new;
	}
	return success;
}

node* deque(qnode** front,qnode** rear)
{
	node *item;
	item = (*front)->element;
	if(NULL == *front)
		exit(-1);
	else if(*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
		*front = (*front)->next;
	printf("%d\t",item->data);
	return item;
}

int free_mem(node* root)
{
	node* ptr = root;
	if(NULL == ptr)
		return failure;
	free_mem(ptr->left);
	free_mem(ptr->right);
	free(ptr);
	ptr = NULL;	
}

