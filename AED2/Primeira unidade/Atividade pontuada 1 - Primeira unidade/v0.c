#include <stdio.h>
#include <stdlib.h>

char nome[6][8] =
    {
        {'A', 'R', 'Q', '1', '.', 't', 'x', 't'},
        {'A', 'R', 'Q', '2', '.', 't', 'x', 't'},
        {'A', 'R', 'Q', '3', '.', 't', 'x', 't'},
        {'A', 'R', 'Q', '4', '.', 't', 'x', 't'},
        {'A', 'R', 'Q', '5', '.', 't', 'x', 't'},
        {'A', 'R', 'Q', '6', '.', 't', 'x', 't'},
}

criar_arquivo(FILE * i[], int x, char nomearq[])
{
    i[x] = fopen(nomearq, "wb"); //parametro função criar arquivo

    if (i[x] == NULL)
    {
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
}

int caraconf(char x)
{
    if (x >= 65 && x <= 90)
    {
        return 1;
    }

    if (x >= 97 && x <= 122)
    {
        return 1;
    }

    if (x >= 48 && x <= 57)
    {
        return 1;
    }

    return 0;
}

int main()
{
    FILE *arq[6];
    char sequencia[27], div{3};
    int i = 0;

    scanf(% c, &sequencia);

    for (i = 0; i < 9; i++)
    {
        div[0] = sequencia[i * 3 + 0];
        div[1] = sequencia[i * 3 + 1];
        div[2] = sequencia[i * 3 + 2];

        if (!caraconf(div[0]) && !caraconf(div[1]) && !caraconf(div[2]))
        {
            criar_arquivo(arq, i % 3, nome[i % 3]);
            fwrite(div, sizeof(char * 3), nome[i % 3], arq);
            fclose(arq);
            break;
        }
    }

    return 0;
}