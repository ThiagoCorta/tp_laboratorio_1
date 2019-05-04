#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TAM 15




int main()
{
   eEmpleado empleados[TAM];
   int auxInt;
   float auxFloat;
   float auxFloat2;
   char auxNombre[51];
   char auxApellido[51];
   char seguir='s';

   initEmployees(empleados,TAM);
   hardCodearEmpleados(empleados,TAM);

   do{


       switch(menuAbm())
       {
            case 1:
                utn_getCadena(auxNombre,50,20,"Ingresar nombre del empleado : \n", "Error ingresar nombre valido: \n");
                utn_getCadena(auxApellido,50,20,"Ingresar apellido del empleado : \n", "Error ingresar apellido valido: \n");
                utn_getFlotante(&auxFloat,20,"ingresar sueldo del empleado : \n","Error ingresar sueldo valido: \n",1,1000000);
                utn_getEntero(&auxInt,20,"Ingresar sector 1/2/3/4/5 : \n", "Error ingresar sector valido : \n",1,5);
                addEmployee(empleados,TAM,auxNombre,auxApellido,auxFloat,auxInt);
                system("Pause");
                break;

            case 2:
                printEmployees(empleados,TAM);
                utn_getEntero(&auxInt,3,"Ingresar ID del empleado que desea Eliminar: ", "Error ingresar ID valido",0,TAM);
                removeEmployee(empleados,TAM,auxInt);
                system("Pause");
                break;

            case 3:
                modifyEmployee(empleados,TAM);
                system("Pause");
                break;

            case 4:
                sortEmployees(empleados,TAM);
                printEmployees(empleados,TAM);
                infoSueldos(empleados,TAM,&auxFloat,&auxFloat2,&auxInt);
                printf("Suma de todos los sueldos : %.2f \nPromedio de todos los sueldos : %.2f \n Cantidad de Empleados que superan el promedio : %d \n", auxFloat,auxFloat2,auxInt);
                system("Pause");
                break;

            case 5:
                seguir='n';
                break;

            default:
                printf("Ingresar opcion valida\n");
                system("pause");
                break;

       }

    }while(seguir=='s');


}


