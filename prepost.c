#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
	int val;
	struct stack *next;
};
typedef struct stack Stack;
void postfix();
void prefix();
int pop(Stack**);
void push(Stack**,int);
void main()
{
	int opt;
	do{
		printf("1. Evaluate prefix\n2. Evaluate postfix\n3. Exit\nEnter choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:	//prefix();
					break;
			case 2: postfix();
					break;
			case 3: break;
			default: printf("Incorrect choice!\n");
		}
	}while(opt!=3);
}

void postfix()
{
	char post[50];
	Stack *s=NULL;
	int op1,op2,i;
	printf("Enter postfix notation:");
	fflush(stdin);
	gets(post);
	//printf("%s",post);
	for(i=0;post[i]!='\0';i++)
	{
		//printf("%d",post[i]);
		if(post[i]>='0'&&post[i]<='9')
		{
			op1=post[i]-48;
			push(&s,op1);
		}
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			printf("%d %d\n");
			switch(post[i])
			{
				case '+':	push(&s,op1+op2);
							break;
				case '-':	push(&s,op1-op2);
							break;
				case '*':	push(&s,op1*op2);
							break;
				case '/':	push(&s,op1/op2);
							break;
			}
		}
	}
	printf("Answer is: %d",pop(&s));
}

int pop(Stack **s)
{
	if(*s==NULL)
	{//	printf("Stack emptu");
		return 0;
	}
	Stack*temp=*s;
	*s=(*s)->next;
	int r=temp->val;
	free(temp);
	return r;
}

void push(Stack**s,int v)
{
	Stack *new;
	new=(Stack*)malloc(sizeof(Stack));
	new->val=v;
	new->next=*s;
	*s=new;

}
