#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1001

typedef struct{
	char expressao[MAX];
	char inversa[MAX];
} Expressao;

typedef struct{
	int topo;
	Expressao dados[MAX];
} Pilha;

Pilha* criarPilha(){
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

int estahVaziaPilha(Pilha* p){
	if(p->topo == 0) return 1;
	else return 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, Expressao e){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = e;
	p->topo++;
	return 1;
}

Expressao desempilhar(Pilha *p) { 
	Expressao temp;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

void imprimirDadosPilha(Pilha* p){
	int i;
	if(p != NULL){
		if(!estahVaziaPilha(p)){
			for(i=p->topo-1; i>=0; i--){
				//printf("%s\n", p->dados[i]);
				printf ("0\n");
			}
		}
	}
}

Pilha *p1;

void main(){
	Expressao e;
	int valor;

	while(scanf("%s",&e.expressao) != EOF){
		p1 = criarPilha();
		 
		empilhar(p1, e);
		strcpy(e.inversa, e.expressao);
		strrev(e.inversa);
		valor = strcmp(e.expressao, e.inversa);
		
		if (valor != 0){
			desempilhar(p1);
			printf ("1\n");
		}
		
   		else{
   			imprimirDadosPilha(p1);	
		}
   		
    	free(p1);
	}
}
