#include <stdio.h>

int soma_primos(int n, int vetor1[n]);

int main()
{
    int n;
    printf("Digite ate quantos numeros voce quer\n");
    scanf("%d", &n);

    int vetor1[n];
    for (int i = 0; i < n; i++)
    {
        vetor1[i] = i + 1;
    }
    
    int k = soma_primos(n, vetor1);
    printf("A soma totaç é %d", k);
}

int soma_primos(int n, int vetor1[n])
{
    int somatudo = 0;
    for (int j = 0; j < n; j++)
    {
        int primo = 1;
        for (int i = 2; i * i <= vetor1[j]; i++)
        {
            if (vetor1[j] % i == 0)
            {
                primo = 0;
                break;
            }
        }
        if (primo && vetor1[j] > 1)
        {
            somatudo += vetor1[j];
        }
    }

    return somatudo;
}