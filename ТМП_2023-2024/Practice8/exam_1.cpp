#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> applyFunction(const vector<T>& inputList, T (*func)(T)) {
    vector<T> result;
    for (const auto& item : inputList) {
        result.push_back(func(item));
    }
    return result;
}

// Hàm ví dụ: tính bình phương của một số nguyên
int square(int x) {
    return x * x;
}

int main() {
    vector<int> inputList = {1, 2, 3, 4, 5};

    vector<int> result = applyFunction(inputList, square);

    // In kết quả
    for (const auto& item : result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}