#include <iostream>

using namespace std;

class Heap
{
private:
    int *heapArray;
    int maxSize;
    int currentSize;

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < currentSize && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < currentSize && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != i)
        {
            swap(heapArray[i], heapArray[largest]);
            heapify(largest);
        }
    }

public:
    Heap(int size)
    {
        maxSize = size;
        currentSize = 0;
        heapArray = new int[maxSize];
    }

    ~Heap()
    {
        delete[] heapArray;
    }

    void insertNode(int value)
    {
        if (currentSize == maxSize)
        {
            cout << "Heap is full. Cannot insert more nodes." << endl;
            return;
        }

        int i = currentSize;
        heapArray[i] = value;

        while (i > 0 && heapArray[i] > heapArray[(i - 1) / 2])
        {
            swap(heapArray[i], heapArray[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        currentSize++;
        cout << "Node inserted successfully." << endl;
    }

    void searchNode(int value)
    {
        bool found = false;
        for (int i = 0; i < currentSize; i++)
        {
            if (heapArray[i] == value)
            {
                found = true;
                cout << "Node found at index " << i << endl;
            }
        }

        if (!found)
            cout << "Node not found in the heap." << endl;
    }

    void deleteNode(int value)
    {
        int i;
        for (i = 0; i < currentSize; i++)
        {
            if (heapArray[i] == value)
                break;
        }

        if (i == currentSize)
        {
            cout << "Node not found in the heap." << endl;
            return;
        }

        heapArray[i] = heapArray[currentSize - 1];
        currentSize--;

        heapify(i);

        cout << "Node deleted successfully." << endl;
    }

    void displayHeap()
    {
        if (currentSize == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Nodes in the heap: ";
        for (int i = 0; i < currentSize; i++)
        {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

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

void Menu()
{
    system("cls");
    cout << "----- Menu -----" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Search for a node" << endl;
    cout << "3. Delete a node" << endl;
    cout << "4. Display the heap" << endl;
    cout << "5. Exit" << endl;
    cout << "-----------------" << endl;
}

int main()
{
    int maxSize;
    cout << "Enter the maximum size of the heap: ";
    cin >> maxSize;

    Heap heap(maxSize);
    int value;

    while(1)
    {
        Menu();
        int choice = AnalysChoose("Enter your choice: ", 1, 5);

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            heap.insertNode(value);
            system("pause");
            break;

        case 2:
            cout << "Enter the value to search for: ";
            cin >> value;
            heap.searchNode(value);
            system("pause");
            break;

        case 3:
            cout << "Enter the value to be deleted: ";
            cin >> value;
            heap.deleteNode(value);
            system("pause");
            break;

        case 4:
            heap.displayHeap();
            system("pause");
            break;

        case 5:
            cout << "Exiting...";
            exit(0);
            break;
        }
    } 

    return 0;
}