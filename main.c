#include <stdio.h>
#include <stdbool.h>

struct aluno {

    char nome[200];
    float nota1;
    float nota2;
}
strAluno[3];

int main()
{
    const int TAMANHO = 3;
    bool condicao = true;
    int valor, quantidadeParaCadastro, arrayEstaCheio = 0;
    

    while(condicao){
        printf("\n\nDigite o número de uma das opções abaixo ");
        printf("\n1-Cadastrar um novo estudante ");
        printf("\n2-Listar todos os dados dos estudantes cadastrados ");
        printf("\n3-Buscar aluno por nome");
        printf("\n4-Sair\n");
        scanf("%d", &valor);
        
        switch(valor){
            
            case 1: {
                
                printf("Quantos alunos deseja cadastrar?");
                scanf("%d", &quantidadeParaCadastro);
 
                if(arrayEstaCheio > TAMANHO || quantidadeParaCadastro > TAMANHO){
                    printf("\nNão é possível cadastrar alunos\n");
                    break;
                }

                for (int i = 0; i < quantidadeParaCadastro; i++) {
                    setbuf(stdin, NULL);
                    printf("\nDigite o nome completo do aluno %d:", i+1);
                    scanf("%[^\n]", strAluno[i].nome); 
                    printf("\nDigite a nota 1 do aluno: ");
                    scanf("%f", &strAluno[i].nota1);
                    printf("\nDigite a nota 2 do aluno: ");
                    scanf("%f", &strAluno[i].nota2);

                    arrayEstaCheio += quantidadeParaCadastro;
                }
                break;
            }
            
            case 2: {

                printf("\n>>>>Alunos cadastrados<<<<");
                for (int i = 0; i < TAMANHO; i++) {
                    if(strAluno[i].nome != 0){
                    printf("\nAluno %d", i+1);
                    printf("\nNome do aluno: %s", strAluno[i].nome);
                    printf("\nNota 1 do aluno: %f", strAluno[i].nota1);
                    printf("\nNota 2 do aluno: %f", strAluno[i].nota2);
                    printf("\n--------------------------------------");
                    }
                }
                break;
            }
            
            case 3:{

                char buscarAlunoPorNome[200];
                printf("Digite o nome do aluno: ");
                scanf("%s", buscarAlunoPorNome);

                for (int i = 0; i < TAMANHO; i++){
                    if(strAluno[i].nome == buscarAlunoPorNome){
                        printf("\nNome do aluno: %s", strAluno[i].nome);
                        printf("\nNota 1 do aluno: %f", strAluno[i].nota1);
                        printf("\nNota 2 do aluno: %f", strAluno[i].nota2);
                    }else{
                        printf("\nAluno não encontrado");
                    }
                }
                break;
            }

            case 4:{
                condicao = false;
                break;
            }
            
        }
    }

    return 0;
}

