#include<stdio.h>

#define MAX 10

int n;
int epsilon[MAX][MAX],closure[MAX][MAX],trans[MAX][MAX],result[MAX][MAX];

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
    int i,j,k,l;

    printf("Enter the number of states: ");
    scanf("%d",&n);

    printf("Enter the epsilon transition table :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&epsilon[i][j]);
        }
    }

    printf("Enter the transition table for inputs: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&trans[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        findClosure(i,i);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(closure[i][j]==1)
            {
                for(k=0;k<n;k++)
                {
                    if(trans[j][k]==1)
                    {
                        for(l=0;l<n;l++)
                        {
                            if(closure[k][l]==1)
                            {
                                result[i][l]=1;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("NFA :\n");
    for(i=0;i<n;i++)
    {
        printf("q%d->",i);
        for(j=0;j<n;j++)
        {
            if(result[i][j]==1)
            {
              printf("q%d ",j);  
            }
        }
        printf("\n");
    }


    return 0;
}