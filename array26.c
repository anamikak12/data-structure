#include<stdio.h>
void main()
{
int ar1[20],ar2[20],ar3[40],n1,n2,n3;
void readdata(int[],int);
void sortdata(int[],int);
void printdata(int[],int);
void mergedata(int[],int[],int[],int,int);
printf("no of elements in 1st array[1-20]:");
scanf("%d,",&n1);
readdata(ar1,n1);
printf("\n no of elements in 2nd array[1-20]:");
scanf("%d,",&n2);
readdata(ar2,n2);
sortdata(ar1,n1);
sortdata(ar2,n2);
mergedata(ar1,ar2,ar3,n1,n2);
printf("\n sorted array1:");
printdata(ar1,n1);
printf("\n sorted array2:");
printdata(ar2,n2);
printf("\n merged array:");
printdata(ar3,n1+n2);
}
void readdata(int a[],int n){
int i;
printf("enter %d no:",n);
for(i=0;i<n;i++)
scanf("%d,",&a[i]);
return;
}
void printdata(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d,",a[i]);
return;
}
void sortdata(int a[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;}
return;
}
void mergedata(int a[],int b[],int c[],int n1,int n2)
{
int i,j,k;
i=j=k=0;
while(i<n1 && j<n2)
if(a[i]<b[j])
c[k++]=a[i++];
else 
c[k++]=b[j++];
while(i<n1)
c[k++]=a[i++];
while(j<n2)
c[k++]=b[j++];
return;
}
