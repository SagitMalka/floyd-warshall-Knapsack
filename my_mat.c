#include <stdio.h>


void floydWarshall();
int min(int a, int b);

int mat[10][10];


void scan() {
    int x;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf(" %d", &x);
            mat[i][j] = x;
        }
    }
    floydWarshall();
}

int pathExist() {
    int i, j;
    scanf("%d %d", &i, &j);
    if (mat[i][j] == 0) {
        return 0;
    } else {
        return 1;
    }
}

void shortestPath() {
    int i, j;
    scanf("%d %d", &i, &j);
    if (mat[i][j] == 0 || i == j) {
        printf("-1\n");
    } else {
        printf("%d\n", mat[i][j]);
    }
}

void floydWarshall() {
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == j)
                    mat[i][i] = 0;
                else if (i == k || j == k)
                    continue;
                else {
                    int matSum = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0)
                        matSum = 0;
                    mat[i][j] = min(mat[i][j], matSum);
                }
            }
        }
    }
}

int min(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a > b)
        return b;
    else
        return a;
}