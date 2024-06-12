#include <stdio.h>
#include <stdlib.h>

int *separaPositivo(int *vetorFoda, int n, int *len1)
{
    int *vetorFoda2 = NULL;
    int numero = 0;
    for (int i = 0; i < n; i++)
    {
        if (vetorFoda[i] % 2 == 0)
        {
            numero++;
            vetorFoda2 = realloc(vetorFoda2, sizeof(int) * numero);
            vetorFoda2[numero - 1] = vetorFoda[i];
        }
    }
    *len1 = numero;
    return vetorFoda2;
}

int *separaNegativo(int *vetorFoda, int n, int *len2)
{
    int *vetorFoda3 = NULL;
    int numero = 0;
    for (int i = 0; i < n; i++)
    {
        if (vetorFoda[i] % 2 != 0)
        {
            numero++;
            vetorFoda3 = realloc(vetorFoda3, sizeof(int) * numero);
            vetorFoda3[numero - 1] = vetorFoda[i];
        }
    }
    *len2 = numero;
    return vetorFoda3;
}

int main()
{
    int n = 0;
    printf("Digite os quantos valores voce quer digitar\n");
    scanf("%d", &n);
    int *vetorDeInteiros = malloc(sizeof(int) * n);

    printf("Digite os valores:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetorDeInteiros[i]);
    }

    int len1 = 0;
    int len2 = 0;
    int *vp = separaPositivo(vetorDeInteiros, n, &len1);
    int *vn = separaNegativo(vetorDeInteiros, n, &len2);

    for (int i = 0; i < len1; i++)
    {
        printf("Valores Par: %d\n", vp[i]);
    }

    for (int i = 0; i < len2; i++)
    {
        printf("Valores impar: %d\n", vn[i]);
    }

    free(vetorDeInteiros);
    free(vp);
    free(vn);

    return 0;
}
