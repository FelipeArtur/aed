#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Primeiro crie um arquivo e grave as notas de forma semelhante a uma matriz 3X3

void entrada_dados(char *nomearq);
void saida_dados(char *nomearq);

int main()
{
    setlocale(LC_ALL, "portuguese");
    char nomearq[30];
    printf("Digite o nome do arquivo: ");
    gets(nomearq);
    entrada_dados(nomearq);
    return 0;
}

void entrada_dados(char *nomearq)
{
    FILE *arq;
    float nota1, nota2, nota3;
    arq = fopen(nomearq, "r");
    if (arq == NULL)
    {
        printf("Arquivo não existe");
        exit(0);
    }
    else
    {

        while (fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF)
        {
            printf("Nota1: %.2f,Nota2: %.2f,Nota3: %.2f\n", nota1, nota2, nota3);
        }
    }
    fclose(arq);
}
