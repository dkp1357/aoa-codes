#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE];

int validColor(int color, int k, int x[], int n) 
{
    for (int i = 0; i < k; i++)
    {
        // if i is connected to k and i's color  
        if (adj[i][k] != 0 && x[i] == color) 
        {
            return 0;
        }
    }
    return 1;
}

// k = vertex
void mColouring(int k, int m, int x[], int n)
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

    for (int i = 0; i < m; i++)
    {
        if (validColor(i, k, x, n) == 1) 
        {
            x[k] = i;
            mColouring(k+1, m, x, n);
        }
    }
}

int main(int argc, char const *argv[])
{
    int m;
    printf("enter number of colors: ");
    scanf("%d", &m);

    int n;
    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter adj matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int x[n];
    mColouring(0, m, x, n);
    return 0;
}
