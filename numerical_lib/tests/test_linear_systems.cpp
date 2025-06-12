#include "../include/linear_systems.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>


using namespace NumLib::LinearSystems;

void test_gauss_elimination_correct() {
    std::vector<std::vector<double>> A = { {2, 1, -1}, {-3, -1, 2}, {-2, 1, 2} };
    std::vector<double> b = { 8, -11, -3 };

    auto x = gauss_elimination(A, b);

    assert(std::abs(x[0] - 2.0) < 1e-10);
    assert(std::abs(x[1] - 3.0) < 1e-10);
    assert(std::abs(x[2] - (-1.0)) < 1e-10);

    std::cout << "✓ Gauss elimination - correct case passed\n";
}

void test_gauss_elimination_singular() {
    std::vector<std::vector<double>> A = { {1, 1}, {1, 1} };
    std::vector<double> b = { 2, 3 };

    try {
        gauss_elimination(A, b);
        assert(false); // Should throw
    }
    catch (const std::runtime_error&) {
        std::cout << "✓ Gauss elimination - singular matrix handled\n";
    }
}

void test_lu_decomposition_correct() {
    std::vector<std::vector<double>> A = { {2, 1, 1}, {4, 3, 3}, {8, 7, 9} };

    auto lu = lu_decomposition(A);

    // Sprawdź wymiary
    assert(lu.L.size() == 3);
    assert(lu.U.size() == 3);
    assert(lu.P.size() == 3);

    std::cout << "✓ LU decomposition - correct case passed\n";
}

void test_lu_solve_correct() {
    std::vector<std::vector<double>> A = { {2, 1}, {1, 3} };
    std::vector<double> b = { 3, 4 };

    auto lu = lu_decomposition(A);
    auto x = solve_lu(lu, b);

    assert(std::abs(x[0] - 1.0) < 1e-10);
    assert(std::abs(x[1] - 1.0) < 1e-10);

    std::cout << "✓ LU solve - correct case passed\n";
}

int main() {
    test_gauss_elimination_correct();
    test_gauss_elimination_singular();
    test_lu_decomposition_correct();
    test_lu_solve_correct();

    std::cout << "All linear systems tests passed!\n";
    return 0;
}