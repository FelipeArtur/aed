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

//HEAP SORT

// Function to swap the the position of two elements
void swap(int *a, int *b){
	  int temp = *a;
	  *a = *b;
	  *b = temp;
}
	void heapify(int arr[], int n, int i){
	  // Find largest among root, left child and right child
	  int largest = i;
	  int left = 2 * i + 1;
	  int right = 2 * i + 2;
	
	  if (left < n && arr[left] > arr[largest])
	    largest = left;
	
	  if (right < n && arr[right] > arr[largest])
	    largest = right;
	
	  // Swap and continue heapifying if root is not largest
	  if (largest != i)
	  {
	    swap(&arr[i], &arr[largest]);
	    heapify(arr, n, largest);
	  }
}
	// Main function to do heap sort
	void heapSort(int arr[], int n){
	  // Build max heap
	  for (int i = n / 2 - 1; i >= 0; i--)
	    heapify(arr, n, i);
	
	  // Heap sort
	  for (int i = n - 1; i >= 0; i--)
	  {
	    swap(&arr[0], &arr[i]);
	
	    // Heapify root element to get highest element at root again
	    heapify(arr, i, 0);
	  }
}
	
	// Print an array
	void printArray(int arr[], int n){
	  for (int i = 0; i < n; ++i)
	    printf("%d ", arr[i]);
	}

//----------------------------------------------------------------------------

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
	int i;
	int swapped[size];
	
	// Transformando todas as letras em minúsculas.
	for(i = 0; i < size; i++){
		swapped[i] = caps(&stack[i], 0);
	}

	heapSort(stack, size);
	
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
	
	
	printf("Digite um texto (máx. 27 letras):\n\n");
	
	// Atribuindo os valores de controle.
	i = 0;
	j = 0;
	
	// Lendo os três primeiros dados e alocando na memória.
	for(i = 0; i < 3; i++){
		scanf("%c", &stack[i]);
		if(stack[i] == 10){
			finish = 1;
			break;
		}
		partition_size++;
	}
	
	// Demonstração.
	printf("\nPRIMEIRA DIVISÃO\n\n");
	// Ordena os dados na memória.
	order_stack(stack, partition_size);
	
	// Palavra menor que 3 letras
	if(partition_size < 3){
		// Escreve no arquivo e finaliza o código.
		archive_append(archive[i%3], i%3, stack); // Não sei como funciona
		for(i = 0; i < partition_size; i++){
			// Demonstração.		
			printf("%c ", stack[i]);
		}
		printf("- Arquivo 1\n");
		return 0;
	}
		
	while(1){
		// Palavra maior que 3 letras.
		// Continua lendo a entrada de dados até que a menor letra da memória seja menor que a última letra do arquivo. ou;
		// Continua lendo a entrada de dados até que não exista mais letras na memória.
		while((stack[0] >= lower && stack[0] != 125) || (stack[1] >= lower && stack[1] != 125) || (stack[2] >= lower && stack[2] != 125)){
			// Se o primeiro elemento for o enter (numericamente menor), ele o transforma em 125 (numericamente maior) e reordena.
			// Identifica que a string de entrada acabou e ativa o estado de finalização.
			// No final do processo, quando a última letra for escrita no arquivo, a memória não consta mais com valores de letra, apenas o 125.
			if(stack[0] == 10){
				stack[0] = 125;
				order_stack(stack, 3);
				finish = 1;
			}
			for(j = 0; j < 3; j++){
				// Verifica se a menor letra da memória é maior que a última letra do arquivo, e se é diferente de 10 (\n).
				if(lower <= stack[j] && stack[j] != 10){
					// Caso seja, ele adiciona a letra no final do arquivo.
					lower = stack[j];
					printf("%c ", stack[j]);
					archive_append_unit(archive[i%3], i%3, stack[j]);
					if(finish){
						// Se o estado de finalização estiver ativo, ele atribui o valor de 125 no lugar da memória. 
						stack[j] = 125;
					} else{
						// Se o estado de finalização estiver inativo, ele lê a próxima letra da string de entrada.
						scanf("%c", &stack[j]);
					}
					break;
				}
			}
			// Ao final da atribuição, ele ordena a memória novamente e verifica se há letras.
			order_stack(stack, 3);
			if(stack[0] == 125 && stack[1] == 125 && stack[2] == 125){break;}
		}
		
		// Finaliza o arquivo e abre o arquivo sequente.
		archive_append_unit(archive[i%3], i%3, 10);
		printf("- Arquivo %d\n", (i%3)+1);
		i++;
		lower = 0;
		// Verifica se a atribuição terminou por falta de letras na memória.
		// Se sim, finaliza a leitura da memória.
		if(stack[0] == 125 && stack[1] == 125 && stack[2] == 125){break;}
	}

	// Redefine o valor da memória para realizar a leitura do arquivo.
	// O número 1 foi escolhido pois o número 0 equivale ao final do arquivo na leitura.
	stack[0] = 1; stack[1] = 1; stack[2] = 1;
	// Demonstração.
	printf("\nSEGUNDA DIVISÃO\n\n");
	
	// Verifica se ainda há alguma letra a ser lida no arquivo.
	while(stack[0] != 0 || stack[1] != 0 || stack[2] != 0){
		// Lê os arquivos até chegar na "letra" de divisão (\n).
		while(stack[0] != 125 || stack[1] != 125 || stack[2] != 125){
			for(i = 0; i < 3; i++){
				// Escreve a letra do arquivo na posição do cursor na memória.
				stack[i] = archive_get_letter(archive[i], i, cursor[i]);
			}
			// Procura o menor valor dentro da memória.
			remove = smaller(stack);
			// Termina a ordenação caso a memória não possua letras.
			if(remove == -1){break;}
			// Demonstração.
			printf("%c ", stack[remove]);
			// Escreve a letra no arquivo de ordenação.
			archive_append_unit(archive[3], 3, stack[remove]);
			// Avança o cursor do arquivo cujo a letra foi removida.
			cursor[remove]++;
		}
		// Escreve um divisor no arquivo.
		archive_append_unit(archive[3], 3, 10);
		
		// Avança o cursor para o início do próximo bloco do arquivo.
		for(i = 0; i < 3; i++){
			cursor[i] = cursor[i] + 2;
			stack[i] = archive_get_letter(archive[i], i, cursor[i]);
		}
		// Demonstração.
		printf("- Arquivo 4\n");
	}
	// Demonstração.
	printf("\nTERCEIRA DIVISÃO\n\n", stack[0], stack[1], stack[2]);
	
	// Redefine os valores das variáveis de controle e dos primeiros arquivos.
	i = 0;
	j = 0;
	archive_create(archive[0], 0);
	archive_create(archive[1], 1);
	archive_create(archive[2], 2);
	
	// Atribui cada bloco dentro do último arquivo para um arquivo inicial.
	while(archive_get_letter(archive[3], 3, i) != 0){
		int letter = archive_get_letter(archive[3], 3, i);
		// Caso leia a divisão de blocos, avança para o próximo arquivo.
		if(letter == 10){
			printf("- Arquivo %d\n", j+1);
			j++;
			i+=2;
		} else{
			printf("%c ", letter);
			archive_append_unit(archive[j], j, letter);
			i++;
		}		
	}
	printf("\n");
	// Redefine o último arquivo.
	archive_create(archive[3], 3);
	
	// Redefine os valores da memória e cursores.
	stack[0] = 1; stack[1] = 1; stack[2] = 1;
	cursor[0] = 0;cursor[1] = 0;cursor[2] = 0;
	
	// Realiza o processo de ordenação da segunda divisão novamente.
	// Dessa vez, os primeiros arquivos terão um bloco apelas.
	// O último arquivo terá a ordenação final.
	// Para entender o código abaixo, ler a secção "SEGUNDA DIVISÃO"
	while(stack[0] != 0 || stack[1] != 0 || stack[2] != 0){
		while(stack[0] != 125 || stack[1] != 125 || stack[2] != 125){
			for(i = 0; i < 3; i++){
				stack[i] = archive_get_letter(archive[i], i, cursor[i]);
			}
			remove = smaller(stack);
			if(remove == -1){break;}
			
			printf("%c ", stack[remove]);
			archive_append_unit(archive[3], 3, stack[remove]);
			cursor[remove]++;
		}
		archive_append_unit(archive[3], 3, 10);
		for(i = 0; i < 3; i++){
			cursor[i] = cursor[i] + 2;
			stack[i] = archive_get_letter(archive[i], i, cursor[i]);
		}
		printf("- Arquivo 4\n");
	}
	
	return 0;
}
