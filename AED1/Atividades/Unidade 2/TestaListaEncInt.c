#include "listaencint.h"

LISTA *l1, *l2, *l3, *l4; // Ponteiro para Ponteiro (nó cabeça)

int main(){
	
	l1 = cria_lista();
	l2 = cria_lista();
	l3 = cria_lista();
	l4 = cria_lista();


	insere_listase(l1, 3);
	insere_listase(l1, 6);
	insere_listase(l1, 9);
	insere_listase(l1, 12);
	insere_listase(l1, 15);
	insere_listase(l1, 18);
	insere_listase(l1, 21);
	insere_listase(l1, 24);
	insere_listase(l1, 27);
	insere_listase(l1, 30);
	
	
	insere_listase(l2, 2);
	insere_listase(l2, 4);
	insere_listase(l2, 6);
	insere_listase(l2, 8);
	insere_listase(l2, 10);
	insere_listase(l2, 12);
	insere_listase(l2, 14);
	insere_listase(l2, 16);
	insere_listase(l2, 18);
	insere_listase(l2, 20);
	
	printf("Lista 1:\n");
	imprime_listase(l1);
	
	printf("Lista 2:\n");
	imprime_listase(l2);
	
	//Implementar uma função para concatenar 2 listas
	printf("Lista concatenada:\n");
	concatenar_listase(l1,l2);
	
	//Lista ordenada 
	printf("Lista ordenada:\n");
	inserir_ordenado_crescente(l3, 2);
	inserir_ordenado_crescente(l3, 0);
	inserir_ordenado_crescente(l3, 9);
	inserir_ordenado_crescente(l3, 1);
	inserir_ordenado_crescente(l3, 7);
	
	imprime_listase(l3);
	
	//Lista ordenada invertida
	printf("Lista invertida:\n");
	inserir_ordenado_decrescente(l4, 2);
	inserir_ordenado_decrescente(l4, 0);
	inserir_ordenado_decrescente(l4, 9);
	inserir_ordenado_decrescente(l4, 1);
	inserir_ordenado_decrescente(l4, 7);
	
	imprime_listase(l4);
	
	return 0;
}
