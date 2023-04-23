//Breno Passos e Felipe Lima 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[150];
	int peso;
	int idade;
	float altura; 
} Renas;

typedef struct no{
	Renas dados;
	struct no *prox;
} NO;

typedef struct{
	NO *ini;
	NO *fim;
}FILA; 

typedef struct{
	FILA *filaprio;
	FILA *filanormal;
}FILA_DE_PRIORIDADE;

FILA* cria_fila(){ // ela irá alocar um espaço na memória;
	FILA *fi = (FILA*) malloc(sizeof(FILA));
	if(fi != NULL){ // Deu certo a alocação
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila está vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_vazia(FILA *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}

int enfileira(FILA *f, Renas r){ 
	if(f==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados = r;
	novo_no->prox = NULL;
	if(f->ini==NULL){ // Fila vazia, vamos inserir no início
		f->ini = novo_no;
		f->fim = novo_no;
	}else{
		f->fim->prox = novo_no;
		f->fim = novo_no;
		//Gerar as condiçoes a partir daqui 
	}
	return 1;
}

int desenfileira(FILA *f, Renas *r){ 
	if(f==NULL) return 0;
	NO *aux = f->ini;
	
	strcpy(r->nome, aux->dados.nome);
	r->peso = aux->dados.peso;
	r->idade = aux->dados.idade;
	r->altura = aux->dados.altura;
	
	// Desloca o inicio fazendo-o apontar para o próximo nó
	f->ini = aux->prox;
	// Libera o nó desempilhado
	free(aux);

	return 1;
}

void destroi_fila(FILA *f){
	NO *atu = f->ini;
	while (atu!=NULL){
		f->ini=atu->prox;
		free(atu);
		atu=f->ini;
	}
	f=NULL;
}

void imprime_fila(FILA *f){
	int n; 
	if(fila_vazia(f)) printf("FILA VAZIA! ");
	NO *aux = f->ini;
	while (aux!=NULL){
		n++;
		printf("%d - %s\n", n, aux->dados.nome);
		aux=aux->prox;
	}
}


FILA *f;	

int main(){
	f = cria_fila();
	
	int casos, total, treno, cenario=0, i;
	Renas r;
	
	scanf ("%d", &casos);
	while (casos > 0){
		cenario++;
		scanf("%d %d", &total, &treno);
		
		while (total > 0){   
			scanf("%s %d %d %f", &r.nome, &r.peso, &r.idade, &r.altura); 
			enfileira(f, r);		
		total--; 
		}
		printf("CENARIO {%d}\n", cenario);
		imprime_fila(f);
		printf("\n");
		destroi_fila(f);
	casos--;	
	}		
	return 0;
}
