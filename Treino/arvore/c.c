#include <stdio.h>
#include <stdlib.h>

// --- Definição da Estrutura ---
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// --- Criação de Novo Nó ---
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --- Inserção (Árvore Binária de Busca) ---
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// --- Percursos ---
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// --- Exercício 1: Contagem de Nós ---
int contarNos(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // Adaptado de 'esquerda/direita' para 'left/right'
    return 1 + contarNos(root->left) + contarNos(root->right);
}

// --- Exercício 2: Altura da Árvore ---
int altura(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // Adaptado de 'esquerda/direita' para 'left/right'
    int alturaEsquerda = altura(root->left);
    int alturaDireita = altura(root->right);
    
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

// --- Exercício 3: Menor Valor ---
int menorValor(Node* root) {
    if (root == NULL) {
        printf("A árvore está vazia.\n");
        return -1; // Valor de erro
    }
    Node* atual = root;
    while (atual->left != NULL) {
        atual = atual->left;
    }
    // Adaptado de 'valor' para 'data'
    return atual->data;
}

// --- Exercício 3: Maior Valor ---
int maiorValor(Node* root) {
    if (root == NULL) {
        printf("A árvore está vazia.\n");
        return -1; // Valor de erro
    }
    Node* atual = root;
    while (atual->right != NULL) {
        atual = atual->right;
    }
    // Adaptado de 'valor' para 'data'
    return atual->data;
}

// --- Função Main para Testes ---
int main() {
    Node* root = NULL;
    
    /* Criando a árvore do exemplo:
          5
         / \
        3   7
       / \ / \
      2  4 6  8  (Adicionei o 8 para teste)
    */
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8); 

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
    
    printf("--------------------------\n");
    printf("Total de nós: %d\n", contarNos(root));
    printf("Altura da árvore: %d\n", altura(root));
    printf("Menor valor: %d\n", menorValor(root));
    printf("Maior valor: %d\n", maiorValor(root));

    return 0;
}