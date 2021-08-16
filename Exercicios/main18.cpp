#include <bits/stdc++.h>
using namespace std;

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
    cin >> nro;
    gets(text); // armazena o enter do nro;

    for(int j=0; j<30; j++){ // zerando alfabeto;
        alfa[j] = 0;
    }

    while(nro > 0){ 
        gets(text); // lê cada frase

        for(int i=0; i<strlen(text); i++){
            cout << text[i] << endl;
            qualLetra(alfa, text[i], 65, 97, 0);
        }
        
        nro--;
    }

    for(int i=0; i<29; i++){
        int maior = i;

        for(int j=i+1; j<30; j++){ //localizar maior valor de alfa
            if(alfa[j] > alfa[maior]){
                maior = j;
            }
            if(alfa[j] == alfa[maior]){ // se houver valores iguais prevalece o de menor posicao 
                if(j < maior) maior = j;
            }
        }

        if(alfa[maior] > 0){
            char aux = maior + 64; // nro pertencente a tabela ascii
            cout << aux << " " << alfa[maior] << endl;;
            alfa[maior] = 0;
        }
    }

    // char maior_letra=65;
    // for(int j=0; j<30; j++){ 
    //     if(alfa[j] > 0){
    //         cout << maior_letra << " = " << alfa[j] << endl;
    //     }
    //     maior_letra++;
    // }

    return 0;
}