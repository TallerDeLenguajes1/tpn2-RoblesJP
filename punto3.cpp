#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15 // filas

// funciones
void cargarMatriz(int, int, int*);
void mostrarMatriz(int, int, int*);
void paresPorFila(int, int, int*);

int main() {
    srand(time(NULL));
    int M = rand() % 11 + 5; // columnas
    int matriz[N][M]; // matriz de NxM elementos
    printf("- Matriz %dx%d generada.\n", N, M);
    cargarMatriz(N, M, matriz[0]);
    printf("- Matriz cargada: \n");
    mostrarMatriz(N, M, matriz[0]);
    printf("- Mostrando numeros pares por fila");
    paresPorFila(N, M, matriz[0]);
    return 0;
}

void cargarMatriz(int filas, int columnas, int* matriz) {
    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf(">> Ingrese elemento %d,%d: ", i + 1, j + 1); scanf("%d", matriz + (i * columnas + j));
        }
    }
    printf("\n");
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

void paresPorFila(int filas, int columnas, int* matriz) {
    int cont;
    for (int i = 0; i < filas; i++) {
        cont = 0;
        for(int j = 0; j < columnas; j++) {
            if (*(matriz + (i * columnas + j)) % 2 == 0) {
                cont++;
            }
        }
        printf("\nNumeros pares en la fila %d: %d", i + 1, cont);
    }
}
