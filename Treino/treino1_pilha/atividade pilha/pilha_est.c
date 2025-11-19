#include <pilha_est.h>

int main() {
    Stack pilha;
    iniciar(&pilha);
    int numero;
    while (scanf("%d ", &numero) == 1)
    {
        push(&pilha, numero);
    }

    while(!vazia(&pilha))
    {
        pop(&pilha);
    }
    
    
    return 0;
}