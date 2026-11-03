
# Opis działania programu

Program służy do wprowadzania danych osób i zapisywania ich w pliku binarnym o nazwie `database.dat`.

Na początku programu użytkownik podaje liczbę osób, które chce zapisać. Program sprawdza, czy podana liczba jest poprawna i mieści się w zakresie od 1 do 30.

Następnie program pobiera dane każdej osoby:
- imię,
- nazwisko,
- numer.

Wprowadzone dane są przechowywane w tablicy struktur `Person`, która może pomieścić maksymalnie 30 osób.

Po wprowadzeniu wszystkich danych program tworzy plik binarny `database.dat`. Na początku pliku zapisuje liczbę osób (4 bajty), a następnie dane każdej osoby.

Każda osoba zajmuje 68 bajtów:
- imię – 32 bajty,
- nazwisko – 32 bajty,
- numer – 4 bajty.

Po zapisaniu wszystkich danych plik zostaje zamknięty, a program wyświetla komunikat o pomyślnym zapisaniu danych.

Rozmiar pliku zależy od liczby zapisanych osób i można go obliczyć ze wzoru:

**Rozmiar pliku = 4 + liczba osób × 68 bajtów.**
