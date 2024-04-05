#include <stdio.h>
#include <stdlib.h>

int* PegarVelocidade(int NumeroLesmas) {
    int EntradasNaoValidas = 0;
    int *Velocidades = (int *) malloc(NumeroLesmas * sizeof(int));
    for (int i = 0; i < NumeroLesmas; i++) {
        scanf("%d", &Velocidades[i]);
        if (Velocidades[i] < 0) EntradasNaoValidas++;
    }
    if (EntradasNaoValidas == NumeroLesmas) exit(-1);
    else return (Velocidades);
}

int AnalisePercurso(int Velocidade, int Tempo){
    int CmPercorrido = 0;
    if(0 < Velocidade && Velocidade <= 10 && Tempo <= 3) CmPercorrido = Velocidade * Tempo;
    else if(10 < Velocidade && Velocidade <= 20 && Tempo <= 2) CmPercorrido = Velocidade * Tempo;
    else if(20 < Velocidade && Velocidade <= 100 && Tempo <= 1) CmPercorrido = Velocidade * Tempo;
    return CmPercorrido;
}

int DistanciaCorrida(int NumeroLesmas, int* Velocidades, int Tempo){
    int Distancia, MaiorPercurso = 0, Index, i;
    for(i = 0; i < NumeroLesmas; i++){
        Distancia = AnalisePercurso(Velocidades[i], Tempo);
        if (Distancia > MaiorPercurso){
            MaiorPercurso = Distancia;
            Index = i;
        }
    }
    return Index;
}

int main() {
    int NumeroLesmas, Tempo;
    scanf("%d", &NumeroLesmas);
    int* Velocidade = PegarVelocidade(NumeroLesmas);

    if (Velocidade == NULL){
        free(Velocidade);
        return 0;
    }

    else{
        scanf("%d", &Tempo);
        int Index;
        Index = DistanciaCorrida(NumeroLesmas, Velocidade, Tempo);
        printf("%d", Velocidade[Index]);
        free(Velocidade);
    }
}