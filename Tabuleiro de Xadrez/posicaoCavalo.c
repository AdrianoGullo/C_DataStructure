#include <stdio.h>
 
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
 
char SaidaColuna(int Coluna){
    char Index;
    if(Coluna == 0) Index = 'A';
    else if(Coluna == 1) Index = 'B';
    else if(Coluna == 2) Index = 'C';
    else if(Coluna == 3) Index = 'D';
    else if(Coluna == 4) Index = 'E';
    else if(Coluna == 5) Index = 'F';
    else if(Coluna == 6) Index = 'G';
    else if(Coluna == 7) Index = 'H';
    else Index = 'P';
    return Index;
}
 
void AnalisePosicao(int Linha, int Coluna){
    char IndexColuna;
    //movimento do cavalo em um tabuleiro/matriz é em L e varia de 1 a 2 para coluna e linha
    //Movimento 1
    if (Linha+2 < 9 && Coluna-1 < 9){
        IndexColuna = SaidaColuna(Coluna-1);
        if(IndexColuna != 'P' && Linha+2 > 0){
            printf("%c %d\n", IndexColuna, Linha+2);
        }
    }
    //Movimento 2
    if (Linha+2 < 9 && Coluna+1 < 9){
        IndexColuna = SaidaColuna(Coluna+1);
        if(IndexColuna != 'P' && Linha+2 > 0){
            printf("%c %d\n", IndexColuna, Linha+2);
        }
    }
    //Movimento 3
    if (Linha+1 < 9 && Coluna+2 < 9){
        IndexColuna = SaidaColuna(Coluna+2);
        if(IndexColuna != 'P' && Linha+1 > 0){
            printf("%c %d\n", IndexColuna, Linha+1);
        }
    }
    //Movimento 4
    if (Linha-1 < 9 && Coluna+2 < 9){
        IndexColuna = SaidaColuna(Coluna+2);
        if(IndexColuna != 'P' && Linha-1 > 0){
            printf("%c %d\n", IndexColuna, Linha-1);
        }
    }
    //Movimento 5
    if (Linha-2 < 9 && Coluna+1 < 9){
        IndexColuna = SaidaColuna(Coluna+1);
        if(IndexColuna != 'P' && Linha-2 > 0){
            printf("%c %d\n", IndexColuna, Linha-2);
        }
    }
    //Movimento 6
    if (Linha-2 < 9 && Coluna-1 < 9){
        IndexColuna = SaidaColuna(Coluna-1);
        if(IndexColuna != 'P' && Linha-2 > 0){
            printf("%c %d\n", IndexColuna, Linha-2);
        }
    }
    //Movimento 7
    if (Linha-1 < 9 && Coluna-2 < 9){
        IndexColuna = SaidaColuna(Coluna-2);
        if(IndexColuna != 'P' && Linha-1 > 0){
            printf("%c %d\n", IndexColuna, Linha-1);
        }
    }
    //Movimento 8
    if (Linha+1 < 9 && Coluna-2 < 9){
        IndexColuna = SaidaColuna(Coluna-2);
        if(IndexColuna != 'P' && Linha+1 > 0){
            printf("%c %d\n", IndexColuna, Linha+1);
        }
    }
}
 
int main() {
    char Coluna;
    int Linha, IndexColuna;
 
    scanf("%c %d", &Coluna, &Linha);
    IndexColuna = EntradaColuna(Coluna);
    AnalisePosicao(Linha, IndexColuna);
 
    return 0;
}