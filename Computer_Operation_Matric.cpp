#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define N 3 // Номер журнал
#define MAX 20

using namespace std;

void Show_Array(string title, int arr[], int n)
{
    cout << title << " = {";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << arr[i] << "}" << endl;
        }
        else
        {
            cout << arr[i] << ", ";
        }
    }
    cout << "" << endl;
}

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
    cout << "\t---------Menu----------" << endl;
    cout << "\t1.Array exercise" << endl;
    cout << "\t2.Matrix calculation" << endl;
    cout << "\t3.Exit!" << endl;
}

void Practice_Array()
{
    int arr[MAX];
    int sum = 0;
    cout << "\t#----------------------------Exercises N=3---------------------------#" << endl;
    // Задание 2: Заполняем массив от 1 до N+10
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = i + 1;
    }
    Show_Array("Array from 1 to N+10: Array", arr, N + 10);
    // Задание 3: Считаем сумму элементов массива
    for (int i = 0; i < N + 10; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of elements in array: Sum= " << sum << "\n\n";

    // Задание 4: Удваиваем значение каждого четного элемента массива
    for (int i = 0; i < N + 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[i] *= 2;
        }
    }
    Show_Array("The value of each even array element: Array", arr, N + 10);

    // Задание 5: Для N < 10 возводим каждый нечетный элемент массива в степень N
    for (int i = 0; i < N + 10; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr[i] = pow(arr[i], N);
        }
    }
    Show_Array("Raise each odd array element to the N power: Array", arr, N + 10);

    // Задание 6: Выводим массив на экран
    Show_Array("Show Array: arr", arr, N + 10);

    // Задание 7: Записываем в тот же массив его значения в обратном порядке
    for (int i = 0; i < (N + 10) / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[N + 10 - i - 1];
        arr[N + 10 - i - 1] = temp;
    }
    Show_Array("Write to the same array its values in reverse order: Array", arr, N + 10);

    // Задание 8: Очищаем массив, заполняя его числом N
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = 0;
    }
    Show_Array("Clearing the array: Array", arr, N + 10);

    // Задание 9: Заполняем массив случайными значениями
    srand(time(NULL)); // Инициализируем генератор случайных чисел
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = rand() % 100; // Генерируем случайное число от 0 до 99
    }
    Show_Array("Filling an array with random values: Array", arr, N + 10);

    // Задание 10: Сортируем массив по возрастанию, используя алгоритм пузырьковой сортировки
    for (int i = 0; i < N + 10 - 1; i++)
    {
        for (int j = 0; j < N + 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    Show_Array("Sort the array in any way: Arr", arr, N + 10);
    cout << "\t-------------------------#############-------------------------" << endl;
}

void inputMatrix(int **&matrix, int &n, int &m) // Nhận ma trận từ người dùng
{
    do
    {
        cout << "Enter number of rows in matrix: ";
        cin >> n;
        cout << "Enter number of columns in matrix: ";
        cin >> m;
    } while (n < 0 && m < 0);
    // Khởi tạo mảng động với số lượng hàng và cột tương ứng
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }

    // Nhập giá trị cho ma trận
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Matrix[" << i + 1 << "," << j + 1 << "]:";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int **&matrix, int **&transpose, int n, int m) // Chuyển vị ma trận
{
    // Khởi tạo mảng động transpose với số lượng hàng và cột tương ứng
    transpose = new int *[m];
    for (int i = 0; i < m; i++)
    {
        transpose[i] = new int[n];
    }

    // Transpose matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int **&matrix, int n, int m, string message) // Hiển thị ma trận
{
    // Hiển thị ma trận ban đầu hoặc ma trận chuyển vị
    cout << endl
         << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void clearMemory(int **&matrix, int **&transpose, int n, int m) // Giải phóng bộ nhớ
{
    // Giải phóng bộ nhớ của các mảng động
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (int i = 0; i < m; i++)
    {
        delete[] transpose[i];
    }
    delete[] transpose;
}

void CaculationMatrix()
{
    int **matrix, **transpose;
    int n, m;
    system("cls");
    inputMatrix(matrix, n, m); // Nhập ma trận
    transposeMatrix(matrix, transpose, n, m);
    system("cls");                                       // Chuyển vị ma trận
    printMatrix(matrix, n, m, "Original Matrix: ");      // Hiển thị ma trận ban đầu
    printMatrix(transpose, m, n, "Transposed Matrix: "); // Hiển thị ma trận chuyển vị
    clearMemory(matrix, transpose, n, m);                // Giải phóng bộ nhớ
}

void AnalysMenu()
{
    while (1)
    {
        Menu();
        int choice = AnalysChoose("Enter your choice: ", 1, 3);
        switch (choice)
        {
        case 1:
            system("cls");
            Practice_Array();
            system("pause");
            break;
        case 2:
            system("cls");
            CaculationMatrix();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Exit!!!";
            exit(0);
            break;
        }
    }
}

int main()
{
    AnalysMenu();
    return 0;
}