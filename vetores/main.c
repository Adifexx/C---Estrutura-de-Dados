#include <stdio.h>
#include <stdlib.h>


int buscarSequencial(int *numeros, int tamanho, int alvo){
    for(int i=0; i<tamanho; i++){
        if (numeros[i] == alvo){
            return i;
        }
    }
}

int buscarOrdenada(int *numeros1, int tamanho, int alvo){
    for(int i=0; i<tamanho; i++){
        if (numeros1[i] == alvo){
            return i;
        }else{
            if(alvo<numeros1[i])
                return -1;
        }
    }
}




int main()
{
    int numeros[] = {23, 4, 67 ,-8, 54, 90, 21};
    int numeros1[] = {-8, 4, 21 ,23, 54, 67, 90};

    int posicao = buscarSequencial(numeros,7,54);
    printf("Posicao do indice: %d\n", posicao);

    int posicao1 = buscarOrdenada(numeros1,7,21);
    printf("Posicao do indice: %d\n", posicao1);



    return 0;
}
