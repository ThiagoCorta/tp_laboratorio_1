#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setHoursWorked(Employee* this,int hoursWorked);
int employee_getHoursWorked(Employee* this,int* hoursWorked);

int employee_setSalary(Employee* this,int salary);
int employee_getSalary(Employee* this,int* salary);

int printEmployee(Employee* this);

int menu();
int menuModify();
#endif // employee_H_INCLUDED
