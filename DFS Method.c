#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int graph[100][100], int numVertices, int vertex, bool visited[]) {
    visited[vertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, numVertices, i, visited);
        }
    }
}


bool isConnected(int graph[100][100], int numVertices) {
    bool visited[100] = {false};


    dfs(graph, numVertices, 0, visited);


    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int numVertices, numEdges;


    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[100][100] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);


    printf("Enter the edges [V1 V2]:\n");
    for (int i = 0; i < numEdges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }


    if (isConnected(graph, numVertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
