#include <stdio.h>

int main() {
    int cont=20;

    while(cont>0){
        int tam, div;
        scanf("%d %d", &tam, &div);

        if(tam == 0 && div == 0) 
            return 0;

        int nro[tam];
        for(int i=0; i<tam; i++){
            scanf("%d", &nro[i]);
        }

        // ordenando
        for(int j=0; j<tam-1; j++){
            int pos=j;
            for(int k=j+1; k<tam; k++){
                if( nro[k]%div < nro[pos]%div ){
                    pos = k;
                }
                else if( nro[k]%div == nro[pos]%div ){
                    if(nro[k]%2==0 && nro[pos]%2==0){
                        // numeros pares
                        if(nro[k] < nro[pos]) {
                            pos = k;
                        }
                    }
                    else if (nro[k]%2!=0 && nro[pos]%2!=0){
                        // numero impares
                        if(nro[k] > nro[pos]) { 
                            pos = k;
                        }
                    }
                    else {
                        // um par e outro impar
                        if(nro[k]%2!=0) {
                            pos = k;
                        }
                    }
                }
            }
            
            // troca de posição
            if(pos != j) {
                int aux = nro[j];
                nro[j] = nro[pos];
                nro[pos] = aux;
            }

        }

        // printando resultado 
        for(int l=0; l<tam; l++){
            printf("%d\n", nro[l]);
        }

        cont--;
    }

    return 0;
}