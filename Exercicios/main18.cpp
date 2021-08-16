#include <string.h>
#include <iostream>
#include <cstdio>

void qualLetra(int *alfa, char text, int maior, int menor, int pos){
    if(pos >= 25) return;
    if(text == maior || text == menor){
        alfa[pos]++;
    } 
    return qualLetra(alfa, text, maior+1, menor+1, pos+1);
}

int main() {
    int nro, a=0;
    int alfa[30];
    char text[3000];
    scanf("%d", &nro);
    //gets(text); // armazena o enter do nro;

    for(int j=0; j<30; j++){ // zerando alfabeto;
        alfa[j] = 0;
    }

    while(nro > 0){ 
        scanf("%[^\n]", text);
        //gets(text); // lê cada frase
        for(int i=0; i<strlen(text); i++){
            printf("%c\n", text[i]);
            qualLetra(alfa, text[i], 65, 97, 0);
        }
        
        nro--;
    }

    for(int i=0; i<30; i++){
        int maior = i;

        for(int j=0; j<30; j++){ //localizar maior valor de alfa

            if(alfa[j] > alfa[maior]){
                maior = j;
            }
            if(alfa[j] == alfa[maior]){ // se houver valores iguais prevalece o de menor posicao 
                if(j < maior) maior = j;
            }
        }

        if(alfa[maior] > 0){
            char aux = maior + 65; // nro pertencente a tabela ascii
            printf("%c %d\n", aux, alfa[maior]);
            //cout << aux << " " << alfa[maior] << endl;
            alfa[maior] = 0;
        }
    }

    return 0;
}