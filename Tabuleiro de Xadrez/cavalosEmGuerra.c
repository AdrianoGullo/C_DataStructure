#include <stdio.h>
#include <stdlib.h>

char** CriarTabuleiro(){
    char** Tabuleiro;
    int i, j;
    // Alocando a matriz dinamicamente
    Tabuleiro = (char**)malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i++) {
        Tabuleiro[i] = (char*)malloc(8 * sizeof(char));
    }
    // Inicializando a matriz
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            Tabuleiro[i][j] = '-';
        }
    }
    return Tabuleiro;
}

void LimparTabuleiro(char** Tabuleiro){
    int i;
    //Limpar matriz alocada dinamicamente
    for (i = 0; i < 8; i++) {
        free(Tabuleiro[i]);
    }
    free(Tabuleiro);
}

void ImprimirMatriz(char** Tabuleiro) {
    int Linha, Coluna;
    for (Linha = 7; Linha >= 0; Linha--) {
        printf("%d ", Linha + 1);           // Para visualizar o número da linha
        for (Coluna = 0; Coluna < 8; Coluna++) {
            printf("%c ", Tabuleiro[Linha][Coluna]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");      // Para visualizar as colunas
}

int EntradaColuna(char Coluna){
    int Index = -1;
    if(Coluna == 'A') Index = 0;
    else if(Coluna == 'B') Index = 1;
    else if(Coluna == 'C') Index = 2;
    else if(Coluna == 'D') Index = 3;
    else if(Coluna == 'E') Index = 4;
    else if(Coluna == 'F') Index = 5;
    else if(Coluna == 'G') Index = 6;
    else if(Coluna == 'H') Index = 7;
    return Index;
}

int CavaloAtacado(char** Tabuleiro, int Linha, int Coluna, int MovLinha, int MovColuna) {
    //verifica se o cavalo pode atacar o cavalo da posição (Linha+MovLinha, Coluna+MovColuna)
    int PosLinha = Linha + MovLinha;
    int PosColuna = Coluna + MovColuna;
    if (PosLinha < 0 || PosLinha >= 8 || PosColuna < 0 || PosColuna >= 8) return 0;
    if (Tabuleiro[PosLinha][PosColuna] != 'C') return 0;

    return 1;
}

int AnalisePosicao(char** Tabuleiro){
    int CavalosEmGuerra = 0;
    for (int Linha = 0; Linha < 8; Linha++) {
        for (int Coluna = 0; Coluna < 8; Coluna++) {
            if (Tabuleiro[Linha][Coluna] == 'C') {
                //verifica se há cavalos que podem ser atacados pelo cavalo encontrado
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, 2, 1);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, 2, -1);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, 1, 2);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, -1, +2);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, -2, +1);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, -2, -1);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, -1, -2);
                CavalosEmGuerra += CavaloAtacado(Tabuleiro, Linha, Coluna, 1, -2);
            }
        }
    }
    return CavalosEmGuerra;
}

void AnaliseDaGuerra(int CavalosEmGuerra){
    if(CavalosEmGuerra > 0) printf("Os cavalos estao em guerra!\n");
    else if(CavalosEmGuerra == 0) printf("Paz no reino!\n");
}

int main() {
    char** Tabuleiro;
    char Coluna;
    int Linha, IndexColuna, IndexLinha, NumCavalos, i, CavalosEmGuerra = 0;

    Tabuleiro = CriarTabuleiro();
    scanf("%d", &NumCavalos);

    for(i = 0; i < NumCavalos; i++){
        scanf(" %c %d", &Coluna, &Linha);
        IndexColuna = EntradaColuna(Coluna);
        IndexLinha = Linha - 1;
        Tabuleiro[IndexLinha][IndexColuna] = 'C';
    }

    CavalosEmGuerra = AnalisePosicao(Tabuleiro);
    AnaliseDaGuerra(CavalosEmGuerra);
    ImprimirMatriz(Tabuleiro);
    LimparTabuleiro(Tabuleiro);

    return 0;
}