#include "../include/approximation.h"
#include "../include/linear_systems.h"
#include "../include/integration.h"
#include <stdexcept>
#include <cmath>
#include <vector>

namespace NumLib {
    namespace Approximation {

        double phi_function(double x, int j) {
            return std::pow(x, j);
        }

        double evaluate_polynomial(const std::vector<double>& coeffs, double x) {
            double result = 0.0;
            for (size_t j = 0; j < coeffs.size(); j++) {
                result += coeffs[j] * phi_function(x, j);
            }
            return result;
        }

        std::vector<double> least_squares_approximation(std::function<double(double)> f, double a, double b, int degree) {
            if (degree < 0) {
                throw std::invalid_argument("Degree must be non-negative");
            }

            int m = degree + 1;
            std::vector<std::vector<double>> G(m, std::vector<double>(m));
            std::vector<double> d(m);

            // Oblicz macierz Grama G[i][j] = integral(phi_i * phi_j)
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    auto integrand = [i, j](double x) { return phi_function(x, i) * phi_function(x, j); };
                    G[i][j] = Integration::simpson_rule(integrand, a, b, 1000);
                }

                // Oblicz wektor d[i] = integral(f * phi_i)
                auto integrand_d = [f, i](double x) { return f(x) * phi_function(x, i); };
                d[i] = Integration::simpson_rule(integrand_d, a, b, 1000);
            }

            // Rozwi¹¿ uk³ad równañ G * c = d
            return LinearSystems::gauss_elimination(G, d);
        }

        double mean_square_error_approx(const std::vector<double>& coeffs, std::function<double(double)> f, double a, double b, int n) {
            if (n <= 0) return 0.0;

            auto error_squared = [&coeffs, f](double x) {
                double approx = evaluate_polynomial(coeffs, x);
                double error = f(x) - approx;
                return error * error;
                };

            return Integration::simpson_rule(error_squared, a, b, n);
        }

    }
} // namespace NumLib::Approximation