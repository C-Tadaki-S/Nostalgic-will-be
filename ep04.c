#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define NMAX 200

typedef struct produto
{
    // char nome[NMAX];
    int codigo;
    char descricao[NMAX];
    double compra;
    double venda;
};
// manda o menu para o usuário
void mensagem(int *option);
// opção 1, cadastrar o produto
struct produto first(struct produto atual[NMAX], int index);
// opção 2, alterar o produto
struct produto second(struct produto atual[NMAX], int index);
// opção 3, aumento linear na venda de todos
struct produto third(struct produto atual[NMAX], int index);
// opção 4, printa tabela dos produtos
void fourth(struct produto atual[NMAX], int index);
// opção 5, excluir todos os produtos
void fifth(struct produto atual[NMAX], int index);
// opção 6 sai do programa.
struct produto sixth();

int main(void)
{
    int option, index;
    struct produto atual[NMAX];
    index = 0;
    for (int i = 0; i < NMAX; i++)
    {
        atual[i].codigo = 0;
        atual[i].descricao = "000";
        atual[i].compra =
            atual[i].venda
    }
    i = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    printf("Olá, bem vindo ao Gerenciador Sigma (▰ ʖ̯▰)  gostaria de acessar as "
           "minhas funcionalidades? \n");
    printf("Vamos lá então, para até você entender, fiz uma lista:\n\n");
    ////////////////////////////////////////////////////////////////////////////////////////////////
    while (index < 200)
    {
        mensagem(&option);

        switch (option)
        {

        case 1:
            first(atual, index);
            index++;
            continue;
        case 2:
            second(atual, index);
            continue;
        case 3:
            third(atual, index);
            continue;
        case 4:
            fourth(atual, index);
            continue;
        case 5:
            fifth(atual, index);
            continue;
        case 6:
            printf(" ;-; acabou pra nós time. ");
            break;

            ////////////////////////////////////////////////////////////////////////////////////////////////
        case -1:
            printf(" (￣－￣) \n\n");
            continue;
        case 69:
            printf(" (ㆆᴗㆆ) \n\n");
            continue;

        default:
            printf("Opção não válida, não desperdice seu tempo.");
            continue;
        };
        return 0;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////

void mensagem(int *option)
{

    printf("1 - Cadastrar um novo produto\n");
    printf("2 - Alterar um produto\n");
    printf("3 - Aplicar aumento linear de preço de venda\n");
    printf("4 - Listar tabela de preços de produtos\n");
    printf("5 - Excluir todos os produtos\n");
    printf("6 - Sair do Gerenciador Sigma\n\n");
    printf("Digite sua opção: ");
    scanf("%d", &*option);
    printf("\n\n");
}

struct produto first(struct produto atual[NMAX], int index)
{

    printf("Boa! Sou o Joseph e vou te ajudar a cadastrar o produto!\n");
    // printf("Me diga o nome do produto: ");
    printf("\nInforme um código para ele: ");
    scanf("%d", &atual[index].codigo);
    printf("\nDescreva o produto em poucas palavras: ");
    scanf("%s", atual[index].descricao);
    printf("\nMe diga o preço de compra do produto: ");
    scanf("%f", &atual[index].compra);
    printf("\nMe diga o preço de venda desse produto: ");
    scanf("%f", &atual[index].venda);
    printf("\nTudo ok, seu produto foi salvo!");
    printf("\n\n");

    printf("codigo do produto eh: %d\n", atual[index].codigo);
    printf("descrição do produto: %s\n", atual[index].descricao);
    printf("preco compra %f\n", atual[index].compra);
    printf("preco venda %f\n", atual[index].venda);
}

struct produto second(struct produto atual[NMAX], int index)
{
    int i = 0;
    int compara;
    printf("Quer alterar um produto? Sou Evans e vou te ajudar com isso!\n");
    printf("Primeiro, preciso do código do seu produto: ");
    scanf("%d", &compara);

    while (i != index)
    {
        if (atual[i].codigo == compara)
        {
            printf("\nHum, esse é o produto escolhido?: ");
            printf("codigo do produto eh: %d\n", atual[i].codigo);
            printf("descrição do produto: %s\n", atual[i].descricao);
            printf("preco compra %f\n", atual[i].compra);
            printf("preco venda %f\n\n", atual[i].venda);
            printf("Vamos alterar os valores, pedirei novamente por eles:\n");

            printf("\nInforme um código para ele: ");
            scanf("%d", &atual[index].codigo);
            printf("\nDescreva o produto em poucas palavras: ");
            scanf("%s", atual[index].descricao);
            printf("\nMe diga o preço de compra do produto: ");
            scanf("%f", &atual[index].compra);
            printf("\nMe diga o preço de venda desse produto: ");
            scanf("%f", &atual[index].venda);
            printf("\nTudo ok, os dados foram modificados!");
            printf("\n\n");

            printf("codigo do produto eh: %d\n", atual[i].codigo);
            printf("descrição do produto: %s\n", atual[i].descricao);
            printf("preco compra %f\n", atual[i].compra);
            printf("preco venda %f\n\n", atual[i].venda);
            printf("Vamos alterar os valores, pedirei novamente por eles:\n");
        }
        else if (atual[i].codigo != compara)
            continue;
        i++;
    }
}

struct produto third(struct produto atual[NMAX], int index)
{
    double aumento;
    int i = 0;
    double incremento = 0;
    printf("Digite aqui o aumento percentual que deseja aplicar: ");
    scanf("%f", &aumento);

    while (i < index)
    {
        incremento = (atual[i].venda * (aumento / 100.0));
        atual[i].venda += incremento;
        i++;
    }
}

void fourth(struct produto atual[NMAX], int index)
{
    int i = 0;
    printf("   Código   |   Descrição   |   Preço   ");
    while (i < index)
    {
        printf(" %d | %s | %.2f |", atual[i].codigo, atual[i].descricao,
               atual[i].venda);
        i++;
    }
}

void fifth(struct produto atual[NMAX], int index)
{
    int i = 0;
    printf("Eu sou Kell, estou aqui para apagar tudo o que você tem salvo aqui. Você fez sua escolha, encare as consequências!");

    while (i < index)
    {

        atual[i].codigo = 0;
        atual[i].descricao = "nada";
        atual[i].compra = 0;
        atual[i].venda = 0;
        printf("\nHum, esse é o produto escolhido?: ");
        printf("codigo do produto eh: %d\n", atual[i].codigo);
        printf("descrição do produto: %s\n", atual[i].descricao);
        printf("preco compra %f\n", atual[i].compra);
        printf("preco venda %f\n\n", atual[i].venda);
        printf("Vamos alterar os valores, pedirei novamente por eles:\n");
        i++;
    }
}