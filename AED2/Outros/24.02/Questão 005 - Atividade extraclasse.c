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
    int x = 0, y = 0, i = 0, nota;
    float nota[3], nota2[3], nota3[3];
    arq = fopen(nomearq, "r+");

    if (arq == NULL)
    {
        printf("Arquivo não existe");
        exit(0);
    }
    else
    {

        printf("Qual nota deseja alterar?\n");
        printf("Linha: ");
        scanf("%d", &x);
        printf("Coluna: ");
        scanf("%d", &y);
        printf("Qual a nova nota?\n");
        scanf("%d", &nota);

    }
    fclose(arq);
}

void saida_dados(char *nomearq)
{
    FILE *arq;
    float nota1, nota2, nota3;
    arq = fopen(nomearq, "r");
    if (arq == NULL)
    {
        printf(" Não foi possível abrir o arquivo\n");
        exit(0);
    }
    else
    {
        while (fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF)
            printf("Nota 1: %.2f  Nota 2: %.2f Nota 3: %.2f\n", nota1, nota2, nota3);
    }
    fclose(arq);
}
