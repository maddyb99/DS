#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char val;
	struct stack *next;
};
typedef struct stack Stack;
void postfix();
void postfix();
char pop(Stack**);
void push(Stack**,int);
void convert(char[],char[]);
int priority(char ,char );
void display(Stack*);

int main()
{
    char PE[50],IF[50];
    printf("Enter expression: ");
    fflush(stdin);
    gets(IF);
    convert(IF,PE);
    printf("%s",PE);
    return 0;
}

void convert(char IF[],char PE[])
{
    Stack *s=NULL;
    int i,j;
    for(i=0,j=0;IF[i]!='\0';i++)
    {
        //  display(s);
        //printf("PE: %s\n",PE);
        if(IF[i]>='0'&&IF[i]<='9')
        {
            PE[j]=IF[i];
            j++;
            PE[j]='\0';
        }
        else if(IF[i]==')')
        {
            do{
                PE[j]=pop(&s);
                j++;
                PE[j]='\0';
            }while(s->val!='(');
            pop(&s);
        }
        else if(s==NULL||priority(IF[i],s->val))
            push(&s,IF[i]);

        else
        {
            PE[j]=pop(&s);
            j++;
            PE[j]='\0';
            i--;
        }
    }
    if(s!=NULL)
    {
        do{
            PE[j]=pop(&s);
            j++;
            PE[j]='\0';
        }while(s!='\0');
    }
}

void display(Stack *s)
{
    while(s!=NULL)
    {
        printf("%c ",s->val);
        s=s->next;
    }
    printf("\n");
}
char pop(Stack **s)
{
	/*if(*s==NULL)
	{	printf("Stack emptu");
		return 0;
	}*/
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

int priority(char a,char b)
{
    switch(b)
    {
        case'(':return 1;
        case'+':
        case '-':
            if(a=='+'||a=='-')
                return 0;
            else
                return 1;
        case'*':
        case'/':
            if(a=='*'||a=='/')
                return 0;
            else
                return 1;

    }
}
