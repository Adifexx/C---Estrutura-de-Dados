#include <stdio.h>
#include <stdlib.h>

int main()
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
