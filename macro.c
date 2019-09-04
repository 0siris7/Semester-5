#include<stdio.h>
#include<conio.h>
char def[][100];
struct namtab
{char a[20];
 int beg,en;
}nindex[10];
char label[10],opcode[10],operand[10];
int expanding=0,namtabsize=-1,i,defsize=-1;
FILE *f1,*f2;
void getline()
{
     if(expanding==1)
       {
       	
       }
     else
      {
        fscanf(f1,"%s%s%s",label,opcode,operand);
         
      }
}
void processline()
{    int flag=0;
     for(i=0;i<=namtabsize;i++)
     {if(strcmp(opcode,nindex[i].a)==0)
      {expand();
       flag=1;
       break;
       
      }
      
      }
      if(flag==0)
       {
        if(strcmp(opcode,"MACRO")==0)
        {
           define();
           
        }
      else
       {fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
       }
       }
     }
     
      
}
void expand()
{    int k=0;
     expanding=1;
     for(i=nindex[k].beg;i<=nindex[k].en;i++)
      {fprintf(f2,".%s%s%s\n");
         
      }
}
void define()
{
 namtabsize+=1;
 defsize+=1;
 strcpy(label,nindex[namtabsize].a);
 char t1[10];
 t1=label+"\t"+opcode+"\t"+operand+"\n";
 strcpy(t1,def[defsize]);
 getline();
 while(strcmp(opcode,"MEND")!=0)
 {nindex[namtabsize].beg=defsize;
  t1=label+"\t"+opcode+"\t"+operand+"\n";
  defsize+=1;
  strcpy(t1,def[defsize]);
  getline();
 }
 nindex[namtabsize].en=defsize;
 
}


int main()
{ f1=fopen("input.txt","r");
f2=fopen("expand.txt","w");
  while(strcmp(opcode,"END")!=0)
   {getline();
    processline();
    
   }
}
