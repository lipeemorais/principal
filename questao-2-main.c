//-----QUESTÃO 2 -----
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    int opcao;

    do{
        printf("\nOPCOES:\n");
        printf("Opcao 1 -> Execute Pilha\n");
        printf("Opcao 2 -> Execute Fila\n");
        printf("Opcao 3 -> Execute Árvore\n");
        printf("Opcao 0 -> Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            
            case 1:
        {
            Pilha *pilha = criarPilha();
            int opcaoPilha;
            
            do{
                printf("\nOPCOES PILHA:\n");
                printf("Opcao 1 -> Empilhar\n");
                printf("Opcao 2 -> Desempilhar\n");
                printf("Opcao 3 -> Imprimir Pilha\n");
                printf("Opcao 4 -> Limpar Pilha\n");
                printf("Opcao 5 -> Imprimir Topo da Pilha\n");
                printf("Opcao 0 -> Voltar\n");
                printf("Opção: ");
                scanf("%d", &opcaoPilha);

                switch(opcaoPilha){
                    
                    case 1:
                {
                    int dado;
                    
                    printf("Insira o elemento que deseja empilhar: ");
                    scanf("%d", &dado);
                    empilhar(pilha, dado);
                    break;
                }
                case 2:
                    desempilhar(pilha);
                    break;
                case 3:
                    imprimirPilha(pilha);
                    break;
                case 4:
                    limparPilha(pilha);
                    break;
                case 5:
                    imprimirTopoPilha(pilha);
                    break;
                case 0:
                    printf("Voltando ao menu principal\n");
                    break;
                default:
                    printf("Opção invalida!\n");
                    break;
                }
                
            }while(opcaoPilha != 0);

            free(pilha);
            break;
        }
        
        case 2:
        {
            Fila *fila = criarFila();
            int opcaoFila;

            do
            {
                printf("\nOPCOES FILA:\n");
                printf("Opcao 1 -> Enfileirar\n");
                printf("Opcao 2 -> Desenfileirar\n");
                printf("Opcao 3 -> Imprimir Fila\n");
                printf("Opcao 4-> Limpar Fila\n");
                printf("Opcao 5 -> Maior elemento da Fila\n");
                printf("Opcao 6 -> Menor elemento da Fila\n");
                printf("Opcao 0 -> Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcaoFila);

                switch (opcaoFila)
                {
                case 1:
                {
                    int dado;
                    printf("Insira o elemento que deseja enfileirar: ");
                    scanf("%d", &dado);
                    enfileirar(fila, dado);
                    break;
                }
                case 2:
                    desenfileirar(fila);
                    break;
                case 3:
                    imprimirFila(fila);
                    break;
                case 4:
                    limparFila(fila);
                    break;
                case 5:
                {
                    if (fila->frente != NULL){
                        int maiorElemento = encontrarMaiorElementoFila(fila);
                        printf("Maior elemento da Fila: %d\n", maiorElemento);
                    }else{
                        printf("A Fila está vazia!\n");
                    }
                    break;
                }
                case 6:
                {
                    if(fila->frente != NULL){
                        int menorElemento = encontrarMenorElementoFila(fila);
                        printf("Menor elemento da Fila: %d\n", menorElemento);
                    }else{
                        printf("A Fila está vazia.\n");
                    }
                    break;
                }
                case 0:
                    printf("Voltando ao menu principal\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
            } while (opcaoFila != 0);

            free(fila);
            break;
        }
        case 3:
            printf("Executando Arvore:\n");
            break;
        case 0:
            printf("Encerrando o programa\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}