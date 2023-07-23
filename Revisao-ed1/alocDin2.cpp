#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char *p;

    if((p = (char *)malloc(23)) == NULL){
        printf("Erro de alocação!\n");
        exit(1);
    }
    strcpy(p, "isso são 22 caracteres");

    p = (char *)realloc(p,24);

    if(!p){
        printf("Erro no realloc\n");
        exit(1);
    }
    
    strcat(p, ".");
    printf(p);
    printf("\n");
    free(p);

    return 0;
}