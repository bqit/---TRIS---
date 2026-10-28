#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define rDIM 3
#define cDIM 3

// === DICHIARAZIONI FUNZIONI ===

void colorManager(int col);                     // <-- Manager dei colori
void titleHUD();                                // <-- Resa grafica del titolo
void rulesScreen();                             // <-- Schermata delle regole
void editPlayerName();                          // <-- Sistema di modifica nome player
void readyChecker();                            // <-- Verifica se i giocatori sono pronti
void gameEngine(char table[][cDIM]);            // <-- Motore di gioco
void gotoxy(int x, int y);                      // <-- Utilizzato per gestire le coordinate
void moveCursor(int v[]);                       // <-- Utilizzato per spostare il cursore con WASD
void subEmptyChars (char m[][cDIM]);            // <-- Sottrazione caratteri vuoti (Spiegata meglio più avanti R. 697)
void reloadChars (char m[][cDIM]);              // <-- Ricarica caratteri (Spiegata meglio più avanti R. 697)
void victoryScreen(int playerSelector);         // <-- Schermata di vittoria
void drawScreen();                              // <-- Schermata di pareggio
void makeUpper(std::string s);
void chooseRandom(std::string &n1, std::string &n2);
void setNames();

int newNameInput(int c, int p);                 // <-- Input per il nuovo nome

char winner(char m[][cDIM]);                    // <-- TRUE se qualcuno ha vinto

char mainTitleSet();                            // <-- Setta la schermata del titolo


#endif // HEADER_H_INCLUDED
