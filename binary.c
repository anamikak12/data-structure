#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild,*rchild;
};
void main()
{
struct node *insert(struct node*,int);
struct node *search(struct node*,int);
struct node *delete(struct node*,int);
void inorder(struct node*);
struct node *root=0;
int opt,data;
do
{
printf("\n 1insert\n 2.delete\n 3.search\n 4.inorder traversal\n 5.exit\n");
printf("enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter your item:");
       scanf("%d",&data);
      root=insert(root,data);
      break;
case 2:if(root==NULL) 
       printf("BST is empty..");
       else
       {
       printf("enter data to delete:");
       scanf("%d",&data);
       root=delete(root,data);
       if(root==NULL)
       printf("BST is empty..");
       }
       break;
case 3:printf("enter data to search:");
       scanf("%d",&data);
       if(search(root,data)!=0)
       printf("%d found in BST",data);
       else
        printf("%d not found in BST",data); 
        break;
case 4:if(root==NULL)
       printf("BST is empty..\n");
       else
       {
       printf("inorder traversal:");
       inorder(root);
       }
       break;
case 5:exit(0);
break;
}
}
while(9);
}//finction to search an item in bst
struct node *search(struct node *root,int data)
{                               
while(root!=0 && root->data!=data)
if(data<root->data)
root=root->lchild;
else
root=root->rchild;
return root;
} //function to insert an item
struct node *insert(struct node *root,int data)
{
struct node *t,*par=0,*t1;
t=(struct node*)malloc(sizeof(struct node*));
t->data=data;
t->lchild=t->rchild=0;
if(root==0)
root=t;
else if(search(root,data)!=0)
printf("%d is duplicate",data);
else
{
t1=root;
while(t1!=0) // finding inserting location
{
par=t1;
if(data<t1->data) //inserting
t1=t1->lchild;
else
t1=t1->rchild;
}
if(data<par->data)
par->lchild=t;
else
par->rchild=t;
}
return root;
}//function to display BST inorder
void inorder(struct node *root)
{
if(root !=0)
{
inorder(root->lchild);
printf("%d ",root->data);
inorder(root->rchild);
}
} //function to delete a node
struct node *delete(struct node *root,int data)
{
struct node *t=root,*par=0,*suc,*sucpar;
while(t!=0 && t->data!=data)//searching data
{
par=t;
if(data<t->data)
t=t->lchild;
else
t=t->rchild;
}
if(t==0)
printf("%d not found...",data);
else
{
if(t->lchild==0 && t->rchild==0)
{
if(par==0)
root=0;
else if(data<par->data)
par->lchild=0;
else
par->rchild=0;
}
else if(t->lchild==0 || t->rchild==0)
{
if(par==0)
root=root->lchild==0 ? root->rchild:root->lchild;
else if(data<par->data)
par->lchild =t->lchild==0 ? t->rchild:t->lchild;
else
par->rchild =t->lchild==0 ? t->rchild:t->lchild;
}
else
{
sucpar=t;
suc=t->rchild;
while(suc->lchild!=0)//finding inorder success
{
sucpar=suc;
suc=suc->lchild;
}
t->data=suc->data;
if(suc->data<sucpar->data)
sucpar->lchild=suc->rchild;
else
sucpar->rchild=suc->rchild;
t=suc;
}
free(t);
}
return root;
}
