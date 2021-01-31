#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

int main(){
    ESTADO est = inicializar_estado();
    while(!interpretador(est));

    return 0;
}