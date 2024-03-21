#include <stdio.h>
#include <math.h>

int main()
{
    int N = 0;

    printf("Digite quantas vezes queres somar:\n");
    scanf("%d", &N);

    float resultado = 0;
    int divisor = 1;

    for (int i = 0; i < N; i++)
    {
        if ((i+1) % 2 != 0)
        {
            resultado = (resultado + (-4.0 / (divisor += 2)));
        }
        else
        {
            resultado = (resultado + (4.0 / (divisor += 2)));
        }
    }
    resultado = resultado + 4;

    printf("O valor é: %.2f\n", resultado);
}