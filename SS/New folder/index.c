#include<stdio.h>
#include<conio.h>
struct proc
{
	int id,size,mslot;
}process[20];
struct memory
{
	int id,size;
}memoryslot[20],t;
void resort(int m)
{
	int i,j;
	for(i=0;i<m;i++)
        for(j=0;j<m-i-1;j++)
            if(memoryslot[j].id>memoryslot[j+1].id)
            {
                 t=memoryslot[j];
                 memoryslot[j]=memoryslot[j+1];
                 memoryslot[j+1]=t;
            }
}
void sort1(int m)
{
	int i,j;
	for(i=0;i<m;i++)
        for(j=0;j<m-i-1;j++)
            if(memoryslot[j].size>memoryslot[j+1].size)
            {
                 t=memoryslot[j];
                 memoryslot[j]=memoryslot[j+1];
                 memoryslot[j+1]=t;
            }
}
void sort2(int m)
{
	int i,j;
	for(i=0;i<m;i++)
        for(j=0;j<m-i-1;j++)
            if(memoryslot[j].size<memoryslot[j+1].size)
            {
                 t=memoryslot[j];
                 memoryslot[j]=memoryslot[j+1];
                 memoryslot[j+1]=t;
            }
}
void display(int n)
{
	int i;
	printf("\nProcess ID\tProcess Size\tMemory Slot");
    for(i=0;i<n;i++)
    {
         printf("\n%d\t\t%d\t\t",process[i].id,process[i].size);
		 if(process[i].mslot==0)
		 {
		 	printf("Not Alloted");
		 }
		 else
		 {
		 	printf("%d",process[i].mslot);
		 }
    }
}
void reset(int n,int m,int msize[])
{
	int i;
	for(i=0;i<n;i++)
	{
		process[i].mslot=0;
	}
	for(i=0;i<m;i++)
	{
		memoryslot[i].size=msize[i];
	}
}
int main()
{
	int i,j,n,m,msize[20];
	printf("Enter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		process[i].id=i+1;
		printf("Enter the size:");
		scanf("%d",&process[i].size);
		process[i].mslot=0;
	}
	printf("Enter the number of slots:");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		memoryslot[i].id=i+1;
		printf("Enter the size:");
		scanf("%d",&memoryslot[i].size);
		msize[i]=memoryslot[i].size;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(process[i].size<=memoryslot[j].size)
			{
				process[i].mslot=memoryslot[j].id;
				memoryslot[j].size=memoryslot[j].size-process[i].size;
				break;
			}
		}
	}
	printf("\nFirst Fit allocation\n");
	display(n);
	resort(m);
	reset(n,m,msize);
	sort1(m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(process[i].size<=memoryslot[j].size)
			{
				process[i].mslot=memoryslot[j].id;
				memoryslot[j].size=memoryslot[j].size-process[i].size;
				sort1(m);
				break;
			}
		}
	}
	printf("\n\nBest Fit allocation\n");
	display(n);
	resort(m);
	reset(n,m,msize);
	sort2(m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(process[i].size<=memoryslot[j].size)
			{
				process[i].mslot=memoryslot[j].id;
				memoryslot[j].size=memoryslot[j].size-process[i].size;
				sort2(m);
				break;
			}
		}
	}
	printf("\n\nWorst Fit allocation\n");
	display(n);
	getch();
	return 0;
}
