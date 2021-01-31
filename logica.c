#include "logica.h"

int check_empty(ESTADO est, COORD c){
    return (get_piece(est,c) == VAZIO);
}

int valida_jogada_peao(ESTADO est, COORD c1, COORD c2){ //VERIFICAR MOV FRENTE SE TEM ESPACO TABULEIRO
    COORD lista_c_possi[4];
    COR cor = get_cor(est,c1);
    int i = -1;

    if(cor == BRANCA){
        if(check_empty(est,(COORD){c1.lin + 1,c1.col}) && c1.lin != 7){ //Verifica se anda 1 pra frente
                i++;
                lista_c_possi[i] = (COORD){c1.lin +1,c1.col};
            if(check_empty(est,(COORD){c1.lin + 2,c1.col}) && c1.lin == 1){ //Verifica se anda 2 pra frente
                i++;
                lista_c_possi[i] = (COORD){c1.lin +2,c1.col};
            }
        }
        if(!check_empty(est,(COORD){c1.lin + 1,c1.col+1}) && c1.col != 7 && c1.lin != 7 && get_cor(est,(COORD){c1.lin + 1,c1.col+1})==PRETA){ //Come direita
            i++;
            lista_c_possi[i] = (COORD){c1.lin +1, c1.col + 1};
        }
        if(!check_empty(est,(COORD){c1.lin + 1,c1.col-1}) && c1.col != 0 && c1.lin != 7 && get_cor(est,(COORD){c1.lin + 1,c1.col-1})==PRETA){ //Come esquerda
            i++;
            lista_c_possi[i] = (COORD){c1.lin +1, c1.col - 1};
        } 
    }
    else{
        if(check_empty(est,(COORD){c1.lin - 1,c1.col}) && c1.lin != 0){ //Verifica se anda 1 pra frente
                i++;
                lista_c_possi[i] = (COORD){c1.lin - 1,c1.col};
            if(check_empty(est,(COORD){c1.lin - 2,c1.col}) && c1.lin == 6){ //Verifica se anda 2 pra frente
                i++;
                lista_c_possi[i] = (COORD){c1.lin - 2,c1.col};
            }
        }
        if(!check_empty(est,(COORD){c1.lin - 1,c1.col+1}) && c1.col != 7 && c1.lin != 0 && get_cor(est,(COORD){c1.lin - 1,c1.col + 1})==BRANCA){ //Come direita
            i++;
            lista_c_possi[i] = (COORD){c1.lin - 1, c1.col + 1};
        }
        if(!check_empty(est,(COORD){c1.lin - 1,c1.col-1}) && c1.col != 0 && c1.lin != 0 && get_cor(est,(COORD){c1.lin - 1,c1.col - 1})==BRANCA){ //Come esquerda
            i++;
            lista_c_possi[i] = (COORD){c1.lin - 1, c1.col - 1};
        }
    }
    for(;i>=0;i--){ 
        if(lista_c_possi[i].col == c2.col)  
            if(lista_c_possi[i].lin == c2.lin)
                return 1;
    } 
    return 0;
}

int valida_jogada(ESTADO est, COORD c1, COORD c2){
    PIECE piece = get_piece(est,c1);

    switch (piece){
        case PEAO:
            return valida_jogada_peao(est,c1,c2);
    }
}

void move_piece(ESTADO est, COORD coord1 , COORD coord2){
    set_casa(est,coord2,get_cor(est,coord1),get_piece(est,coord1));
    set_casa(est,coord1,BRANCA,VAZIO);
}

COORD text_to_coord(char *coords){ //a8
    COORD coord;
    coord.col = coords[0] - 'a';
    coord.lin = coords[1] - '1';

    return coord;
}
