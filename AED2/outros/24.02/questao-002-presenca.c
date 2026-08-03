#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//ERRO!

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
    char mensagem[50];
    arq = fopen(nomearq, "w");
    if (arq == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo");
        exit(0);
    }
    else
    {
        printf("Digite a mensagem que deseja gravar: ");
        gets(mensagem);
        fprintf(arq, "%s\n", mensagem);
        printf("Digite a segunda mensagem: ");
        gets(mensagem);
        fputs(mensagem, arq);
        fputs("\n", arq);
    }
    fclose(arq);
}

void saida_dados(char *nomearq)
{
    FILE *arq;
    char mensagem;
    arq = fopen(nomearq, "r");
    if (arq == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo");
        exit(0);
    }
    else
    {
        printf("Frases gravadas no arquivo!\n");
        while (fgets(mensagem, sizeof(mensagem), arq) != NULL)
        {
            printf("%s", mensagem);
        }
    }
}
