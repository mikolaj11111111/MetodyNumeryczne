#include "../include/numerical_lib.h"
#include <iostream>
#include <cmath>
#include<vector>
#define M_PI 3.14159265358979323846


int main() {
    std::cout << "=== Przykład: Interpolacja ===" << std::endl;

    // Punkty interpolacji dla funkcji sin(x)
    std::vector<double> x = { 0, M_PI / 4, M_PI / 2, 3 * M_PI / 4, M_PI };
    std::vector<double> y;

    for (double xi : x) {
        y.push_back(std::sin(xi));
    }

    double point = M_PI / 3; // Punkt do interpolacji

    // Interpolacja Lagrange'a
    double lagrange_result = NumLib::Interpolation::lagrange_interpolation(x, y, point);

    // Interpolacja Newtona
    auto coeffs = NumLib::Interpolation::divided_differences(x, y);
    double newton_result = NumLib::Interpolation::newton_interpolation(coeffs, x, point);

    double exact_value = std::sin(point);

    std::cout << "Punkt interpolacji: " << point << std::endl;
    std::cout << "Wartosc dokladna: " << exact_value << std::endl;
    std::cout << "Lagrange: " << lagrange_result << std::endl;
    std::cout << "Newton: " << newton_result << std::endl;
    std::cout << "Blad Lagrange: " << std::abs(exact_value - lagrange_result) << std::endl;
    std::cout << "Blad Newton: " << std::abs(exact_value - newton_result) << std::endl;

    return 0;
}
