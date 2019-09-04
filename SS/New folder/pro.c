#include<stdio.h>
#include<conio.h>
 struct process
 {
        int p;
        int pid;
        int bt;
        int wt;
        int tat;
}s[20],temp;
int main()
{
    int i,n;
    printf("Enter the no. of process ");
    scanf("%d",&n);
    printf("Enter the burst time and priority");
    for(i=1;i<=n;i++)
    {
                    scanf("%d",&s[i].bt);
                    scanf("%d",&s[i].p);
                    s[i].pid=i;
}
s[1].wt=0;
int j;
     for(i=0;i<n-1;i++)
     {
                       for(j=0;j<n-i-1;j++)
                       {
                                           if(s[j].p>s[j+1].p)
                                           {
                                                          temp=s[j];
                                                          s[j]=s[j+1];
                                                          s[j+1]=temp;
                                           }
                       }
                       
                       
     }
    
for(i=1;i<=n;i++)
{
                 s[i].tat=s[i].bt+s[i].wt;
                 s[i+1].wt=s[i].tat;
}
printf("priority scheduling is:\n");
printf("p\t pid\t bt\t wt\t tat\n" );
for(i=1;i<=n;i++)
{
 
 printf("%d\t %d\t %d\t %d\t %d\n",s[i].p,s[i].pid,s[i].bt,s[i].wt,s[i].tat  );
}
getch();
}

