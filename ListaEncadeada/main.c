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
    if(lista == NULL){return 0;} // se a lista nao existe retorna 0

    cel* aux = (cel*) malloc (sizeof(cel)); // cria um ponteiro aux e reserva memoria para uma celula e guarda o endereco dessa memoria em aux
    if(aux == NULL){return 0;} // se a reserva de memoria falhou, retorna 0
    aux->conteudo = x; // conteudo de aux passa a ser x // IMPORTANTE // toda celula criada vai ter um conteudo = x
    aux->seg = NULL; // define que a nova memoria eh a ultima (seguinte = NULL) // IMPORTANTE // toda celula criada vai ter uma seguinte = NULL ate ligar a celula em outra
    if((*lista)== NULL){ // se a lista estiver vazia
        *lista = aux; // *lista pega o endereco da aux, que eh a primeira celula
    }else{
        cel *temp; // declara temp, um ponteiro que vai caminhar pela lista
        temp = *lista; // temp pega o endereco de memoria da primeira celula
        while(temp->seg !=NULL){ // enquanto a proxima celula nao for a ultima (NULL)
            temp = temp->seg; // temp vai pra proxima celula
        } // quando a proxima de temp for nulo (ultima)
        temp->seg = aux; // faz a antiga ultima celula apontar para a nova ultima celula
    }
    return 1;
}

int insere_lista_inicio(Lista *lista, int x) {
    if (lista == NULL) { // se a lista nao existe retorna 0
        return 0;
    }

cel *aux = malloc(sizeof(cel)); // cria um ponteiro aux e reserva memoria para uma celula e guarda o endereco dessa memoria em aux // Cria uma célula na memória e guarda o endereço dela em aux.
if (aux == NULL) { // se a reserva de memoria falhou, retorna 0
    return 0;
}

aux->conteudo = x; // o conteudo de aux passa a ser x
aux->seg = *lista; // a nova célula aponta para a antiga primeira, que aponta para as demais
*lista = aux; // a nova célula passa a ser a primeira

    return 1;
}

int insere_lista_posicao(Lista *lista, int x, int posicao) {
    if (lista == NULL || posicao < 0) return 0;

    cel *aux = malloc(sizeof(cel));
    if (aux == NULL) return 0;
    aux->conteudo = x; // x vira o conteudo de aux

    if (posicao == 0) { // se a posicao escolhida for 0, entao eh o primeiro da lista
        aux->seg = *lista; // a nova celula aponta para a antiga primeira, que aponta para as demais
        *lista = aux; // a nova celula passa a ser a primeira celula novamente
        return 1;
    }

    cel *temp = *lista; // declara temp, um ponteiro que vai caminhar pela lista e pega o endereco da primeira celula
    for (int i = 0; i < posicao - 1 && temp != NULL; i++) { // se um dos dois for falso, nao executa
        temp = temp->seg;
    }

    if (temp == NULL) {
        free(aux);
        return 0; // posição maior que o tamanho da lista
    }
 // 3 -> 5 -> 8
    aux->seg = temp->seg; // o seguinte do aux pega o endereco de memoria do seguinte do temp, que liga nas demais // 3 e 7 -> 5 -> 8
    temp->seg = aux; // o seguinte do temp pega o endereco de memoria do aux, que agora, liga nas demais // 3 -> 7 -> 5 -> 8
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
    cel *aux = *lista; //aux pega o endereco da primeira celula
    printf("Lista: ");
    while(aux != NULL){
        printf(" %d |", aux->conteudo); // printa  conteudo de aux
        aux = aux->seg; // aux vai pra porx e printa dnv
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
    while(aux->seg != NULL){ // enquanto nao chegar no fim da lista
        ant = aux;
        aux = aux->seg;
    }
    if(ant == NULL){ // se o anterior for NULL // se nao tiver sequer celula
        *lista = NULL; // lista fica vazia
        free(aux); // libera o aux
    }else{
        ant->seg = NULL; // faz a proxima celula(aux) apontar pra NULL
        free(aux); // libera o aux
    }
}

int remove_lista_inicio(Lista *lista) {
    if (lista == NULL) {          // Verifica se a lista existe.
        return 0;                 // Não foi possível remover.
    }

    if (*lista == NULL) {         // Verifica se a lista está vazia.
        return 0;                 // Não há célula para remover.
    }

    cel *aux = *lista;            // Guarda o endereço da primeira célula.
    *lista = (*lista)->seg;       // O início passa a apontar para a segunda célula. // a seguinte da lista passa a ser a primeira
    free(aux);                    // Libera a antiga primeira célula.

    return 1;                     // Remoção realizada.
}

int remove_lista_posicao(Lista *lista, int posicao) {
    if (lista == NULL || posicao < 0) { // Verifica se a lista e a posição são válidas.
        return 0;                       // Não foi possível remover.
    }

    if (*lista == NULL) {               // Verifica se a lista está vazia.
        return 0;                       // Não há célula para remover.
    }

    if (posicao == 0) {                 // A posição 0 é a primeira célula.
        return remove_lista_inicio(lista); // Usa a função criada acima.
    }

    cel *temp = *lista;                 // Começa na primeira célula.

    for (int i = 0; i < posicao - 1 && temp != NULL; i++) {
        temp = temp->seg;               // Avança até a célula anterior à desejada.
    }

    if (temp == NULL || temp->seg == NULL) {
        return 0;                       // A posição não existe na lista.
    }
    // 3 -> 5 -> 8
    cel *aux = temp->seg;               // Guarda a célula que será removida. // seguinte do temp = 5 = aux
    temp->seg = aux->seg;               // Liga a anterior à célula seguinte. // seguinte do temp vai pegar o seguinte do aux, que eh 8, logo, 3 -> 8
    free(aux);                          // Libera a célula removida. // libera o aux (5)

    return 1;                           // Remoção realizada.
}

void apagar_toda_lista(Lista *lista){
     if (lista == NULL) return; // Proteção: evita travar o programa se a lista não existir

     cel *aux;
     while(*lista != NULL){ // enquanto a lista nao estiver vazia
        aux = *lista; // aux pega o endereco da primeira celula
        *lista = (*lista)->seg; // a primeira celula passa a ser a seguinte
        free(aux); // libera o aux
     }
     free(lista); // depois que a lista ta vazia (*lista == NULL), libera a lista
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
    //remove_lista_fim(lst);
    imprimir_lista(lst);
    insere_lista_inicio(lst, 6);
    imprimir_lista(lst);
    insere_lista_posicao(lst, 7, 3);
    imprimir_lista(lst);
    remove_lista_inicio(lst);
    imprimir_lista(lst);
    remove_lista_posicao(lst, 1);
    imprimir_lista(lst);


    apagar_toda_lista(lst);
    //imprimir_lista(lst);


    return 0;
}
