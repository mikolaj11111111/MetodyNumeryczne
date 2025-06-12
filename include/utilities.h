#pragma once
#include <vector>

namespace NumLib {
    namespace Utilities {

        // Schemat Hornera
        double horner_scheme(const std::vector<double>& coeffs, double x);

        // Pochodna numeryczna
        double numeric_derivative(std::function<double(double)> f, double x, double h = 1e-6);

        // Funkcje pomocnicze
        void print_matrix(const std::vector<std::vector<double>>& matrix);
        void print_vector(const std::vector<double>& vec);
        bool is_matrix_valid(const std::vector<std::vector<double>>& matrix);

    }
} // namespace NumLib::Utilities