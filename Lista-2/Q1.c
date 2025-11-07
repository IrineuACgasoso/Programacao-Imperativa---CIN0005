#include <stdio.h>

int main() {
    char c = 'a';
    char* pc = &c;

    printf("endereço de c: %p || valor de c: %c\n", &c, c);

    printf("valor de pc: %p || valor do endereço apontado: %c\n", pc, *pc);

    printf("endereço de pc: %p\n", &pc);

    printf("endereço 1: %p || endereço 2: %p\n", &*pc, *&pc);
    printf("Ambos são iguais ao endereço de c por serem operadores opostos.\n");
    printf("Logo, mesmo realizando trajetos de endereço distintos, eles resultam no mesmo valor.\n");

    return 0;
}
