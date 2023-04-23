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
void organizarLista(char lista[]){
	int i = 0, contador = 0;
	int size = strlen(lista);
	while(contador < 3){
		i = 0; 
		while(i < size){
			lista[i] = lista[i + 1];
			i++;
		}
		contador++;
	}

}

int main() {
 setlocale(LC_ALL, "portuguese");
 char nomearq[30]; 
 char lista[26], ram[2];
 int i = 0, cont = 0, num = 3;

 
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
/*
ram[0] = 'X';
ram[1] = '2';
ram[2] = 'A';

organizar(ram);

printf("%s", ram);
*/
//=======================================================teste=================================================================================
/*     
	
	
	strncpy(ram, lista, 3);
	organizarLista(lista);
	
	
	organizar(ram);
	printf("%s\n", ram);

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
*/	
    //=================================================================LOGICA-PARA-COLOCAR-NO-ARQUIVO===========================================

	FILE *pArq1;
	FILE *pArq2;
	FILE *pArq3;
	
	pArq1 = fopen("1.txt", "w+");
	pArq2 = fopen("2.txt", "w+");
	pArq3 = fopen("3.txt", "w+");
	
while(cont < 3){
	

	//=================================ARQ-1========================================
	
	if(strlen(lista) >= 3){
		strncpy(ram, lista, 3);
	}else if(strlen(lista) == 2){
		strncpy(ram, lista, 2);
		ram[2] = '~';
	}else{
		strncpy(ram, lista, 1);
		ram[1] = '~';
		ram[2] = '~';
	}
	organizarLista(lista);
	organizar(ram);
	
	i = 0;
	while(i < 3){
		if((ram[i] >= 65 && ram[i] <= 90) || (ram[i] >= 97 &&  ram[i] <= 122) || (ram[i] >= 48 && ram[i] <= 57) ){
			fputc(ram[i], pArq1);
			i++;
		}else{
			printf("ENTROU1 \n");
			break;
		}
	}
	//=================================ARQ-2========================================
	
	if(strlen(lista) >= 3){
		strncpy(ram, lista, 3);
	}else if(strlen(lista) == 2){
		strncpy(ram, lista, 2);
		ram[2] = '~';
	}else{
		strncpy(ram, lista, 1);
		ram[1] = '~';
		ram[2] = '~';
	}
	organizarLista(lista);
	organizar(ram);
	
	i=0;
	while(i < 3){
		if((ram[i] >= 65 && ram[i] <= 90) || (ram[i] >= 97 &&  ram[i] <= 122) || (ram[i] >= 48 && ram[i] <= 57) ){
			fputc(ram[i], pArq2);
			i++;
		}else{
			printf("ENTROU2 \n");
			break;		
		}
	}
	//=================================ARQ-3========================================
	
	if(strlen(lista) >= 3){
		strncpy(ram, lista, 3);
	}else if(strlen(lista) == 2){
		strncpy(ram, lista, 2);
		ram[2] = '~';
	}else{
		strncpy(ram, lista, 1);
		ram[1] = '~';
		ram[2] = '~';
	}
	organizarLista(lista);
	organizar(ram);
	
	i=0;
	while(i < 3){
		if((ram[i] >= 65 && ram[i] <= 90) || (ram[i] >= 97 &&  ram[i] <= 122) || (ram[i] >= 48 && ram[i] <= 57) ){
			fputc(ram[i], pArq3);
			i++;
		}else{
			printf("ENTROU3 \n");
			break;		
		}
	}


	cont++;
}

//====================================FIM-DA-LOGICA==================================================================	

//====================================LOGICA-2=======================================================================

	rewind(pArq1);
	rewind(pArq2);
	rewind(pArq3);

	fpos_t posicao;
	int cont1 = 0, cont2 = 0, cont3 = 0, block = 0, block2 = 0;
	FILE *pArq4;
	//FILE *pArq5;
	//FILE *pArq6;

	pArq4 = fopen("4.txt", "w+");
	//pArq5 = fopen("5.txt", "w+");
	//pArq6 = fopen("6.txt", "w+");	

	
	ram[0] = fgetc(pArq1);
	ram[1] = fgetc(pArq2);
	ram[2] = fgetc(pArq3);
	
	cont = 0;
	while(cont < 9){
	
	if((cont1 == 3 || cont2 == 3 || cont3 == 3) && block == 0){
		ram[0] = '~';
		//alg = 1;
		block = 1;
		organizar(ram);
	}
	if(( (cont1 == 3 && cont2 == 3) || (cont1 == 3 && cont3 == 3) || (cont2 == 3 && cont3 == 3)) && block2 == 0){
		ram[0] = '~';
		block2 = 1;
		organizar(ram);
	}
		
	organizar(ram);
	printf("RAM: %s \n", ram);
	
	fputc(ram[0], pArq4);
	
	rewind(pArq1);
	rewind(pArq2);
	rewind(pArq3);
		
	while(cont < 100){
		
		fgetpos(pArq1, &posicao);	
		fgetpos(pArq2, &posicao);	
		fgetpos(pArq3, &posicao);		
		
		
		if(ram[0] == fgetc(pArq1) && cont1 < 3){
			cont1++;
			
			if(cont1 < 3){
				ram[0] = fgetc(pArq1);
			}
						
			fsetpos(pArq1, &posicao);
			fputc('~', pArq1);
			break;
		
		}else if(ram[0] == fgetc(pArq2) && cont2 < 3){
			cont2++;
			
			if(cont2 < 3){
				ram[0] = fgetc(pArq2);
			}
			
			fsetpos(pArq2, &posicao);
			fputc('~', pArq2);		
			
			break;
		
		}else if(ram[0] == fgetc(pArq3) && cont3 < 3){
			cont3++;
			
			if(cont3 < 3){
				ram[0] = fgetc(pArq3);	
			}
		
			fsetpos(pArq3, &posicao);
			fputc('~', pArq3);
			
			break;
		}		
	} 

	//printf("RAM: %s \n", ram);
	cont++;		
}

	
	
	fclose(pArq1);
	fclose(pArq2);
	fclose(pArq3);
	fclose(pArq4);


 return 0; 
}


 
