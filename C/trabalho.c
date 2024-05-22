#include <stdio.h>

const int M = 6, N = 6;

int verificaVetor(int vetor[]);
int verificarNumeroRepetido(int vetor[]);
int apagarVetor(int vetor[M][N], int escolha);
int inserirVetor(int vetor[][N], int escolha);
int uniaoVetor(int vetor[][N], int uniao1, int uniao2);
int verificarNumeroRepetido2(int vetor[], int novoElemento);
int intercecaoVetor(int vetor[][N], int inter1, int inter2);
void mostrarConjunto(int vetor[][N], int escolha);
void mostrarTodosConjuntos(int vetor[][N]);
void buscarValor(int vetor[][N], int valor);

int main()
{
    int vetor[M][N];
    int escolha = 1, contador = 0, escolha2 = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vetor[i][j] = 0;
        }
    }

    do
    {
        printf("Digite sua escolha no menu:\n");
        printf("[1] - Criar um conjunto\n");
        printf("[2] - Apagar Conjunto\n");
        printf("[3] - Inserir dados em um conjunto\n");
        printf("[4] - União entre dois conjuntos\n");
        printf("[5] - Interseção entre dois conjuntos\n");
        printf("[6] - Mostrar um conjunto\n");
        printf("[7] - Mostrar todos os conjuntos\n");
        printf("[8] - Fazer busca por um valor\n");
        printf("[0] - Sair do programa\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite em qual conjunto você quer inserir:\n");
            scanf("%d", &escolha2);

            if (verificaVetor(vetor[escolha2]) != 1)
            {
                contador++;
                printf("Digite os valores (terminar com 0):\n");
                do
                {
                    for (int i = 1; i < N; i++)
                    {
                        scanf("%d", &vetor[escolha2][i]);
                        if (vetor[escolha2][i] == 0)
                            break;
                    }
                } while (verificarNumeroRepetido(vetor[escolha2]) == 1);
            }
            break;
        case 2:
            printf("Digite qual conjunto você quer apagar:\n");
            scanf("%d", &escolha2);
            if (escolha2 < contador && escolha2 >= 0)
            {
                if (apagarVetor(vetor, escolha2) == 0)
                {
                    printf("Conjunto apagado com sucesso\n");
                    contador--;
                }
                else
                {
                    printf("Esse conjunto não existe\n");
                }
            }
            break;
        case 3:
            printf("Digite em qual conjunto você quer inserir:\n");
            scanf("%d", &escolha2);

            if (inserirVetor(vetor, escolha2) == 1)
                printf("Conjunto inexistente\n");
            else
                printf("Dados inseridos com sucesso\n");
            break;
        case 4:
        {
            int uniao1 = 0, uniao2 = 0;
            printf("Digite o primeiro conjunto para a união:\n");
            scanf("%d", &uniao1);
            printf("Digite o segundo conjunto para união:\n");
            scanf("%d", &uniao2);

            uniaoVetor(vetor, uniao1, uniao2);
        }
        break;
        case 5:
        {
            int inter1, inter2;
            printf("Digite o primeiro conjunto para a interseção:\n");
            scanf("%d", &inter1);
            printf("Digite o segundo conjunto:\n");
            scanf("%d", &inter2);
            intercecaoVetor(vetor, inter1, inter2);
        }
        break;
        case 6:
            printf("Digite o conjunto que você quer mostrar:\n");
            scanf("%d", &escolha2);
            mostrarConjunto(vetor, escolha2);
            break;
        case 7:
            mostrarTodosConjuntos(vetor);
            break;
        case 8:
        {
            int valor;
            printf("Digite o valor que você quer buscar:\n");
            scanf("%d", &valor);
            buscarValor(vetor, valor);
        }
        break;
        case 0:
            break;
        default:
            printf("Escolha inválida!\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}

int intercecaoVetor(int vetor[][N], int inter1, int inter2)
{
    int livre = -1;

    for (int i = 1; i < M; i++)
    {
        if (vetor[i][0] == 0)
        {
            livre = i;
            break;
        }
    }

    if (livre == -1)
    {
        printf("Não há linha livre disponível\n");
        return -1;
    }

    int contador = 0;

    for (int i = 0; vetor[inter1][i] != 0; i++)
    {
        for (int j = 0; vetor[inter2][j] != 0; j++)
        {
            if (vetor[inter1][i] == vetor[inter2][j])
            {
                if (!verificarNumeroRepetido2(vetor[livre], vetor[inter1][i]))
                {
                    vetor[livre][contador] = vetor[inter1][i];
                    contador++;
                }
                break;
            }
        }
    }

    vetor[livre][contador] = 0;

    return contador;
}

int uniaoVetor(int vetor[][N], int uniao1, int uniao2)
{
    int ConjuntoNovo = -1, contador = 0;
    for (int i = 1; i < M; i++)
    {
        if (vetor[i][0] == 0)
        {
            ConjuntoNovo = i;
            break;
        }
    }

    if (ConjuntoNovo == -1)
    {
        printf("Não há linha livre disponível\n");
        return -1;
    }

    for (int i = 0; vetor[uniao1][i] != 0; i++)
    {
        vetor[ConjuntoNovo][contador] = vetor[uniao1][i];
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

    vetor[ConjuntoNovo][contador] = 0;
    return 0;
}

int inserirVetor(int vetor[][N], int escolha)
{
    if (escolha <= 0 || escolha >= M || vetor[escolha][0] != 0)
        return 1;

    printf("Digite os valores (terminar com 0):\n");
    for (int i = 0; i < N; i++)
    {
        if (vetor[escolha][i] == 0)
        {
            scanf("%d", &vetor[escolha][i]);
            if (vetor[escolha][i] == 0)
                break;
        }
    }

    return 0;
}

int verificarNumeroRepetido2(int vetor[], int novoElemento)
{
    for (int i = 1; vetor[i] != 0; i++)
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
    for (int i = 0; i < N; i++)
    {
        vetor[escolha][i] = 0;
    }
    return 0;
}

int verificaVetor(int vetor[N])
{
    for (int i = 1; i < N; i++)
    {
        if (vetor[i] != 0)
        {
            printf("Falha na operação, vetor já usado.\n");
            return 1;
        }
    }
    return 0;
}

int verificarNumeroRepetido(int vetor[N])
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (vetor[i] == vetor[j] && vetor[i] != 0)
            {
                printf("Número repetido encontrado, digite novamente.\n");
                return 1;
            }
        }
    }
    return 0;
}

void mostrarConjunto(int vetor[][N], int escolha)
{
    if (escolha >= M || escolha <= 0)
    {
        printf("Conjunto não existe\n");
        return;
    }
    for (int i = 0; i < N && vetor[escolha][i] != 0; i++)
    {
        printf("%d ", vetor[escolha][i]);
    }
    printf("\n");
}

void mostrarTodosConjuntos(int vetor[][N])
{
    for (int i = 1; i < M; i++)
    {
        printf("Conjunto %d: ", i);
        for (int j = 1; j < N && vetor[i][j] != 0; j++)
        {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
}

void buscarValor(int vetor[][N], int valor)
{
    int encontrado = 0;
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N && vetor[i][j] != 0; j++)
        {
            if (vetor[i][j] == valor)
            {
                printf("Valor %d encontrado no conjunto %d, posição %d\n", valor, i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado)
    {
        printf("Valor %d não encontrado em nenhum conjunto\n", valor);
    }
}
