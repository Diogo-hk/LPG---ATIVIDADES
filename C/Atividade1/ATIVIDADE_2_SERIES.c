#include <stdio.h>
#include <math.h>

int main()
{
    int N = 0;

    printf("Digite quantas vezes queres somar:\n");
    scanf("%d", &N);

    float resultado = 0;

    for (int i = 1; i < N + 1; i++)
    {
        resultado = resultado + (pow(-1.0, i + 1) / i);
    }

    printf("O valor é: %.2f\n", resultado);
}