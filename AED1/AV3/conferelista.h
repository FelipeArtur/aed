#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Breno Passos, Danilo Shelts, Felipe Lima, Felipe Serra.

typedef struct nu
{
	char dados[20];
	struct nu *prox;
} NU;

typedef NU *LISTA;

LISTA *cria_lista()
{ // ela ir� alocar um espa�o na mem�ria;
	LISTA *li = (LISTA *)malloc(sizeof(LISTA));
	if (li != NULL) // Deu certo a aloca��o
		*li = NULL; // Faz o ponteiro apontar para NULL, ou seja, a lista est� vazia
	return li;
}

int listase_vazia(LISTA *l)
{
	if (l == NULL)
		return 1;
	return 0;
}

int insere_listase(LISTA *l, char c[20])
{ // Esse *l � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da LISTA*, o que est� apontando para o NULL
	if (l == NULL)
		return 0;
	NU *novo_no = (NU *)malloc(sizeof(NU));
	if (novo_no == NULL)
		return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	strcpy(novo_no->dados, c);
	novo_no->prox = NULL;
	if ((*l) == NULL) // Lista est� vazia, vamos inserir no in�cio
		*l = novo_no;
	else
	{
		NU *aux = *l; // novo_no { Z, NULL }
		while (aux->prox != NULL)
		{ // aux = F
			// |A ->B| |B ->F| |F ->Z| |Z ->NULL|
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}
void imprime_listase(LISTA *l)
{
	NU *aux = *l;
	FILE *teste = fopen("Mais.txt", "a+");

	if (teste == NULL)
	{
		printf("Falha no sistema, favor reiniciar\n");
		system("exit");
	}
	else
	{

		while (aux != NULL)
		{
			fprintf(teste, "=====================\n");
			fprintf(teste, "- %s\n", aux->dados);
			fprintf(teste, "=====================\n");
			aux = aux->prox;
		}
		fprintf(teste, "--------------------------fim------------------------\n");
	}
	fclose(teste);
}

int tamanho_listase(LISTA *l)
{
	int cont = 0;
	NU *atu = *l;
	while (atu != NULL)
	{
		cont++;
		atu = atu->prox;
	}
	return cont;
}
