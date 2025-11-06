#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //Quantas linhas serão
    int altura;
    //Letra final
    char char_final;
    scanf("%c", &char_final);
    altura = char_final - 'A' + 1;

    //Print horinzontal
    for (char i = 'A'; i <= char_final; i++)
    {   
        //Quantos pontos terão para cada lado
        int numero_pontos_linha = char_final - i;

        //Qtd de pontos "à esquerda" das letras
        for (int p = 0; p < numero_pontos_linha; p++) {
            printf(".");
        }
        
        //Lado esquerdo do triang (de 'A' -> 'char_final')
        for (char j = 'A'; j <= i; j++) {
            printf("%c", j);
        }

        //Lado direito do triang ('char_final' -> 'A')
        for (char k = i - 1; k >= 'A'; k--) {
            printf("%c", k);
        }

        //Qtd de pontos "à direita" das letras
        for (int p = 0; p < numero_pontos_linha; p++) {
            printf(".");
        }
        printf("\n");
    }
	return 0;

}
