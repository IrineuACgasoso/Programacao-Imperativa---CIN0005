#include <stdio.h>

int main() {

    int vet[5] = {1,2,3,4,5};
    int* p = &vet[0];

    //a)
    printf("endereço de vet: %p || endereço de p: %p\n", vet, p);

    //b)
    printf("valores de vet usando p[]:\n");
    for (int j = 0; j < 5; j++)
    {
        printf("posição %d: %d\n", j, p[j]);
    }
    //c)
    printf("valores de vet usando *p:\n");
    for (int k = 0; k < 5; k++)
    {
        printf("posicao %d: %d\n", k, *(p + k));
    }
    //d)
    printf("valores de vet:\n");
    for (int m = 0; m < 5; m++)
    {
        printf("vet[%d]: %d\n", m, vet[m]);
    }

    return 0;
}