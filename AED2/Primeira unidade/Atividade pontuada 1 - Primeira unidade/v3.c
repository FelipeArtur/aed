#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void criararq(char *nomearq);


void criararq(char *nomearq){
	
	FILE *pArq;
	pArq = fopen(nomearq, "w+");
	fclose(pArq);
	
}

void organizar(char ram[]){
	int contador, i;
	char aux;
	for (contador = 1; contador < 3; contador++){
        for (i = 0; i < 3 - 1; i++){
            if(ram[i] > ram[i + 1]){
        		aux = ram[i];
                ram[i] = ram[i + 1];
                ram[i + 1] = aux;
            }
        }
    }
}


int main() {
 setlocale(LC_ALL, "portuguese");
 char nomearq[30]; 
 char lista[26], ram[2];
 int i = 0;

 
 while(i < 6){
 	printf("Digite o nome do arquivo: ");
 	 gets(nomearq);
 	 criararq(nomearq);
 	 i++;
 }
  
 	scanf("%s", lista);
 	printf("%s\n", lista);
 	
/*
 	if(lista[0] < lista[1]){
 		printf("deu bom \n");
	 }else{
	 	printf("deu ruim \n");
	 }
*/	

// Algoritmo de ordenação Bubblesort:

ram[0] = 'X';
ram[1] = '2';
ram[2] = 'A';

organizar(ram);

printf("%s", ram);

	FILE *pArq;
	pArq = fopen("1.txt", "w+");
	i=0;
	while(i < 3){
		
		if((ram[i] >= 65 && ram[i] <= 90) || (ram[i] >= 97 &&  ram[i] <= 122) || (ram[i] >= 48 && ram[i] <= 57) ){
			fputc(ram[i], pArq);
			i++;
		}else{
			printf("ENTROU");
			break;
		}
	
	}
	fclose(pArq);


 return 0; 
}

