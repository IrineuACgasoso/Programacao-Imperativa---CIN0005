#include "teste.h"


int main() {
    Stack pilha;
    inicialize(&pilha);
    int fatorial, resultado = 1;
    printf("Digite o fatorial desejado: ");
    scanf("%d", &fatorial);
    
    for (int i = 1; i <= fatorial; i++)
    {
        push(&pilha, i);
    }
    
    while (!isEmpty(&pilha))
    {
        resultado = resultado * pop(&pilha);
    }
    
    printf("\nResultado: %d", resultado);
    
    return 0;
}