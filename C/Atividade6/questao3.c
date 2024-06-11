#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, foda = 0;
    printf("Digite quantos valores voce vai querer digitar\n");
    scanf("%d", &n);

    float *MediaDoFloat = malloc(sizeof(float) * n);
    if (MediaDoFloat == NULL)
    {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    float media = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &MediaDoFloat[i]);
        media += MediaDoFloat[i];
    }

    media = media / n;

    float *MediaVapo = NULL;
    for (int i = 0; i < n; i++)
    {
        if (MediaDoFloat[i] >= media)
        {
            foda++;
            float *temp = realloc(MediaVapo, sizeof(float) * foda);
            if (temp == NULL)
            {
                printf("Erro de realocação de memória\n");
                free(MediaDoFloat);
                free(MediaVapo); // É seguro chamar free em um ponteiro NULL.
                return 1;
            }
            MediaVapo = temp;
            MediaVapo[foda - 1] = MediaDoFloat[i];
        }
    }

    printf("A media é: %f\n", media);
    for (int i = 0; i < foda; i++)
    {
        printf("Numero maior ou igual à média: %f\n", MediaVapo[i]);
    }

    free(MediaDoFloat);
    free(MediaVapo);

    return 0;
}
