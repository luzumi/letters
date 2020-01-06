#pragma once

int max(int, int);
void clearScreen();
void pause();
class Random;

//Abgleich mit existierenden deutschen Worten
bool abgleich(std::string wortNeu);

//Neues Wort bauen, altes abbauen
int umwandeln(std::string& eingabe, std::string& eingabe2, char auswahl[], char auswahl1, std::string& wortNeu, unsigned int loeschzeichen, unsigned int anzahl);

int benutzereingabe(unsigned int& x);

// nach gültiger Zeichenauswahl abfragen
bool ueberpruefen(unsigned int stelle, unsigned int menge, bool& pruefer);

//entspricht benutzereingabe zeichenanzahl der vorgabe?
void vergleichen(unsigned int& anzahl);

//generieren des Ausgangswort mit 'anzahl' Zeichen
char wortbilden(int anzahl, unsigned int& kopie);

//erzeugt Schalter für switch in zuordnung()
unsigned int SCHALTER(unsigned int& loeschzeichen, int& schalter);

//Schalter für die korrekte Auswahl des zu ersetzenden Zeichens
unsigned int zuordnung(int schalter, unsigned int& loeschzeichen);
