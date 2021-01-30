#include "interface.h"

void print_casa(CASA casa){
    if(casa->cor == BRANCA)
        printf(WHT "%c|", casa->piece);
    else printf(BLK "%c|", casa->piece);
}

void imprime_linha(){
    printf("\t  +-+-+-+-+-+-+-+-+\n");
}

void imprime_letras(){
    printf("\t  a b c d e f g h\n");
}

void imprime_tabuleiro(ESTADO est){
    
    for(int l = 0 ; l < 8 ; l++){
        imprime_linha();
        printf("\t%d |",8-l); //Imprime info linha
        for(int c = 0 ; c < 8 ; c++){
            print_casa(est->tab[l][c]);
        }
    }
    
}