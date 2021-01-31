#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

int main(){
    ESTADO est = inicializar_estado();
    imprime_tabuleiro(est);
    char *coordtext = "e4";
    COORD c;
    c = text_to_coord(coordtext);
    printf("%d  %d\n",c.lin,c.col);

    return 0;
}