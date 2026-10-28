#include <iostream>
#include <windows.h>    // <-- Libreria utilizzata per l'HANDLE dei colori
#include <string>
#include <ctime>        // <-- Libreria utilizzata per il random
#include <cstdlib>      // <-- Libreria utilizzata per il random
#include <conio.h>      // <-- Libreria utilizzata per il getch();
#include <fstream>

#include "header.h"

using namespace std;

// === VARIABILI GLOBALI ===
bool GAMESTART = false;                                    // <-- Utilizzata per far intendere a tutte le funzioni fino a quando devono operare (Fino all'avvio del gioco)
std::string namePlayer1, namePlayer2;                      // <-- Utilizzati per indicare il nome del player (Inizialmente conterranno 5 caratteri random)
char trisTable[rDIM][cDIM];
int scoreA = 0, scoreB = 0;

void colorManager(int col){

    // Funzione per inserire i vari colori

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);     // <-- HANDLE per l'inserimento dei colori
    SetConsoleTextAttribute(h, col);                // Utilizzato per inserire l'attributo del colore ad un determinato testo

}

char mainTitleSet(){

    int color, stopIntro = 0;
    char choice;

    do{

        for(int i = 0; i < 5; i++){

            color = 12;
            colorManager(color);

            cout << "PLAYER 1: ";

            color = 15;
            colorManager(color);

            cout << namePlayer1 << " [ Punti: " << scoreA << " ] ||";

            color = 12;
            colorManager(color);

            cout << " PLAYER 2: ";

            color = 15;
            colorManager(color);

            cout << namePlayer2 << " [ Punti: " << scoreB << " ]" << endl;

            titleHUD();

            Sleep(150);
            system("CLS");

            color = 12;
            colorManager(color);

            cout << "PLAYER 1: ";

            color = 15;
            colorManager(color);

            cout << namePlayer1 << " [ Punti: " << scoreA << " ] ||";

            color = 12;
            colorManager(color);

            cout << " PLAYER 2: ";

            color = 15;
            colorManager(color);

            cout << namePlayer2 << " [ Punti: " << scoreB << " ]" << endl;

            color = 12;
            colorManager(color);

            titleHUD();

            Sleep(150);         // <-- Funzione Sleep che addormenta il programma (Utilizzata come delay)

            if(i < 4){

                system("CLS");
            }

            stopIntro++;
        }

        color = 15;
        colorManager(color);

        cout << endl;
        cout << "Cosa vuoi fare? [Inserisci un carattere]: ";
        cin >> choice;
        switch(choice){

        case 'X': case 'x':

            cout << "Ultimando i preparativi..." << endl;
            Sleep(2000);
            readyChecker();

        break;
        case 'H': case 'h':

            system("CLS");
            rulesScreen();

        break;
        case 'E': case 'e':

            system("CLS");
            editPlayerName();

        break;

        case 'L': case 'l':

            cout << "Sto chiudendo il gioco..." << endl;
            Sleep(1000);
            cout << endl;

        break;
        default:

            cout << endl;
            cout << "Carattere non consentito!" << endl;
            Sleep(500);
        }

    } while(choice != 'L' && choice != 'l' && choice != 'X' && choice != 'x');

    return choice;
}

void titleHUD(){

        cout << endl;
        cout << endl;
        cout << "\t\t\t\t  ████████╗██████╗░██╗░██████╗" << endl;           // <-- Motivo per cui è stato inserito l'accettazione di caratteri UTF-8
        cout << "\t\t\t\t  ╚══██╔══╝██╔══██╗██║██╔════╝" << endl;
        cout << "\t\t\t\t  ░░░██║░░░██████╔╝██║╚█████╗░" << endl;
        cout << "\t\t\t\t  ░░░██║░░░██╔══██╗██║░╚═══██╗" << endl;
        cout << "\t\t\t\t  ░░░██║░░░██║░░██║██║██████╔╝" << endl;
        cout << "\t\t\t\t  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═════╝░  v.1.2" << endl;
        cout << endl;
        cout << "____________________________________________________________________________________________________________" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t ╒════════════════════════════╕" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t |            MENU'           |" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t ╘════════════════════════════╛" << endl;
        cout << endl;
        cout << "\t\t\t\t ╒════════════════════════════╕" << endl;
        cout << "\t\t\t\t |     Premi X per giocare    |" << endl;
        cout << "\t\t\t\t ╘════════════════════════════╛" << endl;
        cout << endl;
        cout << "\t\t\t\t ╒════════════════════════════╕" << endl;
        cout << "\t\t\t\t |    Premi H per le regole   |" << endl;
        cout << "\t\t\t\t ╘════════════════════════════╛" << endl;
        cout << endl;
        cout << "\t\t\t\t ╒════════════════════════════╕" << endl;
        cout << "\t\t\t\t |  Premi E per modifica nome |" << endl;
        cout << "\t\t\t\t ╘════════════════════════════╛" << endl;
        cout << endl;
        cout << "\t\t\t\t ╒════════════════════════════╕" << endl;
        cout << "\t\t\t\t |     Premi L per uscire     |" << endl;
        cout << "\t\t\t\t ╘════════════════════════════╛" << endl;
}

void rulesScreen(){

    int color = 12;
    colorManager(color);

    cout << endl;
    cout << "█▀█ █▀▀ █▀▀ █▀█ █░░ █▀▀" << endl;
    cout << "█▀▄ ██▄ █▄█ █▄█ █▄▄ ██▄" << endl;
    cout << "_____________________________________________________" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════════════════════════════╕" << endl;
    cout << "|                        MAX. 2 Giocatori                        |" << endl;
    cout << "╘════════════════════════════════════════════════════════════════╛" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════════════════════════════╕" << endl;
    cout << "|             Inserisci il tuo simbolo nello spazio              |" << endl;
    cout << "╘════════════════════════════════════════════════════════════════╛" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════════════════════════════╕" << endl;
    cout << "|            Puoi inserire un solo simbolo per turno             |" << endl;
    cout << "╘════════════════════════════════════════════════════════════════╛" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════════════════════════════╕" << endl;
    cout << "| Utilizza WASD o le frecce direzionali per spostarti di casella |" << endl;
    cout << "╘════════════════════════════════════════════════════════════════╛" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════════════════════════════╕" << endl;
    cout << "|               Premi ENTER per inserire il simbolo              |" << endl;
    cout << "╘════════════════════════════════════════════════════════════════╛" << endl;
    cout << endl;
    cout << endl;

    color = 15;
    colorManager(color);
    system("PAUSE");
}

void editPlayerName(){

    int color = 12, player;
    char choice;
    string newName;
    colorManager(color);

    cout << endl;
    cout << "█▀▄▀█ █▀█ █▀▄ █ █▀▀ █ █▀▀ ▄▀█   █▄░█ █▀█ █▀▄▀█ █▀▀" << endl;
    cout << "█░▀░█ █▄█ █▄▀ █ █▀░ █ █▄▄ █▀█   █░▀█ █▄█ █░▀░█ ██▄" << endl;
    cout << "_____________________________________________________" << endl;
    cout << endl;
    cout << "╒════════════════════════════════════════╕" << endl;
    cout << "|      Quale nome vuoi cambiare? (1-2)   |" << endl;
    cout << "╘════════════════════════════════════════╛" << endl;
    cout << endl;

    color = 15;
    colorManager(color);
    cout << "Inserisci il numero del giocatore: ";
    cin >> player;
    while(player <= 0 || player > 2){
        cout << endl;
        cout << "Numero del giocatore inserito non valido! (RICORDA: 1 [MODIFICA PLAYER 1] || 2 [MODIFICA PLAYER 2])" << endl;
        cout << "Inserisci il numero del giocatore: ";
        cin >> player;
    }

    player = newNameInput(color, player);

    cout << endl;

    color = 2;
    colorManager(color);
    cout << "OTTIMO! Nome modificato con successo." << endl;

    color = 15;
    colorManager(color);

    Sleep(40);
    cout << "Vuoi modificare anche l'altro nome? (Y/y per accettare): ";
    cin >> choice;
    cout << endl;
    switch(choice){

    case 'Y': case 'y':

        cout << "OTTIMO! Prepariamo il tutto, ci vorrà qualche istante." << endl;
        Sleep(1000);
        system("CLS");

        color = 12;
        colorManager(color);

        cout << endl;
        cout << "█▀▄▀█ █▀█ █▀▄ █ █▀▀ █ █▀▀ ▄▀█   █▄░█ █▀█ █▀▄▀█ █▀▀" << endl;
        cout << "█░▀░█ █▄█ █▄▀ █ █▀░ █ █▄▄ █▀█   █░▀█ █▄█ █░▀░█ ██▄" << endl;
        cout << "_____________________________________________________" << endl;
        cout << endl;

        color = 15;
        colorManager(color);

        if(player == 1){

            player = 2;
        } else {

            player = 1;
        }

        player = newNameInput(color, player);

    break;
    default:

        cout << "Verrai reindirizzato al titolo tra un istante!" << endl;
        Sleep(1000);
    }

}

int newNameInput(int c, int p){

    if(p == 1){

        cin.ignore();
        cout << endl;
        cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
        getline(cin, namePlayer1);

        while(namePlayer1.empty()){

            cout << endl;
            cout << "Nome non valido! (RICORDA: il nome non può essere vuoto)." << endl;
            cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
            getline(cin, namePlayer1);
        }

        while(namePlayer1.size() > 8){

            cout << endl;
            cout << "Nome non valido! (RICORDA: il numero max. di caratteri è 8)." << endl;
            cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
            getline(cin, namePlayer1);
        }
    } else {

        cin.ignore();
        cout << endl;
        cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
        getline(cin, namePlayer2);

        while(namePlayer1.empty()){

            cout << endl;
            cout << "Nome non valido! (RICORDA: il nome non può essere vuoto)." << endl;
            cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
            getline(cin, namePlayer2);
        }

        while(namePlayer1.size() > 8){

            cout << endl;
            cout << "Nome non valido! (RICORDA: il numero max. di caratteri è 8)." << endl;
            cout << "Inserisci il nuovo nome del PLAYER " << p << " (Max. 8 Caratteri): ";
            getline(cin, namePlayer2);
        }

    }

    return p;
}

void readyChecker(){

    int color = 12;
    string newName, temp;
    colorManager(color);

    system("CLS");
    cout << endl;
    cout << "█▀▀ ▀   ▀█▀ █░█ ▀█▀ ▀█▀ █▀█   █▀█ █▀█ █▀█ █▄░█ ▀█▀ █▀█ ▀█" << endl;
    cout << "██▄ ░   ░█░ █▄█ ░█░ ░█░ █▄█   █▀▀ █▀▄ █▄█ █░▀█ ░█░ █▄█ ░▄" << endl;
    cout << "_________________________________________________________________" << endl;
    cout << endl;

    color = 15;
    makeUpper(namePlayer1);
    colorManager(color);

    cout << ", Ci sei?" << endl;
    system("PAUSE");

    color = 12;
    colorManager(color);

    cout << endl;

    color = 15;
    makeUpper(namePlayer2);

    colorManager(color);
    cout << ", Ci sei?" << endl;
    system("PAUSE");

    cout << endl;
    cout << endl;
    cout << "La partita sta iniziando!" << endl;
    Sleep(1000);

    gameEngine(trisTable);
}


void gameEngine(char table[][cDIM]){

    int coordVect[2];
    int color, x, y, playerSelector = 1; // <-- Utilizzata per capire chi deve inserire il carattere
    char win = 'O';


    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){

                table[i][j] = '\0';      // <-- Carico in ogni area della matrice uno spazio (In modo tale che quando verrà inserito il carattere dall'utente la tabella
        }                               //     sia impostata correttamente)
    }

    do{
        system("CLS");

        reloadChars(table);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        color = 12;
        colorManager(color);

        if(playerSelector == 1){

            cout << namePlayer1;
        } else {

            cout << namePlayer2;
        }


        color = 15;
        colorManager(color);
        cout << " E' il tuo turno!" << endl;

        cout << endl;

        cout << "\t|\t|\t" << endl;
        cout << "   " << table[0][0] << "    |   " << table[0][1]  << "   |    " << table[0][2]  << endl;
        cout << "________|_______|_______" << endl;

        cout << "\t|\t|\t" << endl;
         cout << "   " << table[1][0] << "    |   " << table[1][1]  << "   |    " << table[1][2]  << endl;
        cout << "________|_______|_______" << endl;

        cout << "\t|\t|\t" << endl;
        cout << "   " << table[2][0] << "    |   " << table[2][1]  << "   |    " << table[2][2]  << endl;
        cout << "\t|\t|\t" << endl;

        moveCursor(coordVect);

        y = coordVect[0];
        x = coordVect[1];

        if(table[x][y] == ' '){         // <-- Se la cella è occupata, vieta l'inserimento

            if(playerSelector == 1){

                table[x][y] = 'O';
            } else {

                table[x][y] = 'X';
            }

            subEmptyChars(table);

            win = winner(table);

            if(playerSelector == 1){

                playerSelector++;
            } else {

                playerSelector--;
            }
        }


    } while(win == 'O');

    Sleep(500);

    if(win != 'W'){

        drawScreen();

    } else {

        if(playerSelector == 1){

            playerSelector++;
        } else {

            playerSelector--;
        }

        victoryScreen(playerSelector);
    }

}

void gotoxy(int x, int y){

    COORD cursor = {x, y};                                  // <-- Gestisce le coordinate del cursore
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, cursor);             // <-- Imposta la posizione del cursore in base a X e Y
}

void moveCursor(int v[]){

    int x, y, moveCur, limitX = 0, limitY = 0;

        x = 3;
        y = 7;

        gotoxy(x, y);

        do {

            moveCur = getch();          // <-- getch() Viene utilizzato per memorizzare l'ASCII number del tasto che viene premuto
                                        // I tasti delle frecce direzionali tuttavia non sembrano rispondere (E.g 22477 [Freccia su])
            switch (moveCur){

            case 100: case 77:       // ASCII number 100 = D

                if(limitX < 2){

                    x += 9;
                    gotoxy(x, y);
                    limitX++;
                }

            break;
            case 97: case 75:        // ASCII number 97 = A

                if(limitX > 0){
                    x -= 9;
                    gotoxy(x, y);
                    limitX--;
                }

            break;
            case 115: case 80:       // ASCII number 115 = S

                if(limitY < 2){

                    y += 3;
                    gotoxy(x, y);
                    limitY++;
                }

            break;
            case 119: case 72:       // ASCII number 119 = W

                if(limitY > 0){
                    y -= 3;
                    gotoxy(x, y);
                    limitY--;
                }
        }


    } while (moveCur != 13);

    v[0] = limitX;   // <-- Carichiamo in un vettore le due coordinate indicate da limitX e limitY
    v[1] = limitY;   //     (Utilizzate per il posizionamento del carattere del giocatore)
}

char winner(char m[][cDIM]){

    char some1win = 'O';

    if(m[0][0] == m[0][1] && m[0][1] == m[0][2]){       // <-- A seguire tutte le condizioni di vittoria

        some1win = 'W';
    }

    if(m[1][0] == m[1][1] && m[1][1] == m[1][2]){

        some1win = 'W';
    }

    if(m[2][0] == m[2][1] && m[2][1] == m[2][2]){

        some1win = 'W';
    }

    if(m[0][0] == m[1][0] && m[1][0] == m[2][0]){

        some1win = 'W';
    }

    if(m[0][1] == m[1][1] && m[1][1] == m[2][1]){

        some1win = 'W';
    }

    if(m[0][2] == m[1][2] && m[1][2] == m[2][2]){

        some1win = 'W';
    }

    if(m[0][0] == m[1][1] && m[1][1] == m[2][2]){

        some1win = 'W';
    }

    if(m[2][0] == m[1][1] && m[1][1] == m[0][2]){

        some1win = 'W';
    }

    return some1win;
}


void subEmptyChars (char m[][cDIM]){            // <-- Ho creato questa funzione per il seguente motivo seguendo questo ragionamento:

                                                //  Assegnando inizialmente ad ogni cella della matrice uno spazio, mi sono reso conto
    for(int i = 0; i < 3; i++){                 //  che quando si verificava se il giocatore avesse vinto, dopo l'inserimento di un solo
                                                //  carattere la partita terminava poiché effettivamente, gli spazi inseriti inizialmente
        for(int j = 0; j < 3; j++){             //  venivano considerati perché rispettavano le condizioni di vittoria.
                                                //  Ho quindi creato questa funzione che sostituisce momentaneamente ogni spazio della matrice
            if(m[i][j] == ' '){                 //  con un carattere random (a-z) in modo tale che siano tutti diversi eccetto i caratteri inseriti dagli
                                                //  utenti.
                m[i][j] = rand() % 26 + 97;
            }                                   //  Gli spazi sostituiti dai numeri random verranno ricaricati utilizzando reloadChars() dopo la verifica
        }                                       //  Di vittoria.
    }
}

void reloadChars (char m[][cDIM]){              // Funzione sopracitata

    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){

            if(m[i][j] != 'O' && m[i][j] != 'X'){

                m[i][j] = ' ';
            }
        }
    }
}

void victoryScreen(int playerSelector){

    int color;
    system("CLS");

    for(int i = 0; i < 5; i++){

        system("CLS");
        cout << endl;
        cout << endl;

        color = 15;
        colorManager(color);

        cout << "█░█ █ ▀█▀ ▀█▀ █▀█ █▀█ █ ▄▀█" << endl;
        cout << "▀▄▀ █ ░█░ ░█░ █▄█ █▀▄ █ █▀█" << endl;
        Sleep(100);

        system("CLS");

        cout << endl;
        cout << endl;

        color = 12;
        colorManager(color);

        cout << "█░█ █ ▀█▀ ▀█▀ █▀█ █▀█ █ ▄▀█" << endl;
        cout << "▀▄▀ █ ░█░ ░█░ █▄█ █▀▄ █ █▀█" << endl;
        Sleep(100);

    }

    color = 12;
    colorManager(color);

    cout << endl;
    cout << endl;

    if(playerSelector == 1){

        cout << namePlayer1;

        color = 15;
        colorManager(color);
        cout << " ha vinto!!!" << endl;
        scoreA++;
    } else {

        cout << namePlayer2;

        color = 15;
        colorManager(color);
        cout << " ha vinto!!!" << endl;
        scoreB++;
    }

    cout << endl;
    cout << endl;
    system("PAUSE");

}

void drawScreen(){

    int color;
    system("CLS");

    for(int i = 0; i < 5; i++){

        system("CLS");
        cout << endl;
        cout << endl;

        color = 15;
        colorManager(color);


        cout << "█▀█ ▄▀█ █▀█ █▀▀ █▀▀ █▀▀ █ █▀█" << endl;
        cout << "█▀▀ █▀█ █▀▄ ██▄ █▄█ █▄█ █ █▄█" << endl;
        Sleep(100);

        system("CLS");

        cout << endl;
        cout << endl;

        color = 12;
        colorManager(color);

        cout << "█▀█ ▄▀█ █▀█ █▀▀ █▀▀ █▀▀ █ █▀█" << endl;
        cout << "█▀▀ █▀█ █▀▄ ██▄ █▄█ █▄█ █ █▄█" << endl;
        Sleep(100);

    }

    color = 12;
    colorManager(color);

    cout << endl;
    cout << endl;

    color = 15;
    colorManager(color);
    cout << "Avete pareggiato!!!" << endl;

    cout << endl;
    cout << endl;
    system("PAUSE");

}

void makeUpper(string s){

    char temp;
    for(unsigned int i = 0; i < s.size(); i++){

        temp = toupper(s[i]);
        cout << temp;

    }
}

void chooseRandom(string &n1, string &n2){

    srand(time(NULL));

    int n;
    string vNames[200] = {"Lampada", "Zanzariera", "Cuscino", "Tappeto", "Pianoforte", "Ciabatta", "Pennello", "Cartella", "Bicchiere", "Palloncino", "Sciarpa", "Martello", "Spazzolino da denti", "Cestino", "Ombrello", "Calcolatrice", "Giraffa", "Tazza", "Ventilatore", "Zaino", "Frullatore", "Tastiera", "Sedia a sdraio", "Giradischi", "Palla", "Foglio di carta", "Radiatore", "Caciotta", "Libro", "Borsa", "Pattumiera", "Portachiavi", "Sgabello", "Righello", "Lucchetto", "Scatola", "Elastico", "Penna", "Orologio", "Agenda", "Farfalla", "Ghiaccio", "Borsellino", "Quaderno", "Cassettiera", "Borraccia", "Penna a sfera", "Fotocamera", "Tastierino numerico", "CD", "Bussola", "Ciondolo", "Monocolo", "Puzzle", "Motozappa", "Girello", "Bastoncino incensato", "Clessidra", "Frusta", "Fionda", "Sestante", "Trottola", "Spilla", "Incudine", "Cerbottana", "Fermaporta", "Collare", "Gemelli", "Abaco", "Astrolabio", "Pergamena", "Maracas", "Molla", "Poggiapiedi", "Zoccolo", "Fischietto", "Ferretto", "Scodella", "Pirografo", "Levacapsule", "Siringa", "Marcatore", "Balsamo labbra", "Teglia", "Tarocco", "Raschietto", "Fioretto", "Barometro", "Fusto", "Cinghia", "Braciere", "Narghile'", "Distillatore", "Lavagna", "Moneta", "Ventaglio", "Fonendoscopio", "Tampone", "Biscottiera", "Siluro", "Calzino", "Candelabro", "Lucchetto a combinazione", "Spatola", "Casco", "Chiodo", "Bavaglino", "Lanterna", "Gomitolo", "Boccia", "Chiavetta USB", "Radiocomando", "Chitarra", "Accendino", "Catena", "Monitor", "Fumetto", "Lavatrice", "Sottobicchiere", "Cappello", "Campanello", "Grembiule", "Pala", "Piumino", "Folletto", "Portaombrelli", "Centrifuga", "Lente d'ingrandimento", "Moka", "Pompa per bicicletta", "Mazza da baseball", "Tornio", "Portafoglio", "Scopa elettrica", "Tavolino", "Fermaporte a molla", "Piuma", "Macchina fotografica", "Elastico per capelli", "Mouse", "Mazza da golf", "Scala", "Occhiali da sole", "Piastra per capelli", "Sveglia", "Graffetta", "Lucerna", "Tape dispenser", "Tuta da ginnastica", "Puzzle 3D",
"Manopola", "Cucchiaino", "Lavagna magnetica", "Termometro", "Zainetto", "Benda", "Cappotto", "Rubinetto", "Stendibiancheria", "Giostra", "Telecomando", "Altalena", "Pianta in vaso", "Righello flessibile", "Gabbia", "Ferma-libri", "Tagliacarte", "Cintura", "Globo terrestre", "Gonfiabile", "Tappo di bottiglia", "Pianta grassa", "Sveglia analogica", "Gioiello", "Pacchetto regalo", "Casco da moto", "Lucidatrice", "Pietra da affilare", "Passepartout", "Contenitore ermetico", "Vassoio", "Ventola da soffitto", "Scaldabagno", "Cucchiaio di legno", "Droni", "Piastra per waffle", "Trinciaerba", "Dizionario", "Album fotografico", "Apribottiglie", "Pallina da ping pong", "Adesivo", "Pallina anti-stress", "Lucchetto a combinazione", "Guantoni da boxe", "Vetrinetta", "Accendigas", "Materassino gonfiabile", "Candelabro solare"};

    n = rand() % 200;
    n1 = vNames[n];

    n = rand() % 200;
    n2 = vNames[n];


}

void setNames(){

    chooseRandom(namePlayer1, namePlayer2);

}


