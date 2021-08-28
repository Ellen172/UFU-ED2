#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *vet, int size) {
    int i, continua, aux, fim=size;
    do{
        continua = 0;
        for(i=0; i<fim-1; i++){
            if(vet[i] > vet[i+1]) {
                // troca a posição
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                continua = i;
            }
        }
        fim --;
    }while (continua != 0);
}

void bubble2(int *vet, int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(vet[i] > vet[j]){
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){
    int n, vet[200];
    cout << "Tamanho do vetor: ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++){
        cout << "Digite o " << i+1 << "o vetor: ";
        cin >> vet[i];
    }

    //bubbleSort(vet, n);
    bubble2(vet, n);

    cout << "Vetores ordenados: ";
    for(int j=0; j<n; j++){
        cout << vet[j];
        if(j<n-1) cout << ", ";
        else cout << endl;
    }

    return 0;
}