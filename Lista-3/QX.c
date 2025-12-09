#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 400

typedef struct pilha_est
{
    char expressao[MAX];
    int top;
} Stack;

void iniciar(Stack* pilha) {
    pilha->top = -1;
}

int cheia(Stack* pilha) {
    if (pilha->top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int vazia(Stack* pilha) {
    if (pilha->top == -1)
    {
        return 1;
    }
    return 0;
    
}

void push(Stack* pilha, char caractere) {
    if (cheia(pilha))
        {
            return;
        }
    pilha->top++;
    pilha->expressao[pilha->top] = caractere;
}

char pop(Stack* pilha) {
    if (vazia(pilha))
    {
        return '\0';
    }
    return pilha->expressao[pilha->top--];
}


char top(Stack* pilha) {
    if (vazia(pilha)) {
        return '\0';
    }
    return pilha->expressao[pilha->top];
}

int prioridade(char operador) {
    switch (operador)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int teste_operando(char operando) {
    return (operando >= 'a' && operando <= 'z');
}

void conversao_polonesa(char* expressao) {
    Stack pilha;
    iniciar(&pilha);
    char polonesa[MAX] = "";
    int index_pol = 0;

    for (int i = 0; i < strlen(expressao); i++)
    {
        char caractere = expressao[i];

        if (teste_operando(caractere))
        {
            polonesa[index_pol++] = caractere;
        }

        else if (caractere == '(')
        {
            push(&pilha, caractere);
        }

        else if (caractere == ')')
        {
            while (!vazia(&pilha) && top(&pilha) != '(')
            {
                polonesa[index_pol++] = pop(&pilha);
            }

            if (!vazia(&pilha) && top(&pilha) == '(')
            {
                pop(&pilha);
            }
        }
        else
        {
            //Vê se a operação atual não é prioritária
            while (!vazia(&pilha) && top(&pilha) != '(' && prioridade(top(&pilha)) >= prioridade(caractere))
            {
                polonesa[index_pol++] = pop(&pilha);
            }
            push(&pilha, caractere);
            
            }
        }
    while (!vazia(&pilha))
    {
        polonesa[index_pol++] = pop(&pilha);
    }
    //Finaliza a string
    polonesa[index_pol] = '\0';
    printf("%s\n", polonesa);
}
    






int main() {
    int n_expressoes;
    char expressao[MAX];

    scanf("%d", &n_expressoes);

    for (int i = 0; i < n_expressoes; i++)
    {
        scanf("%s", expressao);
        conversao_polonesa(expressao);
    }
    
	return 0;
}