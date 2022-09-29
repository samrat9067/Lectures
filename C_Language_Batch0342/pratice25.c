#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next = NULL;
}*head;

void insert(int n)
{
	struct Node *newNode,*temp;
	newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = n;

	if(head==NULL)
	{
		head = newNode;
	}
	else{

		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void serach(int n)
{
	struct Node *temp;

	int f =0;
	if(head==NULL)
		{
			printf("There is no data.....\n");
			return;
		}

		temp = head;

		while(temp!=NULL)
		{
			if(temp->data=n)
			{
				f =1;
				printf("Data is found %d\n",n);
			}
			temp = temp->next;
		}
		if(f==0){
			printf("data not found %d\n",n);
		}
}
void delete_me(int n)
{
	int f =0;
	struct Node *temp;

	temp = head;

	if(head==NULL)
		{
			printf("No data is found ... stack underflow...\n");
			return;
		}

		while(temp!=NULL)
		{
			if(temp->next->data==n)
			{
				f =1;
				printf("im in ..%d,%d\n",n,temp->data);
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}

		if(f=0)
		{
			printf("Data not found %d ...\n",n);
		}
		else{
			printf("delete ....\n");
		}
}

void display()
{
	struct Node *temp;

	if(head==NULL)
	{
		printf("There is no data \n");
	}
	else{
		temp = head;
		while(temp->next!=NULL)
		{
			printf("Data %d\n",temp->data);
			temp = temp->next;
		}
		printf("data %d\n",temp->data);
	}
}
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);

	delete_me(30);

	display();
}