#include<stdlib.h>
#include<stdio.h>

float *get_mem() {
    float *p = (float *)calloc(100, sizeof(float)); // aloca o ponteiro p em 100 espaços de tamanho float

    if(!p){
        printf("Erro de alocação!\n");
        exit(1);
    }

    return p;
}

struct endereco {
    char nome[40];
    char rua[40];
    char cidade[40];
    char estado[2];
};

struct endereco *get_struct() {
    struct endereco *p; 

    if((p = (struct endereco *)malloc(sizeof(struct endereco))) == NULL){
        printf("Erro de alocação!");
        exit(1);
    }

    return p;
}

int main(){

    //get_mem();
    get_struct();

    return 0;
}