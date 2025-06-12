#pragma once
#include <vector>

namespace NumLib {
    namespace Interpolation {

        // Interpolacja Lagrange'a
        double lagrange_interpolation(const std::vector<double>& x, const std::vector<double>& y, double point);

        // Interpolacja Newtona
        std::vector<double> divided_differences(const std::vector<double>& x, const std::vector<double>& y);
        double newton_interpolation(const std::vector<double>& coeffs, const std::vector<double>& x, double point);

        // B³¹d œredniokwadratowy
        double mean_square_error(const std::vector<double>& x_test, const std::vector<double>& y_test,
            const std::vector<double>& x_nodes, const std::vector<double>& y_nodes);

    }
} // namespace NumLib::Interpolation