#include <stdio.h>
#include <stdlib.h>

char** CriarLabirinto(int Linha, int Coluna){
    char** Labirinto;
    int i;
    Labirinto = (char**)malloc(Linha * sizeof(char*));
    for (i = 0; i < Linha; i++) {
        Labirinto[i] = (char*)malloc(Coluna * sizeof(char));
    }
    return Labirinto;
}

int** LocaisVisitados(int Linha, int Coluna) {
    int** Visitados;
    int i;
    Visitados = (int**)malloc(Linha * sizeof(int*));
    for (i = 0; i < Linha; i++) {
        Visitados[i] = (int*)malloc(Coluna * sizeof(int));
        for (int j = 0; j < Coluna; j++) {
            Visitados[i][j] = 0;
        }
    }
    return Visitados;
}

void LimparLabirinto(char** Labirinto, int Linha) {
    for (int i = 0; i < Linha; i++) {
        free(Labirinto[i]);
    }
    free(Labirinto);
}

void LimparLocaisVisitados(int **Visitados, int Linha) {
    for (int i = 0; i < Linha; i++) {
        free(Visitados[i]);
    }
    free(Visitados);
}

void ImprimirLabirinto(char** Labirinto, int Linha, int Coluna) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            printf("%c ", Labirinto[i][j]);
        }
        printf("\n");
    }
}

//para matriz numéricca
void ImprimirVisitados(int** Visitados, int Linha, int Coluna) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            printf("%d ", Visitados[i][j]);
        }
        printf("\n");
    }
}

int* ProcuraEntrada(char** Labirinto, int Linha, int Coluna, int* Index){
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            if(Labirinto[i][j] == 'E'){
                Index[0] = i;
                Index[1] = j;
                return Index;
            }
        }
    }
    return 0;
}

//Função Backtracking
int ProcuraSaida(char** Labirinto, int** Visitados, int Linhas, int Colunas, int IndexX, int IndexY, int contPortal) {

    if (IndexX < 0 || IndexX >= Linhas || IndexY < 0 || IndexY >= Colunas || Visitados[IndexX][IndexY] == 1) return 0;
    Visitados[IndexX][IndexY] = 1;

    if (Labirinto[IndexX][IndexY] == 'S') {
        printf("Encontrou a saida em (%d,%d)", IndexY, IndexX);
        return 1;
    }
    else if(Labirinto[IndexX][IndexY] == 'X'){
        return 0;
    }
    else if (Labirinto[IndexX][IndexY] == 'G' && contPortal == 0) {
        //printf("Achei um portal em (%d,%d)\n", IndexX, IndexY);
        for (int i = 0; i < Linhas; i++) {
            for (int j = 0; j < Colunas; j++) {
                if (Labirinto[i][j] == 'G' && (i != IndexX || j != IndexY) && Visitados[i][j] != 1) {
                    //printf("Novo portal em (%d,%d)\n", i, j);
                    contPortal++;
                    if (ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, i, j, contPortal) != 0) return 1;
                }
            }
        }
    }
    else {
        //blocos com passagem
        if (ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, IndexX+1, IndexY, contPortal)) return 1;
        if (ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, IndexX-1, IndexY, contPortal)) return 1;
        if (ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, IndexX, IndexY+1, contPortal)) return 1;
        if (ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, IndexX, IndexY-1, contPortal)) return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int Linhas = 0, Colunas = 0, NumPortais = 0, contPortal = 0, Output, i;
    char** Labirinto;
    int** Visitados = NULL;
    int* Index = malloc(2 * sizeof(int));

    FILE* arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return 2;
    }

    char DadosLabirinto[10];
    if (fgets(DadosLabirinto, sizeof(DadosLabirinto), arquivo) == NULL) {
        printf("Erro ao ler a primeira linha.\n");
        return 3;
    }
    if (sscanf(DadosLabirinto, "%d %d %d", &Colunas, &Linhas, &NumPortais) != 3) {
        printf("Erro ao analisar primeira linha.\n");
        return 4;
    }

    Labirinto = CriarLabirinto(Linhas, Colunas);
    Visitados = LocaisVisitados(Linhas, Colunas);

    char LinhaLabirinto[101];
    for (i = 0; i < Linhas; i++){
        if (fgets(LinhaLabirinto, Colunas+1, arquivo) == NULL) {
            LimparLabirinto(Labirinto, Linhas);
            LimparLocaisVisitados(Visitados, Linhas);
            free(Index);
            return 5;
        }
        for (int j = 0; j < Colunas; j++){
            Labirinto[i][j] = LinhaLabirinto[j];
        }
        fgetc(arquivo);
    }

    ImprimirLabirinto(Labirinto, Linhas, Colunas);

    ProcuraEntrada(Labirinto, Linhas, Colunas, Index);
    Output = ProcuraSaida(Labirinto, Visitados, Linhas, Colunas, Index[0], Index[1], contPortal);
    if(Output == 0) printf("Labirinto sem saida\n");

    LimparLabirinto(Labirinto, Linhas);
    LimparLocaisVisitados(Visitados, Linhas);
    free(Index);
    fclose(arquivo);

    return 0;
}