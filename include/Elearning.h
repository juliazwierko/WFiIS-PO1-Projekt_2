#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Klasa bazowa reprezentująca użytkownika
class Uzytkownik {
private:
    string imie;
    string nazwisko;
    string login;
    string haslo; // Prywatne pole hasła

public:
    Uzytkownik(string im, string naz, string log, string pass) : imie(im), nazwisko(naz), login(log), haslo(pass) {}

    void wyswietlInformacje() {
        cout << "Imię: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Login: " << login << endl;
        // Nie wyświetlamy hasła
    }
};

// Klasa bazowa reprezentująca ocenę
class Ocena {
protected:
    int wartosc;

public:
    Ocena(int w) : wartosc(w) {}

    void wyswietlOcene() {
        cout << "Ocena: " << wartosc << endl;
    }
};

// Klasa bazowa reprezentująca zadanie
class Zadanie {
protected:
    string nazwa;

public:
    Zadanie(string n) : nazwa(n) {}

    void wyswietlZadanie() {
        cout << "Nazwa zadania: " << nazwa << endl;
    }
};

// Klasa bazowa reprezentująca przedmiot
class Przedmiot {
protected:
    string nazwa;

public:
    Przedmiot(string n) : nazwa(n) {}

    void wyswietlPrzedmiot() {
        cout << "Nazwa przedmiotu: " << nazwa << endl;
    }
};

// Klasy potomne reprezentujące różne typy ocen
class OcenaEgzaminu : public Ocena {
private:
    string nazwa_egzaminu;

public:
    OcenaEgzaminu(int w, string nazwa) : Ocena(w), nazwa_egzaminu(nazwa) {}

    void wyswietlOceneEgzaminu() {
        wyswietlOcene();
        cout << "Nazwa egzaminu: " << nazwa_egzaminu << endl;
    }
};

class OcenaZadaniaDomowego : public Ocena {
private:
    string nazwa_zadania;

public:
    OcenaZadaniaDomowego(int w, string nazwa) : Ocena(w), nazwa_zadania(nazwa) {}

    void wyswietlOceneZadaniaDomowego() {
        wyswietlOcene();
        cout << "Nazwa zadania domowego: " << nazwa_zadania << endl;
    }
};

// Klasy potomne reprezentujące różne typy zadań
class ZadanieDomowe : public Zadanie {
public:
    ZadanieDomowe(string n) : Zadanie(n) {}
};

// Klasy potomne reprezentujące różne przedmioty
class PrzedmiotMatematyka : public Przedmiot {
public:
    PrzedmiotMatematyka() : Przedmiot("Matematyka") {}
};

class PrzedmiotJezykPolski : public Przedmiot {
public:
    PrzedmiotJezykPolski() : Przedmiot("Język Polski") {}
};