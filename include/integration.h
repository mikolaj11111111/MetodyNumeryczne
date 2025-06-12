#pragma once
#include <vector>
#include <functional>

namespace NumLib {
    namespace Integration {

        // Metody podstawowe
        double rectangle_rule(std::function<double(double)> f, double a, double b, int n);
        double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n);
        double simpson_rule(std::function<double(double)> f, double a, double b, int n);

        // Wielomiany
        double rectangle_polynomial(const std::vector<double>& coeffs, double a, double b, int n);
        double trapezoidal_polynomial(const std::vector<double>& coeffs, double a, double b, int n);
        double simpson_polynomial(const std::vector<double>& coeffs, double a, double b, int n);

        // Kwadratury Gaussa-Legendre'a
        double gauss_legendre_single(std::function<double(double)> f, double a, double b,
            const std::vector<double>& nodes, const std::vector<double>& weights);
        double gauss_legendre_composite(std::function<double(double)> f, double a, double b,
            const std::vector<double>& nodes, const std::vector<double>& weights, int subdivisions);

    }
} // namespace NumLib::Integration