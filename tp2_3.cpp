#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15 // filas

// funciones
void cargarMatriz(int, int, int*);
void mostrarMatriz(int, int, int*);
void genVectorCantParesPorFila(int, int, int*, int*);

int main() {
    srand(time(NULL));
    int M = rand() % 11 + 5; // columnas
    int matriz[N][M]; // matriz de NxM elementos
    printf("\n- Matriz %dx%d generada.\n", N, M);
    cargarMatriz(N, M, matriz[0]);
    printf("\n- Matriz cargada: \n");
    mostrarMatriz(N, M, matriz[0]);
    printf("- Mostrando vector generado con la cantidad de numeros pares por fila\n");
    int vecPares[N];
    genVectorCantParesPorFila(N, M, matriz[0], vecPares);
    for (int i = 0; i < N; i++) {
        printf("%d ", vecPares[i]);
    }
    printf("\n\n");
    return 0;
}

void cargarMatriz(int filas, int columnas, int* matriz) {
    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            *(matriz + (i * columnas + j)) = rand() % 900 + 100;
        }
    }
}

void mostrarMatriz(int filas, int columnas, int* matriz) {
    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("%d ", *(matriz + (i * columnas + j)));
        }
        printf("\n");
    }
    printf("\n");
}

void genVectorCantParesPorFila(int filas, int columnas, int* matriz, int* vector) {
    int cont;
    for (int i = 0; i < filas; i++) {
        cont = 0;
        for(int j = 0; j < columnas; j++) {
            if (*(matriz + (i * columnas + j)) % 2 == 0) {
                cont++;
            }
        }
        *vector = cont;
        vector++;
    }
}
