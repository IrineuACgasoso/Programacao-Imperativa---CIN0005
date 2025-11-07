#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float calculo_media_final(int tamanho, float array[tamanho]) {
    //Menores notas iniciadas como valores altos
    float menor_nota = 99, segunda_menor_nota = 99, soma_notas = 0;
    //Percorre o array
    for (int j = 0; j < tamanho ; j++) {
        //Avalia se o proximo é maior e se a menor nota é maior
        if (array[j] < menor_nota)
        {
            segunda_menor_nota = menor_nota;
            menor_nota = array[j];
        }
        //Caso não for a menor nota, testa se pode ser a segunda menor
        else if (array[j] < segunda_menor_nota)
        {
            segunda_menor_nota = array[j];
        }
    }
    //Soma as notas
    for (int k = 0; k < tamanho; k++)
    {
        soma_notas += array[k];
    }
    //Retira as menores
    soma_notas -= menor_nota + segunda_menor_nota;
    //Media
    float media_final = soma_notas/ (tamanho - 2);
    return media_final;
}

int main() {
    int qtd_notas;
    float nota, media;
    //Processa o numero de notas
    scanf("%d", &qtd_notas);

    if (qtd_notas < 3)
    {
        printf("Numero de notas insuficiente.");
    }
    //Caso a qtd de notas seja suficiente
    else {
        float array_notas[qtd_notas];

        for (int i = 0; i < qtd_notas; i++)
        {
            //Processa as notas
            scanf("%f ", &nota);
            array_notas[i] = nota;
        }
        
        //Chama a funcao media final
        media = calculo_media_final(qtd_notas, array_notas);
        
        //Printa a media
        printf("%.2f", media);

        return 0;
    }
}
