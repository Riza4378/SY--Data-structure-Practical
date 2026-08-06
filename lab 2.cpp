#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int EmployeeId;
    string EmployeeName;
    float Salary;
    Employee *next;
};


Employee *head = NULL;


void insertEmployee()
{
    Employee *newEmployee = new Employee;

    cout << "Enter Employee ID: ";
    cin >> newEmployee->EmployeeId;

    cout << "Enter Employee Name: ";
    cin >> newEmployee->EmployeeName;

    cout << "Enter Salary: ";
    cin >> newEmployee->Salary;

    newEmployee->next = head;
    head = newEmployee;

    cout << "Employee Record Inserted Successfully.\n";
}


void deleteEmployee(int id)
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Employee *temp = head;
    Employee *prev = NULL;

   
    if (head->EmployeeId == id)
    {
        head = head->next;
        delete temp;
        cout << "Employee Record Deleted.\n";
        return;
    }

    while (temp != NULL && temp->EmployeeId != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Employee Not Found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Employee Record Deleted.\n";
}


void searchEmployee(int id)
{
    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->EmployeeId == id)
        {
            cout << "\nEmployee Found\n";
            cout << "ID : " << temp->EmployeeId << endl;
            cout << "Name : " << temp->EmployeeName << endl;
            cout << "Salary : " << temp->Salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Employee Not Found.\n";
}


void displayEmployees()
{
    if (head == NULL)
    {
        cout << "No Employee Records.\n";
        return;
    }

    Employee *temp = head;

    cout << "\nEmployee Records\n";
    cout << "-----------------------------\n";

    while (temp != NULL)
    {
        cout << "ID : " << temp->EmployeeId << endl;
        cout << "Name : " << temp->EmployeeName << endl;
        cout << "Salary : " << temp->Salary << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n===== Employee Management =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertEmployee();
            break;

        case 2:
            cout << "Enter Employee ID to Delete: ";
            cin >> id;
            deleteEmployee(id);
            break;

        case 3:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            searchEmployee(id);
            break;

        case 4:
            displayEmployees();
            break;

        case 5:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}














	
	
	
