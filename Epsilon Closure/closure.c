#include<stdio.h>

#define MAX 10

int epsilon[MAX][MAX],closure[MAX][MAX],n;

void findClosure(int state,int start)
{
  closure[start][state]=1;
  for(int i=0;i<n;i++)
  {
    if(epsilon[state][i]==1 &&closure[start][i]==0)
    {
        findClosure(i,start);
    }
  }   
}

int main()
{
    printf("Enter the number of states: ");
    scanf("%d",&n);

    printf("Enter the transition matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&epsilon[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        findClosure(i,i);
    }

    printf("Epsion Closure: \n");
    for(int i=0;i<n;i++)
    {
        printf("epsilon Closure(q%d) = { ",i);
        for(int j=0;j<n;j++)
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