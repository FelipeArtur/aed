#include <stdio.h>
#include <string.h>

int main(){
	char buff[20] = "\n testando novamente";
	
	FILE *arq = fopen("teste.txt", "a");
	
	if(arq == NULL){
		printf("EITA!\n");

	}else{
		fwrite(buff,1,strlen(buff),arq);
		printf("SUCESSO!\n");
		fclose(arq);
	}
	
	system("pause");
  	return(0);
}
