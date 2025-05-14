#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int path[MAX];
int adj[MAX][MAX];
int n;

int isValid(int v, int k) {
    // Check if this vertex `v` is adjacent to the previous vertex `path[k-1]` 
    if (adj[path[k - 1]][v] == 0)
        return 0;

    // Check if the vertex has already been included
    for (int i = 0; i < k; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;
}

void printCycle() {
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // to show cycle back to the first vertex
}

void hamiltonianCycle(int k) {
    if (k == n) {
        // if the last vertex (path[n-1]) is connected to the first
        // path[0] = 0, since we are starting from vertex 0
        if (adj[path[k - 1]][path[0]] == 1) {
            printCycle();
        }
        return;
    }

    for (int v = 1; v < n; v++) {
        if (isValid(v, k)) {
            path[k] = v;
            hamiltonianCycle(k + 1);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // Start from vertex 0
    path[0] = 0;

    printf("Hamiltonian Cycles:\n");
    hamiltonianCycle(1);

    return 0;
}
