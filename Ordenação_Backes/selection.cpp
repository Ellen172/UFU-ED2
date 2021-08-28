#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *vet, int n){
    for(int i=0; i<n-1; i++){
        int menor = i;

        for(int j=i+1; j<n; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }

        if(menor != i) {
            int aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
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

    selectionSort(vet, n);

    cout << "Vetores ordenados: ";
    for(int j=0; j<n; j++){
        cout << vet[j];
        if(j<n-1) cout << ", ";
        else cout << endl;
    }

    return 0;
}