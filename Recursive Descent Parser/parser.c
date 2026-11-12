#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int pos=0;
char input[100];


void E();
void T();
void Eprime();
void Tprime();
void F();

void skip()
{
 if(input[pos]== ' ' || input[pos]== '\t')
 {
    pos++;
 }
}

void Error()
{
    printf("Invalid Expression \n");
    exit(0);
}

void match(char expected)
{
    skip();
    if(input[pos]==expected)
    {
        pos++;
        skip();
    }
    else
    {
        Error();
    }
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    skip();
    if(input[pos]=='+')
    {
        match('+');
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    skip();
    if(input[pos]=='*')
    {
        match('*');
        F();
        Tprime();
    }
}

void F()
{
    skip();
    if (isalnum(input[pos]))
    {
        skip();
        while(isalnum(input[pos]))
        {
            pos++;
        }
    }
    else if (input[pos] == '(') 
    { 
        match('('); 
        E(); 
        match(')'); 
    } 
    else 
    { 
        Error(); 
    }
}

int main()
{
    printf("Enter the expression: ");
    fgets(input,sizeof(input),stdin);

    input[strcspn(input, "\n")] = '\0'; 
    skip(); 
    E(); 
    skip();

    if (input[pos] == '\0') 
    { 
        printf("Valid expression\n"); 
    } 
    else 
    { 
        printf("Invalid expression\n"); 
    } 

    return 0;
}