// aerominas
#include <bits/stdc++.h>
using namespace std;

int menorTempo(int qtd_est, int qtd_trans, int *tarefa1, int *tarefa2, int *trans1, int *trans2, int *inicio, int *final, int menor){
    int tempo1=inicio[0];
    int tempo2=inicio[1];
    int linha=0, i=0;

    cout << "qtd de trans = " << qtd_trans << endl;

    // tempo na linha 1
    linha = 1; i=0;
    while(i < qtd_est){
        if(i < qtd_trans){
            if(linha == 1){
                tempo1 += tarefa1[i];
                tempo1 += trans1[i];
                linha = 2;
            }
            else{
                tempo1 += tarefa2[i];
                tempo1 += trans2[i];
                linha = 1;
            }
        }
        else {
            if(linha == 1) tempo1 += tarefa1[i];
            else tempo1 += tarefa2[i];
        }
        i++;
    }
    if(linha == 1) tempo1 += final[0];
    else tempo1 += final[1];
    cout << "tempo 1 = " << tempo1 << endl;

    // tempo na linha 2
    linha = 2; i=0;
    while(i < qtd_est){
        if(i < qtd_trans) {
            if(linha == 1){
                tempo2 += tarefa1[i];
                tempo2 += trans1[i];
                linha = 2;
            }
            else{
                tempo2 += tarefa2[i];
                tempo2 += trans2[i];
                linha = 1;
            }
        }
        else{
            if(linha == 1) tempo2 += tarefa1[i];
            else tempo2 += tarefa2[i];
        }
        i++;
    }
    if(linha == 1) tempo2 += final[0];
    else tempo2 += final[1];
    cout << "tempo 2 = " << tempo2 << endl;

    // definindo menor tempo
    if(tempo1 < menor) menor = tempo1;
    if(tempo2 < menor) menor = tempo2;

    if(qtd_trans == 0) return menor;
    return menorTempo(qtd_est, qtd_trans-1, tarefa1, tarefa2, trans1, trans2, inicio, final, menor);

}

int main(){
    int n; // casos de teste
    cout << "Digite a qtd de testes: ";
    cin >> n;
    while(n > 0){
        int qtd_est; // qtd de estações que cada linha possui
        cout << "Quantas estacoes cada linha possui? ";
        cin >> qtd_est;

        int tarefa1[1002], tarefa2[1002]; // tempo de realização em cada linha de produção 
        for(int i=0; i<qtd_est; i++){
            cout << "Tempo de realizacao da tarefa na estacao "<< i+1 << " para linha 01: ";
            cin >> tarefa1[i]; 
            cout << "Tempo de realizacao da tarefa na estacao "<< i+1 << " para linha 02: ";
            cin >> tarefa2[i];
        }

        int trans1[1002], trans2[1002]; // tempo de transferência (linha 1 para 2 e linha 2 para 1)
        for(int j=0; j<qtd_est-1; j++){
            cout << "Tempo de transferencia da linha 01 para linha 02 na estacao " << j+1 << ": ";
            cin >> trans1[j]; 
            cout << "Tempo de transferencia da linha 02 para linha 01 na estacao " << j+1 << ": ";
            cin >> trans2[j];
        }

        int inicio[2]; // tempo para iniciar o processo em cada linha de montagem
        for(int l=0; l<2; l++){
            cout << "Insira o tempo para iniciar o processo na linha " << l+1 << ": ";
            cin >> inicio[l];
        }

        int final[2]; // tempo para finalizar o processo em cada linha de montagem
        for(int l=0; l<2; l++){
            cout << "Insira o tempo para finalizar o processo na linha " << l+1 << ": ";
            cin >> final[l];
        }

        cout << endl << "Menor tempo = " << menorTempo(qtd_est, qtd_est-1, tarefa1, tarefa2, trans1, trans2, inicio, final, 10000) << endl;


        n--;
    }  
    return 0;
}