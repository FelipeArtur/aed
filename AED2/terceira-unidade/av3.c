#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvB.h"
//FELIPE SERRA PORTO DE AZEVEDO
//FELIPE ARTUR MACEDO LIMA

int main()
{
	char buff[30];

	FILE *f = fopen("produtos.xml", "r");
	TipoRegistro zap;
	TipoPagina *D;
	Inicializa(&D);

	if (f == NULL)
	{
		printf("Deu ruim\n");
	}

	else
	{
		char palavra[50], final[30];
		char limpar[30] = "l";
		char *p;
		int cont = 0, tam, cont1, vdd = 0, nstring = 0;
		const char s[2] = "<";
		char *pr;
		long valor;
		float valorFloat;
		//printf("Deu Bom\n");

		while ((fgets(palavra, 50, f)) != NULL)
		{

			//printf("CONT: %i FRASE: %s", cont, palavra);
			if (cont == 3)
			{ // PEGA O CODIGO
				//TIRAR O PRIMEIRO "<"
				int tampalavra = strlen(palavra);
				int cont2 = 0;
				while (cont2 < tampalavra)
				{
					if (palavra[cont2] == '<')
					{
						palavra[cont2] = 'i';
						break;
					}
					cont2++;
				}
				//-----------
				//printf("CONT: %i FRASE: %s", cont, palavra);
				p = strtok(palavra, s);
				tam = strlen(p);
				//printf("CONT: %i FRASE: %s", cont, p);
				cont1 = 0;
				//strcpy(final, limpar);
				//fflush(final);
				vdd = 0;
				nstring = 0;
				while (cont1 < tam)
				{
					if (vdd == 1)
					{
						final[nstring] = p[cont1];
						nstring++;
					}
					if (p[cont1] == '>')
					{
						vdd = 1;
					}
					cont1++;
				}
				//printf("final: %s  \n", final);
				final[nstring] = '\0';
				valor = strtoumax(final, &pr, 10);
				//printf("---> Codigo: %i \n", valor);
				zap.codigo = valor;
			}

			if (cont == 4)
			{ // PEGA A DESCRICAO
				//TIRAR O PRIMEIRO "<"
				int tampalavra = strlen(palavra);
				int cont2 = 0;
				while (cont2 < tampalavra)
				{
					if (palavra[cont2] == '<')
					{
						palavra[cont2] = 'i';
						break;
					}
					cont2++;
				}
				//-----------
				//printf("CONT: %i FRASE: %s", cont, palavra);
				p = strtok(palavra, s);
				tam = strlen(p);
				//printf("CONT: %i FRASE: %s", cont, p);
				cont1 = 0;
				vdd = 0;
				nstring = 0;
				while (cont1 < tam)
				{
					if (vdd == 1)
					{
						final[nstring] = p[cont1];
						nstring++;
					}
					if (p[cont1] == '>')
					{
						vdd = 1;
					}
					cont1++;
				}
				final[nstring] = '\0';
				//printf("DESCRICAO: %s \n", final);
				strcpy(zap.descricao, final);
			}
			//	printf("chegou: ->  %i", cont);
			if (cont == 5)
			{ // PEGA O CUSTO
				//TIRAR O PRIMEIRO "<"

				int tampalavra = strlen(palavra);
				int cont2 = 0;
				while (cont2 < tampalavra)
				{
					if (palavra[cont2] == '<')
					{
						palavra[cont2] = 'i';
						break;
					}
					cont2++;
				}
				//-----------
				//printf("CONT: %i FRASE: %s", cont, palavra);
				p = strtok(palavra, s);
				tam = strlen(p);
				//printf("CONT: %i FRASE: %s", cont, p);
				cont1 = 0;
				vdd = 0;
				nstring = 0;
				while (cont1 < tam)
				{
					if (vdd == 1)
					{
						final[nstring] = p[cont1];
						nstring++;
					}
					if (p[cont1] == '>')
					{
						vdd = 1;
					}
					cont1++;
				}
				//printf("DESCRICAO: %s \n", final);
				final[nstring] = '\0';
				valor = strtoumax(final, &pr, 10);
				valorFloat = valor;
				//printf("CUSTO: %f \n", valorFloat);
				zap.custo = valorFloat;
				cont = 0;
				Insere(zap, &D);
			}

			cont++;
		}
		//Imprime(D);

		//Pesquisar um produto pelo c�digo e apresentar o nome e o custo. Caso n�o exista o produto, informar em tela.
		long num;
		printf("Digite um codigo para buscar: ");
		scanf("%ld%[^\n]", &num);
		Pesquisa(num, D);

		//Exibir todos os produtos do portf�lio (c�digo, nome e custo).
		printf("\nDigite qualquer coisa para exibir todos os produtos: ");
		char continuar[88];
		scanf("%s", continuar);
		Imprime1(D);

		//Exibir o custo total de todos os produtos.
		printf("\nDigite qualquer coisa para exibir o custo total de todos os produtos: ");
		char continuar2[88];
		scanf("%s", continuar2);
		soma1(D);
		printf("CUSTO TOTAL: %.2f", custoTotal);

		fclose(f);
	}

	return 0;
}
