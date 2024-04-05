#include <stdio.h>

int contar(char vetor[]){
    int contador = 0;
    int i;
    for (i = 0; i < 501; i++){
        if (vetor[i] != '\0'){
            contador++;
        }
        else{
            i = 501;
        }
    }
    return contador;
}

void imprimir(char vetor[], int i, int j, int c){
    int k;

    if (c < 10) printf("00%d ", c);
    else if(c > 99) printf("%d ", c);
    else printf("0%d ", c);

    if (i+1 < 10) printf("00%d ", i+1);
    else if(i+1 > 99) printf("%d ", i+1);
    else printf("0%d ", i+1);

    if (j < 10) printf("00%d ", j);
    else if(j > 99) printf("%d ", j);
    else printf("0%d ", j);

    for (k=i; k<j; k++){
        printf("%c", vetor[k]);
    }
    printf("\n");
}

int verifica(char frase[], char procura[]){
    int tam = contar(frase);
    int tam1= contar(procura);
    int i, j, k, i2, coc = 0, i2 = 0;

    if (procura[0] == ' '){
        while (i2 != 500){
            int cpos = i;
            int termino = cpos+1;
            coc++;
            i2++;
            imprimir(frase, cpos, termino, coc);
            i++;
            if (i2 == 500){
                break;
            }
        }
    }else{
        for (i = 0; i < tam; i++){
            int cpos = 0;
            int erros = 0;
            for (j = 0; j < 2; j++){
                if (frase[i] == procura[0]){
                    cpos = i;
                    int termino = cpos + tam1 - 1;

                    for (k=1; k<tam1-1; k++){
                        int j2 = j + k;
                        int i2 = i + k;
                        if (frase[i2] != procura[j2]){
                            erros++;
                            if (erros == 2){
                                i++;
                                break;
                            }
                        }
                    }

                    if (erros < 2){									//analise caso - de 2 erros
                        i = i + k - 1;
                        coc++;
                        imprimir(frase, cpos, termino, coc);
                    }
                    erros = 0;

                    if (frase[i] == procura[0]){
                        i--;
                    }

                    break;
                } else if (frase[i] == procura[1]){					//analise primeira letra errada e segunda certa;
                    cpos = i;
                    int termino = cpos + tam1 - 1;

                    if (frase[i-1] != procura[0]){
                        cpos = i-1;
                        termino = termino - 1;
                        i--;
                        erros++;
                    }
                    for (k=1; k<tam1-1; k++){
                        int j2 = j + k;
                        int i2 = i + k;
                        if (frase[i2] != procura[j2]){
                            erros++;
                            if (erros == 2){
                                i++;
                                break;
                            }
                        }
                    }

                    if (erros < 2){									//analise caso - de 2 erros
                        i = i + k - 1;
                        coc++;
                        imprimir(frase, cpos, termino, coc);
                    }
                    erros = 0;
                }
            }
        }
    }
    return coc;
}

int main(void){
    char frase[1501];
    char procura[32];

    fgets(frase, 1501, stdin);
    fgets(procura, 32, stdin);

    int c = verifica(frase, procura);
    if (c==0){
        printf("Nenhuma ocorrencia encontrada\n");
    }
}