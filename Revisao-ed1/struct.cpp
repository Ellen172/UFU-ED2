#include <bits/stdc++.h>

struct notasProva {
    float nota1; 
    float nota2; 
    float nota3; 
};

struct aluno {
    int matricula; 
    notasProva notas;
};

int main(){
    struct aluno turma[3];

    printf("Digite a matricula: \n");
    scanf("%d", &turma[0].matricula);

    printf("Digite a nota da prova 1: \n");
    scanf("%f", &turma[0].notas.nota1);

    printf("Digite a nota da prova 2: \n");
    scanf("%f", &turma[0].notas.nota2);
    
    printf("Digite a nota da prova 3: \n");
    scanf("%f", &turma[0].notas.nota3);

    turma[1] = turma[0];
    turma[2] = turma[0];

    for(int i=0; i<3; i++){
        printf("Aluno: %d \t Matricula: %d \t Nota 1: %.2f \t Nota 2: %.2f \t Nota 3: %.2f \n", 
            i, turma[i].matricula, turma[i].notas.nota1, turma[i].notas.nota2, turma[i].notas.nota3);
    }

    return 0;
}