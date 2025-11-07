#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    //Processa as datas
    int dia_niver, mes_niver, ano_niver, dia_atual, mes_atual, ano_atual, probabilidade, resto;
    scanf("%d/%d/%d %d/%d/%d", &dia_niver, &mes_niver, &ano_niver, &dia_atual, &mes_atual, &ano_atual);

    //Amor
    probabilidade = ((dia_niver + mes_niver + ano_niver + dia_atual + mes_atual + ano_atual) * 7) % 101;
    if (probabilidade < 20)
    {
        printf("Amor: %d%% Pessimo dia para se apaixonar.", probabilidade);
    }
    else if (probabilidade >= 20 && probabilidade <= 40)
    {
        printf("Amor: %d%% Melhor manter o coracao <3 longe de perigo.", probabilidade);
    }
    else if (probabilidade >= 41 && probabilidade <= 69)
    {
        printf("Amor: %d%% Se o papo e as ideias baterem, esta liberado pensar em algo.", probabilidade);
    }
    else if (probabilidade >= 70 && probabilidade <= 80)
    {
        printf("Amor: %d%% Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.", probabilidade);
    }
    else
    {
        printf("Amor: %d%% Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.", probabilidade);
    }
    printf("\n");
    
    //Sorte
    probabilidade = (((dia_atual + dia_niver + mes_atual + mes_niver) * 9) + abs(ano_atual - ano_niver)) % 101;
    if (probabilidade < 30)
    {
        printf("Sorte: %d%% Nem jogue moedas pra cima hoje. Sem tigrinho nem jogos de azar, por favor!", probabilidade);
    }
    else if (probabilidade >= 30 && probabilidade <= 50)
    {
        printf("Sorte: %d%% Melhor nao arriscar. Sem tigrinho nem jogos de azar, por favor!", probabilidade);
    }
    else if (probabilidade >= 51 && probabilidade <= 79)
    {
        printf("Sorte: %d%% Por sua conta em risco. Sem tigrinho nem jogos de azar, por favor!", probabilidade);
    }
    else if (probabilidade >= 80 && probabilidade <= 90)
    {
        printf("Sorte: %d%% Hoje vale a pena arriscar. Sem tigrinho nem jogos de azar, por favor!", probabilidade);
    }
    else
    {
        printf("Sorte: %d%% Nao tenha medo de virar cartas hoje. Sem tigrinho nem jogos de azar, por favor!", probabilidade);
    }
    printf("\n");

    //Trabalho
    probabilidade = ((ano_atual + ano_niver) - (dia_atual + dia_niver + mes_atual + mes_niver) * 8) % 101;
    if (probabilidade < 40)
    {
        printf("Trabalho: %d%% Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.", probabilidade);
    }
    else if (probabilidade >= 40 && probabilidade <= 50)
    {
        printf("Trabalho: %d%% Segura a emocao, nao xinga ninguem, nao esquece de beber agua.", probabilidade);
    }
    else if (probabilidade >= 51 && probabilidade <= 69)
    {
        printf("Trabalho: %d%% Um dia proveitoso com certeza, leve sua simpatia consigo.", probabilidade);
    }
    else if (probabilidade >= 70 && probabilidade <= 84)
    {
        printf("Trabalho: %d%% Boas vibracoes hoje, chances podem estar ao seu redor.", probabilidade);
    }
    else
    {
        printf("Trabalho: %d%% Use do maximo de networking possível hoje, dia bom para negocios.", probabilidade);
    }
    printf("\n");
    
    //Cor
    resto = (int)(pow(dia_atual, 2) + pow(dia_niver, 2) + pow(mes_atual, 2) + pow(mes_niver, 2) + pow(ano_atual, 2) + pow(ano_niver, 2)) % 11;
    char cor[20];
    
    switch (resto)
    {
    case 0:
        strcpy(cor, "Cinza.");
        break;
    case 1:
        strcpy(cor, "Vermelho.");
        break;
    case 2:
        strcpy(cor, "Laranja.");
        break;
    case 3:
        strcpy(cor, "Amarelo.");
        break;
    case 4:
        strcpy(cor, "Verde.");
        break;
    case 5:
        strcpy(cor, "Azul.");
        break;
    case 6:
        strcpy(cor, "Roxo.");
        break;
    case 7:
        strcpy(cor, "Marrom.");
        break;
    case 8:
        strcpy(cor, "Rosa.");
        break;
    case 9:
        strcpy(cor, "Preto.");
        break;
    case 10:
        strcpy(cor, "Branco.");
        break;
    default:
        break;
    }
    
    printf("Cor: %s", cor);

    return 0;
}
