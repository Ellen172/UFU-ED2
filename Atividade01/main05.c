#include <stdio.h>

int main(){
    int n; // numero de museus 
    scanf("%d", &n);
    while(n != -1){
        int cont=0; // numero de vezes que Ada cobra Turinho
        int soma=0; // soma dos ingressos 
        int p[n]; // preço de cada museu
        for(int i=0; i<n; i++){
            scanf("%d", &p[i]);
            soma += p[i];
            if(soma%100 == 0){
                cont++;
                soma = 0;
            }
        }
        printf("%d\n", cont);
        scanf("%d", &n);
    }
}