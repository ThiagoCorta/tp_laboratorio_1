#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* new;
    char buffer[4][30];
    int cant;
    int todoOk=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        printf("%s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile)){
            cant =  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            new=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(new!=NULL){
                ll_add(pArrayListEmployee,new);
                todoOk=1;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }
    return todoOk;
}
    /** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
     *
     * \param path char*
     * \param pArrayListEmployee LinkedList*
     * \return int
     *
     */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int cant;
    Employee* new;
    if(pFile!=NULL && pArrayListEmployee!= NULL){
        while(!feof(pFile)){
            new=employee_new();
           cant = fread(new,sizeof(Employee),1,pFile);
            if(new!=NULL){
                 ll_add(pArrayListEmployee,new);
                 todoOk=1;
            }
            if(cant<1){
                if(feof(pFile)){
                break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }

    return todoOk;
}
