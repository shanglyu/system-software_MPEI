#include <iostream>
#include "complex.h"

using namespace std;
using namespace ComplexNumbers;

int main()
{
    try
    {
        // Создание комплексных чисел
        ComplexNumber c1(2.0, 3.0);
        ComplexNumber c2(4.0, 5.0);

        // Взаимодействие с библиотекой
        ComplexNumber sum = c1.add(c2);
        ComplexNumber difference = c1.subtract(c2);
        ComplexNumber product = c1.multiply(c2);
        ComplexNumber quotient = c1.divide(c2);

        // Вывод результатов
        cout << "Sum: " << sum.getReal() << " + " << sum.getImaginary() << "i" << endl;
        cout << "Difference: " << difference.getReal() << " + " << difference.getImaginary() << "i" << endl;
        cout << "Product: " << product.getReal() << " + " << product.getImaginary() << "i" << endl;
        cout << "Quotient: " << quotient.getReal() << " + " << quotient.getImaginary() << "i" << endl;

        // Вычисление модуля и возведение в степень
        double modulus = c1.modulus();
        ComplexNumber power = c2.power(3);

        // Вывод результатов
        cout << "Modulus of c1: " << modulus << endl;
        cout << "c2 raised to the power of 3: " << power.getReal() << " + " << power.getImaginary() << "i" << endl;

    }
    catch (const char *error)
    {
        cout << "Error: " << error << endl;
    }

    return 0;
}