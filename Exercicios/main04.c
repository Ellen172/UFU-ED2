#include <stdio.h>

int main(){
    int n; // quantidade de k
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        if(i == 0) printf("K");
        else printf("k");
    }
    printf("!\n");
}