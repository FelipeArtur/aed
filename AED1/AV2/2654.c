//Breno Passos e Felipe Lima 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[101];
	int poder, matou, morreu, tamanho;
} GOD;

typedef struct no{
	GOD dados;
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

void inserir_ordenado_matou(LISTA* l, int c, char x[21]){
	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados.matou = c;
	strcpy (aux->dados.nome, x);
	aux ->prox = NULL;
	
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{
		NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados.matou < c){
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

int remover_inicio_matou(LISTA *l){
	int temp;
	if(l == NULL) return 0;
	if((*l) == NULL) return 0;
	
	NO *aux = *l;
	temp = aux->dados.matou;
	*l = aux->prox;
	free(aux);
	return temp;
}

int buscar_pos_matou(LISTA *l, int pos){
	int temp, i = 1;
	if(l == NULL || pos <= 0) return 0;
	NO *aux = *l;
	while(aux != NULL && i < pos){
		aux = aux->prox;
		i++;
	}
	if(aux == NULL) 
		return 0;
	else{
		temp = aux->dados.matou;
		return temp;		
	}
		
}

void inserir_ordenado_morreu(LISTA* l, int c, char x[21]){
	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados.morreu = c;
	strcpy (aux->dados.nome, x);
	aux ->prox = NULL;
	
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{
		NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados.morreu < c){
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

int remover_final_morreu(LISTA *l){
	int temp;
	if(l == NULL) return 0;
	if(*l == NULL) return 0;
	
	NO *anterior,*aux = *l;
	while(aux->prox != NULL){
		anterior = aux;
		aux = aux->prox;
	}
	if(aux == (*l)){
		temp = aux->dados.morreu;
		*l = aux->prox;
		
	}else{
		temp = aux->dados.morreu;
		anterior->prox = aux->prox;
		free(aux);
	}
	
	return temp;
	
}

int buscar_pos_morreu(LISTA *l, int pos){
	int temp, i = 1;
	if(l == NULL || pos <= 0) return 0;
	NO *aux = *l;
	while(aux != NULL && i < pos){
		aux = aux->prox;
		i++;
	}
	if(aux == NULL) 
		return 0;
	else{
		temp = aux->dados.morreu;
		return temp;		
	}
		
}

void inserir_ordenado_poder(LISTA* l, int c, char x[21]){
	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados.poder = c;
	strcpy (aux->dados.nome, x);
	aux ->prox = NULL;
	
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{
		NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados.poder < c){
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

int remover_inicio_poder(LISTA *l){
	int temp;
	if(l == NULL) return 0;
	if((*l) == NULL) return 0;
	
	NO *aux = *l;
	temp = aux->dados.poder;
	*l = aux->prox;
	free(aux);
	return temp;
}

int buscar_pos_poder(LISTA *l, int pos){
	int temp, i = 1;
	if(l == NULL || pos <= 0) return 0;
	NO *aux = *l;
	while(aux != NULL && i < pos){
		aux = aux->prox;
		i++;
	}
	if(aux == NULL) 
		return 0;
	else{
		temp = aux->dados.poder;
		return temp;		
	}
		
}

void inserir_ordenado_tamanho(LISTA* l, int c, char x[21]){
	NO *aux = (NO*) malloc(sizeof(NO));
	
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados.tamanho = c;
	strcpy (aux->dados.nome, x);
	aux ->prox = NULL;
	
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}else{
		NO *anterior, *atual = *l;
	
		while(atual != NULL && atual->dados.tamanho < c){
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

int remover_final_tamanho(LISTA *l){
	int temp;
	if(l == NULL) return 0;
	if(*l == NULL) return 0;
	
	NO *anterior,*aux = *l;
	while(aux->prox != NULL){
		anterior = aux;
		aux = aux->prox;
	}
	if(aux == (*l)){
		temp = aux->dados.tamanho;
		*l = aux->prox;
		
	}else{
		temp = aux->dados.tamanho;
		anterior->prox = aux->prox;
		free(aux);
	}
	
	return temp;
	
}

void imprime_listase(LISTA *l){
    NO *aux = *l;
    while (aux!=NULL){
        printf("%s", aux->dados.nome);
        aux=aux->prox;
        if(aux != NULL){
			printf(" ");
		}
    }
}

LISTA *l1, *l2, *l3, *l4;	

int main(){
	l1 = cria_lista();
	l2 = cria_lista();
	l3 = cria_lista();
	l4 = cria_lista();
	
	GOD g;
	int n, aux, temp1, temp2, temp3, temp4, temp5, temp6;
	
	scanf ("%d", &n);
	aux = n-2;

	while (n >= 1 && n <= 100){
		scanf ("%s %d %d %d", &g.nome, &g.poder, &g.matou, &g.morreu);
		g.tamanho = strlen(g.nome);
		inserir_ordenado_poder(l1, g.poder, g.nome); //Ordenar o poder
		inserir_ordenado_matou(l2, g.matou, g.nome); //Ordenar mais matou 
		inserir_ordenado_morreu(l3, g.morreu, g.nome); //Ordenar mais morreu  
		inserir_ordenado_tamanho(l4, g.tamanho, g.nome);
	n--; 
	}
	
	while (aux != 0){
		remover_inicio_poder(l1);
		remover_inicio_matou(l2);
		remover_final_morreu(l3);
		remover_final_tamanho(l4);
	aux--;
	}
	
	temp1 = buscar_pos_poder(l1, 2);
	temp2 = buscar_pos_poder(l1, 1);
	temp3 = buscar_pos_matou(l2, 2);
	temp4 = buscar_pos_matou(l2, 1);
	temp5 = buscar_pos_morreu(l3, 2);
	temp6 = buscar_pos_morreu(l3, 1);
	
	if (temp1 > temp2){
		remover_inicio_poder(l1);
		imprime_listase(l1);
		
	}else if (temp3 > temp4){
		remover_inicio_matou(l2);
		imprime_listase(l2);
		
	}else if (temp5 < temp6){
		remover_final_morreu(l3);
		imprime_listase(l3);
			
	}else{
		remover_final_tamanho(l4);
		imprime_listase(l4);
		
	}
	return 0;
}
