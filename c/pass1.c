#include<stdio.h>
#include<conio.h>
#include<string.h>

char label[20],opcode[20],operand[20];
int start,loctr,s=-1,temp,i,t=3;
struct symtab
{
	char label[20];
	int addr;
}sy[50];

struct optab
{
	char opcode[20],hexcode[10];
}ot[4];
int main()
{  
    strcpy(ot[0].opcode,"LDA");
    strcpy(ot[0].hexcode,"33");
    strcpy(ot[1].opcode,"STA");
    strcpy(ot[1].hexcode,"44");
    strcpy(ot[2].opcode,"LDCH");
    strcpy(ot[2].hexcode,"53");
    strcpy(ot[3].opcode,"STCH");
    strcpy(ot[3].hexcode,"57");
	FILE *ptr1,*ptr2,*ptr3;
	ptr1=fopen("input.txt","r");
	ptr2=fopen("symtab.txt","w");
	ptr3=fopen("intermediate.txt","w");
    
	fscanf(ptr1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	 {
	 	start=atoi(operand);
	 	loctr=start;
	 	fprintf(ptr3,"\t\t%s\t%s\t%s\n",label,opcode,operand);
	 	fscanf(ptr1,"%s%s%s",label,opcode,operand);
	 }
	 
	else
	{
		loctr=start=0;
		fscanf(ptr1,"%s%s%s",label,opcode,operand);
	}
	
	//while(strcmp(opcode,"END")!=0)
	while(!feof(ptr1))
	 { fprintf(ptr3,"%d\t",loctr);
	 	if(strcmp(label,"**")!=0)
	 	 {
	 	 	for(i=0;i<s;i++)
	 	 	 {
	 	 	 	if(strcmp(label,sy[i].label)==0)
	 	 	 	 {
	 	 	 	 	printf("duplicate label exist\n");
	 	 	 	 	
	 	 	 	 	
					
				 }
				else
				 {
				 	strcpy(sy[i].label,label);
				 	s++;
				 	sy[i].addr=loctr;
				 }
			   }
		  }
		else
		 { for(i=0;i<t;i++)
		    {
		    	if(strcmp(opcode,ot[i].opcode)==0)
		    	 {
		    	 	loctr+=3;
		    	 	
		    	 	
				 }
			}
			
		  	
			
			 
			 if(strcmp(opcode,"WORD")==0)
			  {
			  	loctr+=3;
			  	
			  }
		 else if(strcmp(opcode,"RESW")==0)
			 {
			 	loctr+=(3*atoi(operand));
			 	
			 }
         else if(strcmp(opcode,"RESB")==0)
			 {
			 	loctr+=atoi(operand);
			 	
			 }
		else if(strcmp(opcode,"BYTE")==0)
			 {
			 	loctr+=atoi(strlen(operand));
			 	
			 }
		    
		}
			fprintf(ptr3,"\t%s\t%s\t%s\n",label,opcode,operand);
			fscanf(ptr1,"%s%s%s",label,opcode,operand); 
		 
		  
		
		
	 }
	 
	fprintf(ptr3,"%d\t%s\t%s\t%s\n",loctr,label,opcode,operand);
	int pgm=loctr-start;
	for(i=0;i<s;i++)
	 {
	 fprintf(ptr2,"%s\t%d\n",label,loctr);	
	 }
	
     printf("successful");
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);
	getch();
 } 
