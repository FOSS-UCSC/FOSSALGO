#include <stdio.h>
#include <stdbool.h>

int graph[1000][1000];               // stores adjacency list of graph
int size[1000];                      // stores the size of the adjacency list of a vertex
bool visited[1000];                  // used to keep track of visited vertex during dfs
int u, v, vertex_cnt, edge_cnt;      // declared for taking input
bool is_directed;                    // indicated where graph is directec or not
char response;                       // used to take in input

void depthfirstsearch(int source) {
    visited[source] = true;
    printf("%d ", source);
    for(int i = 0; i < size[source]; i++) {
        if(visited[graph[source][i]] == false) {
            depthfirstsearch(graph[source][i]);
        }
    }
}

int main() {
    // --------- intialization ---------------
    for(int i = 0; i < 1000; i++) {
        size[i] = 0;
        visited[i] = false;
    }

    // --------- input --------------
    printf("Enter the number of vertices in the graph:\n");
    scanf("%d", &vertex_cnt);

    printf("Enter the number of edges in the graph:\n");
    scanf("%d", &edge_cnt);

    printf("Is the graph directed? (y/n): ");
    scanf(" %c", &response);

    printf("Enter the edges of the graph:\n");
    for(int i = 0; i < edge_cnt; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        if(response == 'y') {
            graph[u][size[u]++] = v;
        }else{
            graph[u][size[u]++] = v;
            graph[v][size[v]++] = u;
        }
    }

    // ---------- calling dfs --------------
    printf("Depth first search order of graph is:\n");
    for(int i = 0; i < vertex_cnt; i++) {
        if(visited[i] == false) {
            depthfirstsearch(i);
        }
    }
    printf("\n");

    return 0;
}
