#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char name[20][10],left[10],right[10];
    int constant[20],value[20];
    int i,j,n,pos;

    printf("Enter the number of statemnts: ");
    scanf("%d",&n);

    if(n<0 ||n>20)
    {
        printf("Invalid number of staments!!");
        return 1;
    }

    printf("Enter statements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%9s = %9s",left,right);
        strcpy(name[i],left);  
        
        if(isdigit((unsigned char)right[0]))
        {
            value[i] = atoi(right);
            constant[i]=1;
        }
        else
        {
            pos=-1;
            for(j=i-1;j>=0;j--)
            {
                if(strcmp(name[j],right)==0)
                {
                    pos=j;
                    break;
                }
            }
             
            if (pos != -1 && constant[pos] == 1)
            {
                value[i] = value[pos];
                constant[i] = 1;
            }
            else
            {
                constant[i] = 0;
            }
        }
    }

    
        printf("\nAfter Constant Propagation:\n");

        for (i = 0; i < n; i++)
        {
            if (constant[i] == 1)
                printf("%s = %d\n", name[i], value[i]);
            else
                printf("%s = variable\n", name[i]);
        }

    return 0;
}