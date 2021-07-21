#include <stdio.h>

int main(){
    int teste;
    scanf("%d", &teste);
    for(int i=0; i<teste; i++){
        int qtd;
        scanf("%d", &qtd);
        int moedas, pares=0, impares=0;
        for(int j=0; j<qtd; j++){
            scanf("%d", &moedas);
            if(j%2==0) pares+=moedas;
            else impares+=moedas;
        }
        if(pares > impares) printf("Caso %d: %d\n", i+1, pares);
        else printf("Caso %d: %d\n", i+1, impares);
    }
}