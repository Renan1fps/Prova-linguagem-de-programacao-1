#include <stdio.h>
#include <stdbool.h>

struct aluno {
    char nome[200];
    float nota1;
    float nota2;
    float mediaFinal;
    bool situacao;
}strAluno[30];

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
    printf("\nNota 1 do aluno: %.1f", a.nota1);
    printf("\nNota 2 do aluno: %.1f", a.nota2);
    printf("\nMédia do aluno: %.1f", a.mediaFinal);
    printf("\nSituação do aluno: ");
    printf("%s", a.situacao ? "APROVADO" : "REPROVADO");
    
}

int main()
{
    const int TAMANHO = 3;
    bool condicao = true;
    int valor, quantidadeParaCadastro, arrayEstaCheio = 0, arrayCount = 0;
    char buscarAlunoPorNome[200];
    float media;
    

    while(condicao){
        printf("\n\nDigite o número de uma das opções abaixo ");
        printf("\n1-Cadastrar um novo estudante ");
        printf("\n2-Listar todos os dados dos estudantes cadastrados ");
        printf("\n3-Buscar aluno por nome");
        printf("\n4-Alterar nota do estudante");
        printf("\n5-Listar estudantes aprovados");
        printf("\n6-Listar estudantes reprovados");
        printf("\n8-Sair\n");
        scanf("%d", &valor);
        
        switch(valor){
            
            case 1: {
                
                printf("Quantos alunos deseja cadastrar?\n");
                scanf("%d", &quantidadeParaCadastro);
 
                if(arrayEstaCheio >= TAMANHO || quantidadeParaCadastro > TAMANHO){
                    printf("\nNão é possível cadastrar alunos\n");
                    break;
                }

                for (int i = 0; i < quantidadeParaCadastro; i++) {
                    setbuf(stdin, NULL);
                    printf("\nDigite o nome completo do aluno %d: ", arrayCount + 1);
                    scanf("%[^\n]", strAluno[arrayCount].nome); 
                    printf("\nDigite a nota 1 do aluno: ");
                    scanf("%f", &strAluno[arrayCount].nota1);
                    printf("\nDigite a nota 2 do aluno: ");
                    scanf("%f", &strAluno[arrayCount].nota2);
                    media = (strAluno[arrayCount].nota1 + strAluno[arrayCount].nota2)/2;
                    strAluno[arrayCount].mediaFinal = media;
                    if(strAluno[arrayCount].mediaFinal > 6){
                        strAluno[arrayCount].situacao = true;
                    }else{
                        strAluno[arrayCount].situacao = false;
                    }
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
                        printf("\n------------------");
                    }
                }
                break;
            }
            
            case 3: {

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

            case 4: {

                setbuf(stdin, NULL);
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", buscarAlunoPorNome);
                for (int i = 0; i < TAMANHO; i++){
                    if(comparaStrings(strAluno[i].nome, buscarAlunoPorNome) == 1){
                        printf("\nDigite a nota 1 do aluno: ");
                        scanf("%f", &strAluno[i].nota1);
                        printf("\nDigite a nota 2 do aluno: ");
                        scanf("%f", &strAluno[i].nota2);
                        float novaMedia = (strAluno[i].nota1 + strAluno[i].nota2)/2;
                        strAluno[i].mediaFinal = novaMedia;
                        if(strAluno[i].mediaFinal > 6){
                        strAluno[i].situacao = true;
                        }else{
                            strAluno[i].situacao = false;
                        }
                        break;
                    }
                }
                break;
            }
      


            case 5: {

                printf("\n>>>>Alunos Aprovados<<<<");
                for (int i = 0; i < TAMANHO; i++){
                    if(strAluno[i].situacao == 1){
                        printAluno(strAluno[i]);
                        printf("\n-----------------");
                    }
                }
                break;
            } 

            case 6: {

                printf("\n>>>>Alunos Reprovados<<<<");
                for (int i = 0; i < TAMANHO; i++){
                    if(strAluno[i].situacao == 0){
                        printAluno(strAluno[i]);
                        printf("\n-----------------");
                    }
                }
                break;
            } 

            case 8: {
                condicao = false;
                break;
            } 
        }
    }

    return 0;
}



