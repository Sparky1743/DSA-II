#include <stdio.h>
#include <stdlib.h>

int findParent(int parent[], int node) {
    if (parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    x = findParent(parent, x);
    y = findParent(parent, y);

    if (rank[x] < rank[y]){
        parent[x] = y;
    }

    else if (rank[x] > rank[y]){
        parent[y] = x;
    }

    else{
        parent[y] = x;
        rank[x] ++;
    }
}

int number_of_provinces(int parent[], int n) {
    int count = 0;
    for (int i = 0; i < n; i ++){
        if (parent[i] == i){
            count ++;
        }
    }

    printf("%d", count);
    return count;
}

int main() {
    FILE *inputFile = fopen("prov_input.txt", "r");
    FILE *outputFile = fopen("prov_output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int n, m; // Number of nodes and edges
    fscanf(inputFile, "%d %d", &n, &m);

    // Initialize parent and rank arrays
    int parent[n];
    int rank[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Read edges and union corresponding sets
    for (int i = 0; i < m; i++) {
        int a, b;
        fscanf(inputFile, "%d %d", &a, &b);
        unionSets(parent, rank, a, b);
    }

    // Count the number of connected components
    int provinces = number_of_provinces(parent, n);

    fprintf(outputFile, "%d\n", provinces);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
