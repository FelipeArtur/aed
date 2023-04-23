/*	ALGORITMO E ESTRUTURA DE DADOS - ATIVIDADE PONTUADA 
	
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
	int i, j, k, partition_size, finish = 0;
	int stack[3];
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
	
	for(i = 0; i < 9; i++){
		partition_size = 0;
		stack[0] = 0; stack[1] = 0; stack[2] = 0;
		
		// Lendo a entrada de dados e separando em grupos de, no máximo, três.
		for(j = 0; j < 3; j++){
			scanf("%c", &stack[j]);
			if(stack[j] == 10){
				finish = 1;
				break;
			}
			partition_size++;
		}
		// Demonstração.
		if(i == 0){printf("\nPRIMEIRA DIVISÃO E ORDENAÇÃO\n\n");}
		
		// Ordenando os números da memória e adicionando nos arquivos.
		order_stack(stack, partition_size);
		archive_append(archive[i%3], i%3, stack);
		
		// Demonstração.
		for(j = 0; j < 3; j++){
			if(stack[j]){
				printf("%c", stack[j]);
			}
		}
		if(i%3 == 2){
			printf("\n");
		} else{
			printf(" ");
		}
		// Termina o ciclo caso a leitura seja finalizada antes do limite máximo.
		if(finish){break;}
	}
	printf("\n");
	// Demonstração.
	printf("\nSEGUNDA DIVISÃO E ORDENAÇÃO\n\n");
	
	for(i = 0; i < 3; i++){
		remove = 0;
		// Posiciona o cursor no inicio de cada bloco de três, dentro do arquivo.
		cursor[0] = (i*5);
		cursor[1] = (i*5);
		cursor[2] = (i*5);
		
		for(j = 0; j < 9; j++){
			// Transfere a letra do arquivo para a memória.
			for(k = 0; k < 3; k++){
				stack[k] = 0;
				stack[k] = archive_get_letter(archive[k], k, cursor[k]);
			}
			// Procura o menor valor dentro da memória.
			remove = smaller(stack);
			// Demonstração.
			printf("%c", stack[remove]);
			// Termina a ordenação caso não tenham mais letras nos blocos do arquivo.
			if(remove == -1){break;}
			// Adiciona a letra no arquivo de ordenação, desta vez, em uma string com 9 letras no máximo.
			archive_append_unit(archive[i+3], i+3, stack[remove]);
			// Avança o cursor do arquivo cujo a letra foi removida.
			cursor[remove]++;
		}
		printf("\n");
	}
	
	// Posiciona o cursor no inicio de cada arquivo.
	cursor[0] = 0;
	cursor[1] = 0;
	cursor[2] = 0;
	// Reseta o primeiro arquivo, que se tornará o arquivo final de ordenação.
	archive_create(archive[0], 0);
	
	printf("\nTERCEIRA DIVISÃO E ORDENAÇÃO\n\n");
	for(i = 0; i < 27; i++){
		// Transfere a letra do arquivo para a memória.
		for(j = 0; j < 3; j++){
			stack[j] = 0;
			stack[j] = archive_get_letter(archive[j+3], j+3, cursor[j]);
		}
		// Procura o menor valor dentro da memória.
		remove = smaller(stack);
		// Demonstração.
		printf("%c", stack[remove]);
		// Termina a ordenação caso não tenham mais letras nos arquivo.
		if(remove == -1){break;}
		// Adiciona a letra no arquivo final de ordenação.
		archive_append_unit(archive[0], 0, stack[remove]);
		// Avança o cursor do arquivo cujo a letra foi removida.
		cursor[remove]++;
	}
	printf("\n");
	
	return 0;
}
