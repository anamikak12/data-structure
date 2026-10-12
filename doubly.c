#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
int main()
{
struct node *list=(struct node *)0;
struct node  *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *search(struct node *,int);
void display(struct node *);
struct node *start=(struct node *)0;
int item,opt;
while(1)
{
printf("\n1.insert \n2.delete \n3.search \n4.display \n5.exit");
printf("\nenter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:
     printf("item to insert:");
     scanf("%d",&item);
     start=insert(start,item);
     break;
case 2:
     printf("item to delete:");
     scanf("%d",&item);
     start=delete(start,item);
     break; 
case 3:
     printf("item to search:");
     scanf("%d",&item);
     if(search(start,item)==(struct node*)0)
     printf("item not found\n");
else
printf(" item found\n");
break;
case 4:
display(start);
break;
case 5:
exit(0);
}
}
}//function to insert an item into a doubly linkedlist
struct node * insert(struct node *s, int data)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->left=(struct node *)0;
t->right=s;
if(s!=0)
s->left=t;
return t;
}
void display(struct node *s)
{
if(s==0)
{
printf("\nlist is empty...");
return;
}
printf("\n list elements are:");
while(s!=0)
{
printf("%d\t",s->data);
s=s->right;
}
printf("\n");
return ;
}
struct node* search(struct node*s,int data)
{
while(s!=0 && data != s-> data)
s=s->right;
return s;
}
struct node* delete(struct node*s,int data)
{
struct node *t;
t=search(s,data);
if(t==0)
printf("do not found!\n");
else if(t->left==0)
{
s=s->right;
if(t->right!=0)
s->left=0;
}
else
t->left->right=t->right;
if(t->right!=0)
t->right->left=t->left;
free(t);
return s;
}  

