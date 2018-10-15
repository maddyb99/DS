#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;
void delete(NODE **,int);
void disp(NODE*);
NODE* create(NODE **);
NODE* insert(NODE *);
void insertbw(NODE *,int);
NODE* rev(NODE*);
void swap(NODE *);
void swapal(NODE*);
int palli(NODE*);
NODE*copy(NODE*);
void del(NODE*);
void main()
{
	NODE *start=NULL,*last=NULL;
	int opt,opt2,val;
	do{
		//system("cls");
		printf("\n1.  Create\n2.  Display\n3.  Insert\n4.  Delete\n5.  Reverse\n6.  Add\n7.  Rev fst lst\n8.  Rev alternate\n9.  Pallindrome\n10. Exit\nEnter Choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				last=create(&start);
				break;
			case 2:
				break;
			case 3:
				printf("\nInsert\n1. at begining\n2. in between\n3. at the end\nEnter choice: ");
				scanf("%d",&opt2);
				switch(opt2)
				{
					case 1:
						start=insert(start);
						break;
					case 2:
						printf("Enter value to insert at: ");
						scanf("%d",&val);
						insertbw(start,val);
						break;
					case 3:
						create(&last);
						break;
					default:
						printf("Incorrect choice!\nPress any key to continue...");
				}
				break;
			case 4:
				printf("Enter value to be deleted: ");
				scanf("%d",&val);
				delete(&start,val);
				break;
			case 5:
                start=rev(start);
                break;
            case 6:
                add(start);
                break;
            case 7:
                swap(start);
                break;
            case 8:
                swapal(start);
                break;
            case 9:
                if(palli(start))
                    printf("it is a pallindrome");
                else
                    printf("It is not a pallindorme");
                break;
            case 10:
				printf("Exitting...");
				return;
				break;
			default:
				printf("Incorrect choice!\nPress any key to continue...");
		}
		if(opt<9)
            disp(start);
	}while(opt!=10);
}
void delete(NODE **start,int val)
{
	NODE *prev=NULL,*s=*start;
	while(s!=NULL)
	{
		if(s->info==val)
		{
			if(prev==NULL)
				*start=s->next;
			else
				prev->next=s->next;
			free(s);
			return;
		}
		prev=s;
		s=s->next;
	}
	printf("Value not found");
}
void disp(NODE *s)
{	if (s==NULL)
	{
		printf("No list found!");
		return;
	}
	while(s!=NULL)
	{
		printf("%d  ",s->info);
		s=s->next;
	}
}

NODE* create(NODE **s)
{
	int n;
	NODE*newnode,*prev;
	printf("Enter number of values: ");
	scanf("%d",&n);
	while(n--)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("Enter info: ");
		scanf("%d",&(newnode->info));
		newnode->next=NULL;
		if(*s==NULL)
			*s=newnode;
		else
			prev->next=newnode;
		prev=newnode;
	}
	return (prev);
}
NODE* insert(NODE *s)
{
	int n;
	NODE*newnode,*prev=s;
	printf("Enter number of values: ");
	scanf("%d",&n);
	while(n--)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("Enter info: ");
		scanf("%d",&(newnode->info));
		newnode->next=prev;
		prev=newnode;
	}
	return(prev);
}
void insertbw(NODE *s,int val)
{
	int n;
	NODE*newnode,*prev;
	while(s->info!=val&&s!=NULL)
		s=s->next;
	prev=s;
	if(s==NULL)
	{
		printf("Value not found!");
		return;
	}
	printf("Enter number of values: ");
	scanf("%d",&n);
	while(n--)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("Enter info: ");
		scanf("%d",&(newnode->info));
		newnode->next=prev->next;
		prev->next=newnode;
	}
}

NODE* rev(NODE*start)
{
    NODE*prev=NULL,*cur=start,*next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

void add(NODE*s1)
{
    NODE *s2=NULL,*n1,*n2;
    create(&s2);
    do{
        n1=s1->next;

        n2=s2->next;
        if(n1!=NULL)
            s2->next=n1;
        s1->next=s2;
        s1=n1;
        s2=n2;
    }while(s1!=NULL&&s2!=NULL);
}

void swap(NODE * start)
{
    NODE*temp=start;
    for(;temp->next!=NULL;temp=temp->next);
    start->info+=temp->info;
    temp->info=start->info-temp->info;
    start->info=start->info-temp->info;
}

void swapal(NODE*start)
{
    while(start!=NULL&&start->next!=NULL)
    {
        start->info+=start->next->info;
        start->next->info=start->info-start->next->info;
        start->info=start->info-start->next->info;
        start=start->next->next;
    }
}
NODE*copy(NODE*start)
{
    NODE*newnode,*prev=NULL,*s;
    while(start!=NULL)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->info=start->info;
        if(prev==NULL)
        {
            s=newnode;
            prev=newnode;
        }
        newnode->next=NULL;
        prev->next=newnode;
        prev=newnode;
        start=start->next;
    }
    return s;
}
void del(NODE*start)
{
    NODE*temp;
    do{
        temp=start->next;
        free(start);
        start=temp;
    }while(temp!=NULL);
}
int palli(NODE*start)
{
    NODE*s=rev(copy(start));
    while(s!=NULL)
    {
        if(s->info!=start->info)
        {
            del(s);
            return 0;
        }
        s=s->next;
        start=start->next;
    }
    del(s);
    return 1;
}
