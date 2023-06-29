#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int u;
    int v;
    int w;
} Graph;

/**
 *
 * @param graph Graph in the format (u, v, w) where
 *  the edge is from vertex u to v. And weight
 *  of the edge is w.
 * @param V Number of vertices in graph
 * @param E Number of edges in graph
 * @param src Starting node
 * @param dest Destination node
 * @returns Shortest distance from source to destination
 */
int bellman_ford(Graph graph[], int V, int E, int src, int dest) {
    int dis[V];
    for (size_t i = 0; i < V; i++) {
        dis[i] = INT32_MAX;
    }
    dis[src] = 0;

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (size_t i = 0; i < V - 1; i++) {
        for (size_t j = 0; j < E; j++) {
            Graph jElement = graph[j];
            if (dis[jElement.u] + jElement.w < dis[jElement.v]) {
                dis[jElement.v] = dis[jElement.u] + jElement.w;
            }
        }
    }

    // check for negative-weight cycles.
    for (size_t i = 0; i < E; i++) {
        const int u = graph[i].u;
        const int v = graph[i].v;
        const int w = graph[i].w;
        if (dis[u] != INT32_MAX && dis[u] + w < dis[v]) {
            printf(
                "Graph contains negative weight cycle. Hence, shortest "
                "distance not guaranteed.");
            exit(1);
        }
    }
    for (size_t i = 0; i < V; i++) {
        if (i == dest)
            return dis[i];
    }
}

Graph *get_Graph_struct(int graph_array[][3], int length) {
    Graph *graph = (Graph *)malloc(sizeof(Graph) * length);
    for (size_t i = 0; i < length; i++) {
        graph[i].u = graph_array[i][0];
        graph[i].v = graph_array[i][1];
        graph[i].w = graph_array[i][2];
    }
    return graph;
}

int main(int argc, char const *argv[]) {
    {
        int graph_array[][3] = {
            {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
            {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3},
        };
        const int E = sizeof(graph_array) / sizeof(graph_array[0]);
        Graph *graph = get_Graph_struct(graph_array, E);

        const int V = 5;
        const int destination = 3;
        assert(bellman_ford(graph, V, E, 0, destination) == -2);
    }
    {
        int graph_array[][3] = {
            {0, 1, 3}, {0, 3, 6}, {0, 5, -1}, {1, 2, -3}, {1, 4, -2},
            {5, 2, 5}, {2, 3, 1}, {4, 3, 5},  {5, 4, 2},
        };
        const int E = sizeof(graph_array) / sizeof(graph_array[0]);
        Graph *graph = get_Graph_struct(graph_array, E);

        const V = 6;
        const destination = 4;
        assert(bellman_ford(graph, V, E, 0, destination) == 1);
    }
    {
        int graph_array[][3] = {
            {0, 3, -1}, {0, 2, 4}, {3, 2, 2}, {3, 1, 5}, {2, 1, -1},
        };
        const int E = sizeof(graph_array) / sizeof(graph_array[0]);
        Graph *graph = get_Graph_struct(graph_array, E);

        const V = 4;
        const destination = 1;
        assert(bellman_ford(graph, V, E, 0, destination) == 0);
    }
    return 0;
}
