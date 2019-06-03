#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include <string.h>

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

int menu()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingresar opcion : ");

    fflush(stdin);
    scanf("%d",&opc);

    return opc;

}

int menuModify()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Editar nombre : \n");
    printf("2. Editar horas trabajadas : \n");
    printf("3. Editar sueldo : \n");
    printf("4. Salir\n\n");
    printf("Ingresar opcion : ");

    fflush(stdin);
    scanf("%d",&opc);

    return opc;

}

int printEmployee(Employee* this)
{
    int todoOk=-1;

    if(this!=NULL){
        printf("%5d %12s %12d %10d\n", this->id,this->name,this->hoursWorked,this->salary);
        todoOk=1;
    }

    return todoOk;
}




