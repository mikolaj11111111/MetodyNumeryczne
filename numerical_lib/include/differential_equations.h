#pragma once
#include <vector>
#include <functional>

namespace NumLib {
    namespace DifferentialEquations {

        struct ODEResult {
            std::vector<double> t;
            std::vector<double> y;
        };

        // Metody numeryczne
        ODEResult euler_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);
        ODEResult heun_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);
        ODEResult midpoint_method(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);
        ODEResult runge_kutta_4(std::function<double(double, double)> f, double y0, double t0, double t_end, double h);

    }
} // namespace NumLib::DifferentialEquations