#include <stdio.h>

int main()
{

    int n = 0, c = 1, b = 1;
    float resultado = 1, fat = 1, x = 0;

    printf("Digite o numero de termos:\n");
    scanf("%d", &n);
    printf("Digite o X:\n");
    scanf("%f", &x);

    int a = x;

    for (int i = 1; i < n; i++)
    {
        fat = fat * c;
        resultado = resultado + (x / fat);
        c = c + 1;
        x = x * a;
    }

    printf("%f", resultado);

    return 0;
}