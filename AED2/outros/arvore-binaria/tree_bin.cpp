#include "tree_bin.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Como inicailaizar
	tp_arvore raiz = inicializa_arvore();

	//Casos de teste
	insere_no(&raiz, 6);
	insere_no(&raiz, 8);
	insere_no(&raiz, 3);
	insere_no(&raiz, 12);
	insere_no(&raiz, 1);
	insere_no(&raiz, 4);
	insere_no(&raiz, 7);

	printf("Pré-ordem\n");
	pre_ordem(raiz);

	printf("Em ordem\n");
	em_ordem(raiz);

	printf("Pós-ordem\n");
	pos_ordem(raiz);

	//Buscar dado na árvore
	int busca;
	printf("Qual valor você deseja checar?\n");
	scanf("%d", &busca);
	if (busca_no(raiz, busca))
		printf("Existe\n");
	else
		printf("Não existe\n");

	//Altura da árvore
	int alt = altura_arvore(raiz);
	printf("A altura da arvore é: %d", alt);

	return 0;
}
