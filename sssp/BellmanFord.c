#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
int adj[MAX_NODES][MAX_NODES];

void relax(int u, int v, int d[], int pi[], int n)
{
    int cost = adj[u][v];
    if (d[v] > cost + d[u])
    {
        d[v] = cost + d[u];
        pi[v] = u;
    }
}

void bellmanford(int src, int n)
{
    int d[n];
    int pi[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }

    d[src] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                // if d[u] == INT_MAX, u is not reachable
                if (adj[u][v] != 0 && d[u] != INT_MAX)
                {
                    relax(u, v, d, pi, n);
                }
            }
        }   
    }

    // checking for -ve weight cycles
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            // is reachable and can be relaxed more
            if (adj[u][v] != 0 && d[u] != INT_MAX && d[v] > d[u] + adj[u][v]) {
                printf("Graph contains a negative weight cycle.\n");
                return;
            }
        }
    }

    printf("\nv d p\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", i, d[i], pi[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter adj matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    bellmanford(0, n);

    return 0;
}
