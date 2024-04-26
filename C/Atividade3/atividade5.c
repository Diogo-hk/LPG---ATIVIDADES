#include <stdio.h>

void busca_todos(int n, int vetor[n], int chave);

int main()
{
    int n;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    printf("Digite os valores que vao no vetor:\n");

    int vetor[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int chave;
    printf("Digite o valor chave:\n");
    scanf("%d", &chave);

    busca_todos(n, vetor, chave);
}

void busca_todos(int n, int vetor[n], int chave)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == chave)
        {
            p++;
        }
    }
    if(p > 0)
    {
        printf("O valor '%d' repetiu : %d\n", chave, p);
    }
}