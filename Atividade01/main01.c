//Minha mãe mandou

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, n, k;
    scanf("%d", &x);
    for(int i=0; i<x; i++){
        scanf("%d %d", &n, &k);
        int cont=0, volta=0;
        for(int i=0; i<(29*k); i++){
            if(cont == n) cont=0;
            cont++;
            if(cont == 1) volta++;
        }
        printf("%d %d\n", volta, cont+1);
    }
}