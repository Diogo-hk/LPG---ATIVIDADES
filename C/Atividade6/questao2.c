#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char *s, int n);

int main()
{
    char stringFoda[50];
    printf("Digite as palavras que voce vai digitar:\n");
    fgets(stringFoda, 50, stdin);

    // Remove o caractere de nova linha se estiver presente
    size_t len = strlen(stringFoda);
    if (len > 0 && stringFoda[len - 1] == '\n')
    {
        stringFoda[len - 1] = '\0';
    }

    int n;
    printf("Quantas vezes repetir:\n");
    scanf("%d", &n);

    char *stringFoda2 = repetidor(stringFoda, n);

    printf("Palavra original : '%s'\nPalavra Copia : '%s'\n", stringFoda, stringFoda2);

    free(stringFoda2);

    return 0;
}

char *repetidor(char *s, int n)
{
    int len = strlen(s);
    char *vetorFodao = malloc((len * n + 1) * sizeof(char));

    if (vetorFodao == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    vetorFodao[0] = '\0';

    for (int i = 0; i < n; i++)
    {
        strcat(vetorFodao, s);
    }

    return vetorFodao;
}
