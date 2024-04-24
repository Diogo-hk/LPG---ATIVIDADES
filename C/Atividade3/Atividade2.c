#include <stdio.h>

void fibonacci(long long int n, long long int vetor1[n]);

int main()
{
    long long int n;
    printf("Digite o tamanho do vetor\n");
    scanf("%lld", &n);
    long long int vetor1[n];

    fibonacci(n, vetor1);
}

void fibonacci(long long int n, long long int vetor1[n])
{
    vetor1[0] = 1;
    vetor1[1] = 1;
    printf("%lld %lld", vetor1[0], vetor1[1]);
    for (int i = 2; i < n; i++)
    {
        vetor1[i] = vetor1[i-1] + vetor1[i-2];
        printf(" %lld", vetor1[i]);
    }
    printf("\n");
}