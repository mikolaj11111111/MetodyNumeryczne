#pragma once
#include <functional>

namespace NumLib {
    namespace NonlinearEquations {

        struct RootResult {
            double root;
            int iterations;
            bool converged;
            double function_value;
        };

        // Metody znajdowania pierwiastków
        RootResult bisection_method(std::function<double(double)> f, double a, double b, double epsilon = 1e-8, int max_iter = 1000);
        RootResult newton_method(std::function<double(double)> f, std::function<double(double)> df, double x0, double epsilon = 1e-8, int max_iter = 1000);
        RootResult secant_method(std::function<double(double)> f, double x0, double x1, double epsilon = 1e-8, int max_iter = 1000);

    }
} // namespace NumLib::NonlinearEquations