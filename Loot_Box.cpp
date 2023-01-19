#include <iostream>
#include <ctime>

using namespace std;
using dukaty = int;
using kilogramy = double;
using text = char[100];

enum class rzadkosc { powszechny, rzadki, unikalny, epicki };
const char* tabRzadkosc[4] = { "powszechny", "rzadki", "unikalny", "epicki" };
enum class rodzaj { broń, zbroja, amulet, pierścień, hełm, tarcza, buty };
const char* tabTyp[7] = { "broń", "zbroja", "amulet", "pierścień", "hełm", "tarcza", "buty" };

struct Przedmiot
{
	text nazwa;
	dukaty wartosc;
	kilogramy waga;
	rzadkosc klasaRzadkosci;
	rodzaj typ;
};

void wypelnij(Przedmiot& p, char const* nazwa, dukaty wart, kilogramy waga, rzadkosc rzad, rodzaj typ)
{
	strcpy_s(p.nazwa, nazwa);
	p.wartosc = wart;
	p.waga = waga;
	p.klasaRzadkosci = rzad;
	p.typ = typ;
}

Przedmiot losowanie(Przedmiot* przedm)
{
	int los = rand() % 10 + 1;
	int index;
	if (los < 5)
		index = 0;
	else if (los >= 5 && los <= 7)
		index = 1;
	else if (los >= 8 && los <= 9)
		index = 2;
	else
		index = 3;
	return przedm[index];
}

ostream& operator<<(ostream& str, Przedmiot const& p) //utworzona z wykorzystaniem wykladu nr 9
{
	str << "Przedmiot: \t Nazwa: " << p.nazwa << endl << "\t\t" << " Wartość: " << p.wartosc << " dukatów " << endl
		<< "\t\t" << " Ciężar: " << p.waga << " kilogramów " << endl
		<< "\t\t" << " Rzadkość: " << tabRzadkosc[(int)p.klasaRzadkosci] << endl
		<< "\t\t" << " Typ Przedmiotu: " << tabTyp[(int)p.typ] << endl << endl;
	return str;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	Przedmiot miecz, buty, tarcza, amulet;
	cout << "Działanie funkcji wypełniającej oraz operatora <<:" << endl << endl;
	wypelnij(miecz, "Srebrny Miecz", 300, 8.0, rzadkosc::powszechny, rodzaj::broń);
	wypelnij(buty, "Spartańskie sandały", 450, 4.0, rzadkosc::rzadki, rodzaj::buty);
	wypelnij(tarcza, "Krasnoludzka Tarcza", 600, 7.0, rzadkosc::unikalny, rodzaj::tarcza);
	wypelnij(amulet, "Amulet Ognia", 1500, 1.0, rzadkosc::epicki, rodzaj::amulet);
	cout << miecz << buty << tarcza << amulet << endl << endl;
	Przedmiot tabPrzedm[] = { miecz, buty, tarcza, amulet };

	cout << "Działanie funkcji losującej: " << endl << endl;
	cout << losowanie(tabPrzedm) << endl;
}
