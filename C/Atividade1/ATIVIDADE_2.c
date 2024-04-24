int main()
{
    float A = 0, B = 0, C = 0;
    float maior, medio, menor;

    printf("Digite os tres lados de um triangulo: ");
    scanf("%f %f %f", &A, &B, &C);

    if (A >= B && A >= C)
    {
        maior = A;
        if (B > C)
        {
            medio = B;
            menor = C;
        }
        else
        {
            medio = C;
            menor = B;
        }
    }
    if (B >= A && B >= C)
    {
        maior = B;
        if (A > C)
        {
            medio = A;
            menor = C;
        }
        else
        {
            medio = C;
            menor = A;
        }
    }
    if (C >= A && C >= B)
    {
        maior = C;
        if (A > B)
        {
            medio = A;
            menor = B;
        }
        else
        {
            medio = B;
            menor = A;
        }
    }
    if (maior >= medio + menor)
    {
        printf("Nao forma triangulo\n");
        return 0;
    }
    else
    {

        if (pow(maior, 2) == pow(medio, 2) + pow(menor, 2))
        {
            printf("TRIANGULO RETANGULO\n");
        }
        if (pow(maior, 2) > pow(medio, 2) + pow(menor, 2))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        if (pow(maior, 2) < pow(medio, 2) + pow(menor, 2))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if (maior == medio && maior == menor)
        {
            printf("TRIANGULO EQUILATERO\n");
        }
        if ((maior == medio && maior != menor) || (medio == menor && medio != maior))
        {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}