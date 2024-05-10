#include <stdio.h>
const int M = 5, N = 5;

int verificaVetor(int vetor[]);
int verificarNumeroRepetido(int vetor[]);
int apagarVetor(int vetor[][], int escolha);

int main()
{
    int vetor[M][N], escolha = 1, contador = 0, escolha2 = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vetor[i][j] = 0;
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }

    do
    {

        printf("Digite oque sua escolha no menu:\n");
        printf("[1] - Criar um conjunto\n");
        printf("[2] - Apagar Conjunto\n");
        printf("[0] Sair do programa\n");
        getchar();

        scanf("%d", &escolha);

        if (escolha == 1)
        {
            printf("Digite em qual conjunto voce quer inserir:\n");
            scanf("%d", &escolha2);

            if (verificaVetor(vetor[escolha2]) != 1)
            {
                contador++;
                printf("Digite os valores\n");
                do
                {
                    for (int i = 0; i < N; i++)
                    {
                        scanf("%d", &vetor[escolha2][i]);
                    }
                } while (verificarNumeroRepetido(vetor[escolha2]) == 1);
            }
        }

        if (escolha == 2)
        {
            printf("Digite qual conjunto voce quer apagar\n");
            scanf("%d", &escolha2);
            if (escolha2 <= contador && escolha2 >= 0)
            {
                if(apagarVetor(vetor, escolha2) == 0)
                    printf("Conjunto apagado com sucesso\n");
                
                else
                    printf("Esse conjunto nao existe");
            }
        }

    } while (escolha != 0);

     for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
}

int apagarVetor(int vetor[][], int escolha)
{
    vetor[5][2];
}

int verificaVetor(int vetor[N])
{
    for (int i = 0; i < N; i++)
    {
        if (vetor[i] != 0)
        {
            printf("Falha na operação, Vetor ja usado.\n");
            return 1;
        }
    }
    return 0;
}

int verificarNumeroRepetido(int vetor[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(vetor[i] == vetor[j])
            {
                printf("Numero repetido encontrado, Digite novamente.\n");
                return 1;
            }
        }
    }
    return 0;
}