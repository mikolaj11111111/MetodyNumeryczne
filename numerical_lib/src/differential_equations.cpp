#include "../include/differential_equations.h"
#include <stdexcept>

namespace NumLib {
    namespace DifferentialEquations {

        ODEResult euler_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
            if (h <= 0 || t_end <= t0) {
                throw std::invalid_argument("Invalid parameters");
            }

            ODEResult result;
            double t = t0;
            double y = y0;

            result.t.push_back(t);
            result.y.push_back(y);

            while (t < t_end) {
                if (t + h > t_end) {
                    h = t_end - t;
                }

                y = y + h * f(t, y);
                t = t + h;

                result.t.push_back(t);
                result.y.push_back(y);
            }

            return result;
        }

        ODEResult heun_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
            if (h <= 0 || t_end <= t0) {
                throw std::invalid_argument("Invalid parameters");
            }

            ODEResult result;
            double t = t0;
            double y = y0;

            result.t.push_back(t);
            result.y.push_back(y);

            while (t < t_end) {
                if (t + h > t_end) {
                    h = t_end - t;
                }

                double k1 = h * f(t, y);
                double y_test = y + k1;
                double k2 = h * f(t + h, y_test);

                y = y + (k1 + k2) / 2.0;
                t = t + h;

                result.t.push_back(t);
                result.y.push_back(y);
            }

            return result;
        }

        ODEResult midpoint_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
            if (h <= 0 || t_end <= t0) {
                throw std::invalid_argument("Invalid parameters");
            }

            ODEResult result;
            double t = t0;
            double y = y0;

            result.t.push_back(t);
            result.y.push_back(y);

            while (t < t_end) {
                if (t + h > t_end) {
                    h = t_end - t;
                }

                double k1 = h * f(t, y);
                double y_test = y + k1 / 2.0;
                double k2 = h * f(t + h / 2.0, y_test);

                y = y + k2;
                t = t + h;

                result.t.push_back(t);
                result.y.push_back(y);
            }

            return result;
        }

        ODEResult runge_kutta_4(std::function<double(double, double)> f, double y0, double t0, double t_end, double h) {
            if (h <= 0 || t_end <= t0) {
                throw std::invalid_argument("Invalid parameters");
            }

            ODEResult result;
            double t = t0;
            double y = y0;

            result.t.push_back(t);
            result.y.push_back(y);

            while (t < t_end) {
                if (t + h > t_end) {
                    h = t_end - t;
                }

                double k1 = h * f(t, y);
                double k2 = h * f(t + h / 2.0, y + k1 / 2.0);
                double k3 = h * f(t + h / 2.0, y + k2 / 2.0);
                double k4 = h * f(t + h, y + k3);

                y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
                t = t + h;

                result.t.push_back(t);
                result.y.push_back(y);
            }

            return result;
        }

    }
} // namespace NumLib::DifferentialEquations