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
```
numerical_lib/
├── include/           # Pliki nagłówkowe (.h)
├── src/              # Implementacje (.cpp)
├── tests/            # Testy jednostkowe
└── examples/         # Przykłady użycia
```

## Kompilacja i uruchamianie w Visual Studio 2022

### Krok 1: Otwórz projekt
1. **Uruchom Visual Studio 2022**
2. **File → Open → Folder**
3. **Wybierz folder główny projektu** (zawierający CMakeLists.txt)
4. **Poczekaj na automatyczną konfigurację CMake**

### Krok 2: Konfiguracja (jeśli potrzebna)
Jeśli pojawią się błędy konfiguracji:
1. **Prawym przyciskiem na CMakeLists.txt** w Solution Explorer
2. **"Usuń pamięć podręczną i skonfiguruj ponownie"**

### Krok 3: Kompilacja
1. **Prawym przyciskiem na CMakeLists.txt**
2. **"Kompiluj"**
3. **Sprawdź wyniki w oknie Output (CMake)**

## Uruchamianie testów

### Metoda 1: Przez Visual Studio
1. **Po pomyślnej kompilacji**
2. **Prawym przyciskiem na CMakeLists.txt**
3. **"Uruchom testy"**
4. **Wyniki w oknie Output**

### Metoda 2: Developer Command Prompt
```bash
cd ścieżka_do_projektu/out/build/x64-Debug
ctest
```

### Oczekiwane wyniki testów
- ✅ **test_approximation** - aproksymacja wielomianowa
- ✅ **test_differential_equations** - równania różniczkowe
- ✅ **test_integration** - całkowanie numeryczne
- ❌ **test_interpolation** - interpolacja (znany błąd - test celowo zawiesza się)
- ✅ **test_linear_systems** - układy równań liniowych
- ✅ **test_nonlinear_equations** - równania nieliniowe
- ✅ **test_utilities** - narzędzia pomocnicze

**Wynik: 6/7 testów powinno przejść pomyślnie (86% sukces)**

## Uruchamianie przykładów

### Po kompilacji dostępne są programy przykładowe:

#### Metoda 1: PowerShell/Command Prompt
```bash
cd ścieżka_do_projektu/out/build/x64-Debug
.\example_linear_systems.exe
.\example_interpolation.exe
```

#### Metoda 2: File Explorer
1. **Przejdź do folderu:** `out/build/x64-Debug/`
2. **Dwukrotnie kliknij na pliki .exe:**
   - `example_interpolation.exe`
   - `example_linear_systems.exe`

### Opis przykładów
- **example_interpolation.cpp** - demonstracja interpolacji wielomianowej
- **example_linear_systems.cpp** - rozwiązywanie układów równań liniowych

## Struktura plików

### Pliki nagłówkowe (include/)
- `differential_equations.h` - równania różniczkowe
- `integration.h` - całkowanie numeryczne
- `utilities.h` - narzędzia pomocnicze
- `approximation.h` - aproksymacja
- `interpolation.h` - interpolacja
- `linear_systems.h` - układy równań liniowych
- `nonlinear_equations.h` - równania nieliniowe

### Implementacje (src/)
- Odpowiadające pliki .cpp z implementacjami

### Testy (tests/)
- `test_*.cpp` - testy jednostkowe dla każdego modułu

### Przykłady (examples/)
- `example_interpolation.cpp` - demo interpolacji
- `example_linear_systems.cpp` - demo układów równań
