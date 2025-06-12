#include "../include/interpolation.h"
#include <stdexcept>
#include <cmath>
#include<vector>

namespace NumLib {
    namespace Interpolation {

        double lagrange_interpolation(const std::vector<double>& x, const std::vector<double>& y, double point) {
            int n = x.size();
            if (n != y.size() || n == 0) {
                throw std::invalid_argument("x and y vectors must have same non-zero size");
            }

            double result = 0.0;

            for (int i = 0; i < n; i++) {
                double li = 1.0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        if (std::abs(x[i] - x[j]) < 1e-12) {
                            throw std::runtime_error("Duplicate x values in interpolation nodes");
                        }
                        li *= (point - x[j]) / (x[i] - x[j]);
                    }
                }
                result += li * y[i];
            }

            return result;
        }

        std::vector<double> divided_differences(const std::vector<double>& x, const std::vector<double>& y) {
            int n = x.size();
            if (n != y.size() || n == 0) {
                throw std::invalid_argument("x and y vectors must have same non-zero size");
            }

            std::vector<std::vector<double>> table(n, std::vector<double>(n, 0.0));

            // Pierwsza kolumna
            for (int i = 0; i < n; i++) {
                table[i][0] = y[i];
            }

            // Obliczanie ilorazów ró¿nicowych
            for (int j = 1; j < n; j++) {
                for (int i = 0; i < n - j; i++) {
                    if (std::abs(x[i + j] - x[i]) < 1e-12) {
                        throw std::runtime_error("Duplicate x values");
                    }
                    table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
                }
            }

            std::vector<double> coeffs(n);
            for (int i = 0; i < n; i++) {
                coeffs[i] = table[0][i];
            }

            return coeffs;
        }

        double newton_interpolation(const std::vector<double>& coeffs, const std::vector<double>& x, double point) {
            int n = coeffs.size();
            if (n != x.size() || n == 0) {
                throw std::invalid_argument("coeffs and x vectors must have same non-zero size");
            }

            double result = coeffs[0];

            for (int i = 1; i < n; i++) {
                double term = coeffs[i];
                for (int j = 0; j < i; j++) {
                    term *= (point - x[j]);
                }
                result += term;
            }

            return result;
        }

        double mean_square_error(const std::vector<double>& x_test, const std::vector<double>& y_test,
            const std::vector<double>& x_nodes, const std::vector<double>& y_nodes) {
            if (x_test.size() != y_test.size() || x_test.empty()) {
                throw std::invalid_argument("Test vectors must have same non-zero size");
            }

            double sum = 0.0;
            int n = x_test.size();

            for (int i = 0; i < n; i++) {
                double interpolated = lagrange_interpolation(x_nodes, y_nodes, x_test[i]);
                double error = y_test[i] - interpolated;
                sum += error * error;
            }

            return sum / n;
        }

    }
} // namespace NumLib::Interpolation