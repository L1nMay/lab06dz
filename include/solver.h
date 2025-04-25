#pragma once

#include <string>

/**
 * @brief Solves quadratic equation ax^2 + bx + c = 0
 * @param a Coefficient for x^2
 * @param b Coefficient for x
 * @param c Constant term
 * @return String with solution or error message
 */
std::string solve_equation(double a, double b, double c);
