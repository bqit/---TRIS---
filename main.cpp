
/* === HELP ===

    -- COLORI PER L'HANDLE

        - colore 15: Bianco
        - colore 12: Rosso
*/

#include <iostream>

#include "header.h"

using namespace std;

int main()
{
    system("chcp 65001 > nul");   // <-- Utilizzato per permettere l'inserimento di caratteri UTF-8

    char charReturned;
    setNames();

    do{

        charReturned = mainTitleSet();

    } while(charReturned != 'L' && charReturned != 'l');

    exit(0);

}
