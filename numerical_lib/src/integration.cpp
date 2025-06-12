#include "../include/integration.h"
#include "../include/utilities.h"
#include <stdexcept>
#include <cmath>

namespace NumLib {
    namespace Integration {

        double rectangle_rule(std::function<double(double)> f, double a, double b, int n) {
            if (n <= 0) return 0.0;

            double h = (b - a) / n;
            double sum = 0.0;

            for (int i = 0; i < n; i++) {
                double xi = a + i * h;
                sum += f(xi);
            }

            return sum * h;
        }

        double trapezoidal_rule(std::function<double(double)> f, double a, double b, int n) {
            if (n <= 0) return 0.0;

            double h = (b - a) / n;
            double sum = (f(a) + f(b)) / 2.0;

            for (int i = 1; i < n; i++) {
                double xi = a + i * h;
                sum += f(xi);
            }

            return sum * h;
        }

        double simpson_rule(std::function<double(double)> f, double a, double b, int n) {
            if (n <= 0) return 0.0;
            if (n % 2 != 0) n++;

            double h = (b - a) / n;
            double sum = f(a) + f(b);

            for (int i = 1; i < n; i++) {
                double xi = a + i * h;
                if (i % 2 == 0) {
                    sum += 2 * f(xi);
                }
                else {
                    sum += 4 * f(xi);
                }
            }

            return sum * h / 3.0;
        }

        double rectangle_polynomial(const std::vector<double>& coeffs, double a, double b, int n) {
            if (n <= 0) return 0.0;

            double h = (b - a) / n;
            double sum = 0.0;

            for (int i = 0; i < n; i++) {
                double xi = a + i * h;
                sum += Utilities::horner_scheme(coeffs, xi);
            }

            return sum * h;
        }

        double trapezoidal_polynomial(const std::vector<double>& coeffs, double a, double b, int n) {
            if (n <= 0) return 0.0;

            double h = (b - a) / n;
            double sum = (Utilities::horner_scheme(coeffs, a) + Utilities::horner_scheme(coeffs, b)) / 2.0;

            for (int i = 1; i < n; i++) {
                double xi = a + i * h;
                sum += Utilities::horner_scheme(coeffs, xi);
            }

            return sum * h;
        }

        double simpson_polynomial(const std::vector<double>& coeffs, double a, double b, int n) {
            if (n <= 0) return 0.0;
            if (n % 2 != 0) n++;

            double h = (b - a) / n;
            double sum = Utilities::horner_scheme(coeffs, a) + Utilities::horner_scheme(coeffs, b);

            for (int i = 1; i < n; i++) {
                double xi = a + i * h;
                if (i % 2 == 0) {
                    sum += 2 * Utilities::horner_scheme(coeffs, xi);
                }
                else {
                    sum += 4 * Utilities::horner_scheme(coeffs, xi);
                }
            }

            return sum * h / 3.0;
        }

        double gauss_legendre_single(std::function<double(double)> f, double a, double b,
            const std::vector<double>& nodes, const std::vector<double>& weights) {
            if (nodes.size() != weights.size()) {
                throw std::invalid_argument("Nodes and weights must have same size");
            }

            double result = 0.0;
            double jacobian = (b - a) / 2.0;

            for (size_t i = 0; i < nodes.size(); i++) {
                double x = (b - a) * nodes[i] / 2.0 + (a + b) / 2.0;
                result += weights[i] * f(x);
            }

            return result * jacobian;
        }

        double gauss_legendre_composite(std::function<double(double)> f, double a, double b,
            const std::vector<double>& nodes, const std::vector<double>& weights, int subdivisions) {
            if (subdivisions <= 0) return 0.0;

            double h = (b - a) / subdivisions;
            double total = 0.0;

            for (int i = 0; i < subdivisions; i++) {
                double a_sub = a + i * h;
                double b_sub = a + (i + 1) * h;
                total += gauss_legendre_single(f, a_sub, b_sub, nodes, weights);
            }

            return total;
        }

    }
} // namespace NumLib::Integration