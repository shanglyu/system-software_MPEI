#include "complex.h"
#include <cmath>

namespace ComplexNumbers {
    ComplexNumber::ComplexNumber(double real, double imaginary)
        : real(real), imaginary(imaginary) {}

    double ComplexNumber::getReal() const {
        return real;
    }

    double ComplexNumber::getImaginary() const {
        return imaginary;
    }

    void ComplexNumber::setReal(double real) {
        this->real = real;
    }

    void ComplexNumber::setImaginary(double imaginary) {
        this->imaginary = imaginary;
    }

    ComplexNumber ComplexNumber::add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber ComplexNumber::subtract(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const {
        double newReal = (real * other.real) - (imaginary * other.imaginary);
        double newImaginary = (real * other.imaginary) + (imaginary * other.real);
        return ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber ComplexNumber::divide(const ComplexNumber& other) const {
        if (other.real == 0 && other.imaginary == 0) {
            throw "Division by zero is not allowed";
        }

        double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
        double newReal = ((real * other.real) + (imaginary * other.imaginary)) / divisor;
        double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / divisor;
        return ComplexNumber(newReal, newImaginary);
    }

    double ComplexNumber::modulus() const {
        return sqrt((real * real) + (imaginary * imaginary));
    }

    ComplexNumber ComplexNumber::power(int exponent) const {
        double magnitude = pow(modulus(), exponent);
        double angle = atan2(imaginary, real);
        double newReal = magnitude * cos(exponent * angle);
        double newImaginary = magnitude * sin(exponent * angle);
        return ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber ComplexNumber::squareRoot() const {
        double magnitude = sqrt(modulus());
        double angle = atan2(imaginary, real);
        double newReal = magnitude * cos(angle / 2);
        double newImaginary = magnitude * sin(angle / 2);
        return ComplexNumber(newReal, newImaginary);
    }

}