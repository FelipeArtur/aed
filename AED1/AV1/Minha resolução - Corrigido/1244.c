#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 51

typedef struct{
	char palavra [MAX];
} Palavra;

typedef struct{
	int cont;
	Palavra dados[MAX];
} Lista;

Lista* criarLista(){
	Lista *l;
	l = (Lista*)malloc(sizeof(Lista));
	if(l != NULL){
		l->cont = 0;
	}
	return l;
}

int estahVaziaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == 0;
}

int estaCheiaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == MAX;
}

int inserirOrdenado(Lista* l, Palavra p){
	int i, posicao;
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	if(estahVaziaLista(l)) 
		posicao = 0;
	else{
		for(i=l->cont-1; i>=0 && (strlen(l->dados[i].palavra) < strlen(p.palavra)); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = p;
	l->cont++;
	return 1;
}

void imprimirDadosLista(Lista* l){
	int i;
	if(l != NULL){
		if(!estahVaziaLista(l)){
			for(i=0; i<l->cont; i++){
				if (i != l->cont-1) printf("%s ", l->dados[i].palavra);
				else printf("%s\n", l->dados[i].palavra);
			}
		}else{
			printf("Lista esta vazia!\n");
		}
	}else{
		printf("Lista nao foi criada!\n");
	}
}
Lista *li;	

void main(){
	int n;
	char palavra[3001], *sub;
	Palavra p;
	li = criarLista();
	
	scanf ("%d",&n);
	
	while (n >= 1 && n <= 50){
		scanf(" %[^\n]s", &palavra);
		sub = strtok (palavra," ");
			
		while (sub != NULL){
			strcpy(p.palavra,sub);
			inserirOrdenado(li,p);
			sub = strtok(NULL," ");
		}
		imprimirDadosLista(li);
		li->cont = 0;
		n--;
	}
}
