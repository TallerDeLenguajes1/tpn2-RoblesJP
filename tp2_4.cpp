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
void mostrarPC(PC*);

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
        mostrarPC(lista_pc);
        lista_pc++;
    }
}

void mostrarPCMasVieja(int cant, PC* lista_pc) {
    int aux = INT_MAX;
    PC* p_aux = lista_pc;
    for (int i = 0; i < cant; i++) {
        if (lista_pc->anio_fabricacion < aux) {
            aux = lista_pc->anio_fabricacion;
        }
        lista_pc++;
    }
    lista_pc = p_aux;
    for (int i = 0; i < cant; i++) {
        if (lista_pc->anio_fabricacion == aux) {
            printf("\nPC#%d", i + 1);
            mostrarPC(lista_pc);
        }
        lista_pc++;
    }
}

void mostrarPCMasRapida(int cant, PC* lista_pc) {
    int aux = 0;
    PC* p_aux = lista_pc;
    for (int i = 0; i < cant; i++) {
        if (lista_pc->ghz > aux) {
            aux = lista_pc->ghz;
        }
        lista_pc++;
    }
    lista_pc = p_aux;
    for (int i = 0; i < cant; i++) {
        if (lista_pc->ghz == aux) {
            printf("\nPC#%d", i + 1);
            mostrarPC(lista_pc);
        }
        lista_pc++;
    }
}

void mostrarPC(PC* pc) {
    printf("\nVelocidad de procesador: %dGhz", pc->ghz);
    printf("\nTipo de procesador: %s", pc->tipo_procesador);
    printf("\nCantidad de nucleos: %d", pc->cant_nucleos);
    printf("\nAnio de fabricacion: %d", pc->anio_fabricacion);
    printf("\n");
}