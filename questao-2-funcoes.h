//estrutura para o nó da pilha
typedef struct NoPilha{
    int dado;
    struct NoPilha *proximo;
}NoPilha;

typedef struct{
    NoPilha *topo;
}Pilha;

Pilha *criarPilha(){
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

//função para empilhar elementos
void empilhar(Pilha *pilha, int dado){
    NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    novoNo->dado = dado;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

//função para desempilhar elementos
void desempilhar(Pilha *pilha){
    if (pilha->topo != NULL){
        NoPilha *noRemovido = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(noRemovido);
    }
}

//função para imprimir pilha
void imprimirPilha(Pilha *pilha){
    NoPilha *noAtual = pilha->topo;
    printf("Pilha: ");
    while (noAtual != NULL)
    {
        printf("%d ", noAtual->dado);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

//função para limpar pilha 
void limparPilha(Pilha *pilha){
    while (pilha->topo != NULL){
        desempilhar(pilha);
    }
}

//função para imprimir topo da pilha 
void imprimirTopoPilha(Pilha *pilha){
    if (pilha->topo != NULL){
        printf("Topo da Pilha: %d\n", pilha->topo->dado);
    }else{
        printf("A Pilha está vazia.\n");
    }
}

//estrutura para o nó da fila
typedef struct NoFila{
    int dado;
    struct NoFila *proximo;
}NoFila;

typedef struct{
    NoFila *frente;
    NoFila *tras;
}Fila;

Fila *criarFila(){
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    novaFila->frente = NULL;
    novaFila->tras = NULL;
    return novaFila;
}

//função que enfilera os elementos
void enfileirar(Fila *fila, int dado){
    NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if(fila->tras == NULL){
        fila->frente = novoNo;
        fila->tras = novoNo;
    }else{
        fila->tras->proximo = novoNo;
        fila->tras = novoNo;
    }
}

//função que desenfileira os elementos
void desenfileirar(Fila *fila){
    if(fila->frente != NULL){
        NoFila *noRemovido = fila->frente;
        fila->frente = fila->frente->proximo;
        free(noRemovido);

        if(fila->frente == NULL){
            fila->tras = NULL;
        }
    }
}

//função que imprime a fila 
void imprimirFila(Fila *fila){
    NoFila *noAtual = fila->frente;
    printf("Fila: ");
    while(noAtual != NULL){
        printf("%d ", noAtual->dado);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

//função que limpa a fila 
void limparFila(Fila *fila){
    while(fila->frente != NULL){
        desenfileirar(fila);
    }
}

//função para encontrar o maior elemento na fila 
int encontrarMaiorElementoFila(Fila *fila){
    int maiorElemento = fila->frente->dado;
    NoFila *noAtual = fila->frente->proximo;

    while(noAtual != NULL){
        if (noAtual->dado > maiorElemento){
            maiorElemento = noAtual->dado;
        }
        noAtual = noAtual->proximo;
    }

    return maiorElemento;
}

//função para encontrar menor elemento na fila 
int encontrarMenorElementoFila(Fila *fila){
    int menorElemento = fila->frente->dado;
    NoFila *noAtual = fila->frente->proximo;

    while(noAtual != NULL){
        if(noAtual->dado < menorElemento){
            menorElemento = noAtual->dado;
        }
        noAtual = noAtual->proximo;
    }

    return menorElemento;
}