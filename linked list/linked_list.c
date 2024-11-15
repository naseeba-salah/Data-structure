#include<stdio.h>
#include<stdlib.h>

// Node structure

struct Node
{
	int data;
	struct Node *link;
};
struct Node *header=NULL;

//Create Node

struct Node *CreateNode(int data)
{
	struct Node *newnode;
	newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->link=NULL;
	return(newnode);
}

//insertion at front

void insertAtFront(int data)
{
	//call create node function
	struct Node *newnode;
	newnode=CreateNode(data);
	if(header==NULL)           //check it is the first node in the list
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
		
	}
}

//Insert at end of the linked list

void insertAtLast(int data)
{
	struct Node *ptr;
	struct Node *newnode;
	ptr=header->link;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	newnode=CreateNode(data);
	newnode->data=data;
	newnode->link=NULL;
	ptr->link=newnode;
}

// Insert at any

void insertAtAny(int data)
{
	struct Node *ptr;
	struct Node *newnode;
	ptr=header;
	while((ptr!=NULL)&&(ptr->data!=data))
	{
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("key not found insertion not possible");
	}
	newnode=CreateNode(data);
	newnode->link=ptr->link;
	ptr->link=newnode;
	newnode->data=data;
}

//Traversal

void traverseList()
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d", ptr->data);
		ptr=ptr->link;
	}
	printf("\n");

}

// deletion at first

void deleteAtFront()
{
	struct Node *ptr;
	
	if(header==NULL)
	{
		printf("list is empty");
	}
	else{
		ptr=header;
		header=header->link;
		free(ptr);
	}
}
// deletion at end

void deleteAtEnd()
{
	if(header==NULL)
	{
		printf("list is empty");
	}
	else
	{
		struct Node *ptr;
		struct Node *ptr1;
		ptr=header;
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=NULL;
		free(ptr);
	}
}

int main()
{
	
	//struct Node *node;

	insertAtFront(10);
	insertAtFront(20);
	insertAtLast(30);
	insertAtAny(10);
	traverseList();
	deleteAtFront();
	traverseList();
	deleteAtEnd();
	traverseList();
	return(0);

}
