#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() 
{ 
    char stack[100], input[100]; 
    int top = -1, i = 0; 
 
    printf("Enter expression: "); 
    scanf("%99s", input); 
    strcat(input, "$"); 
 
    stack[++top] = '$'; 
    stack[top + 1] = '\0'; 
 
    printf("\n%-15s %-15s %s\n", "STACK", "INPUT", "ACTION"); 
    
    printf("--------------------------------------------\n"); 
 
    while (input[i] != '$') 
    { 
        // Shift 
        stack[++top] = input[i]; 
        stack[top + 1] = '\0'; 
        printf("%-15s %-15s Shift %c\n", stack, input + i + 1, input[i]); 
        i++; 
 
        // Reduce Loop 
        while (1) 
        { 
            // Rule 1: Reduce identifier (i or any letter a-z) -> E 
            if ((stack[top] == 'i') || ((stack[top] >= 'a') && (stack[top] <= 'z'))) 
            { 
                stack[top] = 'E'; 
                stack[top + 1] = '\0'; 
                printf("%-15s %-15s Reduce E->id\n", stack, input + i); 
            } 
            // Rule 2: Reduce (E) -> E 
            else if ((top >= 3) && (stack[top - 2] == '(') && (stack[top - 1] == 'E') && (stack[top] == ')')) 
            { 
                top -= 2; 
                stack[top] = 'E'; 
                stack[top + 1] = '\0'; 
                printf("%-15s %-15s Reduce E->(E)\n", stack, input + i); 
            } 
            // Rule 3: Reduce E+E -> E 
            else if ((top >= 3) && (stack[top - 2] == 'E') && (stack[top - 1] == '+') && (stack[top] == 'E')) 
            { 
                top -= 2; 
                stack[top] = 'E'; 
                stack[top + 1] = '\0'; 
                printf("%-15s %-15s Reduce E->E+E\n", stack, input + i); 
            } 
            // Rule 4: Reduce E*E -> E 
            else if ((top >= 3) && (stack[top - 2] == 'E') && (stack[top - 1] == '*') && (stack[top] == 'E')) 
            { 
                top -= 2; 
                stack[top] = 'E'; 
                stack[top + 1] = '\0'; 
                printf("%-15s %-15s Reduce E->E*E\n", 
                stack, input + i); 
            } 
            else 
            { 
                break; 
            } 
        } 
    } 
    if ((top == 1) && (stack[0] == '$') && (stack[1] == 'E')) 
    { 
        printf("\nResult: Accepted\n"); 
    } 
    else 
    { 
        printf("\nResult: Rejected\n"); 
    } 
return 0; 
} 
