#include<stdio.h>
#include<conio.h>

struct proc
{
       int id,size,ms;
}s[100];

struct mblock
{
       int id1,size1,ref;
}m[100],temp;


int main()
{
   int n,i,d,j,ch;
    printf("enter number of processes:");
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { printf("\nenter size for process[%d]:",i);
      scanf("%d",&s[i].size);
      s[i].id=i;
      s[i].ms=0;
    }
    
    printf("enter number of memory blocks:");
    scanf("%d",&d);
     for(j=1;j<=d;j++)
     {printf("\nenter size for memory[%d]:",j);
      scanf("%d",&m[j].size1);
      m[j].id1=j;
      m[j].ref=m[j].size1;
     }
    
    printf("MENU\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\n");
    printf("choice:");
    scanf("%d",&ch);
    
    switch(ch)
    {
              case 1:
                   
                   for(i=1;i<=n;i++)
                   { for(j=1;j<=d;j++)
                     {
                                     if(s[i].size<=m[j].size1)
                                      {
                                        m[j].size1=m[j].size1-s[i].size;
                                        
                                        s[i].ms=j;
                                        break;
                                      }
                                    
                     }
                   }
                    printf("\nID\tSIZE\tMEMORY SLOT\n");
                   for(i=1;i<=n;i++)
                    {
                     printf("%d\t%d\t",s[i].id,s[i].size);
                     if(s[i].ms==0)
                      {
                                   printf("insufficient memory\n");
                      }
                     else
                      {
                                   printf("%d\n",s[i].ms);
                      }
                     
                    }
                    break;
                    
              case 2:
                   for(i=1;i<=n;i++)
                     { for(j=i+1;j<=n;j++)
                       {
                       if(m[j].size1<m[i].size1)
                        {
                          temp=m[i];
                          m[i]=m[j];
                          m[j]=temp;
                          
                        }
                        }
                      }
                      
                   for(i=1;i<=n;i++)
                   { for(j=1;j<=d;j++)
                     {
                                     if(s[i].size<=m[j].size1)
                                      {
                                        m[j].size1=m[j].size1-s[i].size;
                                        
                                        s[i].ms=j;
                                        break;
                                      }
                           for(i=1;i<=n;i++)
                     { for(j=i+1;j<=n;j++)
                       {
                       if(m[j].size1<m[i].size1)
                        {
                          temp=m[i];
                          m[i]=m[j];
                          m[j]=temp;
                          
                        }
                        }
                      }           
                                    
                     }
                   }
                   
                 printf("\nID\tSIZE\tMEMORY SLOT\n");
                   for(i=1;i<=n;i++)
                    {
                     printf("%d\t%d\t",s[i].id,s[i].size);
                     if(s[i].ms==0)
                      {
                                   printf("insufficient memory\n");
                      }
                     else
                      {
                                   printf("%d\n",s[i].ms);
                      }
                     
                    }
               break;
                   
    }
    getch();
    return 0;
}
