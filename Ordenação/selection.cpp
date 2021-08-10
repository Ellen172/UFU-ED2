#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Digite a qtd de elementos: ";
    cin >> n;

    int vet[n];
    for(int i=0; i<n; i++){
        cout << "Digite o elemento na posicao: ";
        cin >> vet[i];
    }

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

    for(int i=0; i<n; i++){
        cout << "vet [" << i << "] = " << vet[i] << endl;
    }
}