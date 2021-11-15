#include <stdio.h>
#include <stdbool.h>

struct aluno {

    char nome[100];
    int idade;
    double nota1;
    double nota2;
}
strAluno[3];

int main()
{
    bool condicao = true;
    int valor, quantidadeParaCadastro, arrayEstaCheio = 0;
    

    while(condicao){
        printf("\nDigite o número de uma das opções abaixo ");
        printf("\n1-Cadastrar um novo estudante ");
        printf("\n2-Listar todos os dados dos estudantes cadastrados ");
        printf("\n3-Sair\n");
        scanf("%d", &valor);
        
        switch(valor){
            
            case 1: {

                printf("Quantos alunos deseja cadastrar?");
                scanf("%d", &quantidadeParaCadastro);
 
                if(arrayEstaCheio > 3 || quantidadeParaCadastro > 3){
                    printf("\nNão é possível cadastrar alunos\n");
                    break;
                }

                for (int i = 0; i < quantidadeParaCadastro; i++) {
                    printf("\nDigite o nome do aluno: ");
                    scanf("%s", strAluno[i].nome);
                    printf("\nDigite a idade do aluno: ");
                    scanf("%d", &strAluno[i].idade);

                    arrayEstaCheio += quantidadeParaCadastro;
                }
                break;
            }
            
            case 2: {
                printf("\n>>>>Alunos cadastrados<<<<");
                for (int i = 0; i < 3; i++) {
                    printf("\nAluno %d", i+1);
                    printf("\nNome do aluno: %s", strAluno[i].nome);
                    printf("\nIdade do aluno: %d", strAluno[i].idade);
                    printf("\n--------------------------------------");
                }
                break;
            }
            
            case 3:{
                condicao = false;
            }
            
        }
    }

    return 0;
}
