#include<stdio.h>
#include<conio.h>
#include<string.h>
struct op
{
    char opcode[10],hex[10];
}optab[4];
struct symbol
{
    char label[10];
    int address;
}symtab[100];
int s=0;
int main()
{
    int locctr,start,flag=0,i,temp,size;
    char  label1[10],opcode1[10],operand[10];
    FILE *f1,*f2,*f3,*f4,*f5;
    strcpy(optab[0].opcode,"LDA");
    strcpy(optab[0].hex,"33");
    strcpy(optab[1].opcode,"STA");
    strcpy(optab[1].hex,"44");
    strcpy(optab[2].opcode,"LDCH");
    strcpy(optab[2].hex,"56");
    strcpy(optab[3].opcode,"STCH");
    strcpy(optab[3].hex,"57");
    f1=fopen("inter.txt","r");
    f2=fopen("symtab.txt","r");
    f3=fopen("objpgm.txt","w");
    f4=fopen("size.txt","r");
    f5=fopen("assfile.txt","w");
    fscanf(f1,"%d%s%s%s",temp,label1,opcode1,operand);
    fscanf(f4,"%d",size);
      if(strcmp(opcode1,"START")==0)
     {
     	fprintf(f5,"%d%s%s%s",temp,label1,opcode1,operand);
     	fprintf(f3,"H^%s^%d^%s^",label1,temp,size);
     	fscanf(f1,"%d%s%s%s",temp,label1,opcode1,operand);
	 }
	 while(strcmp(opcode1,"END")!=0)
	 {
	 	 for(i=0;i<3;i++)
	 	 {
	 	 	
		  }
	 }
	 fclose(f1);
	 fclose(f2);
	 fclose(f3);
	 fclose(f4);
	 fclose(f5);
	 getch();
}
