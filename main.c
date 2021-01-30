#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "dados.h"

int main(){
    ESTADO est = inicializar_estado();
    imprime_tabuleiro(est);

    return 0;
}