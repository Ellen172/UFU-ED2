// Minha mãe mandou

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x; // repetições do programa
    int n, k;
    // k = quantas vezes serão repetidos a "mamãe mandou"
    // n = qtd de pratos
    scanf("%d", &x);
    for(int i=0; i<x; i++){
        scanf("%d %d", &n, &k);
        int prato=1, volta=0; // prato escolhido; qtd de voltas;
        for(int j=0; j<(29*k); j++){
            if(prato == n+1) prato=1;
            if(prato == 1) volta++; 
            prato++;
        }
        if(prato > n) prato=1;
        printf("%d %d\n", volta, prato);
    }
}