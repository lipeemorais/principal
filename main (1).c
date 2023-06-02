//----- QUESTÃO 1 -----
#include <stdio.h>

//função para imprimir o vetor
void printVet(int vet[], int tam){
    int i;
    
    for(i = 0; i < tam; i++){
        printf("%d| ", vet[i]);
    }
}

//função para ordenar os elementos (BUBBLESORT)
void bubbleSort(int vet[], int tam){
    int x, y;
    
    for(x = 0; x < tam - 1; x++){
        for(y = 0; y < tam - x - 1; y++){
            if(vet[y] > vet[y + 1]){
                //Troca dos elementos vet[y] e vet[y+1]
                
                int prov = vet[y];
                vet[y] = vet[y + 1];
                vet[y + 1] = prov;
            }
        }
    }
}

//função para ordenar os elementos (INSERTIONSORT)
void insertionSort(int vet[], int tam){
    int i, atual, j;
    
    for(i = 1; i < tam; i++){
        atual = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > atual){
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        
        vet[j + 1] = atual;
    }
}

//função para imprimir o vetor
void imprimeVet(int vet[], int tam){
    int i; 
    
    for(i = 0; i < tam; i++){
        printf("%d", vet[i]);
        printf("\n");
    }
}

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




