#include <stdio.h>

const int M = 6, N = 6;

void criarConjunto(int vetor[M], int escolha);
void mostrarConjuntoTodo(int vetor[M][N]);
int verificaNumeroRepetido(int vetor[], int numeroLegal);
void inserirNoConjunto(int vetor[], int escolha);
void removerDoConjunto(int vetor[M][N], int escolha);
void unirConjunto(int vetor[M][N], int escolha, int escolha2);
void intersecaoConjunto(int vetor[M][N], int escolha, int escolha2);
void mostrarUmConjunto(int vetor[], int escolha);
void buscarUmValor(int vetor[M][N], int escolha);

int contador = 0;

int main()
{
    int escolha = -1, escolha2 = -2;
    int vetor[M][N];

    // Inicializa a matriz com 0
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vetor[i][j] = 0;
        }
    }

    while (escolha != 9)
    {
        printf("\n");
        printf("Gerenciamento de conjuntos\n\n");
        printf("Menu\n\n");
        printf("[1] - Criar um novo conjunto\n");
        printf("[2] - Inserir dados em um conjunto\n");
        printf("[3] - Remover um conjunto\n");
        printf("[4] - Fazer a união entre dois conjuntos\n");
        printf("[5] - Fazer a interseção entre dois conjuntos\n");
        printf("[6] - Mostrar um conjunto\n");
        printf("[7] - Mostrar todos os conjuntos\n");
        printf("[8] - Fazer busca por um valor\n");
        printf("[9] - Sair do programa\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite em qual conjunto você quer inserir\n");
            scanf("%d", &escolha);
            criarConjunto(vetor[escolha], escolha);
            contador++;
            break;
        case 2:
            printf("Digite qual conjunto voce quer inserir\n");
            scanf("%d", &escolha);
            inserirNoConjunto(vetor[escolha], escolha);
            break;
        case 3:
            printf("Digite o conjunto que voce quer apagar\n");
            scanf("%d", &escolha);
            removerDoConjunto(vetor, escolha);
            break;
        case 4:
            printf("Digite o conjunto que voce quer unir\n");
            scanf("%d", &escolha);
            printf("\nDigite o segundo conjunto que voce quer unir\n");
            scanf(" %d", &escolha2);
            unirConjunto(vetor, escolha, escolha2);
            break;
        case 5:
            printf("Digite o conjunto que voce quer interseção\n");
            scanf("%d", &escolha);
            printf("\nDigite o segundo conjunto que voce quer unir\n");
            scanf(" %d", &escolha2);
            intersecaoConjunto(vetor, escolha, escolha2);
            break;
        case 6:
            printf("Digite o conjunto que voce quer ver\n");
            scanf("%d", &escolha);
            mostrarUmConjunto(vetor[escolha], escolha);
            break;
        case 7:
            mostrarConjuntoTodo(vetor);
            break;
        case 8:
            printf("Digite o valor que voce quer buscar\n");
            scanf("%d", &escolha);
            buscarUmValor(vetor, escolha);
            break;
        case 9:
            return 0;
        default:
            printf("\nINVÁLIDO, DIGITE NOVAMENTE\n\n\n");
            break;
        }
    }
    return 0;
}

void buscarUmValor(int vetor[M][N], int escolha)
{
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (escolha == vetor[i][j])
                printf("Seu numero escolhido esta no conjunto: %d\n", i);
        }
    }
}

void mostrarUmConjunto(int vetor[], int escolha)
{
    printf("\n");
    printf("Esse é o seu conjunto: ");
    for (int i = 1; i < N; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void intersecaoConjunto(int vetor[M][N], int escolha, int escolha2)
{
    int conjuntoCriado = 0, soma = 1;
    for (int i = 1; i < M; i++)
    {
        if (vetor[i][1] == 0)
        {
            conjuntoCriado = i;
            break;
        }
    }

    for (int i = 1; vetor[escolha][i] != 0; i++)
    {
        for (int j = 1; vetor[escolha2][j] != 0; j++)
        {
            if (vetor[escolha][i] == vetor[escolha2][j])
            {
                vetor[conjuntoCriado][soma++] = vetor[escolha][i];
                break;
            }
        }
    }
}

void unirConjunto(int vetor[M][N], int escolha, int escolha2)
{
    int vetor1 = 0, vetor2 = 0;

    for (int i = 1; i < N; i++)
    {
        if (vetor[escolha][i] != 0)
        {
            vetor1++;
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (vetor[escolha2][i] != 0)
        {
            vetor2++;
        }
    }

    if ((vetor1 + vetor2) > (N - 1))
    {
        printf("Erro, conjunto maior do que pode ser criado\n");
        return;
    }

    int conjuntoCriado = 0;
    for (int i = 1; i < M; i++)
    {
        if (vetor[i][1] == 0)
        {
            conjuntoCriado = i;
            break;
        }
    }

    int toma = 1;
    for (int i = 1; vetor[escolha][i] != 0; i++)
    {
        vetor[conjuntoCriado][toma++] = vetor[escolha][i];
    }

    for (int i = 1; vetor[escolha2][i] != 0; i++)
    {
        if (verificaNumeroRepetido(vetor[conjuntoCriado], vetor[escolha2][i]) == 0)
        {
            vetor[conjuntoCriado][toma++] = vetor[escolha2][i];
        }
    }
}

void removerDoConjunto(int vetor[M][N], int escolha)
{
    if (vetor[escolha][1] == 0 || escolha <= 0 || escolha >= M)
    {
        printf("Vetor inexistente, por favor digite um valido\n");
        return;
    }

    // Shift conjuntos
    for (int i = escolha; i < M - 1; i++)
    {
        for (int j = 1; j < N; j++)
        {
            vetor[i][j] = vetor[i + 1][j];
        }
    }

    // Limpa o último conjunto
    for (int j = 1; j < N; j++)
    {
        vetor[M - 1][j] = 0;
    }

    contador--;
}

void inserirNoConjunto(int vetor[], int escolha)
{
    int tamanhoVetor = 0, numeroLegal;

    for (int i = 1; i < M; i++)
    {
        if (vetor[i] != 0)
            tamanhoVetor++;
    }

    printf("Digite os valores para inserir\n");
    for (int i = tamanhoVetor + 1; i < M; i++)
    {
        scanf("%d", &numeroLegal);

        if (numeroLegal == 0)
            break;

        if (verificaNumeroRepetido(vetor, numeroLegal) == 0)
            vetor[i] = numeroLegal;
        else
        {
            printf("Numero repetido, insira novamente\n");
            i--;
        }
    }
}

int verificaNumeroRepetido(int vetor[], int numeroLegal)
{
    for (int i = 1; i < M; i++)
    {
        if (vetor[i] == numeroLegal)
        {
            return 1;
        }
    }
    return 0;
}

void criarConjunto(int vetor[], int escolha)
{
    int numeroLegal = 0;
    if (escolha > 0 && escolha < M)
    {
        printf("Digite os valores para o conjunto (0 para encerrar): ");
        for (int i = 1; i < M; i++)
        {
            scanf("%d", &numeroLegal);

            if (numeroLegal == 0)
                break;

            if (verificaNumeroRepetido(vetor, numeroLegal) == 1)
            {
                printf("Número repetido, digite novamente: ");
                i--;
            }
            else
            {
                vetor[i] = numeroLegal;
            }
        }
    }
    else
        printf("INVALIDO\n");
    return;
}

void mostrarConjuntoTodo(int vetor[M][N])
{
    printf("\n");
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
}
