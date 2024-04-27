#include <iostream>
#include <vector>
#include <string> 

#include "Elearning.h"

using namespace std;

int main(int argc, char** argv)
{
    // Tworzenie użytkownika
    Uzytkownik uzytkownik("Julia", "Zwierko", "jzwierko", "haslo123");
    cout << "Informacje o użytkowniku:" << endl;
    uzytkownik.wyswietlInformacje();
    cout << endl;

    // Tworzenie ocen egzaminu i zadania domowego
    OcenaEgzaminu ocenaEgzaminu(90, "Matematyka");
    OcenaZadaniaDomowego ocenaZadaniaDomowego(100, "Całki nieoznaczone");
    cout << "Informacje o ocenach:" << endl;
    ocenaEgzaminu.wyswietlOceneEgzaminu();
    ocenaZadaniaDomowego.wyswietlOceneZadaniaDomowego();
    cout << endl;

    // Tworzenie przedmiotów
    PrzedmiotMatematyka matematyka;
    PrzedmiotJezykPolski jezykPolski;
    cout << "Informacje o przedmiotach:" << endl;
    matematyka.wyswietlPrzedmiot();
    jezykPolski.wyswietlPrzedmiot();

    return 0;
}