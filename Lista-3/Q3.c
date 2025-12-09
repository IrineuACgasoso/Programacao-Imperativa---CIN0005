#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_NOME 8

typedef struct Competidor{
    char nome[MAX_NOME];
    int pontos;
    struct Competidor* next;
} Competidor;


int defineComando(char* comando) {
    if (!strcmp(comando, "ADD"))
    {
        //ADD
        return 1;
    }
    else
    {
        //PROX
        return 0;
    }
}

Competidor* addCompetidor(char* nome, int pontos) {
    Competidor* novoComp = (Competidor*) malloc(sizeof(Competidor));

    if (novoComp != NULL)
    {
        for (int i = 0; i < strlen(nome); i++)
        {
            novoComp->nome[i] = nome[i];
        }
        novoComp->pontos = pontos;
        novoComp->next = NULL;
    }
    return novoComp;
}


void checkProx() {}



int main() {
    int numero_comandos, pontos;
    char nome[MAX_NOME], comando[5];

    Competidor competidor;

    scanf("%d", &numero_comandos);

    for (int i = 0; i < numero_comandos; i++)
    {
        scanf("%s ", comando);
        if (defineComando(comando))
        {
            scanf("%s %d", nome, &pontos);
            addCompetidor(nome, pontos);
        }
        else {
            
        }
        
    }
    

	return 0;
}