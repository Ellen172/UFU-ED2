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

int combinacoes(double valor_inicial, double valor, int comb, double moeda, double moeda_inicial){
    cout << "valor_inicial = " << valor_inicial << endl;
    cout << "valor = " << valor << endl;
    cout << "comb = " << comb << endl;
    cout << "moeda = " << moeda << endl;
    cout << "moeda_inicial = " << moeda_inicial << endl;

    int cont=0;
    while(valor-moeda >= 0.00){
        cout << "while" << endl;
        valor -= moeda;
        cont++;
    }
    comb++;
    cout << cont << "x " << moeda << endl;

    if(moeda == 0.05 && moeda_inicial == 0.05) {
        cout << "if 1" << endl;
        return comb;
    }

    moeda = trocaMoeda(moeda);
    return combinacoes(valor_inicial, valor_inicial, comb, moeda, moeda);

}

int main(){
    double valor; 
    cin >> valor;
    while(valor > 0.0){
        double moeda_inicial = defineMoeda(valor);
        int comb=0;
        cout << "resposta = " << combinacoes(valor, valor, comb, moeda_inicial, moeda_inicial) << endl;

        cin >> valor;
    }
}
