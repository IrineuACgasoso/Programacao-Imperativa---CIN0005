#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int soma_algarismos(int numero) {
    int digito, soma = 0;
    while (numero > 0)
    {
        //Soma as unidades
        digito = numero % 10;
        soma += digito;
        //Retira a unidade
        numero /= 10;
    }
    return soma;  
}

int main() {
    //Variaveis padrao
    int numero_xupenio, numero_canais, i, entrada1, entrada2;
    int melhor_canal, melhor_minuto, melhor_termo, soma_sala_vip;
    int distancia = INT_MAX, distancia_anterior = INT_MAX, melhor_distancia = INT_MAX;
    //Processa quantos canais haverão
    scanf("%d %d", &numero_xupenio, &numero_canais);
    for (int canal_atual = 1; canal_atual < numero_canais + 1; canal_atual++)
    {
        scanf("%d %d", &entrada1, &entrada2);
        //Variaveis para o loop
        int minuto_atual = 1, bool = 1;

        //Testa a entrada 1
        int distancia1 = abs(entrada1 - numero_xupenio);
        if (distancia1 < melhor_distancia)
        {
            melhor_distancia = distancia1;
            melhor_canal = canal_atual;
            melhor_minuto = minuto_atual;
            melhor_termo = entrada1;
        }
        //Caso sejam iguais, escolhe o maior canal 
        else if (distancia1 == melhor_distancia) {
            if (canal_atual > melhor_canal) {
                melhor_canal = canal_atual;
                melhor_minuto = minuto_atual;
                melhor_termo = entrada1;
            }
        }

        //Incremento no minuto
        minuto_atual++;

        //Testa a entrada 2
        int distancia2 = abs(entrada2 - numero_xupenio);
        if (distancia2 < melhor_distancia)
        {
            melhor_distancia = distancia2;
            melhor_canal = canal_atual;
            melhor_minuto = minuto_atual;
            melhor_termo = entrada2;
        }
        //Caso sejam iguais, escolhe o maior canal 
        else if (distancia2 == melhor_distancia) {
            if (canal_atual > melhor_canal) {
                melhor_canal = canal_atual;
                melhor_minuto = minuto_atual;
                melhor_termo = entrada2;
            }
        }

        //Incremento no minuto
        minuto_atual++;

        //Salva a ultima dist antes de entrar no loop
        int distancia_anterior = distancia2; 

        while (bool)
        {
            //Testa o termo posterior
            int novo_termo = entrada1 + entrada2;
            entrada1 = entrada2;
            entrada2 = novo_termo;

            //Se o termo posterior for ruim, sai do loop
            int nova_distancia = abs(novo_termo - numero_xupenio);
            if (nova_distancia > distancia_anterior) {
                break;
            }
            //Testa o novo termo
            if (nova_distancia < melhor_distancia) {
                melhor_distancia = nova_distancia;
                melhor_canal = canal_atual;
                melhor_minuto = minuto_atual;
                melhor_termo = novo_termo;
            }
            //Caso sejam igual, escolhe o maior canal 
            else if (nova_distancia == melhor_distancia) {
                if (canal_atual > melhor_canal) {
                    melhor_canal = canal_atual;
                    melhor_minuto = minuto_atual;
                    melhor_termo = novo_termo;
                }
            }

            //Incremento no minuto
            minuto_atual++;
            //Ultima dist passa a ser na nova
            distancia_anterior = nova_distancia;      
        }
    }
    
    soma_sala_vip = soma_algarismos(melhor_termo);
    
    //Print caso VIP
    if (soma_sala_vip > 10)
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!", melhor_canal, melhor_minuto);
    }
    else
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(", melhor_canal, melhor_minuto);
    }

	return 0;
}
        
