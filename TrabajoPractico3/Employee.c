#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int employee_setId(Employee* this,int id)
{
    int todoOk=-1;
    if(this!=NULL && id>0)
    {
       this->id=id;
        todoOk=0;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOk=0;
    }
    return todoOk;
}

int employee_setName(Employee* this,char* name)
{
    int todoOk=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->name,name);
        todoOk=0;
    }
    return todoOk;
}

int employee_getName(Employee* this,char* name)
{
    int todoOk=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        todoOk=0;
    }
    return todoOk;
}

int employee_setHoursWorked(Employee* this,int hoursWorked)
{
    int todoOk=-1;
    if(this!=NULL && hoursWorked>0)
    {
        this->hoursWorked=hoursWorked;
        todoOk=0;
    }
    return todoOk;
}

int employee_getHoursWorked(Employee* this,int* hoursWorked)
{
    int todoOk=-1;
    if(this!=NULL && hoursWorked!=NULL)
    {
        *hoursWorked=this->hoursWorked;
        todoOk=0;
    }
    return todoOk;
}


int employee_setSalary(Employee* this,int salary)
{
    int todoOk=-1;
    if(this!=NULL)
    {
        this->salary=salary;
        todoOk=0;
    }
    return todoOk;
}

int employee_getSalary(Employee* this,int* salary)
{
    int todoOk=-1;
    if(this!=NULL && salary!=NULL)
    {
        *salary=this->salary;
        todoOk=0;
    }
    return todoOk;
}



Employee* employee_new()
{
    Employee* new;
    new = (Employee*) malloc(sizeof(Employee));
    if(new != NULL){
        new->id = 0;
        strcpy(new->name, "");
        new->salary =0;
        new->hoursWorked=0;
    }else{
        printf("\nNo se pudo conseguir memoria para un nuevo empleado...\n");
        system("pause");
    }
    return new;

}


Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary)
{

    Employee* new;
    new=employee_new();
    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && new!=NULL){
        employee_setId(new,atoi(idStr));
        employee_setName(new,nameStr);
        employee_setSalary(new,atof(salary));
        employee_setHoursWorked(new,atoi(hoursWorkedStr));
        return new;
    }
    return NULL;
}



