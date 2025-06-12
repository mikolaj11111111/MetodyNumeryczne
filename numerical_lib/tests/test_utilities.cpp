#include "../include/utilities.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace NumLib::Utilities;

double test_func(double x) {
    return x * x * x; // Derivative should be 3x^2
}

void test_horner_scheme_correct() {
    std::vector<double> coeffs = { 1, 2, 3 }; // 1 + 2x + 3x^2
    double result = horner_scheme(coeffs, 2.0);
    double expected = 1 + 2 * 2 + 3 * 4; // = 17

    assert(std::abs(result - expected) < 1e-10);
    std::cout << "✓ Horner scheme - correct case passed\n";
}

void test_horner_scheme_empty() {
    std::vector<double> coeffs = {};
    double result = horner_scheme(coeffs, 2.0);

    assert(result == 0.0);
    std::cout << "✓ Horner scheme - empty vector handled\n";
}

void test_numeric_derivative_correct() {
    double result = numeric_derivative(test_func, 2.0);
    double expected = 3 * 2 * 2; // 3x^2 at x=2 gives 12

    assert(std::abs(result - expected) < 0.01);
    std::cout << "✓ Numeric derivative - correct case passed\n";
}

void test_matrix_validation_correct() {
    std::vector<std::vector<double>> valid_matrix = { {1, 2}, {3, 4} };
    std::vector<std::vector<double>> invalid_matrix = { {1, 2}, {3} };

    assert(is_matrix_valid(valid_matrix) == true);
    assert(is_matrix_valid(invalid_matrix) == false);

    std::cout << "✓ Matrix validation - correct cases passed\n";
}

int main() {
    test_horner_scheme_correct();
    test_horner_scheme_empty();
    test_numeric_derivative_correct();
    test_matrix_validation_correct();

    std::cout << "All utilities tests passed!\n";
    return 0;
}