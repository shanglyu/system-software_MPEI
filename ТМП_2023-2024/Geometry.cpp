#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    int age;
    string position;

public:
    Employee(int employeeId, string employeeName, int employeeAge, string employeePosition)
        : id(employeeId), name(employeeName), age(employeeAge), position(employeePosition) {}

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getPosition() {
        return position;
    }
    void setId(int employeeId) {
        id = employeeId;
    }


    void setName(string employeeName) {
        name = employeeName;
    }

    void setAge(int employeeAge) {
        age = employeeAge;
    }

    void setPosition(string employeePosition) {
        position = employeePosition;
    }
};

class Program {
private:
    const static int MAX_EMPLOYEES = 100;
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees;
    int nextId;

public:
    Program() {
        numEmployees = 0;
        nextId = 1;
    }

    void displayMenu() {
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employee Information" << endl;
        cout << "3. Modify Employee Information" << endl;
        cout << "4. Fire Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void addEmployee(Employee* employee) {
        if (numEmployees < MAX_EMPLOYEES) {
            employee->setId(nextId);
            employees[numEmployees++] = employee;
            nextId++;
            cout << "Employee added successfully." << endl;
        } else {
            cout << "Maximum number of employees reached. Cannot add more employees." << endl;
        }
    }

    void displayEmployeeInformation() {
        cout << "Employee List:" << endl;
        for (int i = 0; i < numEmployees; i++) {
            cout << "Employee ID: " << employees[i]->getId() << endl;
            cout << "Name: " << employees[i]->getName() << endl;
            cout << "Age: " << employees[i]->getAge() << endl;
            cout << "Position: " << employees[i]->getPosition() << endl;
            cout << endl;
        }
    }

    void modifyEmployeeInformation() {
        int employeeID;
        cout << "Enter the Employee ID to modify: ";
        cin >> employeeID;

        if (employeeID >= 1 && employeeID <= numEmployees) {
            string newName;
            int newAge;
            string newPosition;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new age: ";
            cin >> newAge;

            cout << "Enter new position: ";
            cin.ignore();
            getline(cin, newPosition);

            employees[employeeID - 1]->setName(newName);
            employees[employeeID - 1]->setAge(newAge);
            employees[employeeID - 1]->setPosition(newPosition);

            cout << "Employee information modified successfully." << endl;
        } else {
            cout << "Invalid Employee ID." << endl;
        }
    }

    void fireEmployee() {
        int employeeID;
        cout << "Enter the Employee ID to fire: ";
        cin >> employeeID;

        if (employeeID >= 1 && employeeID <= numEmployees) {
            delete employees[employeeID - 1];

            for (int i = employeeID - 1; i < numEmployees - 1; i++) {
                employees[i] = employees[i + 1];
            }

            numEmployees--;

            cout << "Employee fired successfully." << endl;
        } else {
            cout << "Invalid Employee ID." << endl;
        }
    }

    void run() {
        int choice;

        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1: {
                    string name;
                    int age;
                    string position;

                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter age: ";
                    cin >> age;

                    cout << "Enter position: ";
                    cin.ignore();
                    getline(cin, position);

                    Employee* employee = new Employee(nextId, name, age, position);
                    addEmployee(employee);
                    break;
                }
                case 2:
                    displayEmployeeInformation();
                    break;
                case 3:
                    modifyEmployeeInformation();
                    break;
                case 4:
                    fireEmployee();
                    break;
                case 5:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }

            cout << endl;
        } while (choice != 5);
    }
};

int main() {
    Program program;
    program.run();

    return 0;
}