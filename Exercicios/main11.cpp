#include<bits/stdc++.h>
using namespace std;

double defineMoeda(double valor){
    if(valor >= 100) return 100;
    else if(valor >= 50) return 50;
    else if(valor >= 20) return 20;
    else if(valor >= 10) return 10;
    else if(valor >= 5) return 5;
    else if(valor >= 2) return 2;
    else if(valor >= 1) return 1;
    else if(valor >= 0.5) return 0.5;
    else if(valor >= 0.2) return 0.2;
    else if(valor >= 0.1) return 0.1;
    else return 0.05;
}

double trocaMoeda(double moeda){
    if(moeda == 100) return 50;
    if(moeda == 50) return 20;
    if(moeda == 20) return 10;
    if(moeda == 10) return 5;
    if(moeda == 5) return 2;
    if(moeda == 2) return 1;
    if(moeda == 1) return 0.5;
    if(moeda == 0.5) return 0.2;
    if(moeda == 0.2) return 0.1;
    if(moeda == 0.1) return 0.05;
}

int combinacoes(double valor_inicial, double valor, double moeda_inicial, double moeda, int comb){
    cout << "valor = " << valor << endl;
    int cont=0;
    while(valor-moeda >= 0.00){
        valor -= moeda;
        cont++;
        cout << "valor = " << valor << endl;
    }
    comb++;
    cout << cont << "x " << moeda << endl;

    if(moeda == 0.05 && moeda_inicial == 0.05) {
        return comb;
    }

    if(moeda == 0.05){
        cout << "if 1" << endl;
        moeda_inicial = trocaMoeda(moeda_inicial);
        return combinacoes(valor_inicial, valor_inicial, moeda_inicial, moeda_inicial, comb);
    }

    if(cont > 1){
        cout << "if 2" << endl;
        return combinacoes(valor_inicial, valor_inicial-moeda, moeda_inicial, trocaMoeda(moeda), comb);
    }

    if(valor > 0){
        cout << "if 3" << endl;
        return combinacoes(valor_inicial, valor, moeda_inicial, trocaMoeda(moeda), comb);
    }
    
        cout << "else" << endl;
    moeda_inicial = trocaMoeda(moeda_inicial);
    return combinacoes(valor_inicial, valor_inicial, moeda_inicial, moeda_inicial, comb);


}

int main(){
    double valor; 
    cin >> valor;
    while(valor > 0.0){
        double moeda_inicial = defineMoeda(valor);
        cout << "resposta = " << combinacoes(valor, valor, moeda_inicial, moeda_inicial, 0) << endl;

        cin >> valor;
    }
}
