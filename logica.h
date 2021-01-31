#ifndef LOGICA_H
#define LOGICA_H
#include "dados.h"
#include <stdio.h>

void move_piece(ESTADO est, COORD coord1 , COORD coord2);
int valida_jogada_peao(ESTADO est, COORD c1, COORD c2);
int valida_jogada(ESTADO est, COORD c1, COORD c2);
COORD text_to_coord(char *coords);

#endif