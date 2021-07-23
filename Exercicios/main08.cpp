#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; // casos de teste no arquivo
    cin >> n;
    for(int i=0; i<n; i++){
        int x; // distancia para voar
        cin >> x;

        int dv = x/100; // distancia para voar
        int v[dv]; // vento em cada 100 milhas
        int gasto=0; // gasto de combustivel
        for(int j=9; j>=0; j--){

            for(int k=0; k<dv; k++){
                cin >> v[k];
            }
            for(int l=0; l<dv; l++){
                cout << v[l] << " ";
            } cout << endl;

            cout << "dv = " << dv << endl;
            int pos = 0; // posição do voo

            if (pos-1 >= 0 && v[pos-1] >= v[pos]){
                cout << "descer" << endl;
            } else if(pos+1 <= dv && v[pos+1] > v[pos]){
                cout << "subir" << endl;
            } else {
                cout << "manter" << endl;
            }

        }
        cout << "gasto total = " << gasto << endl;
    }
}