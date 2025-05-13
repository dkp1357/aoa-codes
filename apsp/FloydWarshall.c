#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
int adj[MAX_NODES][MAX_NODES];

void floydwarshall(int* adj[], int* pi[], int n) 
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }

    printf("\nResult Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("\nPredecessor Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", pi[i][j]);
        printf("\n");
    }

}

int main(int argc, char const *argv[])
{
    int n;
    printf("enter number of vertices: ");
    scanf("%d", &n);

    int pi[n][n];

    printf("enter adj matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
            {
                if (i != j)
                {
                    adj[i][j] = INT_MAX;
                } 
                pi[i][j] = -1;
            }
            else 
            {
                pi[i][j] = i;
            }
        }
    }

    floydwarshall(adj, pi, n);

    return 0;
}