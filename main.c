#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorshower[5];
    int contador;

    for(contador = 0; contador < 5; contador++){
        printf("Digite o numero do vetor %d: ", contador);
        scanf("%d", &vetorshower[contador]);
    }

    for(contador = 0; contador < 5; contador++)
        printf("O vetor %d foi %d\n", contador, vetorshower[contador]);
    return 0;
}
