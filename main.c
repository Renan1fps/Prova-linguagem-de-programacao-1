#include <stdio.h>
#include <stdbool.h>

struct aluno {
    char nome[200];
    float nota1;
    float nota2;
}strAluno[3];

int comparaStrings(char nomeUm[], char nomeDois[]){
    int i = 0;
    while(nomeUm[i] == nomeDois[i] && nomeUm[i] != '\0' && nomeDois[i]  != '\0'){
        i++;
    }
    if(nomeUm[i]== '\0' && nomeDois[i]== '\0'){
        return 1;
    }else{
        return 0;
    }
}

void printAluno(struct aluno a){
    printf("\nNome do aluno: %s", a.nome);
    printf("\nNota 1 do aluno: %.2f", a.nota1);
    printf("\nNota 2 do aluno: %.2f", a.nota2);
}

int main()
{
    const int TAMANHO = 3;
    bool condicao = true;
    int valor, quantidadeParaCadastro, arrayEstaCheio = 0, arrayCount = 0;
    char buscarAlunoPorNome[200];
    

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
 
                if(arrayEstaCheio >= TAMANHO || quantidadeParaCadastro > TAMANHO){
                    printf("\nNão é possível cadastrar alunos\n");
                    break;
                }

                for (int i = 0; i < quantidadeParaCadastro; i++) {
                    setbuf(stdin, NULL);
                    printf("\nDigite o nome completo do aluno %d:", i+1);
                    scanf("%[^\n]", strAluno[arrayCount].nome); 
                    printf("\nDigite a nota 1 do aluno: ");
                    scanf("%f", &strAluno[arrayCount].nota1);
                    printf("\nDigite a nota 2 do aluno: ");
                    scanf("%f", &strAluno[arrayCount].nota2);
                    arrayCount += 1;
                    arrayEstaCheio += quantidadeParaCadastro;
                }
                break;
            }
            
            case 2: {

                printf("\n>>>>Alunos cadastrados<<<<");
                for (int i = 0; i < TAMANHO; i++) {
                    if(strAluno[i].nota1 != 0){
                        printf("\nAluno %d", i+1);
                        printAluno(strAluno[i]);
                        printf("\n--------------------------------------");
                    }
                }
                break;
            }
            
            case 3:{
                setbuf(stdin, NULL);
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", buscarAlunoPorNome);

                for (int i = 0; i < TAMANHO; i++){
                    if(comparaStrings(strAluno[i].nome, buscarAlunoPorNome) == 1){
                        printAluno(strAluno[i]);
                        break;
                    }
                }
                break;
            }

            case 4:{
                printf("Saindo do sistema");
                condicao = false;
                break;
            } 
        }
    }

    return 0;
}


