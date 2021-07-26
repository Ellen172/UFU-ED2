#include <bits/stdc++.h>
using namespace std;

void descer(int *gasto, int *col, int *lin, int x){
    cout << "descer" << endl;
    *gasto += 20 - x;
    *col = *col+1; 
    *lin = *lin+1;
}

void subir(int *gasto, int *col, int *lin, int x){
    cout << "subir" << endl;
    *gasto += 60 - x;
    *col = *col-1; 
    *lin = *lin+1;
}

void manter(int *gasto, int *col, int *lin, int x){
    cout << "manter" << endl;
    *gasto += 30 - x;
    *lin = *lin+1;
}


int main(){
    int n; // casos de teste no arquivo
    cin >> n;
    for(int i=0; i<n; i++){
        int x; // distancia para voar
        cin >> x;

        int dv = x/100; // distancia para voar
        int v[10][dv]; // vento em cada 100 milhas
        int gasto=0; // gasto de combustivel

        for(int c=0; c<10; c++){
            for(int l=0; l<dv; l++){
                cin >> v[c][l];
            }
        }
        
        cout << endl;
        for(int c=0; c<10; c++){
            for(int l=0; l<dv; l++){
                cout << v[c][l] << " ";
            }
            cout << endl;
        }
        
        int col=9, lin=0;
        while(col >= 0 && lin <= dv){
            int acima=300, abaixo=300, lateral=300;
            int x = v[col][lin];

            if (col < 8) abaixo = v[col+1][lin+1]; // para descer a coluna precisa ser menor q 8
            if (col > 0) acima = v[col-1][lin+1]; // para subir a coluna precisa ser maior que 0
            if (lin <= dv) lateral = v[col][lin+1]; // para seguir para o lado a linha precisa ser menor que dv

            cout << "col = " << col << endl;
            cout << "lin = " << lin << endl;
            cout << "x = " << x << endl;
            cout << "acima = " << acima << endl;
            cout << "abaixo = " << abaixo << endl;
            cout << "lateral = " << lateral << endl;
            
            if(col == 9 && lin == 0){
                // primeiro ponto (só pode subir)
                subir(&gasto, &col, &lin, x);
            } 

            else if(col + lin == 10){
                // ultimo ponto para descer
                descer(&gasto, &col, &lin, x);
            }

            else {
                if(acima < 0) acima += 20;
                if(abaixo < 0) abaixo += 20;
                if(lateral < 0) lateral += 20;
                
                if(abaixo < acima && abaixo < lateral){
                    descer(&gasto, &col, &lin, x);
                }
                else if (lateral < acima && lateral < abaixo){
                    manter(&gasto, &col, &lin, x);
                }
                else if(acima < lateral && acima < abaixo){
                    subir(&gasto, &col, &lin, x);
                }
            }
        }

        cout << "gasto total = " << gasto << endl;
    }
}