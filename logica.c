#include "logica.h"


COORD text_to_coord(char *coords){ //a8
    COORD coord;
    coord.col = coords[0] - 'a';
    coord.lin = coords[1] - '1';

    return coord;
}
