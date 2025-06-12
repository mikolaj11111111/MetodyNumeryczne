#include "../include/approximation.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace NumLib::Approximation;

double test_quadratic(double x) {
    return x * x; // Perfect quadratic for degree 2 approximation
}

double test_exponential(double x) {
    return std::exp(x);
}

void test_polynomial_evaluation_correct() {
    std::vector<double> coeffs = { 1, 2, 3 }; // 1 + 2x + 3x^2
    double result = evaluate_polynomial(coeffs, 2.0);
    double expected = 1 + 2 * 2 + 3 * 4; // = 17

    assert(std::abs(result - expected) < 1e-10);
    std::cout << "✓ Polynomial evaluation - correct case passed\n";
}

void test_least_squares_correct() {
    // Aproksymacja funkcji kwadratowej wielomianem stopnia 2 powinna być dokładna
    auto coeffs = least_squares_approximation(test_quadratic, 0.0, 1.0, 2);

    assert(coeffs.size() == 3);
    // Współczynniki powinny być około [0, 0, 1] (x^2)
    assert(std::abs(coeffs[0]) < 1e-6); // stały składnik
    assert(std::abs(coeffs[1]) < 1e-6); // składnik liniowy
    assert(std::abs(coeffs[2] - 1.0) < 1e-3); // składnik kwadratowy

    std::cout << "✓ Least squares approximation - exact case passed\n";
}

void test_least_squares_negative_degree() {
    try {
        least_squares_approximation(test_exponential, 0.0, 1.0, -1);
        assert(false); // Should throw
    }
    catch (const std::invalid_argument&) {
        std::cout << "✓ Least squares - negative degree handled\n";
    }
}

void test_mse_approximation_correct() {
    std::vector<double> coeffs = { 0, 0, 1 }; // x^2
    double mse = mean_square_error_approx(coeffs, test_quadratic, 0.0, 1.0, 100);

    assert(mse < 1e-10); // Should be nearly zero for exact approximation
    std::cout << "✓ MSE approximation - correct case passed\n";
}

int main() {
    test_polynomial_evaluation_correct();
    test_least_squares_correct();
    test_least_squares_negative_degree();
    test_mse_approximation_correct();

    std::cout << "All approximation tests passed!\n";
    return 0;
}