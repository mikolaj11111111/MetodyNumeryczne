#include "../include/nonlinear_equations.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace NumLib::NonlinearEquations;

double test_function(double x) {
    return x * x - 2; // Root at sqrt(2)
}

double test_derivative(double x) {
    return 2 * x;
}

void test_bisection_correct() {
    auto result = bisection_method(test_function, 1.0, 2.0);

    assert(result.converged);
    assert(std::abs(result.root - std::sqrt(2)) < 1e-6);
    std::cout << "✓ Bisection method - correct case passed\n";
}

void test_bisection_same_sign() {
    auto result = bisection_method(test_function, 2.0, 3.0); // f(2) and f(3) same sign

    assert(!result.converged);
    std::cout << "✓ Bisection method - same sign handled\n";
}

void test_newton_method_correct() {
    auto result = newton_method(test_function, test_derivative, 1.5);

    assert(result.converged);
    assert(std::abs(result.root - std::sqrt(2)) < 1e-10);
    std::cout << "✓ Newton method - correct case passed\n";
}

void test_secant_method_correct() {
    auto result = secant_method(test_function, 1.0, 2.0);

    assert(result.converged);
    assert(std::abs(result.root - std::sqrt(2)) < 1e-6);
    std::cout << "✓ Secant method - correct case passed\n";
}

int main() {
    test_bisection_correct();
    test_bisection_same_sign();
    test_newton_method_correct();
    test_secant_method_correct();

    std::cout << "All nonlinear equations tests passed!\n";
    return 0;
}