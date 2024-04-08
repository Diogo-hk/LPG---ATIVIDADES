#include <stdio.h>

int verifica_caractere(char letra);

int main()
{
    char letra;
    printf("Digite o caractere:\n");
    scanf("%c", &letra);

    if (verifica_caractere(letra) != 0)
    {
        printf("O valor é : %d\n", verifica_caractere(letra));
    }
    else
    {
        printf("falso\n");
    }
    return 0;
}

int verifica_caractere(char letra)
{
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
    {
        int valor_letra = letra;
        return valor_letra;
    }
    else
    {
        return 0;
    }
}