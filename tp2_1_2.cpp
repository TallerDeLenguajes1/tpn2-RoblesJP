#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5
double mt[N][M];

int main() {
    int totalElementos = N * M;
    double* p_mt = mt[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%lf ", *(p_mt + (i * M + j)));
        }
        printf("\n");
    }

    return 0;
}