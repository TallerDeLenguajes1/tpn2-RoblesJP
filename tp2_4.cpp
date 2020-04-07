#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int ghz;
    int anio_fabricacion;
    char* tipo_procesador;
    int cant_nucleos;
} PC;

// funciones
void cargarLista(int, PC*, char*);
void mostrarLista(int, PC*);
void mostrarPCMasVieja(int, PC*);
void mostrarPCMasRapida(int, PC*);

int main() {
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int cant;

    printf("\n>> Ingrese la cantidad de PCs: "); scanf("%d", &cant);
    PC lista_pc[cant];
    printf("\n- Lista de %d PCs generada.", cant);

    cargarLista(cant, lista_pc, tipos[0]);
    printf("\n\n- Lista cargada con datos aleatorios.");

    printf("\n\n- Mostrando lista");
    mostrarLista(cant, lista_pc);

    printf("\n- Mostrando PC/s mas vieja/s");
    mostrarPCMasVieja(cant, lista_pc);

    printf("\n- Mostrando PC/s mas rapida/s");
    mostrarPCMasRapida(cant, lista_pc);

    printf("\n\n");
    return 0;
}

void cargarLista(int cant, PC* lista_pc, char* tipos) {
    for (int i = 0; i < cant; i++) {
        lista_pc->ghz = rand() % 3 + 1;
        lista_pc->anio_fabricacion = rand() % 18 + 2000;
        lista_pc->tipo_procesador = tipos + (rand() % 6 * 10);
        lista_pc->cant_nucleos = rand() % 4 + 1;
        lista_pc++;
    }
}

void mostrarLista(int cant, PC* lista_pc) {
    for (int i = 0; i < cant; i++) {
        printf("\nPC#%d", i + 1);
        printf("\nVelocidad de procesador: %dGhz", lista_pc->ghz);
        printf("\nTipo de procesador: %s", lista_pc->tipo_procesador);
        printf("\nCantidad de nucleos: %d", lista_pc->cant_nucleos);
        printf("\nAnio de fabricacion: %d", lista_pc->anio_fabricacion);
        printf("\n");
        lista_pc++;
    }
}

void mostrarPCMasVieja(int cant, PC* lista_pc) {
    int aux = INT_MAX;
    for (int i = 0; i < cant; i++) {
        if (lista_pc[i].anio_fabricacion < aux) {
            aux = lista_pc[i].anio_fabricacion;
        }
    }
    for (int i = 0; i < cant; i++) {
        if (lista_pc[i].anio_fabricacion == aux) {
            printf("\nPC#%d", i + 1);
            printf("\nVelocidad de procesador: %dGhz", lista_pc[i].ghz);
            printf("\nTipo de procesador: %s", lista_pc[i].tipo_procesador);
            printf("\nCantidad de nucleos: %d", lista_pc[i].cant_nucleos);
            printf("\nAnio de fabricacion: %d", lista_pc[i].anio_fabricacion);
            printf("\n");
        }
    }
}

void mostrarPCMasRapida(int cant, PC* lista_pc) {
    int aux = 0;
    for (int i = 0; i < cant; i++) {
        if (lista_pc[i].ghz > aux) {
            aux = lista_pc[i].ghz;
        }
    }
    for (int i = 0; i < cant; i++) {
        if (lista_pc[i].ghz == aux) {
            printf("\nPC#%d", i + 1);
            printf("\nVelocidad de procesador: %dGhz", lista_pc[i].ghz);
            printf("\nTipo de procesador: %s", lista_pc[i].tipo_procesador);
            printf("\nCantidad de nucleos: %d", lista_pc[i].cant_nucleos);
            printf("\nAnio de fabricacion: %d", lista_pc[i].anio_fabricacion);
            printf("\n");
        }
    }
}