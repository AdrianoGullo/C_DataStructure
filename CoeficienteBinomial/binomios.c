#include <stdio.h>

int div(long long int d1,long long int d2){				
	if (d1 == d2) return 1;
	if (d1 < d2) return 0;
	else return 1 + div(d1-d2, d2);	
}

long long int fatorial(long long int n){				
	if (n == 0) return 1;
	else return n * fatorial(n-1);
}

int stifel(long long int n1,long long int n2){		
	if (n2 == 0 || n2 == n1) return 1;
	else return (stifel(n1-1,n2-1) + stifel(n1-1,n2));
}

long long int analitica(long long int n1, long long int n2){	
	long long int denominador, metodo;
	denominador = fatorial(n2)*fatorial(n1-n2);
	metodo = div(fatorial(n1),denominador);
	return metodo;
}

int main(){
	long long int numero1, numero2;
	long long int metodo1, denominador, metodo2;

	scanf("%lld %lld", &numero1, &numero2);
	
	if (numero1 < 0 || numero2 < 0) return printf("ERRO: Os numeros devem ser positivos");
	else if (numero2 > numero1) return printf("ERRO: Número 1 deve ser maior que o número 2");
	else if (numero1 > 100 || numero2 > 100) return printf("ERRO: Os numeros devem ser menores que 100");
	else if (numero1 == numero2) return printf("Binômio particular: Quando n1 = n2 o resultado é sempre 1. ");
	else if (numero2 == 0) return printf("Binômio particular: Quando n2 = 0 o resultado é sempre 1. ");
	else if (numero2 == 1) return printf("Binômio particular: Quando n2 = 1 o resultado é sempre n1, no caso, %lld", numero1);
	else if (numero1 <= 100 && numero2 <= 100){	
		metodo1 = analitica(numero1,numero2);
		metodo2 = stifel(numero1,numero2);
		printf("%lld \n", metodo1);
		printf("%lld \n", metodo2);
	}
}
