#include <stdio.h>
#include <stdlib.h>


typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    cel *aux = (cel*) malloc (sizeof(cel));
    if(aux == NULL){
        return 0;
    }
    aux->conteudo = x;
    aux->seg = NULL;

    if(*lista == NULL){
         *lista = aux;
    }else{
        cel *temp;
        temp = *lista;
        while(temp->seg != NULL){
            temp = temp->seg;
        }
        temp->seg = aux;
    }


    return 1;
}


int main()
{
    printf("Inicio Lista!\n");
    Lista *lst;
    lst = cria_lista();
    insere_lista_fim(lst, 10);
    insere_lista_fim(lst, 20);
    insere_lista_fim(lst, 30);
    insere_lista_fim(lst, 40);

    //IMPRIMIR LISTA
    //INSERIR INICIO DA LISTA
    //INSERIR ORDENADO




    return 0;
}
