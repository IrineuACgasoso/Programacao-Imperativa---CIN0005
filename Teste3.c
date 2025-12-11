#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

typedef struct Stack {
    int itens[MAX];
    int top;
    char variavel[MAX];
    int index_variavel;
    int value[MAX];
} Stack;


Stack* iniciarPilha() {
    Stack* pilha = (Stack*) malloc(sizeof(Stack));
    pilha->top = -1;
    pilha->index_variavel = -1;
}

int isEmpty(Stack* pilha) {
    return pilha->top == -1;
}


int isFull(Stack* pilha) {
    return pilha->top == MAX - 1;
    
}

void pushVariavel(Stack* pilha, char variavel, int value) {

    pilha->index_variavel++;
    pilha->variavel[pilha->index_variavel] = variavel;
    pilha->value[pilha->index_variavel] = value;
    return;
}

void pushInt(Stack* pilha, int numero) {
    pilha->itens[++pilha->top] = numero; 
}

int pop(Stack* pilha) {
    if (isEmpty(pilha)) {
        return 0;
    }
    return pilha->itens[pilha->top--];
}



int testeOperando(char character) {
    return (character >= 'a' && character <= 'z');
}

int testeOperador(char character) {
    return (character == '+' || character == '-' || character == '*');
}


int calcularVariavel(Stack* pilha, char character) {
    
    for (int i = 0; i < strlen(pilha->variavel); i++)
    {
        if (pilha->variavel[i] == character) {
            printf("value %d", pilha->value[i]);
            return pilha->value[i];
        }
    }
    return 0;
}


void calcularNpr(Stack* pilha, char operador) {
    int resultado_operacao = 0, v1, v2;

    v2 = pop(pilha);
    v1 = pop(pilha);

    if (operador == '+') resultado_operacao = v1 + v2;
    else if (operador == '-') resultado_operacao = v1 - v2;
    else if (operador == '*') resultado_operacao = v1 * v2;
    
    printf("%c, %d, %d, %d<<<\n", operador, resultado_operacao, v1, v2);
    pushInt(pilha, resultado_operacao);      
}


int main() {
    Stack* pilha;
    char character;
    char entrada[MAX];
    pilha = iniciarPilha();
    
    while (scanf("%c", &character) != 'E') {

        if (character == '=') {
            scanf(" %c", &character);
            
            //Definiu a variavel da linha
            char variavel = character;

            scanf(" %[^\';']", entrada);
            getchar();
            printf("%s\n", entrada);

            char palavra[32];
            int index_palavra = 0;

            for (int i = 0; i < strlen(entrada) + 1; i++) {

                if (i < strlen(entrada) && entrada[i] != ' ') {
                    palavra[index_palavra++] = entrada[i];
                }
                else {
                    palavra[index_palavra] = 0;
                    index_palavra = 0;
                    //Se variavel
                    if (testeOperando(palavra[0])) {
                        printf("Variavel: %s\n", palavra);
                        //Procura o valor da variavel e retorna o valor
                        int int_respectivo = calcularVariavel(pilha, palavra[0]);
                        if (int_respectivo >= 0) {
                            pushInt(pilha, int_respectivo);
                        }   
                    }
                    //Se operador
                    else if (testeOperador(palavra[0]) && strlen(palavra) == 1) {
                        printf("Operador: %s\n", palavra);
                        calcularNpr(pilha, palavra[0]);
                    }
                    else {
                        int valor = atoi(palavra);
                        printf("Operando numero:%d\n", valor);
                        pushInt(pilha, valor);
                    }
                }
            }
            int resultado = pop(pilha);

            pushVariavel(pilha, variavel, resultado);

            printf("%c = %d\n", variavel, resultado);

            getchar();
        }
    }  
    
	return 0;
}
