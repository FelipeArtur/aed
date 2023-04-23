#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1001

typedef struct{
	char expressao[MAX];
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

Pilha *p1;

void main(){
	Expressao e;
	int posicao, aux;

	while(scanf("%s",&e.expressao) != EOF){
		posicao = 0;
		aux = 0;
		p1 = criarPilha();
		
		for(posicao = 0; e.expressao[posicao] != '\0'; posicao++){
            if(e.expressao[posicao] == '('){
                empilhar(p1, e);
    
            }else if(e.expressao[posicao] == ')'){
               if (!estahVaziaPilha(p1)){
				 	desempilhar(p1);
				 }else{
				 	aux = 1;
				}
        	}
		}
		if(estahVaziaPilha(p1) && aux == 0){
			printf("correct\n");
		}else{
			printf("incorrect\n");
		}
		free(p1);
	}	
}
