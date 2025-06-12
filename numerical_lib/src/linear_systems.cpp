#include "../include/linear_systems.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include<vector>

namespace NumLib {
    namespace LinearSystems {

        std::vector<double> gauss_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
            int n = A.size();
            if (n == 0 || A[0].size() != n || b.size() != n) {
                throw std::invalid_argument("Invalid matrix dimensions");
            }

            // Rozszerzenie macierzy
            for (int i = 0; i < n; i++) {
                A[i].push_back(b[i]);
            }

            // Eliminacja w przód
            for (int i = 0; i < n; i++) {
                // Wybór elementu g³ównego
                int max_row = i;
                for (int k = i + 1; k < n; k++) {
                    if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                        max_row = k;
                    }
                }

                if (max_row != i) {
                    std::swap(A[i], A[max_row]);
                }

                if (std::abs(A[i][i]) < 1e-12) {
                    throw std::runtime_error("Matrix is singular");
                }

                // Eliminacja
                for (int j = i + 1; j < n; j++) {
                    double factor = A[j][i] / A[i][i];
                    for (int k = i; k < n + 1; k++) {
                        A[j][k] -= factor * A[i][k];
                    }
                }
            }

            // Podstawianie wsteczne
            std::vector<double> x(n, 0.0);
            for (int i = n - 1; i >= 0; i--) {
                x[i] = A[i][n] / A[i][i];
                for (int j = i - 1; j >= 0; j--) {
                    A[j][n] -= A[j][i] * x[i];
                }
            }

            return x;
        }

        LUDecomposition lu_decomposition(std::vector<std::vector<double>> A) {
            int n = A.size();
            if (n == 0 || A[0].size() != n) {
                throw std::invalid_argument("Matrix must be square");
            }

            LUDecomposition result;
            result.L = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
            result.U = A;
            result.P = std::vector<int>(n);

            for (int i = 0; i < n; i++) {
                result.P[i] = i;
                result.L[i][i] = 1.0;
            }

            for (int k = 0; k < n - 1; k++) {
                // Wybór elementu g³ównego
                int max_row = k;
                double max_val = std::abs(result.U[k][k]);

                for (int i = k + 1; i < n; i++) {
                    if (std::abs(result.U[i][k]) > max_val) {
                        max_val = std::abs(result.U[i][k]);
                        max_row = i;
                    }
                }

                if (max_row != k) {
                    std::swap(result.U[k], result.U[max_row]);
                    std::swap(result.P[k], result.P[max_row]);
                    for (int j = 0; j < k; j++) {
                        std::swap(result.L[k][j], result.L[max_row][j]);
                    }
                }

                if (std::abs(result.U[k][k]) < 1e-10) {
                    throw std::runtime_error("Matrix is singular");
                }

                for (int i = k + 1; i < n; i++) {
                    double multiplier = result.U[i][k] / result.U[k][k];
                    result.L[i][k] = multiplier;

                    for (int j = k; j < n; j++) {
                        result.U[i][j] -= multiplier * result.U[k][j];
                    }
                }
            }

            return result;
        }

        std::vector<double> forward_substitution(const std::vector<std::vector<double>>& L, const std::vector<double>& b) {
            int n = L.size();
            std::vector<double> z(n, 0.0);

            for (int i = 0; i < n; i++) {
                z[i] = b[i];
                for (int j = 0; j < i; j++) {
                    z[i] -= L[i][j] * z[j];
                }
                z[i] /= L[i][i];
            }

            return z;
        }

        std::vector<double> backward_substitution(const std::vector<std::vector<double>>& U, const std::vector<double>& b) {
            int n = U.size();
            std::vector<double> x(n, 0.0);

            for (int i = n - 1; i >= 0; i--) {
                x[i] = b[i];
                for (int j = i + 1; j < n; j++) {
                    x[i] -= U[i][j] * x[j];
                }
                x[i] /= U[i][i];
            }

            return x;
        }

        std::vector<double> solve_lu(const LUDecomposition& lu, const std::vector<double>& b) {
            int n = b.size();
            std::vector<double> Pb(n);

            for (int i = 0; i < n; i++) {
                Pb[i] = b[lu.P[i]];
            }

            std::vector<double> z = forward_substitution(lu.L, Pb);
            return backward_substitution(lu.U, z);
        }

    }
} // namespace NumLib::LinearSystems