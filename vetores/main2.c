{
    int c = 10;
    int *p;
    p = &c;
    //p pegou o endereco de memoria de c
    //se tirar o comercial, da erro porque p é ponteiro

    printf("endereco de memoria: %d\nvalor de c: %d\n", p, *p);

    *p = 12;
    //*p alterou o valor de dentro da posicao de memoria apontada

    printf("novo valor de c: %d\n", c);
    printf("novo valor de *p: %d\n", *p);






    return 0;
}
*/

/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

/*
int main()
{
    void imprime(int *m, int n){
    int i;
    for(i=0; i<n; i++)
    printf("%d \n", m[i]);
    }

    int vet[5] = {1,2,3,4,5};
    imprime(vet,5);

    return 0;
}
*/

//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

/*
int main()
{
  void fatorial(int n){
   if(n==0)
    return 1;
   else return n * fatorial(n-1);
   printf("%d", n);
   }

   fatorial(5);
}
*/

//////////////////////////////////////////////////////////////////


#include <stdio.h>

void imprimeVetor(int *v, int n, int cont){
    if(cont < n){
        // Adicionado \n para pular linha entre as posições
        printf("Posicao %d: %d\n", cont, v[cont]);
        imprimeVetor(v, n, cont + 1);
    }
}

int main()
{
    int vet[5] = {10, 20, 30, 40, 50};
    int n = 5; // DECLARAÇÃO NECESSÁRIA: define o tamanho do vetor

    // Agora 'n' existe e vale 5
    imprimeVetor(vet, n, 0);

    return 0;
}


