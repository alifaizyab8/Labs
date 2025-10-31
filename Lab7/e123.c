// declare a struct employee then store it's id salary and department
#include <stdio.h>
#include <string.h>

struct employee
{
    int id;
    float salary;
    char department[30];
};

void highest_salary(struct employee arr_emp[], int size)
{
    float highest = arr_emp[0].salary;
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr_emp[i].salary > highest)
        {
            highest = arr_emp[i].salary;
            index = i;
        }
    }
    printf("Employee with highest salary: %d\n", index);
}
// declare an array of 40 employees
struct employee arr_emp[40];
int main()
{
    // assign values to the 6th employee in the array
    arr_emp[6].id = 142;
    arr_emp[6].salary = 30000.0;
    strcpy(arr_emp[6].department, "IT Dept");

    printf("Employee ID: %d\n", arr_emp[6].id);
    printf("Employee Salary: %.2f\n", arr_emp[6].salary);
    printf("Employee Department: %s\n", arr_emp[6].department);
    highest_salary(arr_emp, 40);
    return 0;
}
