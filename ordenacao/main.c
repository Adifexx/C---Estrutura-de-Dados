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





int main()
{
    int v[] = {5, 3, 8, 1, 2};

    int tamanho = 5;
    //int tamanho = sizeof(v) / sizeof(v[0]);

    printf("Vetor antes: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    //selectionSort(v, tamanho);
    boubleSort(v, tamanho);
    //insertionSort(v, tamanho);

    printf("\nVetor depois: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
