#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int u, v, cost;
} Edge;

void sortEdges(Edge edges[], int E)
{
    for (size_t i = 0; i < E; i++)
    {
        Edge key = edges[i];
        int j = i-1;
        while (j >= 0 && edges[j].cost > key.cost) {
            edges[j+1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }
}


void unionSet(int u, int v, int sets[], int V)
{
    for (int i = 0; i < V; i++) {
        if (sets[i] == v) {
            sets[i] = u;
        }
    }
}

void kruskal(Edge edges[], int E, int V)
{
    sortEdges(edges, E);

    int used[E];
    for (size_t i = 0; i < E; i++)
    {
        used[i] = 0;
    }

    int sets[V];
    for (size_t i = 0; i < V; i++)
    {
        sets[i] = i;
    }
    
    for (size_t i = 0; i < E; i++)
    {
        Edge edge = edges[i];
        if (sets[edge.u] != sets[edge.v]) 
        {
            unionSet(sets[edge.u], sets[edge.v], sets, V);
            used[i] = 1;
        }
    }
    
    int total_cost = 0;
    for (int i = 0; i < E; i++)
    {
        if (used[i])
        {
            printf("Edge %d->%d, cost: %d\n", edges[i].u, edges[i].v, edges[i].cost);
            total_cost += edges[i].cost;
        }
    }

    printf("\nTotal Cost: %d\n", total_cost);
    
}

int main(int argc, char const *argv[])
{
    int V;
    printf("enter number of vertices: ");
    scanf("%d", &V);

    int E;
    printf("enter number of edges: ");
    scanf("%d", &E);

    Edge edges[E];
    for (size_t i = 0; i < E; i++)
    {
        printf("enter u, v, cost: ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, & edges[i].cost);
    }
    
    kruskal(edges, E, V);

    return 0;
}
