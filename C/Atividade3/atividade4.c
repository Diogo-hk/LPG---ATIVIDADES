#include <stdio.h>

void busca_todos(int n, int vetor[n], int vetor1[n], int chave);

int main()
{
    int n;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    printf("Digite os valores que vao no vetor:\n");

    int vetor[n], vetor1[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int chave;
    printf("Digite o valor chave:\n");
    scanf("%d", &chave);

    busca_todos(n, vetor, vetor1, chave);
}

void busca_todos(int n, int vetor[n], int vetor1[n], int chave)
{
    printf("Indice = ");
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == chave)
        {
            vetor1[i] = vetor[i];
        }
        else
        {
            vetor1[i] = -1;
        }
        printf("| %d ", vetor1[i]);
    }
    printf(" |\n");
}