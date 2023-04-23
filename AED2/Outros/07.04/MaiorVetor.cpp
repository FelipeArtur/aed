#include <stdio.h>
#include <locale.h>

int buscando_rec(int Vetor[6], int local){
	if(local == 0) return Vetor[0];
	
	else {
		int valor = buscando_rec(Vetor, local - 1);
		if (valor > Vetor[local]) return valor;
		else return Vetor[local];
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int Vetor[6] = {3, 5, 120, 3, 1, 0};
	printf("O maior termo presente no vetor é: %d\n", buscando_rec(Vetor, 5));
	return 0;
}
