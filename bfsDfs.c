// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021 

//9. ödev: DFS, BFS uygulaması
#include <stdio.h>

#define N 5

void dfs(int g[N][N], int seen[], int u) {
    seen[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < N; v++) {
        if (g[u][v] == 1 && !seen[v]) {
            dfs(g, seen, v);
        }
    }
}

void bfs(int g[N][N], int start) {
    int seen[N] = {0};
    int q[N], f = 0, r = 0;

    seen[start] = 1;
    q[r++] = start;

    printf("BFS: ");
    while (f < r) {
        int u = q[f++];
        printf("%d ", u);

        for (int v = 0; v < N; v++) {
            if (g[u][v] == 1 && !seen[v]) {
                seen[v] = 1;
                q[r++] = v;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    int log[N] = {0};
    printf("DFS: ");
    dfs(graph, log, 0);
    printf("\n");

    bfs(graph, 0);

    return 0;
}