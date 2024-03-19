#include <stdio.h>
#include <stdlib.h>

// If E is the number of edges and V is the number of vertices then the number of spanning trees possible is : (E choose V - 1) - number of cycles
// reference : https://www.youtube.com/watch?v=4ZlRH0eK-qQ
// reference : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

void makeSet(int parent[], int rank[], int n) 
{ 
    parent[0] = 0;
    rank[0] = 0;
    for (int i = 1; i <= n; i++) { 
        parent[i] = i; 
        rank[i] = 0; 
    } 
} 

// Find set of an element i (uses path compression technique)
int findParent(int parent[], int node) {
    if (parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// A function that does union of two sets of x and y (uses union by rank)
void unionSets(int parent[], int rank[], int x, int y) {
    x = findParent(parent, x);
    y = findParent(parent, y);

    if(rank[x] < rank[y]){
        parent[x] = y;
    }
    else if(rank[x] > rank[y]){
        parent[y] = x;
    }
    else{
        parent[y] = x;
        rank[x] ++;
    }
}

// The main function to construct MST using Kruskal's algorithm
int kruskalMST(int n, int m, int graph[][3]) {
    int parent[n + 1];
    int rank[n + 1];

    makeSet(parent, rank, n);
    int mc = 0;
    // for (int i = 0; i < n; i ++){
    //     printf("parent %d", parent[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i ++){
    //     printf("rank %d", rank[i]);
    // }

    for (int i = 0; i < m; i ++){
        // printf("n = %d", n);
        // printf("m = %d", m);
        int u = findParent(parent, graph[i][0]);
        int v = findParent(parent, graph[i][1]);
        int wt = graph[i][2];

        // printf("%d", u);
        // printf("%d", v);

        if (u != v){
            unionSets(parent, rank, u, v);
            mc += wt;
            printf("%d -- %d == %d\n", graph[i][0], graph[i][1], wt); 
        }
    }
    printf("min cost = %d", mc);
    return mc;
}

int main() {
    // File pointers for input and output files
    FILE *inputFile, *outputFile;
    
    // Open input file in read mode
    inputFile = fopen("mst_input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    
    // Open output file in write mode
    outputFile = fopen("mst_output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    
    // Read n and m from input file
    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);
    
    // Read graph from input file
    int graph[m][3];
    for (int i = 0; i < m; ++i) {
        fscanf(inputFile, "%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    
    // Call Kruskal's MST algorithm
    int result = kruskalMST(n, m, graph);
    
    // Write result to output file
    fprintf(outputFile, "%d\n", result);
    
    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}

