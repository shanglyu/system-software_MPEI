#include "graph.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    Graph graph;

    // Add nodes based on command line arguments
    for (int i = 1; i < argc; i++) {
        graph.addNode(atoi(argv[i]));
    }

    while (1) {
        cout << "1. Add a node" <<endl;
        cout << "2. Find a node" << endl;
        cout << "3. Remove a node" << endl;
        cout << "4. Show all nodes" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value of the node to add: ";
                cin >> value;
                graph.addNode(value);
                cout << "Node added" << endl;
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
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value of the node to remove: ";
                cin >> value;
                graph.removeNode(value);
                cout << "Node removed" << endl;
                break;
            }
            case 4: {
                graph.showAllNodes();
                break;
            }
            case 5: {
                cout << "Exit!!!" <<endl;
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}