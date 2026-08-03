/*	ALGORITMO E ESTRUTURA DE DADOS - PROVA
	
	INTEGRANTES:
	
	Alec Santos;
	Breno Bogéa;
	Danilo Scheltes;
	Felipe Lima;
	Felipe Serra.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

// CAPS: Transforma a letra em maiúscula ou minúscula. retorna se houve alteração na letra.
int caps(int *letter, int option){
	if(option){
		// Transformação de minúscula para maiúscula.
		if(*letter >= 97 && *letter <= 122){
			*letter = *letter - 32;
			return 1;
		} else{
			return 0;
		}
	} else{
		// Transformação de minúscula para maiúscula.
		if(*letter >= 65 && *letter <= 90){
			*letter = *letter + 32;
			return 1;
		} else{
			return 0;
		}
	}
}
// ---------------------------------------------------------------------------
// ORDER STACK: Ordena os números dentro da memória (vetor memória)
void order_stack(int stack[], int size){
	int swapped[size];
	int i, j;
	
	// Transformando todas as letras em minúsculas.
	for(i = 0; i < size; i++){
		swapped[i] = caps(&stack[i], 0);
	}
	// Ordenação por bublle swap.
	for(i = 0; i < size-1; i++){
		for(j = 0; j < size-1; j++){
			if(stack[j] > stack[j+1]){
				int temp = stack[j];
				stack[j] = stack[j+1];
				stack[j+1] = temp;
				
				temp = swapped[j];
				swapped[j] = swapped[j+1];
				swapped[j+1] = temp;
			}
		}
	}
	// Formatando as letras para suas versões originais.
	for(i = 0; i < size; i++){
		if(swapped[i]){caps(&stack[i], 1);}
	}
}
// ---------------------------------------------------------------------------
// ARCHIVE APPEND: adiciona um trecho de 3 letras ao final do arquivo.
int archive_append(FILE *arq, int index, int text[]){
	char arq_name[13];
	char formatted_text[5];
	
	// Seleciona o nome do arquivo baseado no index;
	switch(index){
		case 0:
			strcpy(arq_name, "arquivo_1.txt");
			break;
		case 1:
			strcpy(arq_name, "arquivo_2.txt");
			break;
		case 2:
			strcpy(arq_name, "arquivo_3.txt");
			break;
		case 3:
			strcpy(arq_name, "arquivo_4.txt");
			break;
		case 4:
			strcpy(arq_name, "arquivo_5.txt");
			break;
		case 5:
			strcpy(arq_name, "arquivo_6.txt");
			break;
	}
	
	// Abre o arquivo.
	arq = fopen(arq_name, "a");
	if(arq == NULL){
		printf("Arquivo não encontrado");
		return 1;
	}
	// Adiciona o texto no final do arquivo.
	sprintf(formatted_text, "%c%c%c\n", text[0], text[1], text[2]);
	fputs(formatted_text, arq);
	// Fecha o arquivo.
	fclose(arq);
	
	return 0;
}
// ---------------------------------------------------------------------------
// ARCHIVE APPEND UNIT: adiciona uma letra ao final do arquivo.
int archive_append_unit(FILE *arq, int index, int text){
	char arq_name[13];
	char formatted_text[5];
	
	// Seleciona o nome do arquivo baseado no index;
	switch(index){
		case 0:
			strcpy(arq_name, "arquivo_1.txt");
			break;
		case 1:
			strcpy(arq_name, "arquivo_2.txt");
			break;
		case 2:
			strcpy(arq_name, "arquivo_3.txt");
			break;
		case 3:
			strcpy(arq_name, "arquivo_4.txt");
			break;
		case 4:
			strcpy(arq_name, "arquivo_5.txt");
			break;
		case 5:
			strcpy(arq_name, "arquivo_6.txt");
			break;
	}
	
	// Abre o arquivo.
	arq = fopen(arq_name, "a");
	if(arq == NULL){
		printf("Arquivo não encontrado");
		return 1;
	}
	// Adiciona uma letra no final do arquivo.
	sprintf(formatted_text, "%c", text);
	fputs(formatted_text, arq);
	// Fecha o arquivo.
	fclose(arq);
	
	return 0;
}
// ---------------------------------------------------------------------------
// ARCHIVE CREATE: cria um arquivo.
int archive_create(FILE *arq, int index){
	char arq_name[13];
	
	// Seleciona o nome do arquivo baseado no index;
	switch(index){
		case 0:
			strcpy(arq_name, "arquivo_1.txt");
			break;
		case 1:
			strcpy(arq_name, "arquivo_2.txt");
			break;
		case 2:
			strcpy(arq_name, "arquivo_3.txt");
			break;
		case 3:
			strcpy(arq_name, "arquivo_4.txt");
			break;
		case 4:
			strcpy(arq_name, "arquivo_5.txt");
			break;
		case 5:
			strcpy(arq_name, "arquivo_6.txt");
			break;
	}
	
	// Abre o arquivo.
	arq = fopen(arq_name, "w+");
	if(arq == NULL){
		printf("Arquivo não encontrado");
		return 1;
	}
	// Fecha o arquivo.
	fclose(arq);
	return 0;
}
// ---------------------------------------------------------------------------
// ARCHIVE GET LETTER: lê uma letra do arquivo em determinada posição.
int archive_get_letter(FILE *arq, int index, int position){
	char arq_name[13];
	int letter = 0;
	
	// Seleciona o nome do arquivo baseado no index;
	switch(index){
		case 0:
			strcpy(arq_name, "arquivo_1.txt");
			break;
		case 1:
			strcpy(arq_name, "arquivo_2.txt");
			break;
		case 2:
			strcpy(arq_name, "arquivo_3.txt");
			break;
		case 3:
			strcpy(arq_name, "arquivo_4.txt");
			break;
		case 4:
			strcpy(arq_name, "arquivo_5.txt");
			break;
		case 5:
			strcpy(arq_name, "arquivo_6.txt");
			break;
	}
	
	// Abre o arquivo.
	arq = fopen(arq_name, "r+");
	if(arq == NULL){
		printf("Arquivo não encontrado");
		return 1;
	}
	// Lê a letra do arquivo.
	fseek(arq, position, SEEK_SET);
	fscanf(arq, "%c", &letter);
	// Fecha o arquivo.
	fclose(arq);
	
	return letter;
}
// ---------------------------------------------------------------------------
// SMALLER: retorna o indice do menor elemento na memória.
int smaller(int v[]){
	int i, ended = 1;
	int swapped[3];
	
	// Verifica se possui algum elemento nos arquivos.
	for(i = 0; i < 3; i++){
		if(v[i] == 0 || v[i] == 10){v[i] = 125;}
		else{
			swapped[i] = caps(&v[i], 0);
			ended = 0;
		}
	}
	// Caso não haja, encerra o processo retornando -1.
	if(ended){return -1;}
	
	// Verifica o menor número e retorna o seu índice.
	if(v[0] <= v[1] && v[0] <= v[2]){
		if(swapped[0]){caps(&v[0], 1);}
		return 0;
	}
	if(v[1] <= v[0] && v[1] <= v[2]){
		if(swapped[1]){caps(&v[1], 1);}
		return 1;
	}
	if(v[2] <= v[0] && v[2] <= v[1]){
		if(swapped[2]){caps(&v[2], 1);}
		return 2;
	}
}
// ---------------------------------------------------------------------------
int main(){
	// Configurando localização.
	setlocale(LC_ALL, "Portuguese");
	// Declaração de variáveis.
	int i, j, k, partition_size = 0, finish = 0;
	int lower = 0;
	int stack[3] = {0, 0, 0};
	int cursor[3] = {0, 0, 0};
	int remove = 0;
	FILE *archive[6];
	// Criando os arquivos.
	archive_create(archive[0], 0);
	archive_create(archive[1], 1);
	archive_create(archive[2], 2);
	archive_create(archive[3], 3);
	archive_create(archive[4], 4);
	archive_create(archive[5], 5);
	
	
	printf("Digite um texto (máx. 27 letras):\n\n");
	
	i = 0;
	j = 0;
	
	for(i = 0; i < 3; i++){
		scanf("%c", &stack[i]);
		if(stack[i] == 10){
			finish = 1;
			break;
		}
		partition_size++;
	}
		
	// palavra menor que 3 letras
	if(partition_size < 3){
		order_stack(stack, partition_size);
		archive_append(archive[i%3], i%3, stack);
		printf("%c%c%c", stack[0], stack[1], stack[2]);
		printf("\n%d", finish);
		return 0;
	}
	
	
	while(1){
		// palavra maior que 3 letras
		while(stack[0] >= lower || stack[1] >= lower || stack[2] >= lower){
			if(stack[0] == 10){
				stack[0] = 125;
				order_stack(stack, 3);
				finish = 1;
			}
			for(j = 0; j < 3; j++){
				if(lower <= stack[j] && stack[j] != 10){
					lower = stack[j];
					printf("%c ", stack[j]);
					archive_append_unit(archive[i%3], i%3, stack[j]);
					if(finish){
						stack[j] = 125;
					} else{
						scanf("%c", &stack[j]);
					}
					
					break;
				}
			}
			order_stack(stack, 3);
			if(stack[0] == 125 && stack[1] == 125 && stack[2] == 125){break;}
		}
		archive_append_unit(archive[i%3], i%3, 10);
		printf("\n");
		i++;
		lower = 0;
		if(stack[0] == 125 && stack[1] == 125 && stack[2] == 125){break;}
	}

	
	return 0;
}
