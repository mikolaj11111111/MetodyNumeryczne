#include "../include/numerical_lib.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== Przyk�ad: Rozwi�zywanie uk�adu r�wna� ===" << std::endl;

    // Uk�ad: 2x + y = 3, x + 3y = 4
    std::vector<std::vector<double>> A = { {2, 1}, {1, 3} };
    std::vector<double> b = { 3, 4 };

    // Metoda Gaussa
    auto A_copy = A;
    auto b_copy = b;
    auto solution_gauss = NumLib::LinearSystems::gauss_elimination(A_copy, b_copy);

    std::cout << "Rozwi�zanie metod� Gaussa: ";
    for (double x : solution_gauss) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Metoda LU
    auto lu = NumLib::LinearSystems::lu_decomposition(A);
    auto solution_lu = NumLib::LinearSystems::solve_lu(lu, b);

    std::cout << "Rozwi�zanie metod� LU: ";
    for (double x : solution_lu) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}