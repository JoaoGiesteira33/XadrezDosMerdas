#include "interface.h"

char *casa_to_char(CASA casa){
    char *peca = malloc(sizeof(char) * 3);

    switch (casa->piece){
        case TORRE: 
            strcpy(peca,"♖");
            break;
        case REI: 
            strcpy(peca,"♔");
            break;
        case RAINHA: 
            strcpy(peca,"♕");
            break;
        case CAVALO: 
            strcpy(peca,"♘");
            break;
        case PEAO: 
            strcpy(peca,"♙");
            break;
        case BISPO:
            strcpy(peca,"♗");
            break;
        case VAZIO:
            strcpy(peca," ");
            break;
    }
    return peca;
}

void print_casa(CASA casa){
    if(casa->cor == BRANCA)
        printf(WHT " %c " RESET "|", (casa->piece));
    else printf(BLK " %c " RESET "|", (casa->piece));
}

void imprime_linha(){
    printf("\t  +---+---+---+---+---+---+---+---+\n");
}

void imprime_letras(){
    printf("\t    a   b   c   d   e   f   g   h\n");
}

void imprime_tabuleiro(ESTADO est){
    
    for(int l = 0 ; l < 8 ; l++){
        imprime_linha();
        printf("\t%d |",8-l); //Imprime info linha
        for(int c = 0 ; c < 8 ; c++){
            print_casa(est->tab[7-l][c]);
        }
        putchar('\n');
    }
    imprime_linha();
    imprime_letras();
}


int interpretador (ESTADO est) { // Interpretador de Comandos do Jogo //e4 e5
    char linha[BUF_SIZE];
    imprime_tabuleiro(est);

    printf("Insira jogada tipo: c1 c2\n");
    char *coord1, *coord2;

    scanf("%s %s",coord1,coord2);

    COORD coord_i , coord_f;

    coord_i = text_to_coord(coord1);
    coord_f = text_to_coord(coord2);

    printf("%c%c %c%c\n",coord_i.lin,coord_i.col,coord_f.lin,coord_f.col);
}