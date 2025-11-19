#include "fila.h"

int main() {
    Queue fila;
    iniciar(&fila);
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("\n");
    for (int i = 1; i <= numero; i++)
    {
        enqueue(&fila, i);
    }
    printf("\n");

    while(!vazia(&fila))
    {
        desenqueue(&fila);
    }
     
    return 0;
}