#include <stdio.h>

int fibo(int n);

int main()
{
    int n = 0;
    printf("Digite o N-esimo numero:\n");
    scanf("%d", &n);

    printf("O valores %d", fibo(n));
    return 0;
}

int fibo(int n)
{
    int a = 0, aux = 1, aux2 = 0;
    for (int i = 1; i < n; i++)
    {
        aux2 = a + aux;
        a = aux;
        aux = aux2;
    }
    return aux;
}