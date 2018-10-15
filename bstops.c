#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct tnode
{
    int val;
    struct tnode*left,*right;
};
typedef struct tnode TNODE;
void create(TNODE**);
void push(TNODE **,int);
void inorder(TNODE*);
void preorder(TNODE*);
void postorder(TNODE*);
int height(TNODE*,int);
void main()
{
    int opt,opt2;
    TNODE *root=NULL;
    do{
        system("cls");
        printf("1. Create BST\n2. Traverse\n3. Height\n4. Exit\n\nEnter Choice:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: create(&root);
                    break;
            case 2: system("cls");
                    printf("\n2. Traverse\n\t1. Preorder\n\t2. Inorder\n\t3. Postorder\n0. Back to main menu\n\nEnter Choice: ");
                    scanf("%d",&opt2);
                    switch(opt2)
                    {
                        case 0:break;
                        case 1: preorder(root);
                                break;
                        case 2: inorder(root);

                                break;
                        case 3: postorder(root);
                                break;
                        default:printf("Incorrect choice!!");
                    }
                    if(opt2)
                    getch();
            case 3: printf("Height is: %d",height(root,0));
                    getch();
                    break;
            case 4:break;
            default: printf("Incorrect choice!");
                    getch();
        }
    }while(opt!=4);

}

void create(TNODE**root)
{
    int N,val;
    printf("Enter number of nodes: ");
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&val);
        push(root,val);
    }
    return;
}
void push(TNODE **r,int val)
{
    TNODE*newnode;
    if(*r==NULL)
    {
        newnode=(TNODE*)malloc(sizeof(TNODE));
        newnode->val=val;
        newnode->left=NULL;
        newnode->right=NULL;
        *r= newnode;
    }
    else if(val<(*r)->val)
        push(&((*r)->left),val);
    else
        push(&((*r)->right),val);
}

void inorder(TNODE *r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    printf("%d ",r->val);
    inorder(r->right);
}
void preorder(TNODE *r)
{
    if(r==NULL)
        return;
    printf("%d ",r->val);
    preorder(r->left);
    preorder(r->right);
}
void postorder(TNODE *r)
{
    if(r==NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->val);
}

int height(TNODE *r,int h)
{
    if(r==NULL)
        return h;
    int l,rt;
    l=height(r->left,h+1);
    rt=height(r->right,h+1);
    return((rt>l)?rt:l);
}
