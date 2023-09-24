#include <iostream>
#include <cmath>  
#include <vector>

using namespace std;

// Hàm giải SLAE bằng phương pháp Jacobi
vector<double> solveJacobi(const vector<vector<double>>& A, const vector<double>& b, double tolerance, int maxIterations) {
    int n = A.size();
    vector<double> x(n, 0.0); // Ước lượng ban đầu
    vector<double> xNew(n, 0.0);
    int iter = 0;
    double error = tolerance + 1.0; // Giá trị lỗi ban đầu

    while (error > tolerance && iter < maxIterations) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            xNew[i] = (b[i] - sum) / A[i][i];
        }

        error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(xNew[i] - x[i]);
        }

        x = xNew;
        iter++;
    }

    if (iter >= maxIterations) {
        cout << "Không tìm thấy nghiệm trong số lần lặp quy định." << endl;
    }

    return x;
}

int main() {
    // Ví dụ SLAE
    vector<vector<double>> A = {{4, 1, -1},
                                {2, 7, 1},
                                {1, -3, 12}};
    vector<double> b = {3, 19, 31};
    double tolerance = 1e-6;
    int maxIterations = 100;

    // Giải SLAE bằng phương pháp Jacobi
    vector<double> solution = solveJacobi(A, b, tolerance, maxIterations);

    // Xuất kết quả
    cout << "Nghiệm của SLAE:" << endl;
    for (int i = 0; i < solution.size(); i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}