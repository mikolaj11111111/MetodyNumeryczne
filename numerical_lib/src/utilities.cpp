#include "../include/utilities.h"
#include <iostream>
#include <iomanip>
#include <cmath>

namespace NumLib {
    namespace Utilities {

        double horner_scheme(const std::vector<double>& coeffs, double x) {
            if (coeffs.empty()) return 0.0;

            double result = coeffs.back();
            for (int i = coeffs.size() - 2; i >= 0; i--) {
                result = result * x + coeffs[i];
            }
            return result;
        }

        double numeric_derivative(std::function<double(double)> f, double x, double h) {
            return (f(x + h) - f(x - h)) / (2 * h);
        }

        void print_matrix(const std::vector<std::vector<double>>& matrix) {
            std::cout << std::fixed << std::setprecision(6);
            for (const auto& row : matrix) {
                for (double val : row) {
                    std::cout << std::setw(12) << val << " ";
                }
                std::cout << std::endl;
            }
        }

        void print_vector(const std::vector<double>& vec) {
            std::cout << std::fixed << std::setprecision(6);
            for (double val : vec) {
                std::cout << std::setw(12) << val << std::endl;
            }
        }

        bool is_matrix_valid(const std::vector<std::vector<double>>& matrix) {
            if (matrix.empty()) return false;

            size_t cols = matrix[0].size();
            for (const auto& row : matrix) {
                if (row.size() != cols) return false;
            }
            return true;
        }

    }
} // namespace NumLib::Utilities