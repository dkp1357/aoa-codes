#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
int adj[MAX_NODES][MAX_NODES];

// returns the vertex which is not yet visited with minimum distance
int findMin(int d[], int visited[], int n)
{
    int mini = INT_MAX;
    int u = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && mini > d[i]) 
        {
            mini = d[i];
            u = i;
        }
    }
    return u;
}

void relax(int u, int v, int d[], int pi[], int n)
{
    int cost = adj[u][v];
    if (d[v] > cost + d[u]) 
    {
        d[v] = cost + d[u];
        pi[v] = u;
    }
}

void dijkstra(int src, int n)
{
    int d[n];
    int pi[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
        visited[i] = 0;
    }
    
    // source's distance is 0
    d[src] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = findMin(d, visited, n);
        if (u == -1) break;
        visited[u] = 1;
        
        // checking for u's connections
        for (int v = 0; v < n; v++)
        {
            // v should be connected to u and not yet visited
            if (adj[u][v] != 0 && visited[v] == 0) {
                relax(u, v, d, pi, n);
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

    dijkstra(0, n);
    
    return 0;
}
