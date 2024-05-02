#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void concatena (char str1[], char str2[]);

int main()
{

    char str1[100], str2[100];

    printf("Digite a primeira palavra\n");
    fgets(str1, 100, stdin);

    printf("Digite a segunda palavra\n");
    fgets(str2, 100, stdin);

    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    concatena(str1, str2);

}

void concatena (char str1[], char str2[])
{
    int i = 0, soma = strlen(str1);
    
    while (str2[i] != '\0')
    {
        str1[soma] = str2[i];
        i++;
        soma++;
    }

    str1[soma] = '\0';
    
    printf("%s", str1);
     
}
