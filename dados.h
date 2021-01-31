#ifndef DADOS_H
#define DADOS_H

#include <stdlib.h>

typedef struct coord{
    int lin;
    int col;
}COORD;

typedef enum{
    VAZIO = ' ',
    PEAO = 'i',
    CAVALO = 'C',
    BISPO = 'B',
    TORRE = 'T',
    RAINHA = 'Q',
    REI = 'K'
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

COR get_cor(ESTADO est, COORD coord);
PIECE get_piece(ESTADO est, COORD coord);
void set_check(ESTADO est, int check_n);
void set_jog(ESTADO est, int jog_n);
void set_empty(ESTADO est, COORD coord);
void set_casa(ESTADO est, COORD coord, COR c, PIECE p);
void create_casa(ESTADO est, COORD coord, COR c, PIECE p);
ESTADO inicializar_estado();

#endif