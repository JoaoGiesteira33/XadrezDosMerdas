#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include "dados.h"

#define RED   "\x1B[31m"
#define BLK   "\x1B[33m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


void imprime_tabuleiro(ESTADO est);

#endif