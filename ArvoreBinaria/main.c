#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
}NO;

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));

    if(raiz != NULL){//se a arvore existir
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

void preOrdem_arvBin(ArvBin *raiz){
    if(raiz == NULL){//se a arvore nao existir
        return;
    }
    if(*raiz != NULL){//quando a raiz nao tiver nem esquerda nem direita, ele volta sozinho pro NO anterior
        printf("%d\t", (*raiz)->info);
        preOrdem_arvBin(&((*raiz)->esq));
        preOrdem_arvBin(&((*raiz)->dir));


    }
}

void emOrdem_arvBin(ArvBin *raiz){
  if(raiz==NULL){
      return;
  }
  if(*raiz!=NULL){
    emOrdem_arvBin(&((*raiz)->esq));
    printf("%d\t", (*raiz)->info);
    emOrdem_arvBin(&((*raiz)->dir));
  }
}

void posOrdem_arvBin(ArvBin *raiz){
  if(raiz==NULL){
      return;
  }
  if(*raiz!=NULL){
    posOrdem_arvBin(&((*raiz)->esq));
    posOrdem_arvBin(&((*raiz)->dir));
    printf("%d\t", (*raiz)->info);
  }
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    NO *atual = *raiz;//atual pega o primeiro NO (raiz)

    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor>atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

int totalNosArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL){
        return 0;
    }
    int qtd_dir = totalNosArvBin(&((*raiz)->dir));
    int qtd_esq = totalNosArvBin(&((*raiz)->esq));
    return (qtd_dir+qtd_esq+1);

}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL){
        return -1;
    }
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    int alt_esq = altura_ArvBin(&((*raiz)->esq));

    if(alt_esq>alt_dir){
        return alt_esq+1;
    }else{
        return alt_dir+1;
    }
}

void libera_NO(NO *no){
    if(no == NULL){return;}
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL){return;}
    libera_NO(*raiz);
    free(raiz);
}

NO* remove_atual(NO *atual){
    NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){return 0;}
    NO *ant = NULL;
    NO *atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){//se o valor for encontrado
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }else{
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;


}



int main(void) {

  ArvBin* raiz = cria_ArvBin();
  int N = 10,dados[10] = {28,16,40,11,21,36,48,19,32,56};
  for(int i=0;i<N;i++){
    insere_ArvBin(raiz, dados[i]);
  }

  //libera_ArvBin(raiz);
  int altura = altura_ArvBin(raiz);
  printf("\nAltura: %d ",altura);
  int quantidade = totalNosArvBin(raiz);
  printf("\nQuantidade: %d ",quantidade);

  printf("\nPréOrdem: ");
  preOrdem_arvBin(raiz);
  printf("\nEmOrdem: ");
  emOrdem_arvBin(raiz);
  printf("\nPosOrdem: ");
  posOrdem_arvBin(raiz);
  printf("\nFinalizou.\n");

  //imprime_ArvBin(raiz);
  return 0;
}
