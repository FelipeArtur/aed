//Breno Passos e Felipe Lima 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char carne[21];
	int validade;
} churras;

typedef struct no{
	churras dados;
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

void inserir_ordenado_crescente(LISTA* l, int c, char x[21]){
	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados.validade = c;
	strcpy (aux->dados.carne, x);
	aux ->prox = NULL;
	
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{
		NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados.validade < c){
			anterior = atual;
			atual = atual->prox;
		}
				
		aux ->prox = atual; 
	
		if(atual == *l){
			*l = aux;
		}else{
			anterior->prox = aux;
		}
	}	
}

void imprime_listase(LISTA *l){
    NO *aux = *l;
    while (aux!=NULL){
        printf("%s", aux->dados.carne);
        aux=aux->prox;
        if(aux != NULL){
			printf(" ");
		}
    }
}

LISTA *l;

int main (){
	l = cria_lista();

	int n, aux;
	churras carnes[999]; 

	while(scanf("%d", &n) != EOF){
	aux = n; 
		while(n > 0){
			scanf("%s %d", carnes[n].carne, &carnes[n].validade);
			inserir_ordenado_crescente(l, carnes[n].validade, carnes[n].carne);	
			n--;
		}
	imprime_listase(l);
	printf("\n");	
	destroi_listase(l);	
	}
	return 0;
}
