#include <stdio.h>
#include <stdlib.h>

int dp ( int *pesos, int *valores, int n_itens, int C) {

    if(n_itens == 0) return 0; // itens acabaram

    if(n_itens == 1) {
        if(pesos[0] > C) return 0; // não cabe na mochila
        else {
            return valores[0];
        }
    }

    else {
        int MAX = -1;
        for(int i = n_itens -1; i >= 0; i--) {

            int parte1 = dp(pesos, valores, n_itens -1, C - pesos[i]);
            int parte2 = dp(pesos, valores, n_itens-1, C);

            int maxLocal = parte1 > parte2 ? parte1 : parte2;

            if (maxLocal > MAX) 
                MAX = maxLocal;
        }
        return MAX;
    }
}

int main() {


    printf("melhor valor possivel da mochila = %d\n", dp(pesos, valores, n_itens);
}