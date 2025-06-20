#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

void EnteringPartitions(int32_t&);
double CountingsingATrapezoid(double, double, int32_t, double (*)(double));
double CountingLeftRectangles(double, double, int32_t, double (*)(double));
double CountingRightRectangles(double, double, int32_t, double (*)(double));
double CountingSimpson(double, double, int32_t, double (*)(double));
double CalculationByAverageRectangles(double, double, int32_t, double (*)(double));
double function1(double);
double function2(double);
double function3(double);

int main()
{
    double infinum1{ 0 };
    double maximum1{ 0.8 };
    double maximum2{ 1.8 };
    double maximum3{ 0.3 };
    double integral1{};
    double integral2{};
    int32_t degree{};

    double (*functions[3])(double) { function1, function2, function3 };
    double (*integrals[5]) (double, double, int32_t, double (*)(double)) { CountingLeftRectangles, CountingRightRectangles, CountingSimpson, CountingsingATrapezoid, CalculationByAverageRectangles };

    EnteringPartitions(degree);
    double epsilon{ pow(10, -degree) };

    for (size_t i = 0; i < 3; ++i) {
        double infinum = infinum1;
        double maximum = (i == 0) ? maximum1 : (i == 1) ? maximum2 : maximum3;

        for (size_t j = 0; j < 5; ++j) {
            int32_t num{ 10 };
            integral1 = integrals[j](infinum, maximum, num, functions[i]);
            integral2 = 0;

            while (fabs(integral1 - integral2) > epsilon) {
                num *= 2;
                integral2 = integral1;
                integral1 = integrals[j](infinum, maximum, num, functions[i]);
            }

            std::cout << "Function " << i + 1 << " with method " << j + 1 << ": " << integral1 << "\n";
        }
    }

    return 0;
}

void EnteringPartitions(int32_t& degree)
{
    std::cout << "enter the number of digits after the decimal point for epsilon:\n";
    std::cin >> degree;
}

double function1(double x)
{
    return pow(x, 3) * pow(M_E, 2 * x);
}

double function2(double x)
{
    return 1 / (1 + sqrt(x));
}

double function3(double x)
{
    return 1 / ((x + 1) * sqrt(x * x + 1));
}

double CountingsingATrapezoid(double infinum, double maximum, int32_t num, double (*func)(double))
{
    double height = (maximum - infinum) / num;
    double sum{};
    for (int32_t i = 1; i < num; ++i)
    {
        sum += func(infinum + i * height);
    }
    sum += (func(infinum) + func(maximum)) / 2;
    return height * sum;
}

double CountingLeftRectangles(double infinum, double maximum, int32_t num, double (*func)(double))
{
    double height = (maximum - infinum) / num;
    double sum{};
    for (int32_t i = 0; i < num; ++i)
    {
        sum += func(infinum + i * height);
    }
    return height * sum;
}

double CountingRightRectangles(double infinum, double maximum, int32_t num, double (*func)(double))
{
    double height = (maximum - infinum) / num;
    double sum{};
    for (int32_t i = 1; i <= num; ++i)
    {
        sum += func(infinum + i * height);
    }
    return height * sum;
}

double CountingSimpson(double infinum, double maximum, int32_t num, double (*func)(double))
{
    if (num % 2 != 0)
    {
        std::cout << "The number of partitions must be even\n";
        return 0;
    }
    double height = (maximum - infinum) / num;
    double sum = func(infinum) + func(maximum);
    for (int32_t i = 1; i < num; i += 2)
    {
        sum += 4 * func(infinum + i * height);
    }
    for (int32_t i = 2; i < num; i += 2)
    {
        sum += 2 * func(infinum + i * height);
    }
    return (height / 3) * sum;
}

double CalculationByAverageRectangles(double infinum, double maximum, int32_t num, double (*func)(double))
{
    double height = (maximum - infinum) / num;
    double sum{};
    for (int32_t i = 0; i < num; ++i)
    {
        double mid = infinum + (i + 0.5) * height;
        sum += func(mid);
    }
    return sum * height;
}