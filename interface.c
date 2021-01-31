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
        printf(WHT " %s " RESET "|", casa_to_char(casa));
    else printf(BLK " %s " RESET "|", casa_to_char(casa));
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
    imprime_tabuleiro(est);


    printf("Insira jogada legal: ");
    char * coord1 = malloc(sizeof(char)* 3);
    char * coord2 = malloc(sizeof(char)*3);
    
    COORD coord_i , coord_f;

    
    
    do{
    scanf("%s %s",coord1,coord2);

    coord_i = text_to_coord(coord1);
    coord_f = text_to_coord(coord2);
    }while(!valida_jogada(est,coord_i,coord_f));
    
    move_piece(est,coord_i,coord_f);

    return 0;
}