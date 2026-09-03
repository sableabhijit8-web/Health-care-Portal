// Algorithm: Count Number of Nodes in a Graph

// Step 1: Start

// Step 2: Initialize a 2D array graph[4][4] to represent the adjacency matrix of the graph

// Step 3: Initialize a variable cnt = 0 to count the number of nodes

// Step 4: For each row i in the adjacency matrix (from 0 to 3):
//  → Increment cnt by 1

// Step 5: After the loop ends, cnt will store the total number of nodes in the graph

// Step 6: Print the value of cnt

// Step 7: Stop
// without input
#include<stdio.h>
#include<stdlib.h>

int main(){
    int graph[4][4] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0},
    };
    int cnt = 0;
    for(int i=0; i<4; i++){
          cnt++;
    printf("Number of nodes in the graph: %d\n", cnt);
    return 0;
    }
}
    
// #include <stdio.h>

// int main() {
//     int n;
//     printf("Enter number of nodes in the graph: ");
//     scanf("%d", &n);

//     int graph[n][n];
//     printf("Enter the adjacency matrix:\n");
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     printf("Total number of nodes in the graph = %d\n", n);
//  return 0;
// }