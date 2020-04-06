#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int ghz;
    int anio_fabricacion;
    char* tipo_procesador;
    int cant_nucleos;
} PC;

int main() {
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int cant;
    printf("\n>> Ingrese la cantidad de PCs: "); scanf("%d", &cant);
    PC lista_pc[cant];
    printf("- Lista de %d PCs generada.", cant);

    printf("\n\n");
    return 0;
}
