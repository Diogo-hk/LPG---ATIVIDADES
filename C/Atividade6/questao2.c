#include <stdio.h>
#include <stdlib.h>

char *repetidor(char *s, int n);

int main()
{
    char stringFoda[50];
    printf("Digite as palavras que voce vai digitar\n");
    fgets(stringFoda, 50, stdin);

    int n;
    printf("Quantas vezes repetir\n");
    scanf("%d", &n);

    char *stringFoda = repetidor(stringFoda, n);
}

char *repetidor(char *s, int n)
{

}