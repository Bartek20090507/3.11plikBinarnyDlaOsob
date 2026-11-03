#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

// Struktura przechowujaca dane jednej osoby
struct Person {
    char first_name[32];
    char last_name[32];
    int32_t number;
};

// Funkcja do wprowadzania danych osob
void input_people(Person people[], int32_t count) {
    for (int i = 0; i < count; i++) {
        cout << "\nOsoba " << i + 1 << endl;

        cout << "Podaj imie: ";
        cin >> people[i].first_name;

        cout << "Podaj nazwisko: ";
        cin >> people[i].last_name;

        cout << "Podaj numer: ";
        cin >> people[i].number;
    }
}

// Funkcja zapisujaca dane do pliku binarnego
void save_to_file(const Person people[], int32_t count) {
    ofstream file("database.dat", ios::binary);

    // Sprawdzenie, czy plik zostal poprawnie otwarty
    if (!file) {
        cout << "Blad otwarcia pliku!" << endl;
        return;
    }

    // Zapis liczby osob (4 bajty)
    file.write(
        reinterpret_cast<const char*>(&count),
        sizeof(count)
    );

    // Zapis danych kazdej osoby (68 bajtow)
    for (int i = 0; i < count; i++) {
        file.write(
            reinterpret_cast<const char*>(&people[i]),
            sizeof(Person)
        );
    }

    // Zamkniecie pliku
    file.close();

    cout << "\nDane zapisano do pliku database.dat" << endl;
}

// Funkcja glowna programu
int main() {
    Person people[30];
    int32_t people_count;

    // Wczytanie liczby osob
    cout << "Podaj liczbe osob (max 30): ";
    cin >> people_count;

    // Sprawdzenie poprawnosci podanej liczby
    if (cin.fail() || people_count < 1 || people_count > 30) {
        cout << "Nieprawidlowa liczba osob!" << endl;
        return 1;
    }

    // Wprowadzanie danych osob
    input_people(people, people_count);

    // Zapis danych do pliku binarnego
    save_to_file(people, people_count);

    return 0;
}
