#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main()
{
int opt,data,found;
for(;;)
{
printf("\n1.push\n 2.pop\n 3.display\n 4.search\n 5.exit\n");
printf("enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter elements to insert:");
scanf("%d",&data);
sp=push(sp,data);
break;
case 2: if(sp==NULL)
printf("stack is empty!");
else{
sp=pop(sp,&data);
printf("poped element is :%d\n",data);
}
break;
case 3:
display(sp);
break;
case 4:
printf("enter elements to be searched:");
scanf("%d",&data);
found=search(sp,data);
if(found!=0)
printf("the element is found %d \n",data);
else
printf("%d not found\n",data);
break;
case 5:
exit(0);
break;
}}
return 0;
}
struct node *push(struct node *sp,int data)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;
}
struct node *pop(struct node *sp,int *x)
{
struct node *temp;
if(sp!=NULL)
{
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);
}
return sp;
}
void display(struct node *sp)
{
if(sp==NULL)
{
printf("stack is empty!..");
return;
}
printf("stack elements are:\n");
while(sp!=NULL)
{
printf("%d\n",sp->data);
sp=sp->next;
}
}
int search(struct node *sp,int data)
{
while(sp!=NULL)
{
if(sp->data==data)
return 1;
sp=sp->next;}
return 0;
}
