#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero_strings = 0;

    // Inicializa com NULL
    char** lista_strings = NULL; 

    int memoria_em_alocacao = 1;

    while (memoria_em_alocacao)
    {
        //Cria um array temp para avaliar a entrada
        char temp_array[1000];

        char* nova_string = NULL;

        //Termina a leitura caso o buffer lote
        if (fgets(temp_array, 1000, stdin) == NULL)
        {
            memoria_em_alocacao = 0;
            continue;
        }

        //Retira os bits nao utilizados
        temp_array[strcspn(temp_array, "\n")] = 0;

        //Tamanho real do array
        size_t tamanho_string = strlen(temp_array);

        //Cria o espaço para armazenar a string
        nova_string = (char*) malloc((tamanho_string + 1) * sizeof(char));

        //Copia o temp para a string 
        strcpy(nova_string, temp_array);

        //Aumenta o n° de strings
        numero_strings++;

        //Cria um ptr temporario para tentar alocar a prox string
        char **temp_ptr = (char**)realloc(lista_strings, numero_strings * sizeof(char*));

        if (temp_ptr == NULL)
        {
            //Libera o ponteiro atual
            free(nova_string);
            memoria_em_alocacao = 0;
            continue;
        }
        
        //Atualiza o ptr duplo, agora expandido
        lista_strings = temp_ptr;

        //Adiciona o ponteiro da string para o ponteiro principal
        lista_strings[numero_strings - 1] = nova_string;
    }

    //Dá free caso haja algum erro de alocacao
    if (lista_strings != NULL)
    {
        for (int i = 0; i < numero_strings; i++)
        {
            free(lista_strings[i]);
        }
        free(lista_strings);
    }

    //Caso não consiga alocar
    else
    {
        printf("Falha na alocação.");
    }
    return 0;
}