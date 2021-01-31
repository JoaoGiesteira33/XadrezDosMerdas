#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "logica.h"
#define BUF_SIZE 1024

#define RED   "\x1B[31m"
#define BLK   "\x1B[33m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


void imprime_tabuleiro(ESTADO est);
int interpretador (ESTADO est);

#endif