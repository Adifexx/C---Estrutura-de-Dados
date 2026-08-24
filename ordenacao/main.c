#include <stdio.h>
#include <stdlib.h>


void selectionSort(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        int menor = i;
        for(int j = i+1; j < tamanho; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        int temp = v[i]; //v[i](v[0]) = 5, passa a ser guardado no temp
        v[i] = v[menor]; //v[i] passa a ser igual a v[menor](v[3] = 1) ENTENDER DEPOIS
        v[menor] = temp; //v[menor](v[3]) passa a ser igual a 5(v[3] = 5)

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

    selectionSort(v, tamanho);

    printf("\nVetor depois: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
