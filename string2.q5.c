#include <stdio.h>
#include <string.h>

 // pode omitir quantos elementos o vetor possui
void preencher(char nomes[][100], float* notas1, float* notas2, float* m, char sit[][15]){
    for (int i = 0; i < 20; i++){
        printf("Aluno %d \n", i+1);
        printf("Informe o nome do aluno: ");
        fgets(nomes[i], 20, stdin);
        printf("\n");
        printf("Primeira nota: ");
        scanf("%f", &notas1[i]);
        printf("Segunda nota: ");
        scanf("%f", &notas2[i]);

        //calculando a situacao

        m[i] = (notas1[i]*2 + notas2[i]*3)/5;
        if (m[i] >= 3 && m[i] < 7){
        strcpy(sit[i], "recuperação"); 
        }
        else if(m[i] >= 7){
            strcpy(sit[i], "aprovado"); 
        }
        else {
            strcpy(sit[i], "reprovado"); 
        }

        printf("O(a) aluno(a) %s obteve média %.2f e está %s \n", nomes[i], m[i], sit[i]); //diferenca de 'c' e 's'
    }
}

float mediaT(float* vet){
    int i;
    float soma = 0;
    for(i = 0; i < 20; i++){
        soma += vet[i];
    }
    return soma / 20;
}

//chamar a função dentro do procedimento
void exibirabaixomedia(char nome[][100], float* m){  
    float media = mediaT(m);
    int cont = 0;
    printf("Média da turma: %.2f \n", media);
    printf("Alunos cuja média ficou abaixo da média da turma: \n");
    for (int i  = 0; i < 20; i++){
        if (m[i] < media){
            printf("O(a) aluno(a) %s está com a média abaixo da turma \n", nome[i]);
            cont++;
        }
    }
    printf("Total de alunos abaixo da média da turma é de: %d\n", cont);
}


int main(){
    char nomes[20][100]; // quantos elementos o vetor possui x tamanho 
    char sit[20][15];
    float notas2[20], notas1[20], medias[20];

    printf("Dados dos alunos: \n");
    preencher(nomes, notas1, notas2, medias, sit);
    exibirabaixomedia(nomes, medias);

    return 0;
}
