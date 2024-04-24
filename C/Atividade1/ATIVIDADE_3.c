int main()
{
    int x = 0, y = 0, resultado = 0;
    scanf("%i %i", &x, &y);

    if (y <= x)
    {
        y = y + 24;
        resultado = y - x;
    }

    else
    {
        resultado = y - x;
    }

    printf("O JOGO DUROU %i HORA(S)\n", resultado);
    return 0;
} 