/*
ler vetor de alunos com  3 notas até fim
armazenar em arquivo bin
funções:

criar o arquivo texto com
nome:
nota1:
nota2:
nota3:
media:
gaslighting:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float notas[3];
    float media;
} Aluno;

float calculadora_media(Aluno a) {
    float soma = 0.0;

    for (int k = 0; k < 3; k++)
    {
        soma += a.notas[k];
    }

    return soma / 3.0;
}

void boletim_html(Aluno *alunos, int qtd_alunos) {
    FILE *html;
    if ((html = fopen64("boletim.html", "w")) != NULL) {
        //Cria a tabela
        fprintf(html, "<!DOCTYPE html>\n<html>\n<head>\n");
        fprintf(html, "<title>Boletim de Notas</title>\n");
        fprintf(html, "<style>table, th, td {border: 1px solid black; border-collapse: collapse; padding: 8px; text-align: left;}</style>\n");
        fprintf(html, "</head>\n<body>\n");
        fprintf(html, "<h2>Relatório de Desempenho</h2>\n");

        //Adiciona os dados a serem adicionados
        fprintf(html, "<table style=\"width:100%%\">\n");
        fprintf(html, "<tr><th>Nome</th><th>Nota 1</th><th>Nota 2</th><th>Nota 3</th><th>Média</th><th>Situação</th></tr>\n");

        for (int j = 0; j < qtd_alunos; j++)
        {
            //Mensagem dependente da media
            const char *mensagem;
            if (alunos[j].media >= 7.0)
            {
                mensagem = "Aprovado";
            }
            else if (alunos[j].media < 7.0)
            {
                mensagem = "Reprovado";
            }
            
            //Cria uma linha
            fprintf(html, "<tr>");

            //Add nome
            fprintf(html, "<td>%s</td>", alunos[j].nome);

            //Add notas
            fprintf(html, "<td>%.1f</td>", alunos[j].notas[0]);
            fprintf(html, "<td>%.1f</td>", alunos[j].notas[1]);
            fprintf(html, "<td>%.1f</td>", alunos[j].notas[2]);

            //Add media
            fprintf(html, "<td><b>%.2f</b></td>", alunos[j].media);

            //Add mensagem
            fprintf(html, "<td>%s</td>", mensagem);

            //Fim da linha
            fprintf(html, "</tr>\n");
        }
        //Parte inferior da tabela
        fprintf(html, "</table>\n");
        fprintf(html, "</body>\n</html>\n");
        
        fclose(html);
    }
    return;
}

int main() {
    FILE *arq;
    Aluno *aluno = NULL;
    int i = 0;
    if ((arq = fopen64("boletim.bin", "wb")) != NULL) {
        
        aluno = (Aluno *) malloc(sizeof(Aluno));
        if (aluno != NULL)
        {
            printf("Qual o nome do aluno? "); scanf(" %99[^\n]", aluno[i].nome);
            //Enquanto nao for fim
            while ((strcmp(aluno[i].nome, "fim")))
            {
                //Processa as notas e calcula a media
                printf("Quais foram as suas notas? ");scanf("%f %f %f", &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
                aluno[i].media = calculadora_media(aluno[i]);

                //Incrementa i
                i++;
                
                //Tenta alocar o prox aluno
                aluno = (Aluno *) realloc(aluno, sizeof(Aluno) * (i + 1));
                if (aluno != NULL)
                {
                    printf("Qual o nome do aluno? "); scanf(" %99[^\n]", aluno[i].nome);
                }

                else {
                    exit(1);
                }
            }
            
            //Escreve todos os alunos
            if (i)
            {
                fwrite(aluno, sizeof(Aluno), i, arq);
                boletim_html(aluno, i);
            }
        }
        else {
            exit(1);
        }
    }
    return 0;
}