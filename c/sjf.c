#include<stdio.h>
#include<conio.h>

struct fcfs
{
 int pid,bt,wt,tat;
       
 }obj[100],temp;
 
 int main()
 {    
      printf("enter the number of processes: ");
      int n;
      scanf("%d",&n);
      int i;
      for(i=1;i<=n;i++)
       {
         printf("enter burst time for  process %d:",i);
         scanf("%d",&obj[i].bt);
         obj[i].pid=i;
         
       }
       
      int j;
      for(i=1;i<=n;i++)
                     { for(j=i+1;j<=n;j++)
                       {
                       if(obj[j].bt<obj[i].bt)
                        {
                          temp=obj[i];
                          obj[i]=obj[j];
                          obj[j]=temp;
                          
                        }
                        }
                        
       }


i=1;
while(i!=n+1)
{if(i==1)
 {obj[1].wt=0;
 obj[1].tat=obj[1].bt;
}
else
{
 obj[i].wt=obj[i-1].tat;
 obj[i].tat=obj[i].bt+obj[i].wt;
}
 i++;
}
       
       
       printf("pid\tbt\twt\ttat\n");
       for(i=1;i<=n;i++)
        {
                        
                        printf("%d\t%d\t%d\t%d\n",obj[i].pid,obj[i].bt,obj[i].wt,obj[i].tat);
        }
        getch();
        return 0;
 }
