#include <stdio.h>

int maior_valor(int x, int y, int z);

int main()
{
    int x, y, z;
    printf("Digite os 3 valores X, Y, Z\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    int resultado;
    resultado = maior_valor(x, y, z);
    printf("O maior valor é: %d\n", resultado);
}

int maior_valor(int x, int y, int z)
{
    int valor;
    if (x > y && x > z)
    {
        valor = x;
    }
    else if(y > z)
    {
        valor = y;
    }
    else
    {
        valor = z;
    }
    return valor;
}