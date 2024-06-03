#include <stdio.h>

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main()
{
    int tam = 5, valorMaximo = 0, valorMinimo = 0;
    int vetor[tam];
    int *pMaximo = &valorMaximo, *pMinimo = &valorMinimo;
    printf("Digite os valores do vetor\n");
    
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }

    max_min(vetor, tam, pMinimo, pMaximo);

    printf("O valor maximo é: %d, o valor Minimo é: %d\n", *pMaximo, *pMinimo);
}

void max_min(int vet[], int tam, int *pMin, int *pMax)
{
    *pMin = vet[0];
    *pMax = vet[0];
    for (int i = 1; i < tam; i++)
    {
        if (vet[i] > *pMax)
            *pMax = vet[i];
        
        if(vet[i] < *pMin)
            *pMin = vet[i];
    }
}