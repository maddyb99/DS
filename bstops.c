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
TNODE* del(TNODE*,int);
TNODE*insuc(TNODE*);
void main()
{
    int opt,opt2;
    TNODE *root=NULL;
    do{
        system("cls");
        printf("1. Create BST\n2. Auto create BST\n3. Traverse\n4. Height\n5. Delete\n6. Exit\n\nEnter Choice:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: create(&root);
                    break;
            case 2: autocreate(&root);
                    break;
            case 3: system("cls");
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
                    break;
            case 4: printf("Height is: %d",height(root,0));
                    getch();
                    break;
            case 5: printf("Enter node to be deleted: ");
                    scanf("%d",&opt2);
                    del(root,opt2);
                    getch();
                    break;
            case 6:break;
            default: printf("Incorrect choice!");
                    getch();
        }
    }while(opt!=6);

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
void autocreate(TNODE**root)
{
    int N,val;
    FILE *fp;
    fp=fopen("E:\\Users\\Madhav\\Documents\\2nd Year\\DS\\tree.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&val);
        push(root,val);
    }
    fclose(fp);
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

TNODE* del(TNODE *r,int val)
{
    printf("%d",r->val);
    TNODE*temp;
    int temp2;
    if(r==NULL)
    {
        printf("Val not found");
        return NULL;
    }
    if(r->val==val)
    {
        printf("found");
        if(r->left==NULL&&r->right==NULL)
            return NULL;
        else if(r->left==NULL&&r->right!=NULL)
            return r->right;
        else if(r->left!=NULL&&r->right==NULL)
        {
            printf("mycase");
            return r->left;
        }
        else
        {
            temp=insuc(r->right);
            temp2=temp->val;
            del(r,temp->val);
            r->val=temp2;
            return r;
        }
    }
    else if(r->val>val)
        r->left=del(r->left,val);
    else
        r->right=del(r->right,val);
    return r;
}
TNODE*insuc(TNODE*r)
{
    if(r->left==NULL)
        return r;
    return(insuc(r->left));
}
