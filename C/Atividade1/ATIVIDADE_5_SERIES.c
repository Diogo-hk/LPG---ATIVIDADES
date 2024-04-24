#include <stdio.h>

int main()
{

    int n = 0, c = 1;
    float resultado = 1, fat = 1;

    printf("Digite o numero de termos:\n");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        fat = fat * c;
        resultado = resultado + (1 / fat);
        c = c + 1;
    }

    printf("%f\n", resultado);

    return 0;
}