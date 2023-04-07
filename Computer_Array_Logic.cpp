#include <iostream>
#include <cmath>

using namespace std;

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
    cout << "\t1.Array pointer exercise" << endl;
    cout << "\t2.Matrix calculation" << endl;
    cout << "\t3.Exit!" << endl;
}

// part1
void Practice_Array()
{
    int N = 3;

    // Задайте переменную со значением N
    cout << "N = " << N << endl;

    // Выведите адрес переменной
    cout << "Address of N: " << &N << endl;

    // Создайте указатель на эту переменную
    int *ptrN = &N;

    // Выведите значение указателя
    cout << "Value of pointer ptrN: " << ptrN << endl;

    // Выведите значение, на которое ссылается указатель
    cout << "Value pointed to by ptrN: " << *ptrN << endl;

    // Создайте указатель на предыдущий указатель
    int **ptrptrN = &ptrN;

    // Выведите значение указателя на указатель
    cout << "Value of pointer ptrptrN: " << ptrptrN << endl;

    // Создайте динамический массив
    int *arr = new int[N];

    // Задайте значения элементов массива
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    // Выведите значения элементов массива
    cout << "Values of array arr: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Создайте указатель на массив
    int *ptrArr = arr;

    // Выведите значение указателя на массив
    cout << "Value of pointer ptrArr: " << ptrArr << endl;

    // Выведите значение, на которое ссылается указатель на массив
    cout << "Value pointed to by ptrArr: " << *ptrArr << endl;

    // Создайте указатель на указатель на массив
    int **ptrptrArr = &ptrArr;

    // Выведите значение указателя на указатель на массив
    cout << "Value of pointer ptrptrArr: " << ptrptrArr << endl;

    // Освободите память, выделенную для массива
    delete[] arr;
}

void deleteMatrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Hàm tính định thức của ma trận
double determinant(double **matrix, int n)
{
    double det = 0;
    double **submat = new double *[n];
    for (int i = 0; i < n; i++)
    {
        submat[i] = new double[n];
    }
    if (n == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submat[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submat, n - 1));
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] submat[i];
    }
    delete[] submat;
    return det;
}

// Hàm tính ma trận phụ của một phần tử trong ma trận
void getCofactor(double **matrix, double **temp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Hàm tính ma trận nghịch đảo
void inverse(double **matrix, double **inv, int n)
{
    double det = determinant(matrix, n);
    if (det == 0)
    {
        cout << "Ma tran khong kha nghich" << endl;
        return;
    }
    double **temp = new double *[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(matrix, temp, i, j, n);
            inv[j][i] = (pow(-1, i + j) * determinant(temp, n - 1)) / det;
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
}

// Hàm in ma trận
void printMatrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Thực hiện tính ma trận nghịch đảo
void CaculationMatrix()
{
    int n;
    double **matrix, **inv;
    cout << "Enter the matrix size : ";
    cin >> n;
    matrix = new double *[n];
    inv = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
        inv[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "Original Matrix" << endl;
    printMatrix(matrix, n);
    inverse(matrix, inv, n);
    cout << "Inverser Matrix" << endl;
    printMatrix(inv, n);
    deleteMatrix(matrix, n);
    deleteMatrix(inv, n);
}

// Hàm chọn menu xử lý tính toán ma trận nghịch đảo
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


