#include<stdio.h>
#include<stdlib.h>
int main()
{
	int s[100],n,i,ini,count=0,total=0;
	printf("Enter the no of req:");
	scanf("%d",&n);
	printf("Enter the Seq:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	printf("Enter the initial value:");
	scanf("%d",&ini);
	while(count!=n)
	{
		int index,min=1000,d;
		for(i=0;i<n;i++)
		{
			d=abs(s[i]-ini);
			if(d<min)
			{
				min=d;
				index=i;
			}
		}
	total=total+min;
	ini=s[index];
	s[index]=1000;
	count++;
	}
	printf("The total headmovements is :%d",total);
	return 0;
	
}