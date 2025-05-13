// incomplete

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj[MAX_NODES][MAX_NODES];

int validNext(int next, int k, int x[], int n)
{
    // Check if the vertex has already been used
    for (int i = 0; i < k; i++)
    {
        if (x[i] == next)
            return 0;
    }

    
    if (k == n - 1 && adj[next][x[0]] == 0)
        return 0;
}

void hamiltonian(int k, int x[], int n)
{
    if (k == n)
    {
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", x[i]);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (validNext(i, k, x, n))
        {
            x[k] = i;
            hamiltonian(k+1, x, n);
        }
    }
    
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("\nValid Cycles:\n");

    int x[n];
    x[0] = 0;
    hamiltonian(1, x, n);

    return 0;
}