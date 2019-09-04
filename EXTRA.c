#include<stdio.h>
#include<conio.h>
int read(int a[][5])
{
     int size=5,i=0,j=0,c=1;
     printf("\nEnter the array  :  ");
     for(i=0;i<size;i++)
       for(j=0;j<size;j++)
          scanf("%d",&a[i][j]);
          
          

}
void display(int a[][5])
{
     int i,j;
     for(i=0;i<5;i++)
     {
         for(j=0;j<5;j++)
             printf("\t%d",a[i][j]);
             printf("\n");
     }
}
int linear(int a[][5],int size,int item)
{
     int i,f=0,j;
     for(i=0;i<size&&f!=1;i++)
     {
                    for(j=0;j<size&&f!=1;j++)
                    {
                        if(a[i][j]==item)
                        {
                                      a[i][j]=0;
                                      f=1;
                        }
                        }
     }
     if(f!=1)
     printf("\nItem not found");                                 
   
}
void bingo(int a[][5])
{
     int e,i,j,sum1=0,sum2=0,sum3=0,t=5,c=0;
     char ch='n';
     while(1)
     {
             sum1=0,sum2=0,sum3=0,c=0;
     printf("\nEnter the no  :\n");
     scanf("%d",&e);
     linear(a,t,e);
     for(i=0;i<5;i++)
     {
                     sum1=0;sum2=0;
                     for(j=0;j<5;j++)
                     {
                           sum1+=a[i][j];
                           sum2+=a[j][i];
                     }
                     if(sum1==0)                    
                               c++;                
                     if(sum2==0)
                               c++;
     }
                    /* switch(c)
                     {
                               case 5 :printf("\n\n!!!!!!!BINGO!!!!!!");
                                       getch();
                                       exit(0);
                                       break;
                               case 4 :printf("\nBING\n");
                                       break;
                               case 3 :printf("\nBIN\n");
                                       break;   
                               case 2 :printf("\nBI\n");
                                       break; 
                               case 1 :printf("\nB\n");
                                       break;    
                     }*/
                     
     
     sum1=0;
     for(i=0;i<5;i++)
     {
                     sum3+=a[i][i];
                     sum1+=a[i][4-i];
     }
     if(sum1==0)                    
                               c++;                
     if(sum3==0)
                               c++;
     switch(c)
                     {
                               case 7:
                               case 6:     
                               case 5 :printf("\n\n!!!!!!!BINGO!!!!!!");
                                       getch();
                                       exit(0);
                                       break;
                               case 4 :printf("\nBING\n");
                                       break;
                               case 3 :printf("\nBIN\n");
                                       break;   
                               case 2 :printf("\nBI\n");
                                       break; 
                               case 1 :printf("\nB\n");
                                       break;    
                     }
     printf("do you want to exit");
     fflush(stdin);
     scanf("%c",&ch);
     if(ch=='y')
     exit(0);
     
     display(a);
     }
}
     
int main()
{
     int a[5][5];
     read(a);    
     bingo(a);
     getch();
}
     
     
     
     
