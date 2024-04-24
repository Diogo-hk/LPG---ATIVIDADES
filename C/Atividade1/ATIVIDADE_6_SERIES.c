#include <stdio.h>

int main()
{

    int a = -1;
    float fat = 1, n = 0, x = 0, pot = 1, resultado = 0;

    printf("Digite o numero de termos: ");
    scanf("%f", &n);
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    for (int i = 1; i < 2 * n; i += 2)
    {
        a *= -1;

        fat = 1;
        for (int j = i; j > 0; j--)
        {

            fat *= j;
        }
        pot = 1;
        for (int k = i; k > 0; k--)
        {
            pot *= x * a;
        }
        resultado += (pot / fat);
    }

    printf("%f\n", resultado);

    return 0;
}