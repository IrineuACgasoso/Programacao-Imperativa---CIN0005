#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 501

typedef struct Node
{
    char character;
    struct Node* next;
} Node;

Node* head = NULL;
Node* cursor = NULL;

Node* createNode(char caractere) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL)
    {
        newNode->character = caractere;
        newNode->next = NULL;
    }
    return newNode;
}

void insert(char caractere) {
    Node* newNode = createNode(caractere);

    if (newNode != NULL)
    {
        newNode->next = cursor->next;
        cursor->next = newNode;
        cursor = newNode;
    }
}

void end() {
    Node* atual = head;

    while (atual->next != NULL)
    {
        atual = atual->next;
    }
    cursor = atual;
}


void free_text() {
    Node* atual = head;
    Node* next;
    while (atual != NULL) {
        next = atual->next;
        free(atual);
        atual = next;
    }
    head = NULL;
    cursor = NULL;
}

void print_beiju() {
    Node* atual = head->next;
    while (atual != NULL)
    {
        printf("%c", atual->character);
        atual = atual->next;
    }
}

void resolver(char* text) {
    head = createNode('\0');
    cursor = head;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '[')
        {
            cursor = head;
        }
        else if (text[i] == ']')
        {
            end();
        }
        else
        {
            insert(text[i]);
        }
    }
    print_beiju();
    free_text();
}

int main() {
    char text[MAX];

    scanf("%s", text);
    resolver(text);

	return 0;
}