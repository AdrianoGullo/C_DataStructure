#include <stdio.h>

int div(long long int d1,long long int d2){				//definindo fun��o para divis�o inteira
	if (d1 == d2){
		return 1;
	}
	if (d1 < d2){
		return 0;
	}
	else{
		return 1 + div(d1-d2, d2);	
	}
}

int cont1 = 3;
long long int fat(long long int n){						//definindo fun��o para fatorial
	if (n == 0){
		return 1;
	}
	else {
		cont1++;
		return n*fat(n-1);
	}
}

int cont = 0;
int stifel(long long int n1,long long int n2){			//fun��o recursiva com stifel
	if (n2 == 0 || n2 == n1){
		return 1;
	}
	else{
		cont+=2;
		return (stifel(n1-1,n2-1) + stifel(n1-1,n2));
	}
}


long long int b1,b2,b3;
int analitica(long long int n1, long long int n2){		//fun��o analitica (metodo1)
	b1 = fat(n1);
	b2 = fat(n2);
	b3 = fat(n1-n2);
	return 1;
}



int main(){
	long long int numero1, numero2;
	long long int metodo1, den, metodo2;
	
	scanf("%lld %lld", &numero1, &numero2);
	
	if (numero1 < 0 || numero2 < 0){
		printf("ERRO");
		return 0;
	}
	if (numero2 > numero1){
		printf("ERRO");
		return 0;
	}
	if (numero1 > 20 || numero2 > 20){
		printf("ERRO");
		return 0; 
	}
	if (numero1 <= 20 && numero2 <= 20){	
		
		analitica(numero1,numero2);
		
		den = b2*b3;
		metodo1= div(b1,den);
		
		metodo2 = stifel(numero1,numero2);
		
		printf("%lld \n", metodo1);
		printf("%lld \n", metodo2);
		printf("%d \n", cont1);
		printf("%d \n", cont);
	}
}
