#include <iostream>
#include <cmath>
using namespace std;

const int MAX_ITERATIONS = 100; // Số lần lặp tối đa

void JacobiMethod(int n, double A[][100], double b[], double x[], double epsilon)
{
    double x_new[100];
    double error = 0;
    int iterations = 0;

    do {
        // Sao chép giá trị x hiện tại sang x_new
        for (int i = 0; i < n; i++) {
            x_new[i] = x[i];
        }

        // Tính giá trị mới cho x
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        // Tính sai số
        error = 0;
        for (int i = 0; i < n; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        iterations++;
    } while (error > epsilon && iterations < MAX_ITERATIONS);

    if (iterations >= MAX_ITERATIONS) {
        cout << "Maximum number of iterations exceeded" << endl;
    } else {
        cout << "The approximate solution is: ";
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    double A[100][100];
    double b[100];
    double x[100];
    double epsilon;

    cout << "Enter the value of n:";
    cin >> n;

    cout << "Enter matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }

    cout << "Enter the value of epsilon: ";
    cin >> epsilon;

    // Khởi tạo giá trị ban đầu cho x
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    JacobiMethod(n, A, b, x, epsilon);

    return 0;
}