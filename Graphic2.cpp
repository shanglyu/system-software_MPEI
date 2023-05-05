#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    // Constructor để khởi tạo nút với giá trị và con trỏ next.
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Graph {
public:
    Node* head;

    // Constructor để khởi tạo đồ thị với head là nullptr.
    Graph() {
        head = nullptr;
    }

    // Hàm để thêm một nút mới vào danh sách liên kết.
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Hàm để tìm một nút với giá trị đã cho.
    Node* findNode(int val) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->value == val) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    // Hàm để xóa một nút với giá trị đã cho.
    void removeNode(int val) {
        Node* nodeToRemove = findNode(val);
        if (nodeToRemove == nullptr) {
            return;
        }
        if (nodeToRemove == head) {
            head = nodeToRemove->next;
        }
        else {
            Node* curr = head;
            while (curr->next != nodeToRemove) {
                curr = curr->next;
            }
            curr->next = nodeToRemove->next;
        }
        delete nodeToRemove;
    }
    
    // Hàm để hiển thị tất cả các nút trong đồ thị.
    void showAllNodes() {
        cout << "All nodes in the graph: ";
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// Hàm để yêu cầu người dùng nhập một lựa chọn hợp lệ từ menu.
int AnalysChoose(string title, int a, int b)
{
    int choice;
    bool valid = false;

    while (!valid)
    {
        cout << title;
        cin >> choice;
        if (choice < a || choice > b || !cin.good())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Invalid input!!!" << endl;
        }
        else
        {
            valid = true;
        }
    }
    return choice;
}

// Hàm để hiển thị menu cho người dùng.
void Menu(){
    system("cls");
    cout << "1. Add a node" << endl;
    cout << "2. Find a node" << endl;
    cout << "3. Remove a node" << endl;
    cout << "4. Show all nodes" << endl;
    cout << "5. Quit" << endl;
}

// Hàm để hiển thị menu và cho phép người dùng thực hiện các lựa chọn từ menu.
void AnalysMenu() {
    Graph graph;

    while (1) {
        Menu();
        int choice = AnalysChoose("Enter your choice: ", 1, 5);
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value of the node to add: ";
                cin >> value;
                graph.addNode(value);
                cout << "Node added" << endl;
                system("pause");
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value of the node to find: ";
                cin >> value;
                Node* node = graph.findNode(value);
                if (node != nullptr) {
                    cout << "Node with value " << value << " found" << endl;
                }
                else {
                    cout << "Node with value " << value << " not found" << endl;
                }
                system("pause");
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value of the node to remove: ";
                cin >> value;
                graph.removeNode(value);
                cout << "Node removed" << endl;
                system("pause");
                break;
            }
            case 4: {
                graph.showAllNodes();
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                cout << "Exit!!!";
                exit(0);
        
            }
        }
    }
}

int main() {
    AnalysMenu();
    return 0;
}