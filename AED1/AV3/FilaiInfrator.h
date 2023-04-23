#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Breno Passos, Danilo Shelts, Felipe Lima, Felipe Serra.

typedef struct
{
	char nome[150];
	int idade, delito, tdelito, reincidente, escolaridade, sexo, resultado;
} INFRATOR;

/*Racional > passional*/
//Delito > Reincid�ncia > Tipo de delito

typedef struct no
{
	INFRATOR dados;
	struct no *prox;
} NO;

typedef struct
{
	NO *ini;
	NO *fim;
} FILA;

FILA *cria_fila()
{ // ela ir� alocar um espa�o na mem�ria;
	FILA *fi = (FILA *)malloc(sizeof(FILA));
	if (fi != NULL)
	{					// Deu certo a aloca��o
		fi->fim = NULL; // Faz o ponteiro apontar para NULL, ou seja, a fila est� vazia
		fi->ini = NULL;
	}
	return fi;
}

int fila_vazia(FILA *f)
{
	if (f == NULL || f->ini == NULL)
		return 1;
	return 0;
}

int enfileira(FILA *f, INFRATOR in)
{
	if (f == NULL)
		return 0;
	NO *novo_no = (NO *)malloc(sizeof(NO));
	if (novo_no == NULL)
		return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->dados = in;
	novo_no->prox = NULL;
	if (f->ini == NULL)
	{ // Fila vazia, vamos inserir no in�cio
		f->ini = novo_no;
		f->fim = novo_no;
	}
	else
	{
		//f->fim->prox = novo_no;
		//f->fim = novo_no;
		NO *aux = f->ini;
		NO *temp;
		while (aux != NULL)
		{
			//printf("Entrou 54\n");
			if (f->ini->dados.delito > novo_no->dados.delito)
			{
				temp = f->ini;
				f->ini = novo_no;
				f->ini->prox = temp;
				break;
			}

			if (novo_no->dados.delito < aux->dados.delito)
			{
				temp->prox = novo_no;
				novo_no->prox = aux;
				break;
			}

			if (novo_no->dados.delito == aux->dados.delito)
			{
				if (f->ini == aux && f->ini->dados.reincidente > novo_no->dados.reincidente)
				{
					temp = f->ini;
					f->ini = novo_no;
					f->ini->prox = temp;
					break;
				}

				if (novo_no->dados.reincidente < aux->dados.reincidente)
				{
					temp->prox = novo_no;
					novo_no->prox = aux;
					break;
				}

				if (novo_no->dados.reincidente == aux->dados.reincidente)
				{
					if (f->ini == aux && f->ini->dados.tdelito > novo_no->dados.tdelito)
					{
						temp = f->ini;
						f->ini = novo_no;
						f->ini->prox = temp;
						break;
					}

					if (novo_no->dados.tdelito < aux->dados.tdelito)
					{
						temp->prox = novo_no;
						novo_no->prox = aux;
						break;
					}

					if (f->ini == aux && novo_no->dados.tdelito == aux->dados.tdelito)
					{
						temp = f->ini;
						f->ini = novo_no;
						f->ini->prox = temp;
						//printf("Entrou lest 1\n");
						break;
					}
					if (novo_no->dados.tdelito == aux->dados.tdelito)
					{
						temp->prox = novo_no;
						novo_no->prox = aux;
						//printf("Entrou lest 2\n");
						break;
					}
				}
			}

			temp = aux;
			aux = aux->prox;
			if (aux == NULL)
			{
				f->fim->prox = novo_no;
				f->fim = novo_no;
			}
		}
	}
	return 1;
}

void imprime_fila(FILA *f)
{
	NO *aux = f->ini;
	FILE *preso = fopen("Ficha.txt", "a+");

	if (preso == NULL)
	{
		printf("Falha no sistema, favor reiniciar\n");
		system("exit");
	}

	else
	{
		fprintf(preso, "Menor Prioridade\n");
		while (aux != NULL)
		{
			fprintf(preso, "=====================\n");
			fprintf(preso, "Nome: %s\n", aux->dados.nome);

			//fprintf(preso, "Grau de escolaridade: %d\n", aux->dados.escolaridade);
			if (aux->dados.escolaridade == 1)
			{
				fprintf(preso, "Grau de escolaridade: Fundamental\n");
			}
			else if (aux->dados.escolaridade == 2)
			{
				fprintf(preso, "Grau de escolaridade: M�dio\n");
			}
			else if (aux->dados.escolaridade == 3)
			{
				fprintf(preso, "Grau de escolaridade: Superior\n");
			}
			else
			{
				printf("Grau de escolaridade nãdco identificado.");
			}

			//fprintf(preso, "Sexo: %d\n", aux->dados.sexo);
			if (aux->dados.sexo == 1)
			{
				fprintf(preso, "Sexo: Masculino\n");
			}
			else if (aux->dados.sexo == 2)
			{
				fprintf(preso, "Sexo: Feminino\n");
			}
			else if (aux->dados.sexo == 3)
			{
				fprintf(preso, "Sexo: Outro\n");
			}
			else
			{
				printf("Sexo n�o identificado.");
			}

			fprintf(preso, "Idade: %d\n", aux->dados.idade);

			//fprintf(preso, "Delito: %d\n", aux->dados.delito);
			if (aux->dados.delito == 1)
			{
				fprintf(preso, "Delito: Crimes contra o património\n");
			}
			else if (aux->dados.delito == 2)
			{
				fprintf(preso, "Delito: Crimes contra a administraçãoo pública\n");
			}
			else if (aux->dados.delito == 3)
			{
				fprintf(preso, "Delito: Crimes econômicos\n");
			}
			else if (aux->dados.delito == 4)
			{
				fprintf(preso, "Delito: Crimes contra a honra\n");
			}
			else if (aux->dados.delito == 5)
			{
				fprintf(preso, "Delito: Crimes contra a dignidade sexual\n");
			}
			else if (aux->dados.delito == 6)
			{
				fprintf(preso, "Delito: Crimes contra a pessoa\n");
			}
			else
			{
				printf("Delito não identificado.");
			}

			//fprintf(preso, "Reincidencia: %d\n", aux->dados.reincidente);
			if (aux->dados.reincidente == 1)
			{
				fprintf(preso, "Reincidente: Não \n");
			}
			else if (aux->dados.reincidente == 2)
			{
				fprintf(preso, "Reincidente: Sim \n");
			}
			else
			{
				printf("Reincidente n�o identificado.");
			}

			//fprintf(preso, "Tipo de delito: %d\n", aux->dados.tdelito);
			if (aux->dados.tdelito == 1)
			{
				fprintf(preso, "Tipo de delito: Passional\n");
			}
			else if (aux->dados.tdelito == 2)
			{
				fprintf(preso, "Tipo de delito: Racional\n");
			}
			else
			{
				printf("Tipo de delito n�o identificado.");
			}

			fprintf(preso, "Poss�veis anos de pris�o: %d\n", aux->dados.resultado);
			fprintf(preso, "=====================\n");
			aux = aux->prox;
		}
		fprintf(preso, "Maior Prioridade\n");
	}
	fclose(preso);
}

void destroi_fila(FILA *f)
{
	NO *atu = f->ini;
	while (atu != NULL)

	{
		f->ini = atu->prox;
		free(atu);
		atu = f->ini;
	}
	f = NULL;
}
