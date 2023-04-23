#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
    char ch;
    arq = fopen(nomearq, "w");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    else
    {
        printf("Digite os caracateres desejados: ");
        do
        {
            ch = getchar();
            fputc(ch, arq);
        } while (ch != '\n');
    }
    fclose(arq);
}

void saida_dados(char *nomearq)
{
    FILE *arq;
    char ch;
    arq = fopen(nomearq, "r");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    else
    {
        printf("Caracateres gravados no arquivo: ");
        do
        {
            ch = fgetc(arq);
            if (!feof(arq))
                printf("%c", ch);
        } while (!feof(arq));
    }
}