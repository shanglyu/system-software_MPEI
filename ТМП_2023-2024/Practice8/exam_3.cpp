#include <iostream>

using namespace std;

// Định nghĩa cấu trúc của cây
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Hàm đệ quy để tính giá trị của một hàm cho tất cả các phần tử trong cây
template<typename T, typename Func>
void calculateFunctionValue(TreeNode* node, Func function) {
    if (node == nullptr) {
        return;
    }

    // Tính giá trị của hàm cho phần tử hiện tại và in ra màn hình
    T value = function(node->data);
    cout << "Function value for " << node->data << ": " << value << endl;

    // Đệ quy tính giá trị của hàm cho các phần tử trong cây con trái và cây con phải
    calculateFunctionValue<T, Func>(node->left, function);
    calculateFunctionValue<T, Func>(node->right, function);
}

// Hàm ví dụ: tính bình phương của một số nguyên
int square(int x) {
    return x * x;
}

int main() {
    // Xây dựng cây
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Tính giá trị của hàm bình phương cho tất cả các phần tử trong cây
    calculateFunctionValue<int, int(*)(int)>(root, square);

    // Giải phóng bộ nhớ
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}