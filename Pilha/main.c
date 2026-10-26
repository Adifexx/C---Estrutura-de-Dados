#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Pilha;

Pilha* cria_pilha() {
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));

    if (pilha != NULL) {
        *pilha = NULL;
    }

    return pilha;
}


void imprime_pilha(Pilha *pilha) {
    if (pilha == NULL || *pilha == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    cel *aux = *pilha;
    printf("Pilha: ");
    //printf(" %d ", aux->conteudo);
    while (aux != NULL) {
        printf(" %d |", aux->conteudo);
        aux = aux->seg;
    }
    printf("\n");
}



int push(Pilha *pilha, int x) {
    if (pilha == NULL) {
        return 0;
    }

    cel *aux = malloc(sizeof(cel));

    if (aux == NULL) {
        return 0;
    }

    aux->conteudo = x;
    aux->seg = *pilha;
    *pilha = aux;

    return 1;
}

int pop(Pilha *pilha){
    if (pilha == NULL || *pilha == NULL) {
        return 0;
    }
    cel *aux = *pilha;
    *pilha = (*pilha)->seg;
    free(aux);

    return 1;
}


int main()
{
    printf("Inicio\n");
    Pilha *plh;

    plh = cria_pilha();
    push(plh, 1);
    push(plh, 2);
    push(plh, 3);
    push(plh, 4);
    push(plh, 5);
    imprime_pilha(plh);
    pop(plh);
    imprime_pilha(plh);


    return 0;
}
