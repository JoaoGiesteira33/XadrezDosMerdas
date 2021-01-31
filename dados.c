#include "dados.h"

void set_check(ESTADO est, int check_n){
    est->check = check_n;
}

void set_jog(ESTADO est, int jog_n){
    est->jogador_atual = jog_n;
}

COR get_cor(ESTADO est, COORD coord){
    COR cor;
    cor = est->tab[coord.lin][coord.col]->cor;

    return cor;
}

PIECE get_piece(ESTADO est, COORD coord){
    PIECE piece;
    piece = est->tab[coord.lin][coord.col]->piece;

    return piece;
}

void set_casa(ESTADO est, COORD coord, COR c, PIECE p){
    est->tab[coord.lin][coord.col]->cor = c;
    est->tab[coord.lin][coord.col]->piece = p;
}

void create_casa(ESTADO est, COORD coord, COR c, PIECE p){
    CASA new_casa = malloc(sizeof(struct casa));
    new_casa->cor = c;
    new_casa->piece = p;
    est->tab[coord.lin][coord.col] = new_casa;
}

ESTADO inicializar_estado(){
    ESTADO est = malloc(sizeof(struct estado));
    set_check(est,0);
    set_jog(est,0);

    PIECE ordem[8] = {TORRE,CAVALO,BISPO,RAINHA,REI,BISPO,CAVALO,TORRE};

    for(int i = 0; i < 8 ; i++){ //Cria peoes e vazios
         create_casa(est,(COORD){1,i},BRANCA,PEAO);
         create_casa(est,(COORD){6,i},PRETA,PEAO);
         create_casa(est,(COORD){2,i},BRANCA,VAZIO);
         create_casa(est,(COORD){3,i},BRANCA,VAZIO);
         create_casa(est,(COORD){4,i},BRANCA,VAZIO);
         create_casa(est,(COORD){5,i},BRANCA,VAZIO);
         create_casa(est,(COORD){0,i},BRANCA,ordem[i]);
         create_casa(est,(COORD){7,i},PRETA,ordem[i]);
    }
    return est;
}
