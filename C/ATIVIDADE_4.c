#include <stdio.h>

int main()
{
    int N = 0, B = 0, contador = 0, contadorposi = 0, contadornegativo = 0;
    printf("Digite quantos valores vai querer:\n");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Digite um numero:\n");
        scanf("%d", &B);
        getchar();
        if (B == 0)
        {
            if (B % 2 == 0)
            {
                contador++;
            }
        }
        else
        {
            if (B % 2 == 0)
            {
                contador++;
            }
            if (B > 0)
            {
                contadorposi++;
            } 
            else if (B < 0)
            {
                contadornegativo++;
            }
        }
    }
    printf("%d valor(es) par(es)\n", contador);
    printf("%d valor(es) impar(es)\n", N - contador);
    printf("%d valo(es) positivos(s)\n", contadorposi);
    printf("%d valor(es) negativo(s)\n", contadornegativo);
}