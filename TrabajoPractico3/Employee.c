#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include <string.h>


void employee_delete(Employee* this){
    if(this!=NULL){
        free(this);
    }

}
int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
       this->id=id;
        todoOk=1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setName(Employee* this,char* name)
{
    int todoOk=0;
    if(this!=NULL && name!=NULL && strlen(name)>3)
    {
        strcpy(this->name,name);
        todoOk=1;
    }
    return todoOk;
}

int employee_getName(Employee* this,char* name)
{
    int todoOk=0;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHoursWorked(Employee* this,int hoursWorked)
{
    int todoOk=0;
    if(this!=NULL && hoursWorked>0)
    {
        this->hoursWorked=hoursWorked;
        todoOk=1;
    }
    return todoOk;
}

int employee_getHoursWorked(Employee* this,int* hoursWorked)
{
    int todoOk=0;
    if(this!=NULL && hoursWorked!=NULL)
    {
        *hoursWorked=this->hoursWorked;
        todoOk=1;
    }
    return todoOk;
}


int employee_setSalary(Employee* this,int salary)
{
    int todoOk=0;
    if(this!=NULL && salary>0)
    {
        this->salary=salary;
        todoOk=1;
    }
    return todoOk;
}

int employee_getSalary(Employee* this,int* salary)
{
    int todoOk=0;
    if(this!=NULL && salary!=NULL)
    {
        *salary=this->salary;
        todoOk=1;
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
        free(new);
        new=NULL;
    }
    return new;

}


Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary)
{
    Employee* new;
    new=employee_new();
    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && salary!=NULL && new!=NULL){
        if(!employee_setId(new,atoi(idStr))||
        !employee_setName(new,nameStr)||
        !employee_setSalary(new,atoi(salary))||
        !employee_setHoursWorked(new,atoi(hoursWorkedStr))){
            free(new);
            new=NULL;
        }/*else{
            free(new);
            new=NULL;
        }*/
    }
    return new;
}

int menu()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,10);

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
    printf("4. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,4);

    return opc;

}

int printEmployee(Employee* this)
{
    int todoOk=0;

    if(this!=NULL){
        printf("%5d %12s %12d %10d\n", this->id,this->name,this->hoursWorked,this->salary);
        todoOk=1;
    }

    return todoOk;
}

int ordenarXSueldo(void* emp1, void* emp2){
    int todoOk=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(p1->salary > p2->salary){
            todoOk=1;
         }else if(p1->salary < p2->salary){
            todoOk=-1;
         }else if(p1->salary == p2->salary){
            todoOk=0;
        }
    }

    return todoOk;
}

int compareByName(void* emp1, void* emp2){
    int todoOk=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(strcmp(p1->name,p2->name)>0){
            todoOk=1;
         }else if(strcmp(p1->name,p2->name)<0){
            todoOk=-1;
         }else if(strcmp(p1->name,p2->name)==0){
            todoOk=0;
        }
    }

    return todoOk;
}

int employee_isValidEmp(Employee* emp){
    int todoOk=0,id,hours,salary;
    char name[50];

    if(emp!=NULL){
        employee_getId(emp,&id);
        employee_getHoursWorked(emp,&hours);
        employee_getSalary(emp,&salary);
        employee_getName(emp,name);

        if(id>0 && hours >0 && salary >0 && name !=NULL){
            todoOk=1;
        }
    }
    return todoOk;
}

