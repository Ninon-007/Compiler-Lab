#include<stdio.h>
#include<stdlib.h>

int main()
{

    FILE *fp;
    char result[10],a[10],b[10],op;

    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND !");
        return 1;
    }

    while(fscanf(fp,"%9s = %9s %c %9s",result,a,&op,b)==4)
    {
        printf("MOV AX %s\n",a);

        if(op=='+')
        {
            printf("ADD AX %s\n",b);
        }

        else if(op=='-')
        {
            printf("SUB AX %s\n",b);
        }

        else if(op=='*')
        {
            printf("MOV BX %s\n",b);
            printf("MUL BX\n");
        }

        else if(op=='/')
        {
            printf("MOV BX %s\n",b);
            printf("XOR DX,DX\n");
            printf("DIV BX\n");
        }

        printf("MOX %s, AX \n",result);

    }

    fclose(fp);
    return 0;
}