#include <stdio.h>
#include <stdlib.h>

float *clone(float *vetor, int n);

int main()
{
    int n = 5;
    float vetor[n];
    printf("Digite os valores do vetor\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &vetor[i]);
    }
    float *vetor_clone = clone(vetor, n);

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", vetor_clone[i]);
    }
}

float *clone(float *vetor, int n)
{
    float *vetorFoda = malloc(n * sizeof(float));
    if (vetorFoda == NULL)
        {
            printf("Nao funcionou\n");
            exit(1);
        }

    for (int i = 0; i < n; i++)
    {
        vetorFoda[i] = vetor[i];
    }

    return vetorFoda;
}