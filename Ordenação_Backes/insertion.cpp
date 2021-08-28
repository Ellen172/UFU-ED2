# include <bits/stdc++.h>
using namespace std;

void insertionSort(int *vet, int size){
    int i, j, aux;
    for(i=1; i<size; i++){
        aux = vet[i];
        for(j=i; (j>0)&&(aux < vet[j-1]); j--){
            vet[j] = vet[j-1]; 
            // desloca os elementos maiores para a proxima posição
        }
        vet[j] = aux; // insere no 'espaço em branco' deixado pela troca de posições
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

    insertionSort(vet, n);

    cout << "Vetores ordenados: ";
    for(int j=0; j<n; j++){
        cout << vet[j];
        if(j<n-1) cout << ", ";
        else cout << endl;
    }

    return 0;
}