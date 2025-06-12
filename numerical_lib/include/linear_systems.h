#pragma once
#include <vector>

namespace NumLib {
    namespace LinearSystems {

        // Eliminacja Gaussa
        std::vector<double> gauss_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b);

        // Rozk³ad LU
        struct LUDecomposition {
            std::vector<std::vector<double>> L;
            std::vector<std::vector<double>> U;
            std::vector<int> P;
        };

        LUDecomposition lu_decomposition(std::vector<std::vector<double>> A);
        std::vector<double> solve_lu(const LUDecomposition& lu, const std::vector<double>& b);
        std::vector<double> forward_substitution(const std::vector<std::vector<double>>& L, const std::vector<double>& b);
        std::vector<double> backward_substitution(const std::vector<std::vector<double>>& U, const std::vector<double>& b);

    }
} // namespace NumLib::LinearSystems