#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V], FILE *outputFile) {
    fprintf(outputFile, "Edge \tWeight\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        fprintf(outputFile, "%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }

}

// Function to construct and print MST for a graph
void prim(int graph[V][V], FILE *outputFile)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge
    int key[V];

    // set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST. Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // write the code for the rest of the function below
    for (int i = 0; i < V; i ++){
        int m = minKey(key, mstSet);
        mstSet[m] = true;

        for (int v = 0; v < V; v ++){
            if (graph[m][v] && mstSet[v] == false && graph[m][v] < key[v]){
                parent[v] = m;
                key[v] = graph[m][v];
            }
        }
    }

    // print the constructed MST
    printMST(parent, graph, outputFile);
}

// Driver's code
int main()
{
    int graph[V][V];
    FILE *inputFile = fopen("prim_input.txt", "r");
    FILE *outputFile = fopen("prim_output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read the graph from input.txt
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            fscanf(inputFile, "%d", &graph[i][j]);

    fclose(inputFile);

    // Print the solution
    prim(graph, outputFile);

    fclose(outputFile);

    return 0;
}
