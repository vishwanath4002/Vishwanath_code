#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char names[10][20];
int size[10];
int mem[100]={-1};
int count=0;

int memsize,blksize,total;
int kk=0;
int nn=1;

void allocate(int cnt, int sz)
{
	if(nn==1)
	{
		for(int i=0;i<sz;i++)
		{
			mem[kk]=cnt;
			kk++;
		}
		if(total<=kk)
		{
			nn=0;
		}
	}
	else
	{
		printf("\nNo more files can be allocated.");
	}
}

void display()
{
	printf("\nAllocation Table");
	printf("\nFile Name\tSize\t\tBlocks Allocated");
	for(int i=0;i<count;i++)
	{
		printf("\n%s",names[i]);
		printf("\t\t%d",size[i]);
		printf("\t\t");
		for(int j=0;j<kk;j++)
		{
			if(mem[j]==i)
			{
				printf("%d ",j);
			}
		}
	}
}

void main()
{

	int yy=1;
	printf("\nEnter the memory size in KB : ");
	scanf("%d",&memsize);
	printf("\nEnter the size of each block in KB : ");
	scanf("%d",&blksize);
	total=(int)memsize/blksize;
	printf("\nThe total no. of blocks : %d",total);
	do
	{
		printf("\n");
		printf("\nEnter the name of the file :  ");
		scanf(" %s",names[count]);
		printf("\nEnter the no. of blocks in the file : ");
		scanf("%d",&size[count]);
		allocate(count,size[count]);
		count++;
		printf("Would you like to continue? (Y[1]/N[0]) : ");
		scanf("%d",&yy);
	}while(yy!=0 && nn!=0);
	display();
	printf("\n");
}

	

