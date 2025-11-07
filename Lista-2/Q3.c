#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero_strings = 1;

    char** lista_strings = (char**) malloc(numero_strings * sizeof(char*));

    //Se o ponteiro não for nulo
    if (lista_strings != NULL)
    {
        while (1)
        {
        //Cria um array temp para avaliar a entrada
        char temp_array[1000];

        //Termina a leitura caso o buffer lote
        if (fgets(temp_array, 1000, stdin))
        {
            return 0;
        }

        //Retira os bits nao utilizados
        temp_array[strcspn(temp_array, "\n")] = 0;

        //Tamanho real do array
        size_t tamanho_string = strlen(temp_array);

        //Cria o espaço para armazenar a string
        char* nova_string = (char*) malloc((tamanho_string + 1) * sizeof(char));

        //Copia o temp para a string 
        strcpy(nova_string, temp_array);

        
        }
        
    }
    //Caso não consiga alocar
    else
    {
        printf("Falha na alocação.");
    }
    


    return 0;
}