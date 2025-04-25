#include "solver.h"
#include <iostream>

std::string solve_equation(double a, double b, double c) {
    if (a == 0) {
        return "Not a quadratic equation";
    }

    double discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2*a);
        double x2 = (-b - std::sqrt(discriminant)) / (2*a);
        return "Roots: " + std::to_string(x1) + ", " + std::to_string(x2);
    }
    else if (discriminant == 0) {
        double x = -b / (2*a);
        return "Double root: " + std::to_string(x);
    }
    else {
        return "No real roots";
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter coefficients a, b, c: ";
    std::cin >> a >> b >> c;
    std::cout << solve_equation(a, b, c) << std::endl;
    return 0;
}
