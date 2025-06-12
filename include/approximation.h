#pragma once
#include <vector>
#include <functional>

namespace NumLib {
    namespace Approximation {

        // Aproksymacja metod¹ najmniejszych kwadratów
        std::vector<double> least_squares_approximation(std::function<double(double)> f, double a, double b, int degree);
        double evaluate_polynomial(const std::vector<double>& coeffs, double x);
        double mean_square_error_approx(const std::vector<double>& coeffs, std::function<double(double)> f, double a, double b, int n);

    }
} // namespace NumLib::Approximation