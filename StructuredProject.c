#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 50
#define NAME_LENGTH 100

struct Data {
    int id;
    char name[NAME_LENGTH];
};

struct Data employees[MAX_EMPLOYEES];
int Employee_ID = 0;

void addEmployee() 
{
    struct Data Individual_employee;
    Individual_employee.id = Employee_ID + 1;
    printf("Enter employee name: ");
    scanf("%s", Individual_employee.name);
    employees[Employee_ID] = Individual_employee;
    Employee_ID++;
    printf("Employee added successfully!\n");
}

void removeEmployee() 
{
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    int index_to_delete = -1;
    for (int i = 0; i < Employee_ID; i++) 
    {
        if (employees[i].id == id) 
        {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete == -1) 
    {
        printf("Employee not found.\n");
    } 
    else 
    {
        for (int i = index_to_delete; i < Employee_ID - 1; i++) 
        {
            employees[i] = employees[i+1];
        }
        Employee_ID--;
        printf("Employee removed successfully!\n");
    }
}

void displayEmployees() 
{
    printf("ID\tName\n");
    for (int i = 0; i < Employee_ID; i++) 
    {
        printf("%d\t%s\n", employees[i].id, employees[i].name);
    }
}

void searchEmployee() 
{
    char name[NAME_LENGTH];
    printf("Enter employee name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < Employee_ID; i++) 
    {
        if (strcmp(employees[i].name, name) == 0) 
        {
            printf("Employee found! ID: %d\n", employees[i].id);
            found = 1;
        }
    }
    if (!found) {
        printf("Employee not found.\n");
    }
}

int main() 
{
    int choice;
    while (1) 
    {
        printf("\n");
        printf("--------------------------\n");
        printf("Employee Management System\n");
        printf("--------------------------\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Display Employees\n");
        printf("4. Search Employee\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                addEmployee();
                break;
            case 2:
                removeEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.Please try again\n");
                break;
        }
    }
    return 0;
    
}
