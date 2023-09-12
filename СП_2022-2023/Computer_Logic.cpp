#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <locale.h>

using namespace std;

void Menu()
{
	system("cls");
	cout << "=============MENU============\n";
	cout << "\t1. Arithmetic Operators\n";
	cout << "\t2. Perform trigonometric Operators\n";
	cout << "\t3. Logical Operators\n";
	cout << "\t4. Calculate the power of a number\n";
	cout << "\t5. Calculate factorial\n";
	cout << "\t6. Calculate natural logarithm\n";
	cout << "\t7. Find the least common multiple and the greatest common divisor of two numbers\n";
	cout << "\t8. Have the ability to convert a number from a user-defined number system to another\n";
	cout << "\t9. Find the area of a regular n-gon along a given side\n";
	cout << "\t10.Find quadratic equation\n";
	cout << "\t11.Exit!!!\n";
	cout << "=====================================\n";
}

void submenu()
{
	system("cls");
	cout << "=============Arithmetic Operators============\n";
	cout << "\t1. Addition\n";
	cout << "\t2. Subtraction\n";
	cout << "\t3. Multiplication\n";
	cout << "\t4. Division\n";
	cout << "\t5. Back to menu\n";
	cout << "\t6. Exit\n";
}

void submenu2()
{
	system("cls");
	cout << "=============Perform trigonometric operators============\n";
	cout << "\t1. Sin(x) operator\n";
	cout << "\t2. Cos(x) operator\n";
	cout << "\t3. Tan(x) operator\n";
	cout << "\t4. Cotan(x) operator\n";
	cout << "\t5. Back to menu\n";
	cout << "\t6. Exit\n";
}

void submenu3()
{
	system("cls");
	cout << "=============Logical Operators============\n";
	cout << "\t1. AND(Decimal)\n";
	cout << "\t2. OR(Decimal)\n";
	cout << "\t3. XOR(Decimal)\n";
	cout << "\t4. NOT(Decimal)\n";
	cout << "\t5. Back to menu\n";
	cout << "\t6. Exit\n";
}
void submenu4()
{
	system("cls");
	cout << "=============Greatest common divisor - Least common multiple============\n";
	cout << "\t1. Greatest common divisor\n";
	cout << "\t2. Least common multiple\n";
	cout << "\t3. Back to menu\n";
	cout << "\t4. Exit\n";
}
void submenu5()
{
	system("cls");
	cout << "=============Radix conversion============\n";
	cout << "\t1. Binary to Decimal, Hexdecimal\n";
	cout << "\t2. Decimal to Binary, Hexdecimal\n";
	cout << "\t3. Hexdecimal to Binary, Decimal\n";
	cout << "\t4. Back to menu\n";
	cout << "\t5. Exit\n";
}

void erithmetic()
{
	int a, b, vvod1;
	// bool done = false;
	while (1)
	{
		submenu();
		cout << "Please choose the calculation: ";
		cin >> vvod1;
		if (vvod1 > 0 & vvod1 < 5)
		{
			cout << "The value of a: ";
			cin >> a;
			cout << "The value of b: ";
			cin >> b;
		}
		else if (vvod1 == 5)
		{
			// done = true;
			break;
		}
		else if (vvod1 == 6)
		{
			cout << "Exit\n";
			exit(0);
		}
		else
		{
			continue;
		}
		switch (vvod1)
		{
		case 1:
			cout << "The sum of two numbers is:" << a + b << "\n";
			system("pause");
			break;
		case 2:
			cout << "The difference of two numbers is:" << a - b << "\n";
			system("pause");
			break;
		case 3:
			cout << "The product of two numbers is:" << a * b << "\n";
			system("pause");
			break;
		case 4:
			if (b == 0)
			{
				erithmetic();
			}
			cout << "The quotient of two numbers is:" << a / b << "\n";
			system("pause");
			break;
		}
	}
}

void trigonometric()
{
	int vvod2;
	float goc, g;
	bool done = false;
	while (!done)
	{
		submenu2();
		cout << "Please choose the calculation:: ";
		cin >> vvod2;
		if (vvod2 > 0 & vvod2 < 5)
		{
			cout << "Value of angle:: ";
			cin >> goc;
			// g = (goc*3.14)/180;
		}
		else if (vvod2 == 5)
		{
			done = true;
		}
		else if (vvod2 == 6)
		{
			cout << "Exit\n";
			exit(0);
		}
		else
		{
			continue;
		}
		switch (vvod2)
		{
		case 1:
			cout << "Sin(" << goc << ") = " << sin(goc) << endl;
			system("pause");
			break;
		case 2:
			cout << "Cos(" << goc << ") = " << cos(goc) << endl;
			system("pause");
			break;
		case 3:

			cout << "Tan(" << goc << ") = " << tan(goc) << endl;
			system("pause");
			break;
		case 4:
			cout << "Cot(" << goc << ") = " << 1 / tan(goc) << endl;
			system("pause");
			break;
		}
	}
}

void DectoBin(long n)
{
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0)
	{

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}
long DectoHex(long num)
{
	int temp, i = 1, j, r;
	char hex[50];
	temp = num;
	while (temp != 0)
	{
		r = temp % 16;
		if (r < 10)
			hex[i++] = r + 48;
		else
			hex[i++] = r + 55;
		temp = temp / 16;
	}
	cout << "Value of Decimal to Hexdecimal: ";
	for (j = i; j > 0; j--)
		cout << hex[j];
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++\n";
	return 0;
}
int BinToDec(long long binaryNumber)
{
	int p = 0, decNumber = 0;
	while (binaryNumber > 0)
	{
		decNumber += (binaryNumber % 10) * pow(2, p);
		++p;
		binaryNumber /= 10;
	}
	return decNumber;
}
int BintoHex(int binaryNumber)
{
	int hex[1000];
	int i = 1, j = 0, rem, dec = 0;
	while (binaryNumber > 0)
	{
		rem = binaryNumber % 2;
		dec = dec + rem * i;
		i = i * 2;
		binaryNumber = binaryNumber / 10;
	}
	i = 0;
	while (dec != 0)
	{
		hex[i] = dec % 16;
		dec = dec / 16;
		i++;
	}
	cout << "Value of Binary to Hexdecimal: ";
	for (j = i - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
		{
			cout << (char)(hex[j] + 55);
		}
		else
		{
			cout << hex[j];
		}
	}
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	return 0;
}

int HextoDec(string hexVal)
{

	int len = hexVal.size();

	// Initializing base value to 1, i.e 16^0
	int base = 1, dec_val = 0;

	// Extracting characters as digits from last
	// character
	for (int i = len - 1; i >= 0; i--)
	{
		// if character lies in '0'-'9', converting
		// it to integral 0-9 by subtracting 48 from
		// ASCII value
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (int(hexVal[i]) - 48) * base;

			// incrementing base by power
			base = base * 16;
		}

		// if character lies in 'A'-'F' , converting
		// it to integral 10 - 15 by subtracting 55
		// from ASCII value
		else if ((hexVal[i] >= 'A' && hexVal[i] <= 'F') || (hexVal[i] >= 'a' & hexVal[i] <= 'f'))
		{
			dec_val += (int(hexVal[i]) - 55) * base;

			// incrementing base by power
			base = base * 16;
		}
	}
	return dec_val;
}
int HexToBin(string hexa)
{
	long int i = 0;
	while (hexa[i])
	{
		switch (hexa[i])
		{
		case '0':
			cout << "0000";
			break;
		case '1':
			cout << "0001";
			break;
		case '2':
			cout << "0010";
			break;
		case '3':
			cout << "0011";
			break;
		case '4':
			cout << "0100";
			break;
		case '5':
			cout << "0101";
			break;
		case '6':
			cout << "0110";
			break;
		case '7':
			cout << "0111";
			break;
		case '8':
			cout << "1000";
			break;
		case '9':
			cout << "1001";
			break;
		case 'A':
		case 'a':
			cout << "1010";
			break;
		case 'B':
		case 'b':
			cout << "1011";
			break;
		case 'C':
		case 'c':
			cout << "1100";
			break;
		case 'D':
		case 'd':
			cout << "1101";
			break;
		case 'E':
		case 'e':
			cout << "1110";
			break;
		case 'F':
		case 'f':
			cout << "1111";
			break;
		default:
			cout << "\nPlease enter valid hexadecimal digit " << hexa[i];
		}
		i++;
	}
}

int UCLN(int a, int b)
{
	if (b == 0)
		return a;		   // Sau đệ quy lúc này kiểm tra b chính là a%b được truyền vào tức nó chính là r, còn a chính là b được truyền vào
	return UCLN(b, a % b); // Gọi lại hàm đệ quy tính UCLN giữa b và r
}

int BCNN(int a, int b)
{
	int c;
	c = UCLN(a, b);
	return (a * b) / c;
}

void menulogicbit()
{
	int vvod3, a, b;
	bool done = false;
	while (!done)
	{
		submenu3();
		cout << "Please choose function: ";
		cin >> vvod3;
		if (vvod3 >= 1 && vvod3 <= 3)
		{
			cout << "The value of a: ";
			cin >> a;
			cout << "The value of b: ";
			cin >> b;
		}
		else if (vvod3 == 4)
		{
			cout << "The value of a: ";
			cin >> a;
		}
		else if (vvod3 == 5)
		{
			done = true;
			break;
		}
		else if (vvod3 != 6)
		{
			continue;
		}
		switch (vvod3)
		{
		case 1:
			cout << "Value A&B: " << (a & b) << "\n";
			system("pause");
			break;
		case 2:
			cout << "Value A~B:" << (a | b) << "\n";
			system("pause");
			break;
		case 3:
			cout << "Value A^B:" << (a ^ b) << "\n";
			system("pause");
			break;
		case 4:
			cout << "Value ~A:" << (~a) << "\n";
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Exit!!!";
			exit(0);
			break;
		}
	}
}

void exponential()
{
	long long a, b, result;
	cout << "======Exponential Calculations(a^b)======\n";
	cout << "The value of a: ";
	cin >> a;
	cout << "Please enter the exponent b: ";
	cin >> b;
	result = pow(a, b);
	cout << "Exponential " << a << "^" << b << "= " << result << "\n";
	system("pause");
}

void logarithm()
{
	float a, x, result;
	cout << "=======Calculation program LOG a (X)==========\n";
	cout << "The value of a: ";
	cin >> a;
	cout << "The value of X: ";
	cin >> x;
	if (a < 0 & a == 1 & x < 0)
	{
		system("cls");
		cout << "You entered it wrong, please re-enter it!!!\n";
		logarithm();
	}
	else
	{
		result = log(x) / log(a);
		cout << "Logarit LOG" << a << "(" << x << "): " << result << "\n";
		system("pause");
	}
}
void factorial()
{
	int n;
	long giaiThua = 1;
	cout << "Program to calculate factorial\n";
	cout << "The value of n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		giaiThua = giaiThua * i;
	}
	cout << "The factorial of " << n << " is " << giaiThua << endl;
	system("pause");
}

void UclnBcnn()
{
	int vvod4, a, b;
	bool done = false;
	while (!done)
	{
		submenu4();
		cout << "Please choose the calculation: ";
		cin >> vvod4;
		if (vvod4 > 0 & vvod4 < 3)
		{
			cout << "The value of a: ";
			cin >> a;
			cout << "The value of b: ";
			cin >> b;
		}
		else if (vvod4 == 3)
		{
			done = true;
			break;
		}
		else if (vvod4 == 4)
		{
			cout << "Exit\n";
			exit(0);
		}
		else
		{
			continue;
		}
		switch (vvod4)
		{
		case 1:
			cout << "The GCD of " << a << " and " << b << " is: " << UCLN(a, b) << "\n";
			system("pause");
			break;
		case 2:
			cout << "The LCM of " << a << " and " << b << " is: " << BCNN(a, b) << "\n";
			system("pause");
			break;
		}
	}
}

void Bin2Dec2Hex()
{
	int vvod5;
	long long a;
	string s;
	bool done = false;
	while (!done)
	{
		submenu5();
		cout << "Please choose function: ";
		cin >> vvod5;
		if (vvod5 == 1 || vvod5 == 2)
		{
			cout << "Please enter the value: ";
			cin >> a;
		}
		else if (vvod5 == 3)
		{
			cout << "Please enter the value: ";
			cin >> s;
		}

		else if (vvod5<1 & vvod5> 4)
		{
			system("cls");
			cout << "Enter incorrectly, please re-enter!!!";
			Bin2Dec2Hex();
		}
		else if (vvod5 == 4)
		{
			done = true;
			break;
		}
		else if (vvod5 == 5)
		{
			cout << "Exit\n";
			exit(0);
		}
		switch (vvod5)
		{
		case 1:
			system("cls");
			cout << "Value of Binary to Decimal: " << BinToDec(a) << "\n";
			cout << BintoHex(a) << "\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Value of Decimal to Binary: ";
			DectoBin(a);
			cout << "\n";
			cout << DectoHex(a) << "\n";
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Value of Hexdecimal to Decimal: " << HextoDec(s) << "\n";
			cout << "Value of Hexdecimal to Binary: ";
			HexToBin(s);
			cout << "\n";
			system("pause");
			break;
		}
	}
}

void AreaNGon()
{
	int a, n;
	float s;
	cout << "How many scenes do you want to calculate the area of a regular polygon: ";
	cin >> n;
	cout << "What is the length of each side of the polygon (M): ";
	cin >> a;
	if (n > 0)
	{
		s = (n * pow(a, 2) * (1 / tan(3.14159265359 / n))) / 4;
		cout << "Area of regular polygon with " << n << " equals " << s << "\n";
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Please enter the number of edges greater than 0\n";
		AreaNGon();
	}
}

void quadratic()
{
	float a, b, c;
	cout << "The quadratic equation 2\n";
	cout << "The value of a = ";
	cin >> a;
	cout << "The value of b = ";
	cin >> b;
	cout << "The value of c = ";
	cin >> c;

	// kiem tra cac he so
	if (a == 0)
	{
		if (b == 0)
		{
			printf("The equation has no solution!");
		}
		else
		{
			printf("The equation has one solution: x = %f", (-c / b));
		}
	}
	// tinh delta
	float delta = b * b - 4 * a * c;
	float x1;
	float x2;
	// tinh nghiem
	if (delta > 0)
	{
		x1 = (float)((-b + sqrt(delta)) / (2 * a));
		x2 = (float)((-b - sqrt(delta)) / (2 * a));
		cout << "The equation has 2 solutions: x1 = " << x1 << " va x2=" << x2;
	}
	else if (delta == 0)
	{
		x1 = (-b / (2 * a));
		cout << "The equation has a double solution: x1 x2" << x1;
	}
	else
	{
		printf("The equation has no solution!");
	}
}
void AnalysMenu()
{
	int vvod = 0;
	while (1)
	{
		Menu();
		cout << "\tPlease enter the function: ";
		cin >> vvod;
		if (vvod < 1 || vvod > 12)
		{
			continue;
		}
		switch (vvod)
		{
		case 1:
			system("cls");
			erithmetic();
			break;
		case 2:
			system("cls");
			trigonometric();
			break;
		case 3:
			system("cls");
			menulogicbit();
			break;
		case 4:
			system("cls");
			exponential();
			break;
		case 5:
			system("cls");
			factorial();
			break;
		case 6:
			system("cls");
			logarithm();
			break;
		case 7:
			system("cls");
			UclnBcnn();
			break;
		case 8:
			system("cls");
			Bin2Dec2Hex();
			break;
		case 9:
			system("cls");
			AreaNGon();
			break;
		case 10:
			system("cls");
			quadratic();
			cout << "\n";
			system("pause");
			break;
		case 11:
			system("cls");
			cout << "Exit!!!";
			exit(0);
			break;
		}
	}
}

int main()
{
	// setlocale(LC_ALL, "russian");
	AnalysMenu();
}
