#ifndef GRAPH_H
#define GRAPH_H

class Node {
public:
    int value;
    Node* next;

    Node(int val);
};

class Graph {
public:
    Node* head;

    Graph();

    void addNode(int val);
    Node* findNode(int val);
    void removeNode(int val);
    void showAllNodes();
};

#endif