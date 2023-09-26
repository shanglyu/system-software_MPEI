#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to allocate memory for a matrix
int **allocateMatrix(int rows, int columns)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to fill a matrix with random values in a given range
void fillMatrix(int **matrix, int rows, int columns, int minVal, int maxVal)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int columns)
{
    int **result = allocateMatrix(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
int **scalarMultiplyMatrix(int **matrix, int rows, int columns, int scalar)
{
    int **result = allocateMatrix(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

// Function to transpose a matrix
int **transposeMatrix(int **matrix, int rows, int columns)
{
    int **result = allocateMatrix(columns, rows); // Swap rows and columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Function to display the menu
int displayMenu()
{
    int choice;
    system("cls");
    cout << "Matrix Operations Menu" << endl;
    cout << "----------------------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Scalar Multiplication" << endl;
    cout << "3. Transposition" << endl;
    cout << "4. Display Matrix" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void analyzeMenu(int choice, int **matrix1, int **matrix2, int rows, int columns)
{
    int **result = nullptr;

    switch (choice)
    {
    case 1:
        result = addMatrices(matrix1, matrix2, rows, columns);
        cout << "Result of addition:" << endl;
        printMatrix(result, rows, columns);
        system("pause");
        break;
    case 2:
        int scalar;
        cout << "Enter the scalar value: ";
        cin >> scalar;
        result = scalarMultiplyMatrix(matrix1, rows, columns, scalar);
        cout << "Result of scalar multiplication:" << endl;
        printMatrix(result, rows, columns);
        system("pause");
        break;
    case 3:
        result = transposeMatrix(matrix1, rows, columns);
        cout << "Result of transposition:" << endl;
        printMatrix(result, columns, rows);
        system("pause");
        break;
    case 4:
        // Display the matrices
        cout << "Matrix 1:" << endl;
        printMatrix(matrix1, rows, columns);
        cout << "Matrix 2:" << endl;
        printMatrix(matrix2, rows, columns);
        system("pause");
        break;
    case 5:
        exit(0); // Terminate the program
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    // Deallocate memory for the result matrix
    if (result != nullptr)
    {
        deallocateMatrix(result, rows);
    }
}

int main()
{
    srand(time(0));

    int rows, columns;
    cout << "Enter rows matrix: ";
    cin >> rows;
    cout << "Enter columns matrix: ";
    cin >> columns;

    // Allocate memory for the matrices
    int **matrix1 = allocateMatrix(rows, columns);
    int **matrix2 = allocateMatrix(rows, columns);

    // Fill the matrices with random values
    fillMatrix(matrix1, rows, columns, 1, 9);
    fillMatrix(matrix2, rows, columns, 1, 9);

    while (true)
    {
        int choice = displayMenu();
        analyzeMenu(choice, matrix1, matrix2, rows, columns);
    }

    // Deallocate memory for the matrices
    deallocateMatrix(matrix1, rows);
    deallocateMatrix(matrix2, rows);


    return 0;
}