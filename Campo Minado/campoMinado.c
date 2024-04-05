#include <stdio.h>
#include <stdlib.h>

struct Bomba{
    int x;
    int y;
    int raio;
};

char** CriarCampo(int Linha, int Coluna){
    char** CampoMinado;
    int i;
    CampoMinado = (char**)malloc(Linha * sizeof(char*));
    for (i = 0; i < Linha; i++) {
        CampoMinado[i] = (char*)malloc(Coluna * sizeof(char));
    }
    for (i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            CampoMinado[i][j] = '-';
        }
    }
    return CampoMinado;
}

void LimparCampo(char** CampoMinado, int Linha){
    int i;
    for (i = 0; i < Linha; i++) {
        free(CampoMinado[i]);
    }
    free(CampoMinado);
}

void ImprimirCampo(char** CampoMinado, int Linha, int Coluna) {
    for (int i = Linha; i > 0; i--) {
        printf("%d ", i-1);
        for (int j = 0; j < Coluna; j++) {
            printf("%c ", CampoMinado[i-1][j]);
        }
        printf("\n");
    }
    printf("# ");
    for(int i2 = 0; i2 < Coluna; i2++){
        printf("%d ", i2);
    }
    printf("\n");
}

int AnaliseForaDoCampo(int Linha, int Coluna, int MovLinha, int MovColuna){
    if (MovLinha < 0 || MovLinha >= Linha || MovColuna < 0 || MovColuna >= Coluna) return 0;
    else return 1;
}

char** RaioExplosao(char** CampoMinado, int LinhasCampo, int ColunasCampo, int Linha, int Coluna, int Raio){
    int AnaliseCampo;
    for (int i = -Raio; i <= Raio; i++){
        for(int j = -Raio; j <= Raio; j++) {
            AnaliseCampo = AnaliseForaDoCampo(LinhasCampo,ColunasCampo,Linha+i,Coluna+j);
            if (AnaliseCampo == 1) {
                if(CampoMinado[Linha+i][Coluna+j] != 'B'){
                    CampoMinado[Linha+i][Coluna+j] = '*';           //* significa que é afetado pelo raio da explosao
                }
            }
        }
    }
    return CampoMinado;
}

void AnaliseTanque(char** CampoMinado, int LinhaTanque, int ColunaTanque){
    //Se o tanque estiver onde possui '*' ou 'B', ele está em perigo, assim:
    if(CampoMinado[LinhaTanque][ColunaTanque] != '*' && CampoMinado[LinhaTanque][ColunaTanque] != 'B'){
        printf("Seguro");
    }
    else printf("Perigoso");
}

int main() {
    char** CampoMinado;
    char Input[100];
    int LinhasCampo, ColunasCampo, NumBombas;
    int LinhaTanque, ColunaTanque, InputValido;

    fgets(Input, sizeof(Input), stdin);
    sscanf(Input, "%dx%d", &LinhasCampo, &ColunasCampo);
    CampoMinado = CriarCampo(LinhasCampo, ColunasCampo);

    scanf("%d", &NumBombas);
    struct Bomba *bombas = malloc(NumBombas * sizeof(struct Bomba));

    for(int i = 0; i < NumBombas; i++){
        scanf("%d %d %d", &bombas[i].x, &bombas[i].y, &bombas[i].raio);

        InputValido = AnaliseForaDoCampo(LinhasCampo, ColunasCampo, bombas[i].x, bombas[i].y);
        if(InputValido == 0 || bombas[i].raio < 0){
            LimparCampo(CampoMinado, LinhasCampo);
            free(bombas);
            printf("-1");
            return 0;
        }else{
            CampoMinado[bombas[i].x][bombas[i].y] = 'B';
            CampoMinado = RaioExplosao(CampoMinado, LinhasCampo, ColunasCampo, bombas[i].x, bombas[i].y, bombas[i].raio);
            ImprimirCampo(CampoMinado, LinhasCampo, ColunasCampo);
        }
    }

    scanf("%d %d", &LinhaTanque, &ColunaTanque);
    AnaliseTanque(CampoMinado, LinhaTanque, ColunaTanque);

    LimparCampo(CampoMinado, LinhasCampo);
    free(bombas);
}