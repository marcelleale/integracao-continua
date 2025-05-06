
/* 
Idade

Válida: [0, 12] (Criança), [13, 59] (Adulto), [60, ∞] (Idoso)
Inválida: Menor que 0 ou maior que 120 

Quantidade de bilhetes

Válida: 1 =< bilhetes >= 5
Inválida: 1 > bilhetes > 5 

------------------------------------------------------------------------------------------------------

Validação particionamento em classes de equivalência

Idade
CT = {(0, válido), (12, válido), (-1, inválido), (59, válido)}

Bilhetes
CT = {(0, inválido), (1, válido), (5, válido), (6, inválido)}

CT = {
        (0, 1, válido, 10),         // Criança (R$10 * 1)
        (12, 3, válido, 30),        // Criança (R$10 * 3)
        (160, 5, inválido, -1),     // Idade inválida (idade > 120)
        (12, 6, inválido, -1)       // Quantidade inválida (bilhetes > 5)
};

-------------------------------------------------------------------------------------------------------
Valor Limite

Idade	Classificação esperada
-1	    Inválido
0	    Válido (criança)
12	    Válido (criança)
13	    Válido (adulto)
59	    Válido (adulto)
60	    Válido (idoso)
120	    Válido (idoso)
121	    Inválido


Quantidade	Classificação esperada
0	        Inválido
1	        Válido
5	        Válido
6	        Inválido

CT = {
    (idade, qtd, clas. esperada)

    (-1, 3, inválido),       // idade abaixo do mínimo
    (0, 3, válido),          // idade mínima permitida (criança)
    (12, 3, válido),         // limite superior da criança
    (13, 3, válido),         // limite inferior do adulto
    (59, 3, válido),         // limite superior do adulto
    (60, 3, válido),         // limite inferior do idoso
    (150, 3, válido),        // idade alta, ainda válida (idoso)
    (151, 3, inválido),      // idade acima do permitido
    (30, 0, inválido),       // quantidade abaixo do mínimo
    (30, 1, válido),         // quantidade mínima permitida
    (30, 5, válido),         // quantidade máxima permitida
    (30, 6, inválido)        // quantidade acima do máximo
};

*/

//Chamada das bibliotecas
#include "../test/minunit-master/minunit.h"  
#include "../../src/bilhete.h" 


int tests_run = 0;

// Função auxiliar para calcular preço total com validação
int preco_total_seguro(int idade, int quantidade) {
    if (idade < 0 || idade > 120 || !verificar_qtd_bilhetes(quantidade)) {
        return -1;
    }
    return calc_preco_total(idade, quantidade);
}

// Casos de teste
static char *testes_calculo_preco() {
    mu_assert("Erro no teste (0,1)", preco_total_seguro(0, 1) == 10);
    mu_assert("Erro no teste (12,3)", preco_total_seguro(12, 3) == 30);
    mu_assert("Erro no teste (160,5)", preco_total_seguro(160, 5) == -1);
    mu_assert("Erro no teste (12,6)", preco_total_seguro(12, 6) == -1);
    return 0;
}

static char *testes_limites_valores() {
    mu_assert("Erro no teste (-1,3)", preco_total_seguro(-1, 3) == -1);
    mu_assert("Erro no teste (0,3)", preco_total_seguro(0, 3) == 30);
    mu_assert("Erro no teste (12,3)", preco_total_seguro(12, 3) == 30);
    mu_assert("Erro no teste (13,3)", preco_total_seguro(13, 3) == 90);
    mu_assert("Erro no teste (59,3)", preco_total_seguro(59, 3) == 90);
    mu_assert("Erro no teste (60,3)", preco_total_seguro(60, 3) == 45);
    mu_assert("Erro no teste (150,3)", preco_total_seguro(150, 3) == 45);
    mu_assert("Erro no teste (151,3)", preco_total_seguro(151, 3) == -1);
    mu_assert("Erro no teste (30,0)", preco_total_seguro(30, 0) == -1);
    mu_assert("Erro no teste (30,1)", preco_total_seguro(30, 1) == 30);
    mu_assert("Erro no teste (30,5)", preco_total_seguro(30, 5) == 150);
    mu_assert("Erro no teste (30,6)", preco_total_seguro(30, 6) == -1);
    return 0;
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(testes_calculo_preco);
    MU_RUN_TEST(testes_limites_valores);
    return 0;
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
