#include <stdio.h>

int main()
{

    int a = -1, cont = 0;
    float fat = 1, n = 0, x = 0, pot = 1, resultado = 0;

    printf("Digite o numero de termos: ");
    scanf("%f", &n);
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    for (int i = 1; i < 2 * n; i += 2)
    {
        cont++;

        fat = 1;
        for (int j = i; j > 0; j--)
        {

            fat *= j;
        }
        pot = 1;
        for (int k = i; k > 0; k--)
        {
            pot *= x;
        }

        if (cont % 2 == 0)
        {
            resultado += (pot / fat);
        }
        else
        {
            resultado += (-pot / fat);
        }
    }

    printf("%f\n %f\n %f\n", resultado, pot, fat);

    return 0;
}