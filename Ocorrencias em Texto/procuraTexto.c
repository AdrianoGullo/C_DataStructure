#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calcularArrayLPS(char *padrao, int tamanhoPadrao, int *arrayLPS) {
    int comprimentoPrefixoAtual = 0;
    arrayLPS[0] = 0;

    int indice = 1;
    while (indice < tamanhoPadrao) {
        if (padrao[indice] == padrao[comprimentoPrefixoAtual]) {
            comprimentoPrefixoAtual++;
            arrayLPS[indice] = comprimentoPrefixoAtual;
            indice++;
        } else {
            if (comprimentoPrefixoAtual != 0) {
                comprimentoPrefixoAtual = arrayLPS[comprimentoPrefixoAtual - 1];
            } else {
                arrayLPS[indice] = 0;
                indice++;
            }
        }
    }
}

int buscaPadraoKMP(char* texto, char* padrao) {
    int tamanhoPadrao = strlen(padrao);
    int tamanhoTexto = strlen(texto);

    int* arrayLPS = (int*)malloc(sizeof(int) * tamanhoPadrao);
    if (arrayLPS == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }

    int indicePadrao = 0;
    int indiceTexto = 0;
    int ocorrencias = 0;

    calcularArrayLPS(padrao, tamanhoPadrao, arrayLPS);

    while (indiceTexto < tamanhoTexto) {
        if (padrao[indicePadrao] == texto[indiceTexto]) {
            indicePadrao++;
            indiceTexto++;
        }
        if (indicePadrao == tamanhoPadrao) {
            // Encontrou uma ocorrência
            ocorrencias++;
            indicePadrao = arrayLPS[indicePadrao - 1];
        } else if (indiceTexto < tamanhoTexto && padrao[indicePadrao] != texto[indiceTexto]) {
            if (indicePadrao != 0) {
                indicePadrao = arrayLPS[indicePadrao - 1];
            } else {
                indiceTexto++;
            }
        }
    }
    free(arrayLPS);
    return ocorrencias;
}

int main(void) {
    char frase[1501];
    char procura[32];

    fgets(frase, 1501, stdin);
    fgets(procura, 32, stdin);

    // Remova a quebra de linha das strings
    frase[strcspn(frase, "\n")] = '\0';
    procura[strcspn(procura, "\n")] = '\0';

    int c = buscaPadraoKMP(frase, procura);
    if (c == 0) {
        printf("Nenhuma ocorrencia encontrada\n");
    } else {
        printf("Numero de ocorrencias: %d\n", c);
    }
    return 0;
}