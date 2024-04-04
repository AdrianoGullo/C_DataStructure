#include <stdio.h>

typedef enum { false, true } bool;

int listaDivisores(int n, int divisores[], int * apontaOps) {
    int primos[95] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499}; // Vetor com todos primos de 1 a 500
    int numDiv = 0, num1 = n, pPos = 0;

    while (num1 > 1 && pPos < 95) {
        if (num1 % primos[pPos] == 0) {
            divisores[numDiv] = primos[pPos];
            numDiv++;
            num1 = num1/primos[pPos];
            (*apontaOps) += 2;
        }
        else {
            pPos++;
            (*apontaOps) += 1;
        }
    }
    return numDiv;
}

int exponen(int x, int y) {
    int i, exp = 1;
    for (i = 0; i < y; i++) exp = exp*x;
    return exp;
}

void mdcLista(int a, int b) { 
    int ops =0, mdc = 1, i1 = 0, i2 = 0;
    int divisoresA[95], divisoresB[95];
    int numDivA, numDivB;

    numDivA = listaDivisores(a, divisoresA, &ops);
    numDivB = listaDivisores(b, divisoresB, &ops);
    
    while (i1 < numDivA  && i2 < numDivB){
		if (divisoresA[i1] == divisoresB[i2]){
			mdc = mdc*divisoresA[i2];
			ops++;
			i1++;
			i2++;
		}
		else if (divisoresA[i1] > divisoresB[i2]) i2++;
		else if (divisoresA[i1] < divisoresB[i2]) i1++;
		ops++;
	}
    
    printf("MDC utilizando listagem de fatores: \nmdc = %d \nNum. operacoes: %d\n", mdc, ops);
    return;
}

int mdcEuclidesAux(int a, int b, int * apontaOps) {
	(*apontaOps)+=1;
	if (a > b){
		a = a - b;
		(*apontaOps)+=1;	
		return mdcEuclidesAux( a, b, apontaOps);
	}
	else if (a < b){
		b = b - a;
		(*apontaOps)+=1;
		return mdcEuclidesAux(a, b, apontaOps);
	}
	else if (a == b){
		return a;
	}
}

void mdcEuclides(int a, int b) {
    int ops = 0, mdc = 0;
    mdc = mdcEuclidesAux(a,b,&ops);
    printf("MDC utilizando o algoritmo de Euclides: \nmdc = %d \nNum. operacoes: %d\n", mdc, ops);
}


void mdcBinario(int a, int b) {
    int ops = 0, mdc = 0;
    int aDiv, bDiv, d;
    
    aDiv = a%2;
    bDiv = b%2;
    d = 0;
    
    while (aDiv == 0 && bDiv == 0){
		a = a/2;
    	b = b/2;	
    	d += 1;
    	aDiv = a%2;
    	bDiv = b%2;
	}
	while (a != b){
		d += 2;
		if (aDiv == 0){
			a=a/2;
			aDiv = a%2;
			d +=1;
		}
		else if (bDiv == 0){
			d += 2;
			b=b/2;
			bDiv = b%2;
		}
		else if (a > b){
			a = (a-b)/2;
			d += 2;
		}
		else {
			b = (b-a)/2;
			d += 2;
		}
	}
	mdc = exponen(2, d)*a;
	d += 2;
	
    printf("MDC utilizando o algoritmo binario: \nmdc = %d \nNum. operacoes: %d\n", mdc, ops);
    return;
}   

bool validaEntrada(int a, int b) {
       if (a < 0 || b < 0) return false;
	   else if (a > 500 || b > 500) return false;
       return true; 
}

int main() {
    int a,b;

    scanf("%d %d", &a, &b);
    if (!validaEntrada(a,b)) return 0 + printf("ERRO\n");
    
    mdcLista(a,b);
    printf("Listagm de fatores:\n");
    mdcEuclides(a,b);
    printf("\nEuclides:\n");
    mdcBinario(a,b);
    printf("Binário:\n");
    return 0;
}
