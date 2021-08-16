#include <bits/stdc++.h>
using namespace std;

int main() {
    int nro, a=0;
    char text[3000];
    cin >> nro;
    gets(text); // armazena o enter do nro;

    while(nro > 0){ 
        gets(text); // lê cada frase

        for(int i=0; i<strlen(text); i++){
            cout << text[i] << endl;
            
        }
        
        nro--;
    }
    return 0;
}