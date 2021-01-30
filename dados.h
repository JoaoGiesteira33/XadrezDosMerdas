#ifndef DADOS_H
#define DADOS_H

#include <stdlib.h>

typedef struct coord{
    int lin;
    int col;
}COORD;

typedef enum{
    VAZIO = ' ',
    PEAO = 'p',
    CAVALO = 'n',
    BISPO = 'b',
    TORRE = 'r',
    RAINHA = 'q',
    REI = 'k'
}PIECE;

typedef enum{
    BRANCA, //0
    PRETA  //1
}COR;

typedef struct casa{
    PIECE piece;
    COR cor;
}*CASA;

typedef struct estado{
    CASA tab[8][8];
    int jogador_atual;//0 branco - 1 preto
    int check;
}*ESTADO;

void set_check(ESTADO est, int check_n);
void set_jog(ESTADO est, int jog_n);
void set_empty(ESTADO est, COORD coord);
void set_casa(ESTADO est, COORD coord, CASA casa);
void create_casa(ESTADO est, COORD coord, COR c, PIECE p);
ESTADO inicializar_estado();

#endif