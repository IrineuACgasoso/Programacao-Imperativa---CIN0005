#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Sinal {
    int amplitude;
    int frequencia;
    float energia;
    char periodico[10];
    int pontos;
    int ind_original;
    int vitoria_charmosa;
 } Sinal;

int compararador_sinais(const void *primeiro_ponteiro, const void *segundo_ponteiro) {
    //Converte os ponteiros de void para struct
    const Sinal *sinal_a = (const Sinal *)primeiro_ponteiro;
    const Sinal *sinal_b = (const Sinal *)segundo_ponteiro;

    //B - A garante que o maior valor vai vir primeiro
    if (sinal_a->pontos != sinal_b->pontos) {
        return (sinal_b->pontos - sinal_a->pontos);
    }
    //Desempate por ordem original
    return (sinal_a->ind_original - sinal_b->ind_original);
}



Sinal* funcao_print(Sinal* cremosa, Sinal* inimigo, int* numero_inimigos) {

    //PRINT CREMOSA//

    printf("%d %d %.2f %d", cremosa->amplitude, cremosa->frequencia, cremosa->energia, cremosa->pontos);
    //Caso ela tenha vencido algum sinal
    if (cremosa->vitoria_charmosa == 1)
    {
        //Printa o winner + parenteses inical
        printf(" WINNER (");
    
        //Printa quais sinais ela venceu
        for (int i = 0; i < numero_inimigos; i++)
        {
            //Pula os vetores 'F' / Derrotas
            if (inimigo[i].vitoria_charmosa == 1)
            {
                printf(" %d", i + 1);    
            }
        }
        //Printa o parenteses final
        printf(" )");
    }
    printf("\n---\n");

    //PRINT INIMIGOS//
    
    //Contador para flawless victory
    int flawless_victory = 0;
    for (int m = 0; m < numero_inimigos; m++)
    {
        printf("%d %d %.2f %d", inimigo[m].amplitude, inimigo[m].frequencia, inimigo[m].energia, inimigo[m].pontos);
        if (inimigo[m].vitoria_charmosa == 0)
        {
            printf(" WINNER");
        }
        else
        {
            flawless_victory++;
        }
        printf("\n");
    }
    if (flawless_victory == numero_inimigos)
    {
        printf("FLAWLESS VICTORY!");
    }
    
    
}

int main() {

    //Instancia de cremosa (unica)
    Sinal sinal_cremosa;
    int pontuacao_cremosa = 0;
    sinal_cremosa.pontos = 0;
    sinal_cremosa.vitoria_charmosa = 0;
    
    //Ponteiro para os inimigos (multiplos ou nao)
    Sinal* sinal_inimigos = NULL;
    int pontuacao_inimigo = 0;
    //Serve de indice atual
    int numero_inimigos = 0;
    int array_inimigos_derrotados[100];

    //Struct temporaria para impedir leituras erradas no EOF
    Sinal inimigo_temp;

    //Processa os dados da cremosa
    scanf("%d %d %f %s", &sinal_cremosa.amplitude, &sinal_cremosa.frequencia, &sinal_cremosa.energia, sinal_cremosa.periodico);

    //Processa os dados dos inimigos
    int return_scanf = scanf("%d %d %f %s", &inimigo_temp.amplitude, &inimigo_temp.frequencia, &inimigo_temp.energia, inimigo_temp.periodico);    
    
    while (return_scanf == 4) {

        //Restabelece as pontuacoes como zero a cada inimigo novo
        int pontuacao_inimigo = 0;
        int pontuacao_cremosa = 0;

        //Tenta alocar o proximo inimigo
        sinal_inimigos = (Sinal*) realloc(sinal_inimigos, (numero_inimigos + 1) * sizeof(Sinal));
        if (sinal_inimigos != NULL)
        {
            sinal_inimigos[numero_inimigos] = inimigo_temp;
            //Salva o indice original antes da reordenacao
            sinal_inimigos[numero_inimigos].ind_original = numero_inimigos + 1;

            //BATALHA 
            //Amplitude  
            if (sinal_cremosa.amplitude > sinal_inimigos[numero_inimigos].amplitude)
            {
                pontuacao_cremosa++;
            }
            else if (sinal_cremosa.amplitude < sinal_inimigos[numero_inimigos].amplitude)
            {
                pontuacao_inimigo++;
            }

            //Frequencia
            if (sinal_cremosa.frequencia == sinal_inimigos[numero_inimigos].frequencia)
            {
                pontuacao_cremosa++;
                pontuacao_inimigo++;
            }
            else if (sinal_cremosa.frequencia % sinal_inimigos[numero_inimigos].frequencia == 0)
            {
                pontuacao_cremosa++;
            }
            else if (sinal_inimigos[numero_inimigos].frequencia % sinal_cremosa.frequencia == 0)
            {
                pontuacao_inimigo++;
            }
            
            //Energia 
            if (sinal_cremosa.energia > sinal_inimigos[numero_inimigos].energia)
            {
                pontuacao_cremosa++;
            }
            else if (sinal_cremosa.energia < sinal_inimigos[numero_inimigos].energia)
            {
                pontuacao_inimigo++;
            }

            //Periodico
            if (strcmp(sinal_cremosa.periodico, "TRUE") == 0 && strcmp(sinal_inimigos[numero_inimigos].periodico, "FALSE") == 0)
            {
                pontuacao_cremosa++;
            }
            else if (strcmp(sinal_cremosa.periodico, "FALSE") == 0 && strcmp(sinal_inimigos[numero_inimigos].periodico, "TRUE") == 0)
            {
                pontuacao_inimigo++;
            }
            
            if (pontuacao_cremosa > pontuacao_inimigo)
            {
                //Salva se o atual inimigo perdeu
                sinal_inimigos[numero_inimigos].vitoria_charmosa = 1;
                //Salva que cremosa venceu alguma vez
                sinal_cremosa.vitoria_charmosa = 1;
            }
            else
            {
                //Salva se ele venceu
                sinal_inimigos[numero_inimigos].vitoria_charmosa = 0;
            }
            
            //Adiciona os pontos
            if (pontuacao_cremosa > sinal_cremosa.pontos)
            {
                //Verifica se a nova pontuacao e melhor
                sinal_cremosa.pontos = pontuacao_cremosa;
            }

            sinal_inimigos[numero_inimigos].pontos = pontuacao_inimigo;

            //Incrementa o inimigo/indice
            numero_inimigos++;

            //Tenta ler o proximo inimigo
            return_scanf = scanf("%d %d %f %s", &inimigo_temp.amplitude, &inimigo_temp.frequencia, &inimigo_temp.energia, inimigo_temp.periodico);
        }
        else {
            printf("Erro.");
        }
    }

    //Qsort para ordenar decrescentemente
    qsort(sinal_inimigos, numero_inimigos, sizeof(Sinal), compararador_sinais);
    //Chama a funcao para fazer o output
    funcao_print(&sinal_cremosa, sinal_inimigos, numero_inimigos);

    free(sinal_inimigos);

    return 0;
}
