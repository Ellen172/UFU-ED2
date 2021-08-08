// aerominas
#include <bits/stdc++.h>
using namespace std;

int menorTempo(int qtd_est, int qtd_trans, int pos, int pulo, int *tarefa1, int *tarefa2, int *trans1, int *trans2, int inicio, int *final, int menor){
    int tempo=inicio;
    int linha=0, i=0, pos_aux=pos, cont_trans=0, pulo_aux=pulo;

    cout << "qtd de trans = " << qtd_trans << endl;
    cout << "pos = " << pos << endl;
    cout << "pulo = " << pulo << endl;

    // tempo na linha 1
    linha = 1; i=0;
    while(i < qtd_est){
        if(linha == 1){
            tempo += tarefa1[i];
            cout << "tarefa1[" << i << "] = " << tarefa1[i] << endl;
            if(i == pos_aux && cont_trans < qtd_trans){
                tempo += trans1[pos_aux];
                cout << "trans1[" << pos_aux << "] = " << trans1[pos_aux] << endl;
                pos_aux+=pulo_aux;
                if(pulo > 1) pulo_aux--; 
                cont_trans++;
                linha = 2;
            }
        }
        else{
            tempo += tarefa2[i];
            cout << "tarefa2[" << i << "] = " << tarefa2[i] << endl;
            if(i == pos_aux && cont_trans < qtd_trans){
                tempo += trans2[pos_aux];
                cout << "trans2[" << pos_aux << "] = " << trans2[pos_aux] << endl;
                pos_aux+=pulo_aux;
                if(pulo > 1) pulo_aux--; 
                cont_trans++;
                linha = 1;
            }
        }
        i++;
    }
    if(linha == 1) tempo += final[0];
    else tempo += final[1];
    cout << "tempo = " << tempo << endl;

    // definindo menor tempo
    if(tempo < menor) menor = tempo;

    if(qtd_trans == 0) return menor;
    if(qtd_trans+pos == qtd_est-1) return menorTempo(qtd_est, qtd_trans-1, 0, 1, tarefa1, tarefa2, trans1, trans2, inicio, final, menor);
    if(qtd_trans == 1 || pos+pulo == qtd_est-2) return menorTempo(qtd_est, qtd_trans, pos+1, 1, tarefa1, tarefa2, trans1, trans2, inicio, final, menor);
    return menorTempo(qtd_est, qtd_trans, pos, pulo+1, tarefa1, tarefa2, trans1, trans2, inicio, final, menor);

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

        int menor1 = menorTempo(qtd_est, qtd_est-1, 0, 1, tarefa1, tarefa2, trans1, trans2, inicio[0], final, 10000);
        int menor2 = menorTempo(qtd_est, qtd_est-1, 0, 1, tarefa1, tarefa2, trans1, trans2, inicio[1], final, 10000);

        cout << endl << "Menor =";

        if(menor1 < menor2) cout << menor1 << endl;
        else cout << menor2 << endl;


        n--;
    }  
    return 0;
}