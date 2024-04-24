#include <stdio.h>

int tipo_triangulo(float x, float y, float z);

int main()
{
    float x = 0, y = 0, z = 0;
    printf("Digite os lados X do triangulo:\n");
    scanf("%f", &x);
    printf("Digite os lados Y do triangulo:\n");
    scanf("%f", &y);
    printf("Digite os lados Z do triangulo:\n");
    scanf("%f", &z);

    float resultado;
    resultado = tipo_triangulo(x, y, z);

    if (resultado == 0)
    {
        printf("Nao e triangulo\n");
    }
    else if (resultado == 1)
    {
        printf("Triangulo equilatero\n");
    }
    else if (resultado == 2)
    {
        printf("Triangulo isoceles\n");
    }
    else if (resultado == 3)
    {
        printf("Triangulo escaleno\n");
    }

}

int tipo_triangulo(float x, float y, float z)
{
    if ((x < y+z) && (y < x+z) && (z < x+y))
    {
        if(x == y && x == z)
        {
            return 1;
        }
        else if ( (x == y && x != z) || (x == z && x != y) || (y == z && y != x))
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    return 0;
}
