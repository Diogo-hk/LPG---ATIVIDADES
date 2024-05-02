#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaPalavra (char s[], char c);

int main()
{
    char s[20];
    printf("Digite a palavra\n");
    fgets(s, 20, stdin);
    s[strlen(s) - 1] = '\0';

    char c;
    printf("Digite a letr aque vai procurar\n");
    scanf("%c", &c);

    if (buscaPalavra(s, c) == 1)
    {
        printf("Tem essa letra\n");
    }
    else
    {
        printf("nao tem essa letra\n");
    }


}

int buscaPalavra(char s[], char c)
{
    int d = strlen(s);
    int contador = 0;
    for (int i = 0; i < d; i++)
    {
        if (s[i] == c)
        {
            return 1;
        }
    }

    return 0;
}