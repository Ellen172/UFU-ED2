#include <stdio.h>
#include <stdlib.h>

int somaMoedas(int qtd, int *moedas, int i, int d, int maior) {
    int j=i, soma=0;
    if(i >= qtd){
        return maior;
    }
    while(qtd>0 && j<qtd){
        soma += moedas[j];
        j+=d; 
    }
    if(soma > maior){
        maior = soma;
    } 
    if(d >= qtd){
        return somaMoedas(qtd, moedas, i+1, 2, maior);
    } 
    return somaMoedas(qtd, moedas, i, d+1, maior);

}

int main(){
    int teste;
    scanf("%d", &teste);
    for(int i=0; i<teste; i++){
        int qtd, distancia=2, inicio=0;
        scanf("%d", &qtd);
        int moedas[qtd];
        for(int j=0; j<qtd; j++){
            scanf("%d", &moedas[j]);
        }
        int maior = 0;
        int resposta = somaMoedas(qtd, moedas, inicio, distancia, maior);
        printf("Caso %d: %d\n", i+1, resposta);
    }
    return 0;
}