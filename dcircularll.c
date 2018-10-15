#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next,*prev;
};
typedef struct node NODE;
void delete(NODE **,int);
void disp(NODE*);
void create(NODE **);
void insert(NODE *,int);
void inserts(NODE *);
void main()
{
	NODE *last=NULL;
	int opt,opt2,val;
	do{
		system("clear");
		printf("\n\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\nEnter Choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				create(&last);
				printf("List:");
				break;
			case 2:
				break;
			case 3:
				printf("\nInsert\n1. at begining\n2. in between\n3. at the end\nEnter choice: ");
				scanf("%d",&opt2);
				switch(opt2)
				{
					case 1:
						inserts(last);
						break;
					case 2:
						printf("Enter value to insert at: ");
						scanf("%d",&val);
						insert(last,val);
						break;
					case 3:
						create(&last);
						break;
					default:
						printf("Incorrect choice!\nPress any key to continue...");
				}
				printf("New list:");
				break;
			case 4:
				printf("Enter value to be deleted: ");
				scanf("%d",&val);
				delete(&last,val);
				printf("New list:");
				break;
			case 5:
				printf("Exitting...");
				break;
			default:
				printf("Incorrect choice!\nPress any key to continue...");
		}
		disp(last);
	}while(opt!=5);
}

void delete(NODE **last,int val)
{
	NODE *prev=*last,*l=(*last)->next;
	do{
		if(l->info==val)
		{
			if(l==*last)
				*last=prev;
			prev->next=l->next;
			free(l);
			return;
		}
		prev=l;
		l=l->next;
	}while(l!=(*last)->next);
	printf("Value not found");
}

void create(NODE **l)
{
	int n;
	NODE*newnode;
	printf("Enter number of values: ");
	scanf("%d",&n);
	while(n--)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("Enter info: ");
		scanf("%d",&(newnode->info));
		if(*l==NULL)
		{
		    newnode->next=newnode;
		    newnode->prev=newnode;
		}
		else
		{	newnode->next=(*l)->next;
			newnode->prev=(*l);
			(*l)->next->prev=newnode;
			(*l)->next=newnode;
		}
		*l=newnode;
	}
}


void disp(NODE*last)
{
	if (last==NULL)
	{
		printf("No list found!");
		return;
	}
	NODE*temp=last;
	do{
		printf("%d",last->next->info);
		last=last->next;
	}while(last!=temp);
}

void insert(NODE *l,int val)
{
	int n;
	NODE*last=NULL,*temp=l->next;
	do{
		temp=temp->next;
	}while(temp->info!=val&&temp!=l->next);
	if(temp==NULL)
	{
		printf("Value not found!");
		return;
	}
	l=temp->next;
	create(&last);
	l->prev=last;
	last->next->prev=temp;
	temp->next=last->next;
	last->next=l;
}


void inserts(NODE *l)
{
	NODE*last=NULL,*n=l->next;
	create(&last);
	n->prev=last;
	last->next->prev=l;
	l->next=last->next;
	last->next=n;
}

