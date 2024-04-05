#include <stdio.h>
#include <stdlib.h>

struct Bomba{
    int x;
    int y;
    int raio;
};

struct Tanques{
    int x;
    int y;
    int res;
};

int** CriarCampo(int Linha, int Coluna){
    int** CampoMinado;
    int i;
    CampoMinado = (int**)malloc(Linha * sizeof(int*));
    for (i = 0; i < Linha; i++) {
        CampoMinado[i] = (int*)malloc(Coluna * sizeof(int));
    }
    for (i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            CampoMinado[i][j] = 0;
        }
    }
    return CampoMinado;
}

void ImprimirCampo(int** CampoMinado, int Linha, int Coluna) {
    for (int i = Linha; i > 0; i--) {
        printf("%d ", i-1);
        for (int j = 0; j < Coluna; j++) {
            printf("%d ", CampoMinado[i-1][j]);
        }
        printf("\n");
    }
    printf("# ");
    for(int i2 = 0; i2 < Coluna; i2++){
        printf("%d ", i2);
    }
    printf("\n");
}

void LimparCampo(int** CampoMinado, int Linha){
    int i;
    for (i = 0; i < Linha; i++) {
        free(CampoMinado[i]);
    }
    free(CampoMinado);
}

int AnaliseForaDoCampo(int Linha, int Coluna, int MovLinha, int MovColuna){
    if (MovLinha < 0 || MovLinha >= Linha || MovColuna < 0 || MovColuna >= Coluna) return 0;
    else return 1;
}

int** RaioExplosao(int** CampoMinado, int LinhasCampo, int ColunasCampo, int Linha, int Coluna, int Raio){
    for (int i = -Raio; i <= Raio; i++){
        for(int j = -Raio; j <= Raio; j++) {
            if (Linha+i >= 0 && Linha+i < LinhasCampo && Coluna+j >= 0 && Coluna+j < ColunasCampo) {
                CampoMinado[Linha+i][Coluna+j]++;           // Incrementa o número de explosões no local
            }
        }
    }
    return CampoMinado;
}

void AnaliseTanque(int** CampoMinado, int LinhaTanque, int ColunaTanque, int Resistencia){
    if(CampoMinado[LinhaTanque][ColunaTanque] <= Resistencia) printf("Ufa");
    else printf("Boom");
}

int main() {
    int** CampoMinado;
    char Input[100];
    int LinhasCampo, ColunasCampo, NumBombas;
    int InputValido, PosTanque;

    fgets(Input, sizeof(Input), stdin);
    sscanf(Input, "%dx%d", &LinhasCampo, &ColunasCampo);
    CampoMinado = CriarCampo(LinhasCampo, ColunasCampo);

    scanf("%d", &NumBombas);
    struct Bomba *bombas = malloc(NumBombas*sizeof(struct Bomba));

    for(int i = 0; i < NumBombas; i++){
        scanf("%d %d %d", &bombas[i].x, &bombas[i].y, &bombas[i].raio);

        InputValido = AnaliseForaDoCampo(LinhasCampo, ColunasCampo, bombas[i].x, bombas[i].y);
        if(InputValido == 0 || bombas[i].raio < 0){
            LimparCampo(CampoMinado, LinhasCampo);
            free(bombas);
            printf("-1");
            return 0;
        }else{
            CampoMinado = RaioExplosao(CampoMinado, LinhasCampo, ColunasCampo, bombas[i].x, bombas[i].y, bombas[i].raio);
        }
    }

    struct Tanques *tanque = malloc(sizeof(struct Tanques));
    tanque->x = -1;
    tanque->y = -1;
    tanque->res = -1;
    scanf("%d %d %d", &tanque->x, &tanque->y, &tanque->res);

    PosTanque = AnaliseForaDoCampo(LinhasCampo, ColunasCampo, tanque->x, tanque->y);
    if(PosTanque == 0 || tanque->res < 1) printf("-1");
    else AnaliseTanque(CampoMinado, tanque->x, tanque->y, tanque->res);

    LimparCampo(CampoMinado, LinhasCampo);
    free(bombas);
    free(tanque);
    return 0;
}