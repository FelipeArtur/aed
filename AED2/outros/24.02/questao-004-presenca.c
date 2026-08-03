#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void entrada_dados(char *nomearq);
void saida_dados(char *nomearq);

//Feito por Daniel Marinho, você precisas entender a forma que ele resolveu a questão.

int main()
{
    //Main padrão
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
    //Ele criou 3 vetores e armazenou os dados.
    FILE *arq;
    int i = 0;
    float nota1[3], nota2[3], nota3[3];
    arq = fopen(nomearq, "r+");

    if (arq == NULL)
    {
        printf("Arquivo n�o existe");
        exit(0);
    }
    else
    {
        while (fscanf(arq, "%f %f %f", &nota1[i], &nota2[i], &nota3[i]) != EOF)
        {
            nota1[i]++;
            nota2[i]++;
            nota3[i]++;
            i++;
        }
        rewind(arq);
        for (i = 0; i < 3; i++)
        {
            fprintf(arq, "%f %f %f\n", nota1[i], nota2[i], nota3[i]);
        }
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
        printf(" N�o foi poss�vel abrir o arquivo\n");
        exit(0);
    }
    else
    {
        while (fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF)
            printf(" || Nota 1: %.2f - Nota 2: %.2f - Nota 3: %.2f  ||\n", nota1, nota2, nota3);
    }
    fclose(arq);
}
