#include<stdio.h>
#include<conio.h>

struct fcfs
{
 int pid,bt,wt,tat;
       
       
 }obj[100];
 
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
         if(i==1)
          { obj[i].pid=1;
            obj[i].wt=0;
            obj[i].tat=obj[i].bt;
          }
         else
          { obj[i].pid=i;
            obj[i].wt=obj[i-1].tat;
            obj[i].tat=obj[i].bt+obj[i].wt;
          }
          
       }
       printf("processid\tbursttime\twaiting time\tturn around time\n");
       for(i=1;i<=n;i++)
        {
                        
                        printf("%d\t\t%d\t\t%d\t\t%d\n",obj[i].pid,obj[i].bt,obj[i].wt,obj[i].tat);
        }
        getch();
        return 0;
 }
