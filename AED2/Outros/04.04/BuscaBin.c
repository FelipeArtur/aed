#include <stdio.h>
#include <locale.h>

int busca_binaria (int *V, int K, int B){

	int ESQ, DIR, meio;
	ESQ = 0; DIR = K-1;
	while (ESQ <= DIR) {
		meio = (ESQ + DIR)/ 2;
		
		if (B == V[meio]){
			return meio;
		}else if (B < V[meio]){
			DIR = meio -1;
		}else{
			ESQ = meio +1;
		}
		
	return -1;
	}
}

int busca_binaria_rec (int *V, int esquerda, int direita, int busca){
	int meio;
	
	meio = (esquerda + direita) / 2;
	
	if (V[meio] == busca){
		printf("Posição: %d\n", meio);
		return meio;
	}
	
	if (esquerda > direita) {
	 	printf("O valor não foi encontrado");
        return -1;
    }
    
    if (V[meio] < busca) { 
        return busca_binaria_rec(V, meio +1, direita, busca);
    }else{ 
		return busca_binaria_rec(V, esquerda, meio -1, busca);
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int V[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, Final = 10, Inicial = 0, valor = 0;
	
	printf("Qual o valor que deseja encontrar?\n");
	scanf("%d", &valor);
	
	//printf("Padrão: \n");
	//busca_binaria(V,Final, valor);
	//printf("============= \n");
	printf("Recursivo: \n");
	busca_binaria_rec(V, Inicial, Final - 1, valor);
		
	return 0;
}
