//----- QUESTÃO 1 -----
#include <stdio.h>
#include "funcoes.h"

int main(){
    int tam;
    
    printf("Insira o tamanho do seu vetor:\n");
    scanf("%d", &tam);
    
    int vet[tam];
    int i;
    
    for(i = 0; i < tam; i++){
        printf("Insira o %d° elemento: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    int opcao;
    
    printf("Digite o metodo de ordenacao que deseja:\n");
    printf("\nOpcao 1 -> BubbleSort");
    printf("\nOpcao 2 -> InsertionSort");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
        
    printf("\n\nVetor desordenado:");
    printVet(vet, tam);
        
    switch(opcao){
        case 1:
            bubbleSort(vet, tam);
            printf("\nBubbleSort: ");
            break;
        case 2:
            insertionSort(vet, tam);
            printf("\nInsertionSort: ");
            break;
    }
    
    printVet(vet, tam);
    
    return 0;
}





