#include<stdio.h>
#include<conio.h>
int t,size,element[100],head;
void scan()
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
	 	if(element[i]>head)
	 	 {
	 	 	index=i;
	 	 	break;
		  }
	 }
	printf("SCAN\n"); 
	printf("%d->",head); 
	for(i=(index-1);i>=0;i--)
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
	 
	for(i=index;i<size;i++)
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

void fcfs()
{ 
  int i,sum=0,d;
  printf("\nFCFS\n");
  printf("%d->",head);
  for(i=0;i<size;i++)
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
	int rem=head;
	int rev[100];
	for(i=0;i<size;i++)
	 {
	 	rev[i]=element[i];
	 }
	
	scan();
		head=rem;
		for(i=0;i<size;i++)
	 {
	 	element[i]=rev[i];
	 }
	
	
	fcfs();
	
	head=rem;
		for(i=0;i<size;i++)
	 {
	 	element[i]=rev[i];
	 }
	 
	 scanc();

	
	getch();
	return 0;
}
