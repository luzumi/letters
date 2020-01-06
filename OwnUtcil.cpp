#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include <cassert>

#include "ownUtil.hpp"

using namespace std;
#define WIN
#ifndef _RANDOM_H
#define _RANDOM_H



// Datei: random.cpp


class Random
{
private:			//Zufallsgenerator
	Random()
	{
		std::srand(static_cast<int>(std::time(NULL)));
	}
public:
	static int rnd(int lowerbounds, int upperbounds)
	{
		static Random dummy;
		assert(upperbounds - lowerbounds < RAND_MAX);
		return lowerbounds + std::rand() % (upperbounds - lowerbounds + 1);
	}
	static unsigned int rnd32()
	{
		static Random dummy;
		int rnd1 = rand();
		int rnd2 = rand();
		int rnd3 = rand();
		unsigned int bigrnd = ((rnd1 & 0x03) << 30) + (rnd2 << 15) + rnd3;
	}
};

#endif

int max(int a, int b) {			//max wert ermitteln
	return a > b ? a : b;
}

void clearScreen() {				//consoleninhalt löschen
#if defined(WIN32) 
	system("cls");
#endif
#if defined(LINUX)
	system("clear");
#endif
}

void pause() {
#ifdef WIN32
	system("pause");
#endif

#ifndef WIN
	int i;
	cin >> i;
#endif
}

bool abgleich()
{
	return false;
}

bool abgleich(string wortNeu) {
	//ifstream liest allewoerter.txt in datei ein
	string pruefwort = wortNeu;
	ifstream datei;
	string zeile;		//
	bool wahr = false;

	datei.open("C:/Users/corat/Source/Repos/letters/alleworter_klein.txt");
	if (datei.is_open()) {
		while (getline(datei, zeile))		//durchkämmt zeile für zeile
		{

			for (int i = 0; i < zeile.size(); i++) {
				if (zeile[i] == 13)			//ersetzt Zeilenumbrüche mit leerzeichen
				{
					zeile[i] = ' ';

				}
			}
			for (int i = 0; i < zeile.size(); i++) {
				if (pruefwort == zeile) {
					cout << pruefwort << " - gueltiges Wort !";
					wahr = true;
					break;
				}
			}


		}
	}


	else {
		cerr << "fehler beim oeffnen der Datei";
	}
	cout << endl;
	return wahr;
}

int umwandeln(string& eingabe, string& eingabe2, char auswahl[], char auswahl1, string& wortNeu, unsigned int loeschzeichen, unsigned int anzahl) {

	eingabe.copy(auswahl, 1, loeschzeichen - 1);		//kopiert nach dem loeschzahl zeichen  1 zeichen in auswahl(muss char[] sein)

	int b = auswahl[0];
	auswahl1 = b;
	//
	wortNeu.append(1, auswahl1);						//fügt ausgewähltes zeichen in das erratene wort


	eingabe.replace(loeschzeichen - 1, 1, "_");			//ersetzt nach dem loeschzahl 1 zeichen 

	//eingabe.erase(loeschzeichen - 1, 1);													//ersetzt nach dem loeschzahl 1 zeichen 
	//zeichenLoeschen(loeschzeichen, eingabe);

	cout << "\nDein Wort: " << wortNeu << endl << endl;
	cout << "\nEs bleiben diese Buchstaben zur weiteren Auswahl \n" << eingabe << endl;

	return anzahl;

}

int benutzereingabe(unsigned int& x) {  //Eingabe des 'x'ten Zeichens zur Auswahl aus den zur Verfügung stehenden Zeichen

	do {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> x;
	} while (!cin);



	return x;
}

bool ueberpruefen(unsigned int stelle, unsigned int menge, bool& pruefer) {

	unsigned int loeschzeichen = stelle;
	//cout << pruefer << '\t' << loeschzeichen << '\t' << menge << '\t' << stelle << endl;

	if (loeschzeichen > menge) {
		menge++;
		cout << "\nDiese Stelle ist nicht belegt! Probiere eine Position zwischen 1 und " << menge - 1;
		cout << "\nProbiers nochmal!" << endl;

		benutzereingabe(menge);

		pruefer = false;
		return pruefer;
	}
	else if (loeschzeichen < 0) {
		menge++;
		cout << "\nDeine Eingabe war ungültig! Probiere eine Position zwischen 1 und " << menge;
		cout << "\nProbiers nochmal!" << endl;
		benutzereingabe(menge);
		pruefer = false;
		return pruefer;
	}
	else if (loeschzeichen == 0) {
		pruefer = false;
		return pruefer;
	}
	return pruefer;
}

void vergleichen(unsigned int& anzahl) {
	while (anzahl < 1 || anzahl > 20) {
		cout << "\nBitte eine Auswahl zwischen 0 und 20 treffen! \n" << endl << "Nochmal bitte. " << endl;
		cout << "Wieviele Buchstaben moechtest du sortieren (max 10)?" << endl;
		benutzereingabe(anzahl);
	}

	cout << "\nDu moechtest es also mit " << anzahl << " Buchtsaben versuchen." << endl;
}

char wortbilden(int anzahl, unsigned int& kopie) {	//https://en.cppreference.com/w/cpp/numeric/random/discrete_distribution
								//Zuffalsgenerator erstellt mit array mit anzahl zeichen unter 
								//Berücksichtigung der Wahrscheinlichkeit des Vorkommens einzelnen Buchstaben im deutschen Wortschatz
	std::random_device rd;
	std::mt19937 gen(rd());
	std::discrete_distribution<> d({ 1740, 978, 755, 727, 700, 651, 615, 508, 476, 435, 344, 306, 301, 253, 251, 189, 189, 166, 121, 112, 79, 67, 27, 4, 3, 2 }); // Wahrscheinlichkeit des Vorkommens einzelnen Buchstaben im deutschen Wortschatz
	std::map<int, int> m;
	for (int n = 0; n < anzahl; ++n) {
		++m[d(gen)];
		kopie = d(gen) + 97;
		return kopie;
	}
}

unsigned int SCHALTER(unsigned int& loeschzeichen, int& schalter) {

	if (loeschzeichen == 1 || loeschzeichen == 2) {
		schalter = 1;
		return schalter;
	}
	else if (loeschzeichen == 3 || loeschzeichen == 4) {
		schalter = 2;
		return schalter;
	}
	else if (loeschzeichen == 5 || loeschzeichen == 6) {
		schalter = 3;
		return schalter;
	}
	else if (loeschzeichen == 7 || loeschzeichen == 8) {
		schalter = 4;
		return schalter;
	}
	else if (loeschzeichen == 9 || loeschzeichen == 10) {
		schalter = 5;
		return schalter;
	}
	else if (loeschzeichen == 11 || loeschzeichen == 12) {
		schalter = 6;
		return schalter;
	}
	else if (loeschzeichen == 13 || loeschzeichen == 14) {
		schalter = 7;
		return schalter;
	}
	else if (loeschzeichen == 15 || loeschzeichen == 16) {
		schalter = 8;
		return schalter;
	}
	else if (loeschzeichen == 17 || loeschzeichen == 18) {
		schalter = 9;
		return schalter;
	}
	else if (loeschzeichen == 19 || loeschzeichen == 20) {
		schalter = 10;
		return schalter;
	}

}

unsigned int zuordnung(int schalter, unsigned int& loeschzeichen) {
	switch (schalter) {
	case 1:
		loeschzeichen = loeschzeichen;
		return loeschzeichen;
		break;
	case 2:
		loeschzeichen = loeschzeichen + 1;
		return (loeschzeichen);
		break;
	case 3:
		loeschzeichen = loeschzeichen + 2;
		return (loeschzeichen);
		break;
	case 4:
		loeschzeichen = loeschzeichen + 3;
		return (loeschzeichen);
		break;
	case 5:
		loeschzeichen = loeschzeichen + 4;
		return (loeschzeichen);
		break;
	case 6:
		loeschzeichen = loeschzeichen + 5;
		return (loeschzeichen);
		break;
	case 7:
		loeschzeichen = loeschzeichen + 6;
		return (loeschzeichen);
		break;
	case 8:
		loeschzeichen = loeschzeichen + 7;
		return (loeschzeichen);
		break;
	case 9:
		loeschzeichen = loeschzeichen + 8;
		return (loeschzeichen);
		break;
	case 10:
		loeschzeichen = loeschzeichen + 9;
		return (loeschzeichen);
		break;
	default:
		break;
	}
	return loeschzeichen;
}
