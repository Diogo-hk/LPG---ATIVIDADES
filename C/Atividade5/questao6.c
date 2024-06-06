#include <stdio.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main()
{
    int tam = 5, indice = 0;
    float vetor[tam], max = 0.0;

    printf("Digite os valores do vetor\n");
    for (int i = 0; i < tam; i++)
    {
        scanf("%f", &vetor[i]);
    }
    max_vetor(vetor, tam, &max, &indice);

    printf("O maior valor e: %f, o indice dele e %d\n", max, indice);

}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice)
{
    for (int i = 0; i < tam; i++)
    {
        if (*pMax < vet[i])
        {
            *pMax = vet[i];
            *pIndice = i;
        }
    }
    
}
