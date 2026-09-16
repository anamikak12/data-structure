#include<stdio.h>
#include<stdlib.h>
#define size 10
int stk[size];
int sp=-1;
void main()
{
void push(int);
int pop(),opt,item;
void print();
do
{
printf("\n1.push\n 2.pop\n 3.display\n 4.exit\n");
printf(" enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter item:");
scanf("%d",&item);
push(item);
break;
case 2:item=pop();
if(item!=9)
printf("poped value=%d\n",item);
break;
case 3:print();
break;
case 4:
exit(0);
}}
while(1);
}
void push(int x)
{
if(sp==size-1)
{
printf("stack is full\n");
return;
}
else
{
stk[++sp]=x;
return;
}
}
int pop()
{
if(sp==-1)
{
printf("stack is empty\n");
return 9;
}
else
{
return stk[sp--];
}
}
void print()
{
int i;
for(i=0;i<=sp;i++)
if(sp!=-1)
printf("%d\t",stk[i]);
else
printf("stack is empty\n");
return;
}
