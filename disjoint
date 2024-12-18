#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum number of elements in the disjoint set

// Structure for representing a disjoint set
typedef struct {
    int parent[MAX_SIZE]; // Parent array
    int rank[MAX_SIZE];   // Rank array for union by rank
    int size;             // Number of elements in the set
} DisjointSet;

// Function to create a disjoint set with `n` elements
void createSet(DisjointSet *ds, int n) {
    ds->size = n;
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // Each element is its own parent (self-loop)
        ds->rank[i] = 0;    // Initialize rank as 0
    }
    printf("Disjoint set with %d elements created.\n", n);
}

// Function to find the representative (root) of the set containing `x`
// Uses path compression for optimization
int find(DisjointSet *ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]); // Path compression
    }
    return ds->parent[x];
}

// Function to perform union of two sets containing `x` and `y`
// Uses union by rank for optimization
void unionSets(DisjointSet *ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX != rootY) {
        // Union by rank
        if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
        printf("Union of elements %d and %d completed.\n", x, y);
    } else {
        printf("Elements %d and %d are already in the same set.\n", x, y);
    }
}

// Function to display the disjoint set
void displaySet(DisjointSet *ds) {
    printf("Element:  ");
    for (int i = 0; i < ds->size; i++) {
        printf("%d ", i);
    }
    printf("\nParent:   ");
    for (int i = 0; i < ds->size; i++) {
        printf("%d ", ds->parent[i]);
    }
    printf("\n");
}

int main() {
    DisjointSet ds;
    int n, choice, x, y;

    printf("Enter the number of elements in the disjoint set: ");
    scanf("%d", &n);
    createSet(&ds, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find representative of an element\n");
        printf("2. Union of two elements\n");
        printf("3. Display disjoint set\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to find: ");
                scanf("%d", &x);
                if (x < 0 || x >= n) {
                    printf("Invalid element!\n");
                } else {
                    int representative = find(&ds, x);
                    printf("Representative of element %d is %d\n", x, representative);
                }
                break;

            case 2:
                printf("Enter two elements to perform union: ");
                scanf("%d %d", &x, &y);
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    printf("Invalid elements!\n");
                } else {
                    unionSets(&ds, x, y);
                }
                break;

            case 3:
                displaySet(&ds);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
