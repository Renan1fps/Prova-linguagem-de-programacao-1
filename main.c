#include <stdio.h>
#include <stdbool.h>

struct aluno {
    int idade;
    int nota;
}
strAluno[2];

int main()
{
    bool condicao = true;
    int valor;
    

    while(condicao){
        printf("\nDigite o número de uma das opções abaixo: ");
        printf("\n1-Cadastrar aluno: ");
        printf("\n2-Listar alunos cadastrados: ");
        printf("\n3-Sair:\n ");
        scanf("%d", &valor);
        
        switch(valor){
            
            case 1:{
                for (int i = 0; i < 2; i++) {
                    printf("\nDigite a idade do aluno: ");
                    scanf("%d", &strAluno[i].idade);
                }
                break;
            }
            
            case 2:{
                for (int i = 0; i < 2; i++) {
                    printf("\nDados aluno:");
                    printf("\nIdade do aluno: %d", strAluno[i].idade);
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
