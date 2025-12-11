#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NOME 8

typedef struct Competidor{
    char nome[MAX_NOME];
    int pontos;
    struct Competidor* left;
    struct Competidor* right;
} Competidor;

Competidor* root = NULL;

Competidor* next = NULL;
Competidor* prev = NULL;

int defineComando(char* comando) {
    return (!strcmp(comando, "ADD"));
}

Competidor* createCompetidor(char* nome, int pontos) {
    Competidor* novoComp = (Competidor*) malloc(sizeof(Competidor));

    if (novoComp != NULL)
    {
        strcpy(novoComp->nome, nome);
        novoComp->pontos = pontos;
        novoComp->left = NULL;
        novoComp->right = NULL;
    }
    return novoComp;
}

Competidor* addPlayer(Competidor* node, char* nome, int pontos, bool* inserido, bool* existente)  {
    if (node == NULL) {
        *inserido = true;
        return createCompetidor(nome, pontos);
    }
    if (!strcmp(nome, node->nome)) {
        *existente = true;
        return node;
    }
    
    if (pontos >= node->pontos)
    {
        node->right = addPlayer(node->right, nome, pontos, inserido, existente);
    }
    else if (pontos < node->pontos)
    {
        node->left = addPlayer(node->left, nome, pontos, inserido, existente);
    }
    
    return node; 
}

void Add(char* nome, int pontos) {
    bool inserido = false;
    bool existente = false;

    root = addPlayer(root, nome, pontos, &inserido, &existente);

    if (existente) {
        printf("%s ja esta no sistema.\n", nome);
    }
    else if (inserido) {
        printf("%s inserido com sucesso!\n", nome);
    }
}


void Prox(Competidor* node, int alvo) {
    if (node == NULL)
    {
        return;
    }
    if (node->pontos == alvo)
    {
        // Maior valor na subárvore esquerda
    if (node->left != NULL) {
        Competidor* temp = node->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        prev = temp;
    }

    // Menor valor na subárvore direita
    if (node->right != NULL) {
        Competidor* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        next = temp;
    }
    
    // Nó alvo foi encontrado
    return;
    }

    else if (alvo < node->pontos) {
        next = node;
        Prox(node->left, alvo);  
    }
    else {
        prev = node;
        Prox(node->right, alvo);
    }
}

void findProx(int pontos) {
    // Reseta os ponteiros
    prev = NULL;
    next = NULL;
    
    // Encontrar o nó alvo
    Prox(root, pontos);

    Competidor* target = NULL;
    Competidor* current = root;
    while(current != NULL) {
        if (current->pontos == pontos) {
            target = current;
            break;
        } else if (pontos < current->pontos) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (target == NULL)
    {
        return;
    }

    char* nome_alvo = target->nome;

    // Apenas N existe no sistema... (Predecessor=NULL e Sucessor=NULL)
    if (prev == NULL && next == NULL) {
        printf("Apenas %s existe no sistema...\n", nome_alvo);
    } 
    // N e o menor! e logo apos vem SUC (Predecessor=NULL)
    else if (prev == NULL) {
        printf("%s e o menor! e logo apos vem %s\n", nome_alvo, next->nome);
    } 
    // N e o maior! e logo atras vem PRE (Sucessor=NULL)
    else if (next == NULL) {
        printf("%s e o maior! e logo atras vem %s\n", nome_alvo, prev->nome);
    } 
    // N vem apos PRE e antes de SUC (Ambos existem)
    else {
        printf("%s vem apos %s e antes de %s\n", nome_alvo, prev->nome, next->nome);
    }
}

int main() {
    int numero_comandos, pontos;
    char nome[MAX_NOME], comando[5];

    scanf("%d", &numero_comandos);

    for (int i = 0; i < numero_comandos; i++)
    {
        scanf("%s ", comando);
        if (defineComando(comando))
        {
            scanf("%s %d", nome, &pontos);
            Add(nome, pontos);
        }
        else {
            scanf("%d", &pontos);
            findProx(pontos);
        } 
    }
	return 0;
}