//ARQUIVO BILHETE.C 

#include <stdio.h>
#include "bilhete.h"

int main(){

    int idade, quantidade;

    printf("Digite a idade do visitante: ");
    scanf("%d", &idade);

    printf("Digite a quantidade de bilhetes: ");
    scanf("%d", &quantidade);

    if (verificar_qtd_bilhetes(quantidade)) {
        int total = calc_preco_total(idade, quantidade);
        printf("Preco total: R$ %d\n", total);
    } else {
        printf("Erro: A quantidade máxima permitida por pessoa é %d bilhetes.\n", limite_bilhetes);
    }

    return 0;

}