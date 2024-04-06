#include <stdio.h>
#include <stdlib.h>

int** CriarFilas(int Linhas, int Filas) {
    int** Banco;
    Banco = (int**)malloc(Linhas * sizeof(int*));
    for (int i = 0; i < Linhas; i++) {
        Banco[i] = (int*)malloc(Filas * sizeof(int));
        for (int j = 0; j < Filas; j++) {
            Banco[i][j] = 0;
        }
    }
    return Banco;
}

void LimparFilas(int** Filas, int Linha) {
    for (int i = 0; i < Linha; i++) {
        free(Filas[i]);
    }
    free(Filas);
}

void ImprimirFilas(int** Filas, int Linha, int Coluna) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            printf("%d ", Filas[i][j]);
        }
        printf("\n");
    }
}

void PassaClientesVetor(int** FilaBanco, int* FilaOrdenada, int Linha, int contFila){
    for (int i = 0; i < Linha; i++){
        for(int j = 0; j < 100; j++){
            if(FilaBanco[i][j] != 0){
                FilaOrdenada[contFila] = FilaBanco[i][j];
                contFila++;
            }
        }
    }
}

int Intercala(int* FilaOrdenada, int Valor1, int r, int Valor2) {
    int* Auxiliar = malloc((Valor2 - Valor1 + 1) * sizeof(int));
    int i = Valor1, j = r + 1, k = 0;

    while (i <= r && j <= Valor2) {
        if (FilaOrdenada[i] <= FilaOrdenada[j]) {
            Auxiliar[k] = FilaOrdenada[i];
            i++;
        } else {
            Auxiliar[k] = FilaOrdenada[j];
            j++;
        }
        k++;
    }

    while (i <= r) {
        Auxiliar[k] = FilaOrdenada[i];
        i++;
        k++;
    }
    while (j <= Valor2) {
        Auxiliar[k] = FilaOrdenada[j];
        j++;
        k++;
    }

    for (i = Valor1; i <= Valor2; i++) {
        FilaOrdenada[i] = Auxiliar[i - Valor1];
    }
    free(Auxiliar);
    return 1;
}

void ImprimirFilaOrdenada(int* FilaOrdenada, int contClientes){
    for (int i = 0; i < contClientes; i++) {
        printf("%d ", FilaOrdenada[i]);
    }
    printf("\n");
}

//Ordenação por MergeSort
void OrdenaFila(int* FilaOrdenada, int Valor1, int Valor2){
    int r;
    if(Valor1 < Valor2){
        r = (Valor1 + Valor2) / 2;
        OrdenaFila(FilaOrdenada, Valor1, r);
        OrdenaFila(FilaOrdenada, r + 1, Valor2);
        Intercala(FilaOrdenada, Valor1, r, Valor2);
    }
}

int main() {
    int Linhas = 0, contClientes = 0, contFilas = 0, ClientesNaFila = 0;
    scanf("%d", &Linhas);
    int** FilaBanco = NULL;
    int* FilaOrdenada = NULL;
    if (Linhas == 0) return 0;

    FilaBanco = CriarFilas(Linhas, 100);
    for (int i = 0; i < Linhas; i++){
        scanf("%d", &ClientesNaFila);
        contClientes += ClientesNaFila;
        for (int j = 0; j < ClientesNaFila; j++){
            scanf("%d", &FilaBanco[i][j]);
        }
    }

    FilaOrdenada = malloc((contClientes + 2) * sizeof(int));
    PassaClientesVetor(FilaBanco, FilaOrdenada, Linhas, contFilas);
    ImprimirFilaOrdenada(FilaOrdenada, contClientes);

    OrdenaFila(FilaOrdenada, 0, contClientes - 1);
    ImprimirFilaOrdenada(FilaOrdenada, contClientes);

    LimparFilas(FilaBanco, Linhas);
    free(FilaOrdenada);
    return 1;
}
