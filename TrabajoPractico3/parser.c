#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

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

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        printf("%s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile)){
            cant =  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            new=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(new!=NULL)
            {
                ll_add(pArrayListEmployee,new);
;           }
            if(cant < 4)
            {
                if( feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }
        }
    }
    return 1;
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

    return 1;
}

