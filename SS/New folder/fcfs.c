#include<stdio.h>
#include<conio.h>
 struct process
 {
        int pid;
        int bt;
        int wt;
        int tat;
}s[20];
int main()
{
    int i,n;
    printf("Enter the no. of process ");
    scanf("%d",&n);
    printf("Enter the bt ");
    for(i=1;i<=n;i++)
    {
                    scanf("%d",&s[i].bt);
                    s[i].pid=i;
}
s[1].wt=0;
for(i=1;i<=n;i++)
{
                 s[i].tat=s[i].bt+s[i].wt;
                 s[i+1].wt=s[i].tat;
}
printf("fcfs scheduling is:\n");
printf("pid\t bt\t wt\t tat\n" );
for(i=1;i<=n;i++)
{
 
 printf("%d\t %d\t %d\t %d\n",s[i].pid,s[i].bt,s[i].wt,s[i].tat  );
}
getch();
}
                    
                    
                    
                    

    

    
