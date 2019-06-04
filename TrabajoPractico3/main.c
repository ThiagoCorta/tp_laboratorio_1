#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char seguir= 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagText=0;
    int flagBin=0;

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\nLos datos fueron cargados correctamente..");
                    flagText=1;
                }else{
                printf("Error al cargar archivos.\n");
                }
                system("pause");
                break;
            case 2:
               if(controller_loadFromBinary("data.bin",listaEmpleados)==1){
                   printf("\nLos datos fueron cargados correctamente..");
                    flagBin=1;
               }else{
               printf("Error al cargar archivos.\n");
               }
               system("pause");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==1){
                    printf("\nEmpleado agregado exitosamente!!\n");
                }
                system("pause");
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados)==1){
                    printf("\nEmpleado modificado exitosamente!!\n");
                }
                system("pause");
                break;
            case 5:
                printf("Baja incompleta.");
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                printf("Sort incompleto.");
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                system("pause");
                break;

            case 10:
                seguir='n';
                    break;
            default:
                printf("Ing opcion valida.\n");
                system("pause");
                break;
        }
    }while(seguir=='s');
    return 0;
}


