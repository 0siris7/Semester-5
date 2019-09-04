#include<stdio.h>
#include<conio.h>

int main()
{
    int i,n,q,hd,c;
    printf("\nEnter the number of tracks : ");
    scanf("%d",&n);
    int p[n];
    printf("\nEnter the size of the work queue : ");
    scanf("%d",&q);
    int w[q];
    printf("\nEnter the work queue elements : ");
    for(i=0;i<q;i++)
    {
       scanf("%d",&w[i]);
    }
    printf("\nEntered elemets are : ");
    for(i=0;i<q;i++)
    {
       printf("%d\t",w[i]);
    }
    printf("\nEnter the Head start position: ");
    scanf("%d",&hd);
    int seek=0;
    for(i=0;i<q;i++)
    {
       if(hd>w[i])
       {
       seek=seek+(hd-w[i]);
       hd=w[i];
       }
       else
       {
          seek=seek+(w[i]-hd);
           hd=w[i];
       }
    }
    printf("seek time : %d ",seek);
    
    getch();
}
