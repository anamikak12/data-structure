#include<stdio.h>
#include<stdlib.h>
struct bit{
unsigned char x:1;
};
int uset[]={0,1,2,3,4,5,6,7,8,9},size=10;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersect(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[10]={0},b[10]={0},c[10]={0};
int n;
printf("number of elements in set A:");
scanf("%d",&n);
readset(a,n);
printf("number of elements in set B:");
scanf("%d",&n);
readset(b,n);
printf("Set A: ");
printset(a);
printf("Set B: ");
printset(b);
unionset(a,b,c);
printf("AUB=");
printset(c);
intersect(a,b,c);
printf("A intersect B=");
printset(c);
difference(a,b,c);
printf("A-B=");
printset(c);
}        //to read a set and store a bit string
void readset(struct bit a[],int n)
{
int x,i,k;
printf("enter %d elements:",n);
for(i=0;i<n;i++)
{
scanf("%d",&x);
for (k=0;k<size;k++)//if x is a member of union at set
if(uset[k]==x)
{ //set corresponding to x in a[]
a[k].x=1;
break;
}
}
return;
}//to print a set from bit string representaion
void printset(struct bit a[])
{
 int k;
 printf("{");
for (k = 0; k < size; k++)
 if (a[k].x == 1)
 printf("%d,", uset[k]);
 printf("}\n");
return;}
//to find union of 2 sets using bitstring
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x= a[k].x | b[k].x;
return;
}//To find intersection of two sets
void intersect(struct bit a[], struct bit b[], struct bit c[])
{
int k;
for (k = 0; k <size; k++)
c[k].x = a[k].x & b[k].x;
return;
}//to find difference of 2 sets
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
if(a[k].x==1)
c[k].x=a[k].x ^ b[k].x;
return;
}

