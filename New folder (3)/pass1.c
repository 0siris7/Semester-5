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
    int locctr,start,flag=0,i;
    char  label1[10],opcode1[10],operand[10];
    FILE *f1,*f2,*f3,*f4;
    strcpy(optab[0].opcode,"LDA");
    strcpy(optab[0].hex,"33");
    strcpy(optab[1].opcode,"STA");
    strcpy(optab[1].hex,"44");
    strcpy(optab[2].opcode,"LDCH");
    strcpy(optab[2].hex,"56");
    strcpy(optab[3].opcode,"STCH");
    strcpy(optab[3].hex,"57");
    f1=fopen("input.txt","r");
    f2=fopen("symtab.txt","w");
    f3=fopen("inter.txt","w");
    f4=fopen("size.txt","w");
    fscanf(f1,"%s%s%s",label1,opcode1,operand);
    if(strcmp(opcode1,"START")==0)
    {
        start=atoi(operand);
        locctr=start;
        fprintf(f3,"%d\t%s\t%s\t%s\n",start,label1,opcode1,operand);
        fscanf(f1,"%s%s%s",label1,opcode1,operand);
    }
    else
        locctr=0;
    while(strcmp(opcode1,"END")!=0)
    {
    fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label1,opcode1,operand);
        if(strcmp(label1,"**")!=0)
        {
            for(i=0;i<s;i++)
                if(strcmp(symtab[i].label,label1)==0)
                {
                    printf("Error label reoccured!");
                    getch();
                    exit(0);
                }
            strcpy(symtab[s].label,label1);
            symtab[s].address=locctr;
            s++;
        }
        for(i=0;i<4;i++)
            if(strcmp(optab[i].opcode,opcode1)==0)
            {
                locctr+=3;
                flag=1;
                break;
            }
        if(flag==0)
            if(strcmp(opcode1,"WORD")==0)
                locctr+=3;
            else if(strcmp(opcode1,"RESW")==0)
                locctr+=(3*atoi(operand));
            else if(strcmp(opcode1,"RESB")==0)
                locctr+=atoi(operand);
            else if(strcmp(opcode1,"BYTE")==0)
                locctr+=1;
            else
            {
                printf("Error opcode not found!");
                getch();
            	exit(0);
            }
        flag=0;
       // fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label1,opcode1,operand);
        fscanf(f1,"%s%s%s",label1,opcode1,operand);
    }
    if(strcmp(opcode1,"END")==0)
    {
        fprintf(f3,"%d\t%s\t%s\t%d",locctr+3,label1,opcode1,start);
    }
    for(i=0;i<s;i++)
        fprintf(f2,"%s\t%d\n",symtab[i].label,symtab[i].address);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Completed!");
    int res=(locctr+3)-start;
    fprintf(f4,"%d",res);
    fclose(f4);
    getch();
}
