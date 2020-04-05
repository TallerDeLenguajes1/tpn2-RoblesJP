#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

int main() {
    int f, c;
    double mt[N][M];
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < M; c++) {
            printf("%lf ", mt[f][c]);
        }
        printf("\n");
    }

    return 0;
}