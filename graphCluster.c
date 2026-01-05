// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//8. ödev : Array olarak verilen bir graph’da cluster çıkarma.
#include <stdio.h>

#define V 5

void scan(int adj[V][V], int seen[], int u) {
    seen[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !seen[v]) {
            scan(adj, seen, v);
        }
    }
}

void find_groups(int graph[V][V]) {
    int state[V] = {0};
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!state[i]) {
            printf("Group %d: ", ++count);
            scan(graph, state, i);
            printf("\n");
        }
    }
}

int main() {
    int map[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    find_groups(map);
    return 0;
}