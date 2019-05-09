#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"

//Defino el TAMANIO del array de empleados.
#define TAM 1000


int main()
{



    /*IMPORTANTE, el warning del STRICMP no supe como sacarlo, consulte con el profesor y con varios companieros y a muchos
      les pasaba lo mismo y el profesor tampoco supo como sacarlo.
    */


    //Declaro variables necesarias.

   int auxInt;
   int flag=0;
   float auxFloat;
   float auxFloat2;
   char auxNombre[51];
   char auxApellido[51];
   char seguir='s';
   eEmpleado empleados[TAM];

   //Inicializo la lista de empleados con el estado en LIBRE.
   initEmployees(empleados,TAM);

   //Esta funcion que esta COMENTADA, lo que hace es que me hardcodea empleados para que sea mas facil probar el programa.
   //hardCodearEmpleados(empleados,12);

   do{

        //Veo si la lista de empleados esta vacia, si esta vacia el flag es 0 y si hay empleados cargados el flag es 1.
        if(listEmpty(empleados,TAM)==0)
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
                /*Se piden los datos con funciones que validan que sea correcto y se da un limite de 20 intentos.
                  Se pasan variables auxiliares por punteros para validar.
                  Una ves que tengo las auxiliares cargadas y validadas se le pasan a la funcion addemployee,
                  que busca un indice libre en la lista, le da un id autoincremental y lo ingresa al sistema.
                */
                utn_getCadena(auxNombre,50,20,"Ingresar nombre del empleado : \n", "Error ingresar nombre valido: \n");
                utn_getCadena(auxApellido,50,20,"Ingresar apellido del empleado : \n", "Error ingresar apellido valido: \n");
                utn_getFlotante(&auxFloat,20,"ingresar sueldo del empleado : \n","Error ingresar sueldo valido: \n",1,1000000);
                utn_getEntero(&auxInt,20,"Ingresar sector 1/2/3/4/5 : \n", "Error ingresar sector valido : \n",1,5);
                addEmployee(empleados,TAM,auxNombre,auxApellido,auxFloat,auxInt);
                system("pause");
                break;

            case 2:
                /*Funcion que valida que el flag sea 0, si es 0 se muestra el mensaje "Para poder dar de baja empleados-
                  primero hay que ingresarlos".
                */
                if(validateFlag(&flag,"\nPara poder dar de baja empleados primero hay que ingresarlos.\n")==0)
                {
                    /*Se muestra la lista de empleados, se pide un ID validado que se pasa una variable aux por puntero.
                        Se pregunta si esta seguro que desea dar de baja al empleado y se hace la baja logica, cambiando
                        el estado de OCUPADO a LIBRE.*/
                    printEmployees(empleados,TAM);
                    utn_getEntero(&auxInt,3,"Ingresar ID del empleado que desea Eliminar: ", "Error ingresar ID valido",0,TAM);
                    removeEmployee(empleados,TAM,auxInt);
                    system("pause");
                }
                break;

            case 3:
                //Funcion que valida que el flag sea != de 0 o 0.
                if(validateFlag(&flag,"\nPara poder modificar empleados primero hay que ingresarlos.\n")==0)
                {
                    /*modifyEmployee, te muestra la lista de empleados, te pide un ID del empleado que te gustaria modificar
                      una ves que ingresas un ID valido que existe en el sistema, se entra al menu que te da opcion de modificar
                      NOMBRE-APELLIDO-SUELDO-SECTOR y la opcion de volver al menu.
                      Una ves que entras a alguna opcion, por EJ nombre, te pide que ingreses un nuevo nombre, se valida que sea
                      correcto, te pregunta si estas seguro, si pones 's', se hace el cambio y si no te devuelve al menu de modificacion.*/
                    modifyEmployee(empleados,TAM);
                    system("pause");
                }
                break;

            case 4:
                //Funcion que valida que el flag sea != de 0 o 0.
                if(validateFlag(&flag,"\nPara poder mostrar empleados primero hay que ingresarlos.\n")==0)
                {
                    /*sortEmployees, te organiza la lista de empleados por SECTOR y alfabeticamente por APELLIDO, una ves que estan
                      organizados, se muestra la lista de empleados, mostrando ID-Nombre-Apellido-Sueldo-Sector.
                      y con toda esa informacion que nos muestra en la lista, se muestra la SUMA de todos los sueldos,
                      EL PROMEDIO de sueldos, y la cantidad de empleados que SUPERAN al sueldo promedio.
                    */
                    sortEmployees(empleados,TAM);
                    printEmployees(empleados,TAM);
                    infoSueldos(empleados,TAM,&auxFloat,&auxFloat2,&auxInt);
                    printf("\n\nSuma de todos los sueldos : %.2f \nPromedio de todos los sueldos : %.2f \n Cantidad de Empleados que superan el promedio : %d \n\n", auxFloat2,auxFloat,auxInt);
                    system("pause");
                }
                break;

            case 5:
                //Si ingresas a la opcion 5 se termina el programa.
                seguir='n';
                break;

            default:
                //Se valida que no se pueda ingresar ninguna otra opcion que no sea las del menu.
                printf("Ingresar opcion valida\n");
                fflush(stdin);
                system("pause");
                break;

       }

    }while(seguir=='s');

}



