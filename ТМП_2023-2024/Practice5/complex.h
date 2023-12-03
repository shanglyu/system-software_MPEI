#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

namespace ComplexNumbers {
    class ComplexNumber {
    private:
        double real;
        double imaginary;

    public:
        ComplexNumber(double real, double imaginary);

        // Геттеры и сеттеры
        double getReal() const;
        double getImaginary() const;
        void setReal(double real);
        void setImaginary(double imaginary);

        ComplexNumber add(const ComplexNumber& other) const;
        ComplexNumber subtract(const ComplexNumber& other) const;
        ComplexNumber multiply(const ComplexNumber& other) const;
        ComplexNumber divide(const ComplexNumber& other) const;
        double modulus() const;
        ComplexNumber power(int exponent) const;
        ComplexNumber squareRoot() const;

    };
}

#endif  // COMPLEX_NUMBER_H