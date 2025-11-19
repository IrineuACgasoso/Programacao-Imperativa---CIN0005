#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct fila_est
{
    int itens[MAX];
    int front;
    int rear;
} Queue;

int cheia(Queue* fila) {
    return (fila->rear + 1) % MAX == fila->front;
}

int vazia(Queue* fila) {
    return fila->rear == fila->front;

}

void iniciar(Queue* fila) {
    fila->front = 0;
    fila->rear = 0;
}

void enqueue(Queue* fila, int numero) {
    if (cheia(fila))
        {
            printf("A fila está cheia!\n");
            return;
        }
    fila->rear = (fila->rear + 1) % MAX;
    fila->itens[fila->rear] = numero;
    printf("Valor adicionado: %d\n", numero);
}

void desenqueue(Queue* fila) {
    if (vazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    fila->front = (fila->front + 1) % MAX;
    printf("Valor retirado: %d\n", fila->itens[fila->front]);
}
