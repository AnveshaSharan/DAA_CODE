#include <stdio.h>

int main() {
    int n, m, i, j, u[100], v[100], w[100];
    int d[100], src;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    scanf("%d", &src);

    for (i = 0; i < n; i++)
        d[i] = 99999;

    d[src] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (d[u[j]] != 99999 && d[u[j]] + w[j] < d[v[j]])
                d[v[j]] = d[u[j]] + w[j];
        }
    }

    for (i = 0; i < m; i++) {
        if (d[u[i]] != 99999 && d[u[i]] + w[i] < d[v[i]]) {
            printf("Negative cycle exists");
            return 0;
        }
    }

    for (i = 0; i < n; i++)
        printf("Distance to %d = %d\n", i, d[i]);

    return 0;
}