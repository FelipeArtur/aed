//Uso componenetes destes arquivos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FilaiInfrator.h"
#include "conferelista.h"

//Breno Passos, Danilo Shelts, Felipe Lima, Felipe Serra.

char usuario[100], senha[100];
void registro()
{
	FILA *fi;
	fi = cria_fila();
	INFRATOR in;
	int cont, op, op2;

	printf("=================================\n");
	printf("Olá usuário, o que deseja fazer? \n");
	printf("=================================\n");
	printf("1 - Cadastrar infrator\n");
	printf("2 - Voltar ao menu\n");
	printf("=================================\n");
	scanf("%d", &op);
	system("cls");

	switch (op)
	{
	case 1:
		cont = 1;
	cadastro:

		printf("============================================\n");
		printf("Insira ás informações do infrator número: %d\n", cont);
		printf("============================================\n");

		printf("Nome: ");
		scanf(" %[^\n]s", in.nome);
		printf("=====================================\n");

		printf("Informe o grau de escolaridade:\n");
		printf("1 - Fundamental\n");
		printf("2 - Médio\n");
		printf("3 - Superior\n");
		scanf("%d", &in.escolaridade);
		printf("=====================================\n");

		printf("Informe o sexo:\n");
		printf("1 - Masculino\n");
		printf("2 - Feminino\n");
		printf("3 - Outro\n");
		scanf("%d", &in.sexo);
		printf("=====================================\n");

		printf("Informe a idade: ");
		scanf("%d", &in.idade);
		printf("=====================================\n");

		printf("Informe o delito:\n");
		printf("1 - Crimes contra o património\n");
		printf("2 - Crimes contra a administração pública\n");
		printf("3 - Crimes econômicos\n");
		printf("4 - Crimes contra a honra\n");
		printf("5 - Crimes contra a dignidade sexual\n");
		printf("6 - Crimes contra a pessoa\n");
		scanf("%d", &in.delito);
		printf("=====================================\n");

		printf("É reincidente?\n");
		printf("1 - Não\n");
		printf("2 - Sim\n");
		scanf("%d", &in.reincidente);
		printf("=====================================\n");

		printf("Informe o tipo de delito:\n");
		printf("1 - Passional\n");
		printf("2 - Racional\n");
		scanf("%d", &in.tdelito);
		printf("=====================================\n");

		in.resultado = (in.delito * 4) + (in.reincidente * 3) + (in.tdelito * 2);
		enfileira(fi, in);
		cont++;

		system("pause");
		system("cls");

		printf("===========================================\n");
		printf("Deseja inserir um novo infrator?\n");
		printf("===========================================\n");
		printf("1 - Sim\n");
		printf("2 - Não (Salva os dados e fecha o programa)\n");
		printf("===========================================\n");
		scanf("%d", &op2);
		system("cls");

		switch (op2)
		{
		case 1:
			goto cadastro;
			break;

		case 2:
			printf("============================================\n");
			printf("Agradecemos pela preferencia. Até a próxima!\n");
			printf("============================================\n");
			imprime_fila(fi);
			system("pause");
			system("cls");
			main();
			break;
		}

		break;

	case 2:
		system("pause\n");
		system("cls");
		main();
		break;

	default:
		printf("Senhor(a), somos uma instituição séria, favor rever seus atos.\n");
		system("pause");
		system("cls");
		registro();
	}
}

LISTA *li;
int primeiro = 0;
char temp[20];

typedef struct
{
	char usuario[100], senha[100];
} Info;

int buscar_pos(LISTA *l, int pos)
{
	int i = 1;
	if (l == NULL || pos <= 0)
		return 0;
	NU *aux = *l;
	while (aux != NULL && i < pos)
	{
		aux = aux->prox;
		i++;
	}
	if (aux == NULL)
		return 0;
	else
	{
		strcpy(temp, aux->dados);
		return 0;
	}
}

void login()
{
	Info i;

	FILE *dados = fopen("Dados.txt", "r");

	if (dados == NULL)
	{
		printf("ERRO! Por favor faça o cadastro primeiro \n");
		system("pause\n");
		system("cls");
		main();
	}

	else
	{
		printf("=========================================================\n");
		printf("Para efetuar o login favor informar os dados cadastrados:\n");
		printf("=========================================================\n");

		printf("Insira seu nome:\n");
		scanf("%s", &usuario);
		printf("Insira sua senha:\n");
		scanf("%s", &senha);

		while (fread(&i, sizeof(i), 1, dados))
		{
			if (strcmp(usuario, i.usuario) == 0 && strcmp(senha, i.senha) == 0)
			{
				printf("Login feito com sucesso!\n");
				system("pause\n");
				system("cls");
				registro();
			}
		}
		printf("ERRO! Voltando para o menu\n");
		system("pause\n");
		system("cls");
		main();
	}
	fclose(dados);
}

void registrar()
{
	Info i;
	FILE *dados = fopen("Dados.txt", "a+");
	char usuario2[100];
	if (primeiro == 0)
	{
		li = cria_lista();
	}

	if (dados == NULL)
	{
		printf("ARQUIVOS CORROMPIDOS\n");
	}

	else
	{
		printf("Insira o seu nome:\n");
		scanf("%s", &usuario2);
		while (fread(&i, sizeof(i.usuario), 1, dados))
		{
			if (strcmp(usuario2, i.usuario) == 0)
			{
				printf("Desculpe usuário, este nome já existe tente outro.\n");
				registrar();
			}
		}
		strcpy(i.usuario, usuario2);
		insere_listase(li, i.usuario);
		imprime_listase(li);
		printf("Insira a senha:\n");
		scanf("%s", &i.senha);
		fwrite(&i, sizeof(i), 1, dados);

		fclose(dados);

		printf("DADOS SALVOS\n");
		system("pause\n");
		system("cls");
		primeiro = 1;
		login();
	}
}

int main()
{
	Info i;
	int op;
	setlocale(LC_ALL, "Portuguese");

	printf("====================-----------====================\n");
	printf("--------------------JULGAMENTOS--------------------\n");
	printf("====================-----------====================\n");
	system("pause\n");
	system("cls");

	printf("================================\n");
	printf("Olá usuário! O que deseja fazer?\n");
	printf("================================\n");
	printf("1 - Cadastrar\n");
	printf("2 - Login\n");
	printf("3 - Funcionalidades\n");
	printf("4 - Sair\n");
	printf("================================\n");
	scanf("%d", &op);
	system("cls");

	switch (op)
	{
	case 1:
		registrar();
		break;

	case 2:
		login();
		break;

	case 3:
		printf("=====================================================================\n");
		printf("O sistema pedirá o login e senha na primeira interação com o usuário;\n");

		printf("\n");

		printf("O usuário poderá cadastrar os dados do réu táis como: \n");
		printf("\t-Nome\n");
		printf("\t-Grau de escolaridade\n");
		printf("\t-Sexo\n");
		printf("\t-Idade\n");
		printf("\t-Delito\n");
		printf("\t-Tipo de delito (Passional ou Racional)\n");
		printf("\t-Reincidéncia\n");

		printf("\n");

		printf("Os detentos são organiza, tomando como base a seguinte prioridade:\n");
		printf("\t-Delito\n");
		printf("\t-Reincidéncia\n");
		printf("\t-Tipo de delito\n");

		printf("\n");

		printf("Sendo assim, o sistema permitirá:\n");
		printf("\t-Cadastro do usuário e armazenamento dos dados\n");
		printf("\t-Identificação do réu\n");
		printf("\t-Organização da prioridade de julgamento\n");
		printf("\t-Armazenamento da prioridade de atendimento em um arquivo\n");
		printf("\t-Estimativa da sentença do infrator\n");
		printf("=====================================================================\n");
		system("pause");
		system("cls");
		main();
		break;

	case 4:
		exit(0);

	default:
		printf("Senhor(a), somos uma instituição séria, favor rever seus atos.\n");
		system("pause");
		system("cls");
		main();
	}
	return 0;
}
