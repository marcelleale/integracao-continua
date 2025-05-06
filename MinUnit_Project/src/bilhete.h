//ARQUIVO BILHETE.H

//constantes
#define criancas 10 // 0 < criancas <= 12
#define adultos 30 // 12 < adultos < 60
#define idosos 15 // idosos >= 60
#define limite_bilhetes 5

//verificar quantidade limite de bilhetes
int verificar_qtd_bilhetes (int quantidade){
    return (quantidade > 0 && quantidade <= limite_bilhetes);
}

//verificar idade e preço do bilhete
int calc_preco_unitario (int idade){
    if (idade <= 12) {
        return criancas;
    } else if (idade >= 60) {
        return idosos;
    } else {
        return adultos;
    }
}

//calcular preço total de acordo com quantidade e preço
int calc_preco_total (int idade, int quantidade){

    int preco_unitario = calc_preco_unitario(idade);

    return preco_unitario * quantidade;
}

int preco_total_seguro(int idade, int quantidade);
