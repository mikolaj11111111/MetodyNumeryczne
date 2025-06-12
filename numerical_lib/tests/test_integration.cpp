#include "../include/integration.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace NumLib::Integration;

double test_function(double x) {
    return x * x; // Integral from 0 to 1 should be 1/3
}

void test_rectangle_rule_correct() {
    double result = rectangle_rule(test_function, 0.0, 1.0, 1000);
    double expected = 1.0 / 3.0;

    assert(std::abs(result - expected) < 0.01);
    std::cout << "✓ Rectangle rule - correct case passed\n";
}

void test_trapezoidal_rule_correct() {
    double result = trapezoidal_rule(test_function, 0.0, 1.0, 100);
    double expected = 1.0 / 3.0;

    assert(std::abs(result - expected) < 0.001);
    std::cout << "✓ Trapezoidal rule - correct case passed\n";
}

void test_simpson_rule_correct() {
    double result = simpson_rule(test_function, 0.0, 1.0, 100);
    double expected = 1.0 / 3.0;

    assert(std::abs(result - expected) < 1e-10);
    std::cout << "✓ Simpson rule - correct case passed\n";
}

void test_integration_zero_intervals() {
    double result = rectangle_rule(test_function, 0.0, 1.0, 0);
    assert(result == 0.0);
    std::cout << "✓ Integration with zero intervals handled\n";
}

int main() {
    test_rectangle_rule_correct();
    test_trapezoidal_rule_correct();
    test_simpson_rule_correct();
    test_integration_zero_intervals();

    std::cout << "All integration tests passed!\n";
    return 0;
}