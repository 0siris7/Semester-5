#include<stdio.h>
#include<conio.h>
#include<string.h>
struct namtab
{  char name[10]; 
   int a,b;    
    }nt[10];
char deftab[10][10];
char argtab [10][10];    
char label[10];
char opcode[10];
char operand[10];
FILE *f1,*f2;
int exp=0,namtabsize=-1,deftabsize=-1;
int main()
{
  f1=fopen("input.txt","r"); 
  f2=fopen("output.txt","w");  
  //opcode=0;
  while(strcmp(opcode,"END")!=0)
  {
       getline();
       processline();                         
                                
                              }
     }
void getline()
{
     if(exp==1)
     {
              }
     else
     {
       fscanf(f1,"%s%s%s",label,opcode,operand); 
         }         
     }
void processline()
{
   int i,f=0;
   for(i=0;i<10;i++)
   {
     if(strcmp(nt[i].name,opcode)==0)
      { 
        expand();
        f=1;
        break;
      } 
      
   } 
     if(f=0)
     {
      if(strcmp(opcode,"MACRO")==0)
      {
          define();
      } 
      else
      {
        fprintf(f2,"%s\t%s\t%s",label,opcode,operand);
      }  
     }      } 
void define()
{  char temp[20];
   namtabsize++;
   strcpy(nt[namtabsize].name,label);
   deftabsize++;
   nt[namtabsize].a= deftabsize;
   temp= strcat(label,operand);
   strcpy(deftab[deftabsize][0],temp);
   while(strcmp(opcode,"MEND")!=0)
   {
      getline();
      temp= strcat(opcode,operand);
      deftabsize++;
      strcpy(deftab[ deftabsize],temp);
      
   }
  nt[namtabsize].b=deftabsize++;
   
     }
void expand()
{
     exp=1;
     
     
     while(strcmp(opcode,"MEND")!=0)
     {
       getline();
       processline();                         
     }
     exp=0;
     }              
