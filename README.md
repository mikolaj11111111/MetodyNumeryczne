# Biblioteka Numeryczna

## Opis projektu
Biblioteka implementuje podstawowe metody numeryczne w języku C++. Została stworzona na potrzeby laboratorium z metod numerycznych.

## Zakres funkcjonalny biblioteki

### 1. Rozwiązywanie układów równań liniowych
- **Eliminacja Gaussa** z wyborem elementu głównego
- **Rozkład LU** z pivotingiem częściowym
- Podstawianie w przód i w tył

### 2. Interpolacja
- **Interpolacja Lagrange'a** - wielomian interpolacyjny w postaci Lagrange'a
- **Interpolacja Newtona** - wielomian interpolacyjny z ilorazami różnicowymi
- Obliczanie błędu średniokwadratowego interpolacji

### 3. Całkowanie numeryczne
- **Metoda prostokątów** - dla funkcji i wielomianów
- **Metoda trapezów** - dla funkcji i wielomianów
- **Metoda Simpsona** - dla funkcji i wielomianów
- **Kwadratury Gaussa-Legendre'a** - pojedyncze i złożone

### 4. Aproksymacja
- **Metoda najmniejszych kwadratów** - aproksymacja wielomianowa
- Obliczanie błędu średniokwadratowego aproksymacji
- Ewaluacja wielomianów

### 5. Równania różniczkowe zwyczajne
- **Metoda Eulera** - metoda pierwszego rzędu
- **Metoda Heuna** - metoda drugiego rzędu (prediktor-korektor)
- **Metoda punktu środkowego** - metoda drugiego rzędu
- **Metoda Rungego-Kutty 4. rzędu** - metoda czwartego rzędu

### 6. Równania nieliniowe
- **Metoda bisekcji** - dla funkcji ciągłych
- **Metoda Newtona** - z pochodną analityczną
- **Metoda siecznych** - bez pochodnej

### 7. Narzędzia pomocnicze
- **Schemat Hornera** - efektywne obliczanie wartości wielomianów
- **Pochodna numeryczna** - obliczanie pochodnej metodą różnic centralnych
- Funkcje wyświetlania i walidacji macierzy

## Wymagania techniczne

### Język programowania
- C++ (standard C++17 lub nowszy)

### Struktura biblioteki
