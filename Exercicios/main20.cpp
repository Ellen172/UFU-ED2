#include <stdio.h>

int resto (int nro, int div){
    if(nro < 0) {
        nro *= -1;
        int mod = nro%div;
        return mod*(-1);
    }
    return nro%div;
}

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
                if( resto(nro[k],div) < resto(nro[pos],div) ){
                    pos = k;
                }
                else if( resto(nro[k],div) == resto(nro[pos],div) ){
                    if(resto(nro[k],2)==0 && resto(nro[pos],2)==0){
                        // numeros pares
                        if(nro[k] < nro[pos]) {
                            pos = k;
                        }
                    }
                    else if (resto(nro[k],2)!=0 && resto(nro[pos],2)!=0){
                        // numero impares
                        if(nro[k] > nro[pos]) { 
                            pos = k;
                        }
                    }
                    else {
                        // um par e outro impar
                        if(resto(nro[k],2)!=0) {
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