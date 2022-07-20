#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula celula;
typedef celula* pont;
struct celula {
    int num; pont prox;
};
typedef pont numero;

int main(){
    numero p, q, p1, q1;
    int i, j;
    char n[50], naux[50], tab[50][50];

    // ler o numero
    printf("digite um numero: ");
    gets(n);

    p = (numero) malloc(sizeof(celula));
    for (i = 0, q = p; i < strlen(n); i++){
        q->prox = (numero) malloc(sizeof(celula));
        q = q->prox;
        naux[0] = n[i];
        naux[1] = '\0';
        q->num = atoi(naux);
    }
    q->prox = NULL;

    // ler o numero
    printf("digite um numero: ");
    gets(n);

    p1 = (numero) malloc(sizeof(celula));
    for (i = 0, q1 = p1; i < strlen(n); i++){
        q1->prox = (numero) malloc(sizeof(celula));
        q1 = q1->prox;
        naux[0] = n[i];
        naux[1] = '\0';
        q1->num = atoi(naux);
    }
    q1->prox = NULL;

    for (q = p->prox, q1 = p1->prox; q != NULL && q1 != NULL; q = q->prox, q1 = q1->prox){
        q->num = q->num * q1->num;
    }

    // imprimir a cadeia
    i = 0;
    for (q = p->prox; q != NULL; q = q->prox){
        itoa(q->num, tab[i], 10);
        i++;
    }
    n[0] = '\0';
    for (j = 0; j < i; j++){
        strcat(n, tab[j]);
    }
    printf("%s", n);

    return 0;
}
