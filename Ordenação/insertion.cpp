#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Digite a qtd de elementos: " ;
    cin >> n;
    int vet[n];

    for(int l=0; l<n; l++){
        cout << "Digite o elemento na posicao " << l << ": ";
        cin >> vet[l];
    }

    for(int j=1; j<n; j++){
        int chave = vet[n];
        int i = j-1;

        while(i>=0 && vet[i]>chave){ // deslocar ate a posição correta
            vet[i+1] = vet[i];
            i -=1;
        }

        vet[i+1] = chave; // inserção na posição ordenada
    }

    for(int m=0; m<n; m++){
        cout << "vet[" << m << "] = " << vet[m] << endl;
    }
}