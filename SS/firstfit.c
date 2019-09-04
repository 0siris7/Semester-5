#include<stdio.h>
#include<conio.h>
struct process
{
       int pid,size,mslot;
}pr[100];
struct memory
{
       int mid,size;
}my[100];
int main()
{
    int n,i,j,msl[100];
    printf("enter the no:of processes");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
                     printf("enter the content");
                     scanf("%d",&pr[i].pid);
                     printf("enter the size");
                     scanf("%d",&pr[i].size);
                     pr[i].mslot=0;
                     
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
                    printf("enter the mid for m/y");
                    scanf("%d",&my[i].mid);
                    printf("enter the size ");
                    scanf("%d",&my[i].size);
                    msl[i]=my[i].size;
                    
    }
    for(i=0;i<n;i++)
    {
                     for(j=0;j<n;j++)
                     {
                                      if(pr[i].size <= my[j].size)
                                      {
                                                           pr[i].mslot=my[j].mid;
                                                           my[j].size=my[j].size-pr[i].size;
                                                           break;
                                      }
                     }
    }
    for(i=0;i<n;i++)
    {
                     if(pr[i].mslot=0)
                     printf("insufficent memory");
    }
    printf("\n pid/size/mslot");
    for(i=0;i<n;i++);
    {
                      printf("\n%d\t%d\t%d",pr[i].pid,pr[i].size,pr[i].mslot);
    }
    getch();
}
                      
                     
                                        

      
