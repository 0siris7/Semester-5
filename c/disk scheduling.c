#include<stdio.h>
#include<conio.h>

int t,size,element[100],head;
void cscan()
{
	int i,j,temp,index,sum=0,d;
	for(i=0;i<size;i++)
	 {
	 	for(j=i+1;j<size;j++)
	 	 {  if(element[i]>element[j])
	 	    {
			temp=element[i];
	 	 	element[i]=element[j];
	 	 	element[j]=temp;
	 	     }
		  }
		
	 }
	 
	for(i=0;i<size;i++)
	 {
	 	if(element[i] >head)
	 	 {
	 	 	index=i-1;
	 	 	break;
		  }
	 }
	printf("CSCAN\n"); 
	printf("%d->",head); 
	for(i=index;i>=0;i--)
	 {
	 	if(head>element[i])
   	 {
   	 	d=head-element[i];
   	 	head=element[i];
   	 	sum+=d;
		}
	else
	{
		d=element[i]-head;
		head=element[i];
		sum+=d;
	}
	 printf("%d->",head);
	 }
	sum+=head;
	head=0;
	printf("%d->",head);
	head=t-1;
	sum+=head;
	printf(%d)
	printf("%d->",head); 
	for(i=head;i>=(index+1);i--)
	  {
	  	if(head>element[i])
   	 {
   	 	d=head-element[i];
   	 	head=element[i];
   	 	sum+=d;
		}
	else
	{
		d=element[i]-head;
		head=element[i];
		sum+=d;
	}
	printf("%d->",head);
	  }
	printf("\nseek time=%d",sum);
}

int main()
{ int i;
	printf("enter number of tracks:");
	scanf("%d",&t);
	printf("enter work queue size:");
	scanf("%d",&size);
	printf("enter elements:");
	for(i=0;i<size;i++)
	 {
	 	scanf("%d",&element[i]);
	 }
	printf("enter head start pos:");
	scanf("%d",&head);
	cscan();
	getch();
	return 0;
}
