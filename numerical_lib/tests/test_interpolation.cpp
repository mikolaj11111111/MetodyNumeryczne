#include "../include/interpolation.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

using namespace NumLib::Interpolation;

void test_lagrange_interpolation_correct() {
    std::vector<double> x = { 0, 1, 2 };
    std::vector<double> y = { 1, 3, 9 }; // y = x^2 + 2x + 1

    double result = lagrange_interpolation(x, y, 1.5);
    double expected = 1.5 * 1.5 + 2 * 1.5 + 1; // 6.25

    assert(std::abs(result - expected) < 1e-10);
    std::cout << "✓ Lagrange interpolation - correct case passed\n";
}

void test_lagrange_interpolation_duplicate_x() {
    std::vector<double> x = { 0, 1, 1 };
    std::vector<double> y = { 1, 3, 9 };

    try {
        lagrange_interpolation(x, y, 0.5);
        assert(false); // Should throw
    }
    catch (const std::runtime_error&) {
        std::cout << "✓ Lagrange interpolation - duplicate x values handled\n";
    }
}

void test_newton_interpolation_correct() {
    std::vector<double> x = { 0, 1, 2 };
    std::vector<double> y = { 1, 3, 9 };

    auto coeffs = divided_differences(x, y);
    double result = newton_interpolation(coeffs, x, 1.5);
    double expected = 6.25; // Same as Lagrange

    assert(std::abs(result - expected) < 1e-10);
    std::cout << "✓ Newton interpolation - correct case passed\n";
}

void test_mse_correct() {
    std::vector<double> x_test = { 0.5, 1.5 };
    std::vector<double> y_test = { 2.25, 6.25 }; // Exact values
    std::vector<double> x_nodes = { 0, 1, 2 };
    std::vector<double> y_nodes = { 1, 3, 9 };

    double mse = mean_square_error(x_test, y_test, x_nodes, y_nodes);

    assert(mse < 1e-20); // Should be nearly zero
    std::cout << "✓ MSE calculation - correct case passed\n";
}

int main() {
    test_lagrange_interpolation_correct();
    test_lagrange_interpolation_duplicate_x();
    test_newton_interpolation_correct();
    test_mse_correct();

    std::cout << "All interpolation tests passed!\n";
    return 0;
}