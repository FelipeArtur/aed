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

int main() {
 setlocale(LC_ALL, "portuguese");
 char nomearq[30]; 
 char lista[26], ram[2], aux;
 int i = 0, cont = 0;
 int contador;
 
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
ram[0] = 'D';
ram[1] = 'A';
ram[2] = 'H';

    for (contador = 1; contador < 3; contador++)
    {
        for (i = 0; i < 3 - 1; i++)
        {
            if (ram[i] > ram[i + 1])
            {
                aux = ram[i];
                ram[i] = ram[i + 1];
                ram[i + 1] = aux;
            }
        }
    }

printf("%s", ram);

 return 0; 
}

