#include <iostream>
#include <cmath>
using namespace std;

typedef float matrix[100][100];
typedef float array[100];

void Value(int& n, matrix& a, array& b)
{
    cout << "Nhap cap n = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            float t;
            cout << "a[" << i << "][" << j << "] = ";
            cin >> t;
            a[i][j] = t;
        }
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
}

void jacobi(matrix& a, array& b, array& x, int n, float epsilon, int maxIterations)
{
    array x_new;
    int iterations = 0;
    float error = epsilon + 1;

    while (error > epsilon && iterations < maxIterations)
    {
        for (int i = 1; i <= n; i++)
        {
            float sum = 0;
            for (int j = 1; j <= n; j++)
            {
                if (j != i)
                {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        error = 0;
        for (int i = 1; i <= n; i++)
        {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        iterations++;
    }

    if (iterations >= maxIterations)
    {
        cout << "Khong tim thay nghiem trong so lan lap toi da." << endl;
    }
    else
    {
        cout << "Nghiem gan dung: ";
        for (int i = 1; i <= n; i++)
        {
            cout << "x[" << i << "] = " << x[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    matrix a;
    array b, x;
    int n;
    float epsilon;
    int maxIterations;

    Value(n, a, b);

    cout << "Nhap sai so epsilon: ";
    cin >> epsilon;

    cout << "Nhap so lan lap toi da: ";
    cin >> maxIterations;

    for (int i = 1; i <= n; i++)
    {
        x[i] = 0; // Khởi tạo nghiệm ban đầu
    }

    jacobi(a, b, x, n, epsilon, maxIterations);

    return 0;
}