#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Criando a estrutura NO:
typedef int tp_item;

typedef struct tp_no
{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
} tp_no;

typedef tp_no *tp_arvore; //tp_arvore � um ponterio para o n�

//Criando uma �rrvore bin�ria:
tp_arvore inicializa_arvore()
{
	return NULL;
}

//Verificando se a �rvore est� vazia:
int arvore_vazia(tp_arvore raiz)
{
	if (raiz == NULL)
		return 1;
	return 0;
}

//Aloca e retorna o endereço
tp_no *aloca_no()
{
	tp_no *no;
	no = (tp_no *)malloc(sizeof(tp_no));
	return no;
}

//Inserindo um no
int insere_no(tp_arvore *raiz, tp_item e)
{
	tp_no *pai = NULL, *novo, *p = *raiz; // *p = Ponteiro auxiliar
	novo = aloca_no();					  // Criar um novo elemento e colocar o endereço
	if (!novo)
		return 0; //Não alocou (novo = NULL)

	novo->info = e;
	novo->esq = NULL;
	novo->dir = NULL;

	while (p != NULL)
	{ //Buscar a posição onde será inserido o novo nó
		pai = p;
		if (e < p->info)
		{
			p = p->esq;
		}
		else
		{
			p = p->dir;
		}
	}

	if (pai != NULL)
	{
		if (e < pai->info)
		{
			pai->esq = novo;
		}
		else
		{
			pai->dir = novo;
		}
	}
	else
	{
		*raiz = novo;
	}
	return 1;
}

//Imprime os elementos em Pré-ordem (RECURSIVO)
void pre_ordem(tp_no *p)
{
	if (p != NULL)
	{
		printf("%d\n", p->info);
		pre_ordem(p->esq);
		pre_ordem(p->dir);
	}
}

//Imprime os elementos em ordem (RECURSIVO)
void em_ordem(tp_no *p)
{
	if (p != NULL)
	{
		em_ordem(p->esq);
		printf("%d\n", p->info);
		em_ordem(p->dir);
	}
}

//Imprime os elementos em Pós-ordem (RECURSIVO)
void pos_ordem(tp_no *p)
{
	if (p != NULL)
	{
		pos_ordem(p->esq);
		pos_ordem(p->dir);
		printf("%d\n", p->info);
	}
}

//Busca (NÃO RECURSIVA)
tp_no *busca_no(tp_no *p, tp_item e)
{
	while (p != NULL)
	{
		if (e < p->info)
		{
			p = p->esq;
		}
		else
		{
			if (e > p->info)
			{
				p = p->dir;
			}
			else
				return (p);
		}
	};
	return (NULL);
}

//Busca (RECURSIVA)
tp_arvore busca_no_rec(tp_arvore p, tp_item e)
{
	if (p != NULL)
	{
		if (e < p->info)
		{
			return busca_no_rec(p->esq, e);
		}
		else
		{
			if (e > p->info)
			{
				return busca_no_rec(p->dir, e);
			}
			else
				return (p);
		}
	}
	else
		return (NULL);
}

//Altura da árvore
int altura_arvore(tp_arvore raiz)
{
	if (raiz == NULL)
		return 0;
	int alt_esq = altura_arvore(raiz->esq);
	int alt_dir = altura_arvore(raiz->dir);
	if (alt_esq > alt_dir)
	{
		return alt_esq + 1;
	}
	else
		return alt_dir + 1;
}

//Quantidade de nós da árvore
int quant_nos(tp_arvore raiz)
{
	if (raiz == NULL)
		return 0;
	int tot_esq = quant_nos(raiz->esq);
	int tot_dir = quant_nos(raiz->dir);
	return (tot_esq + tot_dir + 1);
}

//APENAS COPIEI OS CÓDIGOS ABAIXO

int remove_no(tp_arvore *raiz, tp_item e)
{
	tp_no *p = *raiz, *ant = NULL, *sub, *pai, *filho;
	while (p != NULL && p->info != e)
	{
		ant = p;
		if (e < p->info)
			p = p->esq;
		else
			p = p->dir;
	}
	if (p == NULL) /* não encontrou */
		return 0;
	/* nó tem no máximo um filho */
	if (p->esq == NULL)
		sub = p->dir;
	else if (p->dir == NULL)
		sub = p->esq;
	else
	{
		/* nó tem dois filhos */
		pai = p;
		sub = p->dir;
		filho = sub->esq;
		while (filho != NULL)
		{
			pai = sub;
			sub = filho;
			filho = sub->esq;
		}
		/* neste ponto, sub é o sucessor em ordem de p */
		if (pai != p)
		{
			/*p não é o pai de sub e sub==pai->esq */
			pai->esq = sub->dir;
			/* remove o nó apontado por sub de sua atual 
				 posição e substitui pelo filho direito de rp */
			/* sub ocupa o lugar de p */
			sub->dir = p->dir;
		}
		/*define filho esq de sub para que sub ocupe o lugar de p */
		sub->esq = p->esq;
	}
	/* insere sub na posição ocupada por p */
	if (ant == NULL)
		*raiz = sub; /* p era raiz */
	else if (p == ant->esq)
		ant->esq = sub;
	else
		ant->dir = sub;
	free(p);
	return 1;
}

void destroi_no(tp_no *no)
{
	if (no == NULL)
		return;
	destroi_no(no->esq);
	destroi_no(no->dir);
	//  printf("\n %d ", no->info);
	free(no);
	no = NULL;
	return;
}

void destroi_arvore(tp_arvore *raiz)
{
	if (*raiz == NULL)
		return;
	destroi_no(*raiz);
	// free(*raiz);
	*raiz = NULL;
}
