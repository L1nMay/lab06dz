#include "solver.h"
#include <iostream>

int main() {
    double a, b, c;

    std::cout << "Quadratic equation solver (ax^2 + bx + c = 0)\n";
    std::cout << "Enter coefficients a, b, c: ";
    std::cin >> a >> b >> c;

    std::string solution = solve_equation(a, b, c);
    std::cout << "Solution: " << solution << std::endl;

    return 0;
}

std::string solve_equation(double a, double b, double c) {
    if (a == 0) {
        return "Not a quadratic equation (a cannot be zero)";
    }

    double discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2*a);
        double x2 = (-b - sqrt(discriminant)) / (2*a);
        return "Two real roots: x1 = " + std::to_string(x1) + ", x2 = " + std::to_string(x2);
    }
    else if (discriminant == 0) {
        double x = -b / (2*a);
        return "One real root: x = " + std::to_string(x);
    }
    else {
        return "No real roots (complex solutions)";
    }
}
