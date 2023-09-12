#include "graph.h"
#include <iostream>

using namespace std;

Node::Node(int val) {
    value = val;
    next =nullptr;
}

Graph::Graph() {
    head = nullptr;
}

void Graph::addNode(int val) {
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

Node* Graph::findNode(int val) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->value == val) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void Graph::removeNode(int val) {
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

void Graph::showAllNodes() {
    cout << "All nodes in the graph: ";
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}