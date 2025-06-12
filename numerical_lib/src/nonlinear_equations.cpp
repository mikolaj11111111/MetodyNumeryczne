#include "../include/nonlinear_equations.h"
#include "../include/utilities.h"
#include <cmath>

namespace NumLib {
    namespace NonlinearEquations {

        RootResult bisection_method(std::function<double(double)> f, double a, double b, double epsilon, int max_iter) {
            RootResult result;

            double fa = f(a);
            double fb = f(b);

            if (fa * fb >= 0) {
                result.converged = false;
                return result;
            }

            double c;
            int iter = 0;

            while ((b - a) / 2.0 > epsilon && iter < max_iter) {
                iter++;
                c = (a + b) / 2.0;
                double fc = f(c);

                if (std::abs(fc) < epsilon) {
                    result.root = c;
                    result.iterations = iter;
                    result.converged = true;
                    result.function_value = fc;
                    return result;
                }

                if (fa * fc < 0) {
                    b = c;
                    fb = fc;
                }
                else {
                    a = c;
                    fa = fc;
                }
            }

            result.root = (a + b) / 2.0;
            result.iterations = iter;
            result.converged = true;
            result.function_value = f(result.root);

            return result;
        }

        RootResult newton_method(std::function<double(double)> f, std::function<double(double)> df, double x0, double epsilon, int max_iter) {
            RootResult result;
            double x = x0;

            for (int i = 0; i < max_iter; i++) {
                double fx = f(x);
                double dfx = df(x);

                if (std::abs(dfx) < 1e-14) {
                    result.converged = false;
                    return result;
                }

                double x_new = x - fx / dfx;

                if (std::abs(x_new - x) < epsilon) {
                    result.root = x_new;
                    result.iterations = i + 1;
                    result.converged = true;
                    result.function_value = f(x_new);
                    return result;
                }

                x = x_new;
            }

            result.converged = false;
            return result;
        }

        RootResult secant_method(std::function<double(double)> f, double x0, double x1, double epsilon, int max_iter) {
            RootResult result;

            double f0 = f(x0);
            double f1 = f(x1);

            for (int i = 0; i < max_iter; i++) {
                if (std::abs(f1 - f0) < 1e-14) {
                    result.converged = false;
                    return result;
                }

                double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

                if (std::abs(x2 - x1) < epsilon) {
                    result.root = x2;
                    result.iterations = i + 1;
                    result.converged = true;
                    result.function_value = f(x2);
                    return result;
                }

                x0 = x1;
                f0 = f1;
                x1 = x2;
                f1 = f(x1);
            }

            result.converged = false;
            return result;
        }

    }
} // namespace NumLib::NonlinearEquations