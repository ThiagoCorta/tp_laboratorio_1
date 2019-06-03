#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk=-1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL){
            parser_EmployeeFromText(f,pArrayListEmployee);
            fclose(f);
            todoOk=1;
        }else{
        printf("\nNo se pudo abrir el archivo!\n");
        }
    }
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk=-1;

    if(path!=NULL && pArrayListEmployee!=NULL){
        f=fopen(path,"rb");
        if(f!=NULL){
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            fclose(f);
            todoOk=1;
        }else{
        printf("\nEl archivo no se pudo abrir\n");
        }

    }


    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int auxInt;
    int auxId;
    int auxHoras;
    char auxChar[50];
    Employee* new;

    if(pArrayListEmployee!=NULL)
    {
        utn_getEntero(&auxId,20,"\nIngresar ID del empleado : ","\nError ingresar ID valido \n",1,9999);
        utn_getCadena(auxChar,50,20,"\nIngresar nombre del empleado : ","\nError ingresar nombre valido : \n");
        utn_getEntero(&auxHoras,20,"\nIngresar horas trabajadas : ", "\nError ingresar horas validas: \n",0,200);
        utn_getEntero(&auxInt,20,"\nIngresar sueldo del empleado : ", "\nError ingresar sueldo valido \n",5000,200000);
        new=employee_new();
        if(new!=NULL)
        {
            employee_setId(new,auxId);
            employee_setName(new,auxChar);
            employee_setHoursWorked(new,auxHoras);
            employee_setSalary(new,auxInt);
            ll_add(pArrayListEmployee,new);
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* new;
    int todoOk=-1;
    int auxInt;
    int auxId;
    int len;
    char auxChar[50];
    char seguir='s';

    if(pArrayListEmployee!=NULL){
        len = ll_len(pArrayListEmployee);
        utn_getEntero(&auxId,20,"\nIngresar ID del empleado que desea modificar : ", "\nError ingresar ID valido\n",0,9999);
        for(int i=0;i<len;i++){
            new=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(new,&auxInt);
            if(auxId==auxInt){
                do{
                    switch(menuModify()){
                        case 1:
                            utn_getCadena(auxChar,50,20,"\nIngresar nuevo nombre del empleado : ", "\nError ingresar nombre valido\n");
                            employee_setName(new,auxChar);
                            todoOk=1;
                            break;
                        case 2:
                            utn_getEntero(&auxInt,20,"\nIngresar nuevas horas trabajadas :","\nError ingresar horas validas \n",0,9999);
                            employee_setHoursWorked(new,auxInt);
                            todoOk=1;
                            break;
                        case 3:
                            utn_getEntero(&auxInt,20,"\nIngresar nuevo sueldo :","\nError ingresar sueldo valido\n",5000,200000);
                            employee_setSalary(new,auxInt);
                            todoOk=1;
                            break;
                        case 4:
                            seguir='n';
                            break;
                        default:
                            printf("Error ingresar opcion valida o salir si desea salir!\n");
                            break;
                    }

                }while(seguir=='s');
            }
        }

    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int todoOk=-1;
    int len;
    int id;
    int hours;
    int salary;
    char name[50];

    if(pArrayListEmployee!=NULL){
        len=ll_len(pArrayListEmployee);
        for(int i=0;i<len;i++){
            aux=(Employee*)ll_get(pArrayListEmployee,i);
           printEmployee(aux);
            /*employee_getId(aux,&id);
            employee_getName(aux,name);
            employee_getHoursWorked(aux,&hours);
            employee_getSalary(aux,&salary);

            printf("%5d %12s %12d %10d\n", id,name,hours,salary);*/

            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1 ;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

