#include <stdio.h>
#include <stdlib.h>


int buscaBinaria(int *v, int tamanho, int alvo){

    int inicio = 0;
    int fim = tamanho-1;
    int meio;

    while(inicio <= fim){
        meio = (inicio+fim)/2;

        if(v[meio] == alvo){
            return meio;
        }
        else if(alvo < v[meio]){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1;
}

int buscaBinariaRecursiva(int *v,int inicio, int fim , int alvo){

    if(inicio > fim){
        return -1;
    }

     int meio = (inicio+fim)/2;

     if(v[meio] == alvo){
        return meio;
     }
     else if(alvo < v[meio]){
        buscaBinariaRecursiva(v, inicio, meio-1, alvo);
     }
     else{
        buscaBinariaRecursiva(v, meio+1, fim, alvo);
     }

}



int main()
{


int v[] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
// int alvo = 54;
// int alvo;
// int tamanho = 10;
// int tamanho;
// int inicio = 0;
// int fim = tamanho-1;
// int meio = (inicio+fim)/2;

printf("Resultado: %d \n", buscaBinaria(v, 10, 54));
printf("ResuldadoRecursiva: %d ", buscaBinariaRecursiva(v, 0, 9, 54));

    return 0;
}
