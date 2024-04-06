#include <stdio.h>
#include <string.h>

typedef struct Data{												//def. do struct data
    int dia;
    int mes;
    int ano;
}date;

typedef struct Aluno{												//def. do struct aluno
    int ra;
    char nome[61];
    struct Data *data;
}pa;

int troca(struct Aluno *pa, struct Aluno aux, int i2){				//troca de posi�oes no vetor struct;
    aux.data = pa[i2].data;
    strcpy(aux.nome, pa[i2].nome);
    aux.ra = pa[i2].ra;
    pa[i2].data = pa[i2+1].data;
    strcpy(pa[i2].nome, pa[i2+1].nome);
    pa[i2].ra = pa[i2+1].ra;
    pa[i2+1].data = aux.data;
    strcpy(pa[i2+1].nome, aux.nome);
    pa[i2+1].ra = aux.ra;
    return i2;
}

void organiza(struct Aluno *pa, int n, char X){
    int i, i2;
    struct Aluno aux;
    for (i=0; i < n; i++){
        for (i2 = 0; i2 < n - 1; i2++){
            //Devolver por R.A
            if (X == 'R'){
                if (pa[i2].ra > pa[i2+1].ra) {
                    troca(pa, aux, i2);
                    i2++;
                }
            }
                //Devolver por Data
            else if (X == 'D'){
                if (pa[i2].data->ano > pa[i2+1].data->ano) {
                    troca(pa, aux, i2);
                    i2++;
                }
                else if (pa[i2].data->ano == pa[i2+1].data->ano){
                    if (pa[i2].data->mes > pa[i2+1].data->mes){
                        troca(pa, aux, i2);
                        i2++;
                    }
                    else if (pa[i2].data->mes == pa[i2+1].data->mes){
                        if (pa[i2].data->dia > pa[i2+1].data->dia){
                            troca(pa, aux, i2);
                            i2++;
                        }
                    }
                }
            }
                //Devolver por NOME
            else if (X == 'N'){
                int oc = strncmp(pa[i2].nome, pa[i2+1].nome, n);
                if (oc > 0){
                    troca(pa, aux, i2);
                }
            }
        }
    }
}

void imprime(struct Aluno *pa, int n){
    int j;
    for (j = 0; j < n; j++){
        printf("%d ", pa[j].ra);
        if (pa[j].data->dia > 9) printf("%d ", pa[j].data->dia);
        else printf("0%d ", pa[j].data->dia);
        if (pa[j].data->mes > 9) printf("%d ", pa[j].data->mes);
        else printf("0%d ", pa[j].data->mes);

        printf("%d", pa[j].data->ano);
        printf("%s", pa[j].nome);
    }
}

int main(void){
    int n, i;
    char X;
    scanf("%d", &n);
    struct Aluno pa[n];
    struct Data date[n];
    for (i=0; i < n; i++){						//pegando dados
        pa[i].data = &date[i];
        scanf("%d", &pa[i].ra);
        scanf("%d", &pa[i].data->dia);
        scanf("%d", &pa[i].data->mes);
        scanf("%d", &pa[i].data->ano);
        fgets(pa[i].nome, 60, stdin);
    }
    scanf("%c", &X);

    for (i = 0; i < n; i++){
        organiza(pa, n, X);
    }

    imprime(pa, n);
}
