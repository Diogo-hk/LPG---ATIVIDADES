#include <stdio.h>
#include <stdlib.h> // Para malloc

typedef struct no
{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
} No;

No *novoNo(int x);
No *rotacaoEsquerda(No *raiz);
No *rotacaoDireita(No *raiz);
No *rotacaoDireitaEsquerda(No *raiz);
No *rotacaoEsquerdaDireita(No *raiz);
No *inserir(No *raiz, int x);
No *balancear(No *raiz);
int maior(int a, int b);
int alturaDoNo(No *no);
int BalanceamentoDoNo(No *no);
void imprimirEmOrdem(No *raiz);

int main()
{
    No *raiz = NULL;
    int valor;

    while (1)
    {
        printf("Digite um valor para inserir na árvore (ou -1 para sair): ");
        scanf("%d", &valor);

        if (valor == -1)
            break;

        raiz = inserir(raiz, valor);
        printf("Árvore em ordem: ");
        imprimirEmOrdem(raiz);
        printf("\n");

        if (raiz != NULL)
            printf("Raiz atual: %d\n", raiz->valor);
    }

    return 0;
}

No *balancear(No *raiz)
{
    int fb = BalanceamentoDoNo(raiz);

    // Rotação à esquerda
    if (fb < -1 && BalanceamentoDoNo(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if (fb > 1 && BalanceamentoDoNo(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à direita (esquerda-direita)
    else if (fb > 1 && BalanceamentoDoNo(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à esquerda (direita-esquerda)
    else if (fb < -1 && BalanceamentoDoNo(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

No *inserir(No *raiz, int x)
{
    if (raiz == NULL) // Árvore vazia
        return novoNo(x);

    if (x < raiz->valor)
        raiz->esquerdo = inserir(raiz->esquerdo, x);
    else if (x > raiz->valor)
        raiz->direito = inserir(raiz->direito, x);
    else
        printf("Valor %d já está presente na árvore.\n", x);

    // Calcula a altura do nó
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // Balanceia a árvore
    raiz = balancear(raiz);

    return raiz;
}

void imprimirEmOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirEmOrdem(raiz->esquerdo);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direito);
    }
}

No *rotacaoEsquerdaDireita(No *raiz)
{
    raiz->esquerdo = rotacaoEsquerda(raiz->esquerdo);
    return rotacaoDireita(raiz);
}

No *rotacaoDireitaEsquerda(No *raiz)
{
    raiz->direito = rotacaoDireita(raiz->direito);
    return rotacaoEsquerda(raiz);
}

No *rotacaoDireita(No *raiz)
{
    No *y = raiz->esquerdo;
    No *filho = y->direito;

    y->direito = raiz;
    raiz->esquerdo = filho;

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No *rotacaoEsquerda(No *raiz)
{
    No *y = raiz->direito;
    No *filho = y->esquerdo;

    y->esquerdo = raiz;
    raiz->direito = filho;

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

int BalanceamentoDoNo(No *no)
{
    if (no == NULL)
        return 0;
    return alturaDoNo(no->esquerdo) - alturaDoNo(no->direito);
}

No *novoNo(int x)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
    {
        printf("ERRO ao alocar memória.\n");
    }
    return novo;
}

int maior(int a, int b)
{
    return (a > b) ? a : b;
}

int alturaDoNo(No *no)
{
    if (no == NULL)
        return -1;
    else
        return no->altura;
}