#include <stdio.h>
#include <stdlib.h>




// ======================= Estrutura da Lista ========================= //

struct node {   
  int dado;   
  struct node *prox;   
} Node;

typedef struct node No;

struct Lista{
   struct node *inicio;
    struct node *fim;
} Lista;

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int menu();

void uniao(struct Lista *lista1, struct Lista *lista2, struct Lista *lista3);

// ======================= Estrutura da Lista ========================= //


// *******************************************************************************************************


// ======================= Estrutura da Pilha ========================= //

struct stack {
    int tam;
    int dado;
    struct node *endereco;
    struct stack *prox;
};

typedef struct stack Pilha;


// ======================= Estrutura da Pilha ========================= //

void inicializarPilha(Pilha *pilha);
int estaVaziaPilha(Pilha *pilha);
int push(Pilha *pilha,struct node *endereco);
int pop(Pilha *pilha);  
int imprimeTopo(Pilha pilha);
void imprimeTudo(Pilha pilha);

int main() {


    int op;
    int dado;

    // Inicializando as listas;
    struct Lista lista1;
    struct Lista lista2;
    struct Lista lista3;

    inicializar(&lista1);   
    inicializar(&lista2);
    inicializar(&lista3);

    // Inicializando as Pilhas
    Pilha p1,p2;
    inicializarPilha(&p1);
    inicializarPilha(&p2);

    do{
        op = menu();
        switch(op){
            case 1:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        if(&lista1.fim != NULL){
                            if(inserirFim(&lista1, dado))
                                printf("Insercao no fim realizado com sucesso na lista 1!");
                            else
                                printf("Falha na insercao!");
                        }else{
                            if(inserirFim(&lista3, dado))
                                printf("Insercao no fim realizado com sucesso na lista 3!");
                            else
                                printf("Falha na insercao!");
                        }
                        
                        break;
            case 2:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        if(inserirFim(&lista2, dado))
                            printf("Insercao no fim realizado com sucesso na lista 2");
                        else
                            printf("Falha na insercao!");
                        break;
            case 3:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        if(inserirFim(&lista3, dado))
                            printf("Insercao no fim realizado com sucesso na lista 3");
                        else
                            printf("Falha na insercao!");
                        break;    
            
            case 4: mostrar(lista1);
                        break;
            case 5: mostrar(lista2);
                        break;
            case 6: mostrar(lista3);
                        break;
            case 7:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        printf("\n%d removidos!!!", remover(&lista1,dado));
                        break;
            case 8:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        printf("\n%d removidos!!!", remover(&lista2,dado));
                        break;
            case 9:  printf("Digite um numero: ");
                        scanf("%d", &dado);
                        printf("\n%d removidos!!!", remover(&lista3,dado));
                        break;
            case 10: 
                        uniao(&lista1,&lista2,&lista3);
                        printf("União das listas realizada com sucesso: ");
                        break;
            case 11:  printf("Listagem feita: ");
                        /* scanf("%d", &dado);
                        printf("\n%d removidos!!!", remover(&lista3,dado));
                        break; */
                        break;
            case 12:    
                        printf("Empilhando as listas");
                        while(&lista1.fim->prox != NULL){
                            push(&p1,lista1.inicio);
                            lista1.inicio = lista1.inicio->prox;
                        }
                        while(&lista2.fim != NULL){
                            push(&p1,lista2.inicio);
                            lista2.inicio = lista2.inicio->prox;
                        }
                        
                        printf("Inserções na pilha realizada com sucesso");
                        break;
            case 13:    printf("\nTchau!!!");
                        break;
            default: printf("\nOpcao Invalida!!!");
        }

    }while(op != 13);
    
    return 0;

}


// ======================= Estrutura da Pilha ========================= //

void inicializarPilha(Pilha *pilha) {
    pilha->tam = 0;
    pilha->prox = NULL;
}

int estaVaziaPilha(Pilha *pilha){
    return pilha->prox == NULL ? 1 : 0;
}

int push(Pilha *pilha,struct node *endereco){
    Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
    if(novo == NULL)
       return 0;

    novo->endereco = endereco;
    novo->prox = pilha->prox;
    pilha->prox = novo;

    pilha->tam++;

    return 1;
}

int pop(Pilha *pilha){
    Pilha *aux = pilha->prox;
    int rem = aux->dado;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

int imprimeTopo(Pilha pilha){

    Pilha *aux = pilha.prox;
    
    return aux->dado;
}

void imprimeTudo(Pilha pilha){
    
    Pilha *aux = pilha.prox;
    
    if(aux == NULL)
    {
        printf("\nPilha esta vazia !");
       return;
    }
    
    printf("\nPilha\n");
    
    while(aux != NULL){
        printf("%d  "  , aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

// ======================= Estrutura da Pilha ========================= //


// ======================= Estrutura da Lista ========================= //

int menu(){
    int op;
    printf("\n 1 - Inserir no Fim Lista 1");
    printf("\n 2 - Inserir no Fim Lista 2");
    printf("\n 3 - Inserir no Fim Lista 3");

    printf("\n 4 - Mostrar Lista 1");
    printf("\n 5 - Mostrar Lista 2");
    printf("\n 6 - Mostrar Lista 3");
    
    printf("\n 7 - Remover itens Lista 1");
    printf("\n 8 - Remover itens Lista 2");
    printf("\n 9 - Remover itens Lista 3");
    printf("\n 10 - Realizar união das listas");
    printf("\n 11 - Inserir as listas em suas devidas pilhas");
    printf("\n 12 - Mostrar Lista unida");
    printf("\n 13 - Sair\n");
    scanf("%d", &op);
    return op;
}

void inicializar(struct Lista *lista){   
  lista->inicio = NULL;   
  lista->fim = NULL;   
}   


int inserirFim(struct Lista *lista, int dado){
    struct node  *novo = malloc(sizeof(struct node));
    novo->dado = dado;

    
    if(novo == NULL)
        return 0;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = NULL;
    }else{
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->fim->prox = NULL;
    }

    return 1;
}

int remover(struct Lista *lista, int dado){
    struct node *aux;
    struct node *ant;
    int qtdDel = 0;
    
    aux = lista->inicio;
    ant = NULL;

    while(aux != NULL){
        if(aux->dado == dado){
            qtdDel++;
            if(aux == lista->inicio){
                lista->inicio = aux->prox;
                free(aux);
                aux = lista->inicio;
            }else if(aux == lista->fim){
                ant->prox = NULL;
                lista->fim = ant;
                free(aux);
                aux = NULL;
            }else{
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
        }else{
            ant = aux;
            aux = aux->prox;
        }
    }
    
    return qtdDel;
}

int mostrar(struct Lista lista){
    struct node *aux;   
    
    if(lista.inicio == NULL){
        return 0;   
    }else{
        aux = lista.inicio;
        while(aux != NULL){
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
    }
    return 1;
}


void uniao(struct Lista *lista1, struct Lista *lista2, struct Lista *lista3){
    
    lista2->fim->prox = lista3->inicio;
    lista1->fim->prox = lista3->inicio;
        
}

// ======================= Estrutura da Lista ========================= //
