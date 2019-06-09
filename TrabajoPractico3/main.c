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

int ordenarXSueldo(void*, void*);
int main()
{
    char seguir= 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\nLos datos fueron cargados correctamente.\n");
                }else{
                printf("\nError al cargar archivos.\n");
                }
                system("pause");
                break;
            case 2:
               if(controller_loadFromBinary("data.bin",listaEmpleados)==1){
                   printf("\nLos datos fueron cargados correctamente.\n");
               }else{
               printf("Error al cargar archivos.\n");
               }
               system("pause");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==1){
                    printf("\nEmpleado agregado exitosamente!!\n");
                }else{
                    printf("\nError al ingresar el empleado.\n");
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
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_removeEmployee(listaEmpleados)==1){
                    printf("\nEl empleado fue dado de baja de forma exitosa!!\n");
                    }else{
                    printf("\nNo se dio de baja al empleado.\n");
                    }
                }else{
                    printf("\nNo hay empleados en el sistema.\n");
                }
                system("pause");
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_ListEmployee(listaEmpleados);
                }else{
                    printf("\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo\n");
                }
                system("pause");
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_sortEmployee(listaEmpleados)==1){
                        printf("\nSe ordeno la lista de empleados!\n");
                    }else{
                        printf("\nNo se pudo ordenar la lista de empleados.\n");
                    }
                }else{
                    printf("\nNo hay empleados cargados que ordenar, agregue o bien cargue desde el archivo\n");
                }
                system("pause");
                break;
            case 8:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsText("data.csv",listaEmpleados)==1){
                        printf("\nDatos de empleados guardados en el archivo TXT con exito!\n");
                    }else{
                        printf("\nNo se pudo guardar los datos en el archivo.\n");
                    }
                }else{
                    printf("\nNo hay nada que guardar.\n");
                }
                system("pause");
                break;
            case 9:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsBinary("data.bin",listaEmpleados)==1){
                        printf("\nDatos de empleados guardados en el archivo BIN con exito!\n");
                    }else{
                        printf("\nNo se pudo guardar los datos en el archivo.\n");
                    }
                }else{
                    printf("\nNo hay nada que guardar.\n");
                }

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
    free(listaEmpleados);
    return 0;
}


