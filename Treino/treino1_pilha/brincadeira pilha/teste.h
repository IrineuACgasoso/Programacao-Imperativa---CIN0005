
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void inicialize(Stack *pilha) {
    pilha->top = -1;
}

int isFull(Stack *pilha) {
    return pilha->top == MAX_SIZE - 1 ? 1 : 0;
}

int isEmpty(Stack *pilha) {
    return pilha->top == -1 ? 1 : 0;
}

void push(Stack *pilha, int valor) {
    if (isFull(pilha))
        printf("A pilha está cheia");
    else {
        pilha->top++;
        pilha->items[pilha->top] = valor;
    }
}

int pop(Stack *pilha) {
    if (isEmpty(pilha)) {
        printf("A pilha está vazia");
        return 1;
    }
    else {
        pilha->top--;
        return pilha->items[pilha->top];
    }
}