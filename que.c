#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front=0,rear=0;
void main()
{
void enqueue(int);
int dequeue(),opt,item;
void display();
do
{
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("enter Your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1: printf("Enter your item:");
        scanf("%d",&item);
        enqueue(item);
        break;
case 2: item=dequeue();
        if(item!=-9)
        printf("Poped value:%d\n",item);
        break;
case 3: display();
        break;
case 4: exit(0);
}
}while(9);
}
void enqueue(int x)
{
int temp;
temp=(rear+1)%SIZE;
if(temp==front)
 printf("Queue is full...!\n");
else
{
rear=temp;
queue[rear]=x;
}
return;
}
int dequeue()
{
if(front==rear)
{
 printf("Queue is empty..\n");
 return -9;
}
 else
 {
 front=(front+1)%SIZE;
 return queue[front];
 }
 }
 void display()
 {
 int i;
 if(front==rear)
  printf("Queue is empty..\n");
else
{
i=(front+1)%SIZE;
do
{
printf("%d ",queue[i]);
i=(i+1)%SIZE;
}
while(i!=(rear+1)%SIZE);
}
return;
}

