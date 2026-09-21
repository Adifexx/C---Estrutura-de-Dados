#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li=NULL;
    }
    return li;
}

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL ){ return 0; }

    cel* aux = (cel*) malloc (sizeof(cel));
    if(aux == NULL){ return 0; }
    aux->conteudo = x;
    aux->seg = NULL;

    if((*lista)==NULL){//se a lista estiver vazia.
        *lista = aux;
    }else{
        cel *temp;
        temp  = *lista;
        while(temp->seg !=NULL){//anda até o fim da lista
            temp = temp->seg;
        }
        temp->seg = aux;
    }
    return 1;
}

void imprimir_lista(Lista *lista){
    if(lista==NULL){
        printf("A lista nao existe.");
        return;
    }
    if(*lista==NULL){
        printf("A lista esta vazia.");
        return;
    }
    cel *aux = *lista;
    printf("Lista: ");
    while(aux != NULL){
        printf(" %d |", aux->conteudo);
        aux=aux->seg;
    }
    printf("\n");
}

int remove_lista_fim(Lista *lista){
    if(lista==NULL){
        printf("A lista nao existe.");
        return 0;
    }
    if(*lista==NULL){
        printf("A lista esta vazia.");
        return 0;
    }
    cel *ant = NULL, *aux = *lista;
    while(aux->seg != NULL){
        ant = aux;
        aux = aux->seg;
    }
    if(ant == NULL){ //aux == *lista
        *lista = NULL;
        free(aux);
    }else{
        ant->seg = NULL;
         free(aux);
    }

    return 1;
}

int remove_lista(Lista *lista){
    if(lista==NULL){
        printf("A lista nao existe\n");
        return 0;
    }
    if(*lista==NULL){
        printf("A lista esta vazia\n");
        return 0;
    }

    cel *ant = NULL, *aux = *lista;
    while(aux->seg != NULL){
        ant = aux;
        aux = aux->seg;
    }
}

void apagar_toda_lista(Lista *lista){

    if (lista == NULL) return; // Proteção: evita travar o programa se a lista não existir

    cel *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->seg;
        free(aux);
    }

    free(lista); // Libera o ponteiro do gerenciador que foi alocado no cria_lista()
}





int main()
{
    printf("Inicio\n");
    Lista *lst;
    lst = cria_lista();

    insere_lista_fim(lst, 1);
    insere_lista_fim(lst, 2);
    insere_lista_fim(lst, 3);
    insere_lista_fim(lst, 4);
    insere_lista_fim(lst, 5);
    imprimir_lista(lst);

    remove_lista_fim(lst);
    remove_lista_fim(lst);
    imprimir_lista(lst);

    apagar_toda_lista(lst);
    //imprimir_lista(lst);


    return 0;
}
