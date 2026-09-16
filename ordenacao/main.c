#include <stdio.h>
#include <stdlib.h>


void selectionSort(int v[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        // Procura a posição do menor valor
        for (int j = i + 1; j < tamanho; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        // Verifica se o menor valor está em outra posição
        if (menor != i) {
            int temp = v[i];  // Guarda o valor atual
            v[i] = v[menor];  // Coloca o menor valor na posição atual
            v[menor] = temp;  // Coloca o valor antigo na posição do menor
        }
    }
}

void boubleSort(int v[], int tamanho){
    int i,j,temp, trocou;
    do{
        trocou = 0;

        for(i = 0; i < tamanho-1; i++){ // 1 passagem = 1 for completo
            if (v[i] > v[i+1]){
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;

                trocou = 1;
            }
        }
        tamanho--;

    }while (trocou == 1);
}

void insertionSort(int v[], int tamanho){
    int i, j, temp;

    for(i = 0; i < tamanho; i++){
        temp = v[i];
        for(j=i; (j>0) && (temp<v[j-1]); j--){ //j-- é a chave
            v[j] = v[j-1];
        }
        v[j] = temp;
    }
}


void merge(int *v, int inicio, int meio, int fim){
    int *temp, i, j, k, tamanho, p1, p2, fim1= 0, fim2=0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*(sizeof(int)));
    if(temp!=NULL){
     for(i=0;i<tamanho;i++){
        if(!fim1 && !fim2){//se ninguem terminou
            if(v[p1]<v[p2]){//verifica quem vai copiar
                temp[i] = v[p1];
                p1++;
            }else{
                temp[i] = v[p2++];//igual a de cima
            }
            if(p1>meio){ fim1= 1;}
            if(p2>fim) {fim2 = 1;}

        }else{//se alguem terminou
            if(!fim1){ temp[i] = v[p1++]; }
            else{ temp[i] = v[p2++]; }
        }
     }
     for(j=0,k= inicio; j<tamanho; j++,k++){
        v[k] = temp[j];
     }

    }
    free(temp);

}


void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = ((inicio+fim)/2);
        mergeSort(v, inicio, meio); //esquerda - meio
        mergeSort(v, meio+1, fim); //meio - direita
        merge(v, inicio, meio, fim);
    }
}



int particiona(int *v, int inicio,int fim){
    int pivo, esq, dir, temp;

    pivo = v[inicio];
    esq = inicio;
    dir = fim;

    while(esq < dir){
        while (v[esq] <= pivo && esq <= fim){
            esq++;
        }
        while (v[dir] > pivo && dir >= 0){
            dir--;
        }
        if(esq < dir){
                temp = v[esq];
                v[esq] = v[dir];
                v[dir]=temp;
        }

            }
            v[inicio] = v[dir];
            v[dir] = pivo;
            return dir;
}


void quickSort(int *v, int inicio, int fim){
    int pivo;
    if (fim > inicio){
        pivo = particiona(v, inicio, fim); // pivo é o indice do numero
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}




int main()
{
    int v[] = {5, 3, 81, 1, 20, 80, -30, 67, 10, 76};

    //int tamanho = 10;
    int tamanho = sizeof(v) / sizeof(v[0]);

    printf("Vetor antes: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    //selectionSort(v, tamanho);
    //boubleSort(v, tamanho);
    //insertionSort(v, tamanho);
    //mergeSort(v,0,9);
    quickSort(v,0,9);

    printf("\nVetor depois: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
