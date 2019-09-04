#include<stdio.h>
#include<conio.h>
void sort(int w[],int q)
{
     int i,j,t;
	for(i=0;i<q;i++)
        for(j=0;j<q-i-1;j++)
            if(w[j]>w[j+1])
            {
                 t=w[j];
                 w[j]=w[j+1];
                 w[j+1]=t;
 }          }
int main()
{
    int i,n,q,hd,cpy,hi,c,l;
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
    sort(w,q);
    printf("\nEntered elemets after sort : ");
    for(i=0;i<q;i++)
    {
       printf("%d\t",w[i]);
    }
    printf("\nEnter the Head start position: ");
    scanf("%d",&hd);
    cpy=hd;
    int seek=0;
    for(i=0;i<q;i++)
    {
      if((w[i]<100)&(w[i+1]>100))
      {
        hi=i+1;
        l=i;
      }
    }
    printf("path : %d ",hd);
    for(i=l;i>=0;i--)
    { 
       printf("\npath : %d ",w[i]);
       seek=seek+(hd-w[i]);
       hd=w[i];
    }
    printf("\npath : %d ",0);
    seek=seek+w[0];
    printf("\npath : %d ",n-1);
    seek=seek+n-1;
    hd=n-1;
    for(i=q-1;w[i]>100;i--)
   {
     printf("\npath: %d ",w[i]);
     seek=seek+(hd-w[i]);
     hd=w[i];
   }
    printf("\nseek time : %d ",seek);
    
    getch();
}
