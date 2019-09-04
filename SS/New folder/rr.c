#include<stdio.h>
#include<conio.h>
struct process
{
       int pid,bt,wt,tat,b;
}s[100];
int main()
{
    int n,i,tq,temp=0,f=0;
    printf("Enter the no. of processes ");
    scanf("%d",&n);
    printf("Enter the time quantum : ");
    scanf("%d",&tq);
    printf("Enter the burst time : ");
    for(i=1;i<=n;i++)
    {
                    s[i].pid=i;
                    scanf("%d",&s[i].bt);
                    s[i].b=s[i].bt;
    }
   while(f!=n)
    {
    for(i=1;i<=n;i++)
    {
                     if(s[i].bt==0)
                     continue;
                  s[i].wt=temp;
                  if(s[i].bt>tq)
                  {
                     s[i].bt-=tq;  
                    s[i].tat=tq+s[i].wt;
                  }
                  else
                  {
                      s[i].tat=s[i].bt+s[i].wt;
                      s[i].bt=0;
                  }
                 
                  temp=s[i].tat;
    }
    f=0;
    for(i=1;i<=n;i++)
    {
        if(s[i].bt==0)
           f++;
   }
   }            
    printf("\n pid\tbt\twt\ttat\n");
    for(i=1;i<=n;i++)
    {
       printf("\n%d",s[i].pid);
       printf("\t%d",s[i].b);
       s[i].wt=s[i].tat-s[i].b;
       printf("\t%d",s[i].wt);
       printf("\t%d",s[i].tat);
    }
    getch();
}
    
