#include <stdio.h>

double fatorial(int numero)
{
    double resultado = 1.0;
    for (int i = 1; i <= numero; i++)
    {
        resultado *= i;
    }
    return resultado;
}

double soma_inversas_fatoriais(int N)
{
    double soma = 0.0;
    for (int i = 0; i <= N; i++)
    {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

double fatorialRecursivo(int numero)
{
    if (numero == 0 || numero == 1)
        return 1;
    else
        return numero * fatorialRecursivo(numero - 1);
}

// Função para calcular a soma das inversas dos fatoriais de 0 até N de forma recursiva
double soma_inversas_fatoriais_recursiva(int N)
{
    if (N == 0)
        return 1;
    else
        return 1.0 / fatorial(N) + soma_inversas_fatoriais_recursiva(N - 1);
}

int main()
{
    int N;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &N);

    double resultado = soma_inversas_fatoriais(N);
    double resultado1 = soma_inversas_fatoriais_recursiva(N);

    printf("A soma das inversas dos fatoriais de 0 até %d é: %.6lf\n", N, resultado1);
    printf("A soma das inversas dos fatoriais de 0 até %d é: %.6lf\n", N, resultado);

    return 0;
}
