#include<stdio.h>
#include<stdlib.h>
int main()
{
  int ReadyQueue[100],i,n,TotalHeadMov=0,initial;
  printf("\nEnter the number of requests");
  scanf("%d",&n);
  for(i=0;i<n;i++){
  printf("\nEnter the sequence order:");
  scanf("%d",&ReadyQueue[i]);
  }
  printf("Enter the initial position:");
  scanf("%d",&initial);
  for(i=0;i<n;i++)
  {
    TotalHeadMov=TotalHeadMov+abs(ReadyQueue[i]-initial);
    initial=ReadyQueue[i];
  }
  printf("Total Head Movement=%d",TotalHeadMov);
}