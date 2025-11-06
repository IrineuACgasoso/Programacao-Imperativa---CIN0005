#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int fatoracao(int fatorado, int *fatores_primos) {
    //Cópia do fatorado      //Comeca em 2
    int fat_copy = fatorado, fator_divisao = 2, indice_atual_array = 0;
    while (fat_copy > 1 && (long long) fator_divisao * fator_divisao <= fat_copy)
    {
        //Enquanto o fator atual for divisor
        if (fat_copy % fator_divisao == 0)
        {
            //Adiciona num array
            fatores_primos[indice_atual_array] = fator_divisao;
            //Divide o numero
            fat_copy = fat_copy / fator_divisao;
            //"Pula" uma casa no array para o proximo valor 
            indice_atual_array += 1;
        }
        else
        {   
            //Caso nao seja divisivel por 2, aumenta 1 no fator
            if (fator_divisao == 2)
            {
                fator_divisao++;
            }
            //Caso contrario, soma 2
            else
            {
                fator_divisao += 2;
            }
        }
    }

    //Adiciona o ultimo primo da fatoração
    if (fat_copy > 1) { 
        fatores_primos[indice_atual_array++] = fat_copy;
    }
    //Retorna o indice atual (vulgo tamanho) do array
    return indice_atual_array;
}

void vigenere(char *descripto, int fator_inicio) {

    //Enquanto nao chegar ao caractere de parada, executa
    for (int i = 0; descripto[i] != '\0'; i++)
    {
        //Se maiuscula
        if (descripto[i] >= 65 && descripto[i] <= 90)
        {
            //Transforma em numeros de 0 a 25, soma a PA, calcula o mod para lidar com 
            //"viradas" no alfabeto e transforma em ASCII novamente
            descripto[i] = ((descripto[i] - 65) + fator_inicio) % 26 + 65; 
            //Executa a PA
            fator_inicio++;
        }
        //Se minuscula
        else if (descripto[i] >= 97 && descripto[i] <= 122)
        {
            //Transforma em numeros de 0 a 25, soma a PA, calcula o mod para lidar com 
            //"viradas" de alfabeto e transforma em ASCII novamente
            descripto[i] = ((descripto[i] - 97) + fator_inicio) % 26 + 97; 
            //Executa a PA 
            fator_inicio++;
        }
        //Caso seja simbolo ou letra nao convencional, nao faz nada
    }  
}

int main(){
    //Array para armazenar os primos
    int array_primos[1000];
    //Inputs
    int numero;
    char string[1000];
    char caractere;

    //Processa e calcula o numero de fatores
    scanf("%d", &numero);
    int tamanho = fatoracao(numero, array_primos);
    printf("%d\n", tamanho);

    //Retira os \n acumulados no buffer pelo scanf
    while (getchar() != '\n');

    //Adiciona a string ao array por fgets, garantindo confiança na representação da string
    fgets(string, 100, stdin);
    //Retira o \n deixado pelo fgets
    string[strcspn(string, "\n")] = 0;
    //Descriptografa
    vigenere(string, tamanho);
    printf("%s", string);
    
    return 0;
}
