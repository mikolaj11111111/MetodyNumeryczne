#include "../include/differential_equations.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace NumLib::DifferentialEquations;

double simple_ode(double t, double y) {
    return -y; // dy/dt = -y, solution: y = y0 * exp(-t)
}

void test_euler_method_correct() {
    auto result = euler_method(simple_ode, 1.0, 0.0, 1.0, 0.1);

    // Sprawdź czy zwraca rozsądne wyniki
    assert(result.t.size() == result.y.size());
    assert(result.t[0] == 0.0);
    assert(result.y[0] == 1.0);
    assert(result.y.back() > 0.3 && result.y.back() < 0.4); // Około exp(-1) ≈ 0.368

    std::cout << "✓ Euler method - correct case passed\n";
}

void test_euler_method_invalid_params() {
    try {
        euler_method(simple_ode, 1.0, 0.0, 1.0, -0.1); // Negative step
        assert(false); // Should throw
    }
    catch (const std::invalid_argument&) {
        std::cout << "✓ Euler method - invalid parameters handled\n";
    }
}

void test_runge_kutta_correct() {
    auto result = runge_kutta_4(simple_ode, 1.0, 0.0, 1.0, 0.1);

    // RK4 powinno być dokładniejsze od Eulera
    double expected = std::exp(-1.0); // ≈ 0.368
    assert(std::abs(result.y.back() - expected) < 0.01);

    std::cout << "✓ Runge-Kutta 4 - correct case passed\n";
}

void test_heun_method_correct() {
    auto result = heun_method(simple_ode, 1.0, 0.0, 1.0, 0.1);

    assert(result.t.size() == result.y.size());
    assert(result.y.back() > 0.3 && result.y.back() < 0.4);

    std::cout << "✓ Heun method - correct case passed\n";
}

int main() {
    test_euler_method_correct();
    test_euler_method_invalid_params();
    test_runge_kutta_correct();
    test_heun_method_correct();

    std::cout << "All differential equations tests passed!\n";
    return 0;
}