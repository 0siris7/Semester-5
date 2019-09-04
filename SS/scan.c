#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,q,hd,x,c,j,l,temp;
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
    for(i=0;i<q;i++)
    {
                    for(j=0;j<q;j++)
                    {
                                    if(w[j]>w[j+1])
                                    {
                                                   temp=w[j];
                                                   w[j]=w[j+1];
                                                   w[j+1]=temp;
                                    }
                    }
    }
    printf("\nsorted elements are ");
     for(i=0;i<q;i++)
    {
       printf("%d\t",w[i]);
    }
    printf("\nenter the head position ");
    scanf("%d",&hd);
    int seek=0;
    for(i=0;i<q;i++)
    {
                    if(w[i]<hd&w[i+1]>hd)
                    {
                               x=i+1;
                               l=i;
                    }
    }
    for(i=1;i>=0;i--)
    {
                     printf("path :%d",w[i]);
                     seek=seek+(w[i]-hd);
                     hd=w[i];
    }
    printf("\npath : %d ",0);
    seek=seek+w[0];
    hd=0;
    for(i=hd;i<q;i++)
   {
     printf("\npath: %d ",w[i]);
     seek=seek+(w[i]-hd);
     hd=w[i];
   }
    printf("\nseek time : %d ",seek);
    
    getch();
}
                     
                          

    
                        
