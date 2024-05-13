#include <stdio.h>
const int M = 5, N = 5;

int verificaVetor(int vetor[]);
int verificarNumeroRepetido(int vetor[]);
int apagarVetor(int vetor[M][N], int escolha);
int inserirVetor(int vetor[][N], int escolha);
int uniaoVetor(int vetor[][N], int uniao1, int uniao2);
int verificarNumeroRepetido2(int vetor[], int novoElemento);

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
        printf("[3] - Inserir dados em um conjunto\n");
        printf("[4] - Interseccao entre dois conjuntos\n");
        printf("[0] Sair do programa\n");

        scanf("%d", &escolha);

        if (escolha == 1)
        {
            printf("Digite em qual conjunto voceN quer inserir:\n");
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
                        if (vetor[escolha2][i] == 0)
                            break;
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
                if (apagarVetor(vetor, escolha2) == 0)
                {
                    printf("Conjunto apagado com sucesso\n");
                    contador--;
                }

                else
                    printf("Esse conjunto nao existe");
            }
        }

        if (escolha == 3)
        {
            printf("Digite em qual conjunto voce quer inserir\n");
            scanf("%d", &escolha2);

            if (inserirVetor(vetor, escolha2) == 1)
                printf("Conjunto inexistente\n");

            else
                printf("Conjunto inserido com sucesso\n");
        }

        if (escolha == 4)
        {
            int uniao1 = 0, uniao2 = 0;
            printf("Digite primeiro conjunto para a uniao\n");
            scanf("%d", &uniao1);
            printf("Digite o segundo conjunto para uniao\n");
            scanf(" %d", &uniao2);

            uniaoVetor(vetor, uniao1, uniao2);
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

int uniaoVetor(int vetor[][N], int uniao1, int uniao2)
{
    int ConjuntoNovo = 0, contador = 0;
    for (int i = 0; i < M; i++)
    {
        if (vetor[i][0] == 0)
        {
            ConjuntoNovo = i;
            break;
        }
    }

    for (int i = 0; vetor[uniao1][i] != 0; i++)
    {
        vetor[ConjuntoNovo][i] = vetor[uniao1][i];
        printf("Vetor conjunto novo: | %d |    ", vetor[ConjuntoNovo][i]);
        contador++;
    }

    for (int i = 0; vetor[uniao2][i] != 0 && i < N; i++)
    {
        if (!verificarNumeroRepetido2(vetor[ConjuntoNovo], vetor[uniao2][i]))
        {
            vetor[ConjuntoNovo][contador] = vetor[uniao2][i];
            contador++;
        }
    }
    return 0;
}

int inserirVetor(int vetor[][N], int escolha)
{
    if (vetor[escolha][0] == 0)
        return 1;

    printf("Digite os valores\n");
    for (int i = 1; i < N; i++)
    {
        if (vetor[escolha][i] == 0)
        {
            scanf("%d", &vetor[escolha][i]);
        }
    }

    return 0;
}

int verificarNumeroRepetido2(int vetor[], int novoElemento)
{
    for (int i = 0; vetor[i] != 0; i++)
    {
        if (vetor[i] == novoElemento)
        {
            return 1;
        }
    }
    return 0;
}

int apagarVetor(int vetor[][N], int escolha)
{
    for (int i = escolha; i < M - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vetor[i][j] = vetor[i + 1][j];
            vetor[i + 1][j] = 0;
        }
    }
    return 0;
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
            if (vetor[i] == vetor[j] && vetor[i] != 0)
            {
                printf("Numero repetido encontrado, Digite novamente.\n");
                return 1;
            }
        }
    }
    return 0;
}