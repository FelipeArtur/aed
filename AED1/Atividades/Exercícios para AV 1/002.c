#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct{
	char placa[9];
	char cor[10];
	char modelo[150];
	int prioridade;	
} Carro;

Carro criarCarro(char* p, char* co, char* m){
	Carro c;
	strcpy(c.placa, p);
	strcpy(c.cor, co);
	strcpy(c.modelo, m);
	return c;
}

typedef struct{
	int ini, fim, cont;
	Carro dados[MAX];
} Fila;

Fila* criarFila(){
	Fila *f;
	f = (Fila*)malloc(sizeof(Fila));
	if(f != NULL){
		f->cont = 0;
		f->ini = 0;
		f->fim = 0;
	}
	return f;
}

void destruirFila(Fila* f){
	free(f);
}

int tamanhoFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont;		
}

int estahVaziaFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont == 0;
}

int estaCheiaFila(Fila* f){
	if(f == NULL) return -1;
	else return f->cont == MAX;
}

int inserirNaFila(Fila* f, Carro c){
	if(f==NULL) return 0;
	if(estaCheiaFila(f)) return 0;
	f->dados[f->fim] = c;
	f->fim = (f->fim+1) % MAX; 
	f->cont++;
	return 1;
}

Carro removerDaFila(Fila *f){ 
	Carro temp;
	if(f != NULL || !estahVaziaFila(f)){	
		temp = f->dados[f->ini]; // pega o valor e incrementa o primeiro da fila
		f->ini = (f->ini+1) % MAX;
		f->cont--;  // um item retirado
		return temp;
	}else{
		return temp;
	}
}

void imprimirCarro(Carro c){
	printf("\n=======================================\n");
	printf("Carro: \n");
	printf("\tPlaca: %s\n", c.placa);
	printf("\tCor: %s\n", c.cor);
	printf("\tModelo: %s\n",c.modelo);
	printf("=======================================\n");
}

void imprimirDadosFila(Fila* f){
	int i, ind;
	if(f != NULL){
		if(!estahVaziaFila(f)){
			for(ind=f->ini, i=0; i < f->cont; i++, ind = ((ind + 1) % MAX)){
				imprimirCarro(f->dados[ind]);
			}
		}else{
			printf("Fila esta vazia!\n");
		}
	}else{
		printf("Fila nao foi criada!\n");
	}
}

Fila *f1;
Fila *f2;
Fila *f3;

int main (){
	int num;
	Carro c;
	f1 = criarFila();
	f2 = criarFila();
	f3 = criarFila();
	
	printf("Quantos carros:\n");
	scanf("%d", &num);
	system("cls");
	
	while (num > 0){
		printf("Placa:\n");
		scanf("%s", c.placa);
		printf("Cor:\n");
		scanf("%s", c.cor);
		printf("Modelo:\n");
		scanf("%s", c.modelo);
	
		if (c.cor == "Preto"){
			inserirNaFila(f1,c);
		}else if (c.cor == "Branco"){
			inserirNaFila(f2,c);
		}else{
			inserirNaFila(f3,c);
		}
	num--;
	}
	imprimirDadosFila(f1);
	imprimirDadosFila(f2);
	imprimirDadosFila(f3);
	return 0;
}
