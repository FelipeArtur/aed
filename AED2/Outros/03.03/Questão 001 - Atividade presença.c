#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define num_p 3

typedef struct
{
    int idade;
    char nome[50];
} Pessoa;

void entrada_dados(char *nomearq);
void saida_dados(char *nomearq);

int main()
{
    setlocale(LC_ALL, "portuguese");
    char nomearq[30];
    printf("Digite o nome do arquivo: ");
    gets(nomearq);
    entrada_dados(nomearq);
    saida_dados(nomearq);
    return 0;
}

void entrada_dados(char *nomearq)
{
    FILE *arq;
    int n;
    Pessoa p[num_p];
    arq = fopen(nomearq, "wb");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    else
    {

        for (n = 0; n < num_p; n++)
        {
            printf("Digite seu nome:\n");
            scanf("%[^\n]s", p[n].nome);
            fflush(stdin);
            printf("Digite sua idade:\n");
            scanf("%d", &p[n].idade);
            fflush(stdin);
        }

        fwrite(p, sizeof(Pessoa), num_p, arq);
    }
    fclose(arq);
}

void saida_dados(char *nomearq)
{
    Pessoa p;
    FILE *arq;
    arq = fopen(nomearq, "rb");

    if (arq == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo");
        exit(0);
    }

    else
    {
        printf("Dados gravados no arquivo: ");

        do
        {
            fread(&p, sizeof(Pessoa), 1, arq);
            if (!feof(arq))
            {
                printf("Nome: %s - ", p.nome);
                printf("Idade: %d\n", p.idade);
            }
        } while (!feof(arq));
    }
}
