#include <bits/stdc++.h>
using namespace std;

int main() {
    int hor, aux, cont=0;
    cin >> hor; 
    int vet[hor];
    for(int i=0; i<hor; i++){
        cin >> vet[i];
    }

    // ordenar elementos 
    // cada troca de posição conta um nó

    for(int j=0; j<hor-1; j++){
        for(int k=j+1; k<hor; k++){
            if(vet[k] < vet[j]) {
                aux = vet[k];
                vet[k] = vet[j];
                vet[j] = aux;   
                cont ++;             
            }
        }
    }

    cout << cont << endl;

    return 0;
}