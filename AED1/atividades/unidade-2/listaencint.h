#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dados;
	struct no *prox;
} NO;

typedef NO* LISTA; // Ponteiro para um Ponteiro

LISTA* cria_lista(){ // ela irá alocar um espaço na memória;
	LISTA *li = (LISTA*) malloc(sizeof(LISTA));
	if(li != NULL) // Deu certo a alocação
		*li = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a lista está vazia
	return li;
}	

int listase_vazia(LISTA *l){
	if(l==NULL) return 1;
	if((*l)==NULL) return 1;
	return 0;
}

// Função que insere ao final da lista
int insere_listase(LISTA *l, int c){ // Esse *l é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(l==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	
	// atribuir os valores para o novo nó;
	novo_no->dados = c;
	novo_no->prox = NULL;   // novo_no { 15, NULL }
	if((*l)==NULL) // Lista está vazia, vamos inserir no início
		*l = novo_no;
	else{
		NO *aux = *l;              // l = 1 e aux = 10   
		while(aux->prox != NULL){  // Lista:
			                       // |1 ->5| |5 ->10| |10 ->15| |15 ->NULL|
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}


void imprime_listase(LISTA *l){
	NO *aux = *l;
	while (aux!=NULL){
		printf("%d ", aux->dados);
		aux=aux->prox;
	}
	printf("\n");
}

int tamanho_listase(LISTA *l){
    int cont=0;
    NO *atu = *l;
    while(atu!=NULL){
        cont++;
        atu=atu->prox;
    }
    return cont;
}

void destroi_listase(LISTA *l){
	NO *atu = *l;                  
	while (atu!=NULL){             
		*l=atu->prox;              
		free(atu);
		atu=*l;
	}
	*l=NULL;
}

void concatenar_listase(LISTA *l1, LISTA *l2){
	NO *aux = *l1;
	if(listase_vazia(l1)){
		*l1 = *l2;
	}else{
		// Move ate o ultimo elemento de l1             
		while (aux->prox != NULL){             
			aux=aux->prox;              		
		}
		aux->prox = *l2;		
	}
	imprime_listase(l1);     
}

void inserir_ordenado_crescente(LISTA* l, int c){// pode ser usado como inserir no meio,no inicio, e no final

	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados = c;
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{//procurar aonde inserir o elemento
	NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados < c){// modo crescente
			anterior = atual;
			atual = atual->prox;
		}		
	
		if(atual == *l){
			aux->prox = (*l);
			*l = aux;
		}else{
			aux->prox = anterior->prox;
			anterior->prox = aux;
		}
	}	
}

void inserir_ordenado_decrescente(LISTA* l, int c){// pode ser usado como inserir no meio,no inicio, e no final

	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados = c;
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{//procurar aonde inserir o elemento
	NO *anterior, *atual = *l;	
	
		while(atual != NULL && atual->dados > c){ // modo decrescente
			anterior = atual;
			atual = atual->prox;
		}		
		
		if(atual == *l){
			aux->prox = (*l);
			*l = aux;
		}else{
			aux->prox = anterior->prox;
			anterior->prox = aux;
		}
	}	
}

