#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
}NO;

typedef struct NO* ArvBin;

ArvBin* criaArvBim(){
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));

    if(raiz != NULL){//se a raiz existir
        *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){//se a avrove nao existir
        return 0;
    }

    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    if(novo == NULL){//se nao conseguir criar
        return 0;
    }

    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL){
        *raiz = novo;
    }else{
        NO *atual = *raiz;
        NO *ant = NULL;

        while(atual != NULL){//enquanto o atual nao for vazio
                ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){//se o valor for maior que o conteudo
                atual = atual->dir;//o atual vai pra direita
            }else{
                atual = atual->esq;//se for menor, o atual vai pra esquerda
            }
        }
        if(valor > ant->info){//ao sair do while, essa parte vai decidir onde o novo NO vai ser adicionado
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){//quando a raiz nao tiver nem esquerda nem direita, ele volta sozinho pro NO anterior
        printf("%d\t", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));


    }
}

int main()
{
    printf("Inicio\n");
    ArvBin *raiz = criaArvBim();
    int N = 10, dados[10] = {28,16,40,11,21,36,48,19,32,56};

    for(int i=0; i<10; i++){
        insere_ArvBin(raiz, dados[i]);
    }
    preOrdem_ArvBin(raiz);

    return 0;
}
