#include "pilha_est.h"

int main() {
    Stack pilha;
    iniciar(&pilha);
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("\n");

    for (int i = 1; i <= numero; i++)
    {
        push(&pilha, i);
    }
    printf("\n");

    while(!vazia(&pilha))
    {
        pop(&pilha);
    }
    
    
    return 0;
}