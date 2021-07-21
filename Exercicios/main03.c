#include <stdio.h>
#include <string.h>

int main(){
    int n; // mensagens coletadas
    scanf("%d", &n);
    while(n != 0){
        char planeta[50], resposta[50];
        int ano, tempo; // ano que a mensagem chegou; tempo que demorou
        int envio[n], menor=4000; // data de envio; menor valor
        for(int i=0; i<n; i++){
            scanf("%s", planeta);
            scanf("%d %d", &ano, &tempo);
            envio[i] = ano - tempo;
            if( envio[i] < menor){
                menor = envio[i];
                strcpy(resposta, planeta);
            }
        }
        printf("%s\n", resposta);
        scanf("%d", &n);
    }
}