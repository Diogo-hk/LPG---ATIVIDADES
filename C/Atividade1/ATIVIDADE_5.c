#include <stdio.h>

int main()
{
    double N, media;
    int notas = 3;

    for (int i = 0; i < notas; i++)
    {
        printf("Digite a nota:\n");
        scanf("%lf", &N);

        if(i == 0)
        {
            media += N * 2;
        }
        if (i == 1)
        {
            media += N * 3;
        }
        if (i == 2)
        {
            media += N * 5;
        }
    }

    printf("A media é: %.2lf\n", media/10);
}