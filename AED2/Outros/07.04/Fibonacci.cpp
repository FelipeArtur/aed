#include <stdio.h>
#include <locale.h>

int fibonacci (int termo){
	int a = 1, b = 0, fibo;
	
	for (int i = 1; i <= termo; i++){
		fibo = a + b;
		a = b;
		b = fibo;
	}
	return fibo;
}

int fibonacci_rec (int termo){
	if (termo == 2 || termo == 3){
		return 1;
	}else if (termo == 1){
		return 0;
	}else return fibonacci_rec (termo-1) + fibonacci_rec(termo-2);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int termo;
	
	printf("Escreva o termo desejado:\n");
	scanf ("%d", &termo);
	fibonacci_rec (termo);
	printf("O elemento presente no termo %d da sequencia fibonacci é: %d\n", termo, fibonacci(termo));
	printf("O elemento presente no termo %d da sequencia fibonacci é: %d\n", termo, fibonacci_rec(termo));

	return 0;
}
