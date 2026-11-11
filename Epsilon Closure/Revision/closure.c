#include<stdio.h>
#define MAX 10

int n;
int closure[MAX][MAX];
int epsilon[MAX][MAX];

void findClosure(int state,int start)
{
    closure[start][state]=1;

    for(int i=0;i<n;i++)
    {
        if(epsilon[state][i]==1 && closure[start][i]==0)
        {
            findClosure(i,start);
        }
    }
}

int main()
{
    int i,j;
    
    printf("Enter the number of states: ");
    scanf("%d",&n);

    printf("Enter the transition table : \n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&epsilon[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        findClosure(i,i);
    }

    printf("Epislon Closure: \n");

    for(i=0;i<n;i++)
    {
        printf("E-closure(q%d) = { ",i);
        for(j=0;j<n;j++)
        {
            if(closure[i][j]==1)
            {
                printf("q%d ",j);
            }
        }
        printf("}\n");
    }
    
    return 0;
}