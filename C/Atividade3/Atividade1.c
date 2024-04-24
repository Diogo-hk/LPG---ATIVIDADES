#include <stdio.h>

int compara(int n, double vetor1[n], double vetor2[n]);

int main()
{
    int n, p;
    printf("Digite o valor do vetor:\n");
    scanf("%d", &n);
    double vetor1[n], vetor2[n];
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor do vetor 1\n");
        scanf("%lf", &vetor1[i]);
        printf("Digite o valor do vetor 2\n");
        scanf("%lf", &vetor2[i]);
    }

    if (compara(n, vetor1, vetor2) == 1)
    {
        printf("Sao iguais\n");
    }
    else
    {
        printf("Sao diferentes\n");
    }
}

int compara(int n, double vetor1[n], double vetor2[n])
{
    for (int i = 0; i < n; i++)
    {
        if (vetor1[i] != vetor2[i])
        {
            return 0;
        }
    }
    return 1;
}