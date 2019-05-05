#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TAM 1000


int main()
{

   int auxInt;
   int flag=0;
   float auxFloat;
   float auxFloat2;
   char auxNombre[51];
   char auxApellido[51];
   char seguir='s';
   eEmpleado empleados[TAM];

   initEmployees(empleados,TAM);
   ///hardCodearEmpleados(empleados,12);

   do{
        auxInt=findEmployeeById(empleados,TAM,100);
        if(auxInt!=-1 && empleados[auxInt].isEmpty==1)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }

       switch(menuAbm())
       {
            case 1:
                utn_getCadena(auxNombre,50,20,"Ingresar nombre del empleado : \n", "Error ingresar nombre valido: \n");
                utn_getCadena(auxApellido,50,20,"Ingresar apellido del empleado : \n", "Error ingresar apellido valido: \n");
                utn_getFlotante(&auxFloat,20,"ingresar sueldo del empleado : \n","Error ingresar sueldo valido: \n",1,1000000);
                utn_getEntero(&auxInt,20,"Ingresar sector 1/2/3/4/5 : \n", "Error ingresar sector valido : \n",1,5);
                addEmployee(empleados,TAM,auxNombre,auxApellido,auxFloat,auxInt);
                system("pause");
                break;

            case 2:
                if(validateFlag(&flag,"\nPara poder dar de baja empleados primero hay que ingresarlos.\n")==0)
                {
                    printEmployees(empleados,TAM);
                    utn_getEntero(&auxInt,3,"Ingresar ID del empleado que desea Eliminar: ", "Error ingresar ID valido",0,TAM);
                    removeEmployee(empleados,TAM,auxInt);
                    system("pause");
                }
                break;

            case 3:
                if(validateFlag(&flag,"\nPara poder modificar empleados primero hay que ingresarlos.\n")==0)
                {
                    modifyEmployee(empleados,TAM);
                    system("pause");
                }
                break;

            case 4:
                if(validateFlag(&flag,"\nPara poder mostrar empleados primero hay que ingresarlos.\n")==0)
                {
                    sortEmployees(empleados,TAM);
                    printEmployees(empleados,TAM);
                    infoSueldos(empleados,TAM,&auxFloat,&auxFloat2,&auxInt);
                    printf("\n\nSuma de todos los sueldos : %.2f \nPromedio de todos los sueldos : %.2f \n Cantidad de Empleados que superan el promedio : %d \n", auxFloat2,auxFloat,auxInt);
                    system("pause");
                }
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

