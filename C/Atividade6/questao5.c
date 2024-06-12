#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1Vetor, int v1, int *v2Vetor, int v2, int *p3);

int main()
{
    int v1;
    printf("Digite o tamanho do V1\n");
    scanf("%d", &v1);
    int v1Vetor[v1];

    printf("Digite os valores de V1: ");
    for (int i = 0; i < v1; i++)
    {
        scanf("%d", &v1Vetor[i]);
    }

    int v2, p3 = 0;
    printf("Digite o tamanho do V2\n");
    scanf("%d", &v2);

    int v2Vetor[v2];
    printf("Digite os valores de V2: ");

    for (int i = 0; i < v2; i++)
    {
        scanf("%d", &v2Vetor[i]);
    }

    int *vetorUniao = uniao(v1Vetor, v1, v2Vetor, v2, &p3);

    printf("O vetor da União é: ");
    for (int i = 0; i < p3; i++)
    {
        printf("%d ", vetorUniao[i]);
    }
    printf("\n");

    free(vetorUniao);
    return 0;
}

int *uniao(int *v1Vetor, int v1, int *v2Vetor, int v2, int *p3)
{
    int *vetorNumeroFoda = NULL;

    for (int i = 0; i < v1; i++)
    {
        (*p3)++;
        vetorNumeroFoda = realloc(vetorNumeroFoda, sizeof(int) * (*p3));
        if (vetorNumeroFoda == NULL)
        {
            perror("Falha ao realocar memória");
            exit(EXIT_FAILURE);
        }
        vetorNumeroFoda[*p3 - 1] = v1Vetor[i];
    }

    for (int i = 0; i < v2; i++)
    {
        int existe = 0;
        for (int j = 0; j < v1; j++)
        {
            if (v2Vetor[i] == v1Vetor[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
        {
            (*p3)++;
            vetorNumeroFoda = realloc(vetorNumeroFoda, sizeof(int) * (*p3));
            if (vetorNumeroFoda == NULL)
            {
                perror("Falha ao realocar memória");
                exit(EXIT_FAILURE);
            }
            vetorNumeroFoda[*p3 - 1] = v2Vetor[i];
        }
    }

    return vetorNumeroFoda;
}
