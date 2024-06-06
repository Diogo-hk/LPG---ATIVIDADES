#include <stdio.h>

void menor_valor_matriz(float matriz[3][4], float *pMenor, int *pLinha, int *pColuna);

int main()
{
    float matriz[3][4];
    float menor;
    int linha, coluna;

    printf("Digite os valores da matriz 3x4:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    menor_valor_matriz(matriz, &menor, &linha, &coluna);

    printf("O menor valor é: %f, localizado na linha %d, coluna %d\n", menor, linha, coluna);

    return 0;
}

void menor_valor_matriz(float matriz[3][4], float *pMenor, int *pLinha, int *pColuna)
{
    *pMenor = matriz[0][0];
    *pLinha = 0;
    *pColuna = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matriz[i][j] < *pMenor)
            {
                *pMenor = matriz[i][j];
                *pLinha = i;
                *pColuna = j;
            }
        }
    }
}
