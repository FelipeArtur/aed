#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10000

typedef struct{
	int horarioS /*Saiu*/, horarioC /*Chegou*/;
} Carro;

Carro criarCarro(int v, int q){
	Carro c;
	c.horarioC = v;
	c.horarioS = q;
	return c;
}

typedef struct{
	int topo;
	Carro dados[MAX];
} Pilha;

Pilha *pilhaSaidas;
int espUsado;

Pilha* criarPilha(){
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

void destruirPilha(Pilha* p){
	free(p);
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, Carro c){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = c;
	p->topo++;
	return 1;
}

Carro desempilhar(Pilha *p) { 
	Carro temp;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

int compararHorarioSaida(Pilha *p, int horatemp)
{
	if(p->dados[p->topo-1].horarioS < horatemp){
		return 0;
	} else {
		return 1;
	}
}

int compararHorarioEntradaSaida(Pilha *p, int horatempChegada)
{
	if(p->dados[p->topo-1].horarioS > horatempChegada){
		return 1;
	}else {
		desempilhar(p);
		espUsado--;
		compararHorarioEntradaSaida(p, horatempChegada);
		return 0;
	}
}

void main(){
	
	int numMot=1, numEsp=0, c, s, incorreto=0, i;
	Carro car;
	
	while(numMot || numEsp){
		
		scanf("%d%d", &numMot, &numEsp);
		incorreto=0;
		espUsado=0;
		pilhaSaidas = criarPilha();
		for(i=0; i<numMot; i++){
			
			scanf("%d%d", &c, &s);
			if(estahVaziaPilha(pilhaSaidas)){
				car = criarCarro(c, s);
				empilhar(pilhaSaidas, car);
				espUsado++;
			}else{
				if(!compararHorarioEntradaSaida(pilhaSaidas, c)){
					if(compararHorarioSaida(pilhaSaidas, s)){
						car = criarCarro(c, s);
						empilhar(pilhaSaidas, car);
						espUsado++;
					}else{
						incorreto++;
					}
				}else{
					if(compararHorarioSaida(pilhaSaidas, s)){
						car = criarCarro(c, s);
						empilhar(pilhaSaidas, car);
						espUsado++;
					}else{
						incorreto++;
					}
				}
			}
			if(espUsado > numEsp){
				incorreto++;
			}
		}

		destruirPilha(pilhaSaidas);
		if((incorreto != 0 && numMot != 0)){
			printf("Nao\n");
		}else if(numMot || numEsp){
			printf("Sim\n");
		}
	}
}
