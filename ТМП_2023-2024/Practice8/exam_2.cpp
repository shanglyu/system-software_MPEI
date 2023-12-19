#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


template<typename T, typename KeyFunc>
unordered_map<T, int> generateAssociativeMap(const vector<T>& inputList, KeyFunc keyFunc) {
    unordered_map<T, int> resultMap;
    for (const auto& item : inputList) {
        T key = keyFunc(item);
        resultMap[key]++;
    }
    return resultMap;
}

// Hàm ví dụ: tính bình phương của một số nguyên
int square(int x) {
    return x * x;
}

int main() {
    vector<int> inputList = {1, 2, 3, 4, 5, 2, 3, 4, 5};

    unordered_map<int, int> resultMap = generateAssociativeMap(inputList, square);

    // In kết quả
    for (const auto& pair : resultMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}