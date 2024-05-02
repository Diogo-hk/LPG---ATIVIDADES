#include <stdio.h>
#include <string.h>

int main() {
    char s[100], s1[100];
    printf("Digite a string: ");
    fgets(s, 100, stdin);

    // Copia a string original para s1 e, em seguida, inverte s1
    strcpy(s1, s);
    strrev(s1);

    // Verifica se a string original e a string invertida são iguais
    if (strcmp(s, s1) == 0) {
        printf("sim, é um palíndromo\n");
    } else {
        printf("não, não é um palíndromo\n");
    }
    
    return 0;
}
