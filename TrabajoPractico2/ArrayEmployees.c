#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"


int menuAbm()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("    1- Alta empleado: \n");
    printf("    2- Baja empleado: \n");
    printf("    3- Modificar empleado:  \n");
    printf("    4- Mostrar Empleados: \n");
    printf("    5- Salir: \n");

    scanf("%d", &opcion);

return opcion;
}


void initEmployees(eEmpleado* list, int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        list[i].isEmpty=0;
    }

}

int findEmptySlot(eEmpleado* list, int len)
{
    int todoOk=-1;

        for(int i = 0 ; i < len ; i++)
        {
            if(list[i].isEmpty==0)
            {
                todoOk=i;
                break;
            }
        }

    return todoOk;
}

int getIdEmployee(eEmpleado* list, int len)
{

    int index;
    int idAnt;
    int id = -1;

    index=findEmptySlot(list,len);

    if(index==0)
    {
        id=100;
    }
    else
    {
        idAnt=list[index-1].id;
        id=idAnt+1;
    }

    while(findEmployeeById(list,len,id)!=-1)
    {
        id++;
    }

    return id;


/*
    int indexLibre=findEmptySlot(list,len);
    int idAnterior;
    int id=-1;

    if(indexLibre==0){
        id=1;
    }else{
        idAnterior=list[indexLibre-1].id;
        id=idAnterior+1;
    }*/

//return id;

}


void addEmployee(eEmpleado* list, int len, char name[],char lastName[],float salary,int sector)
{
    int indice;

    indice=findEmptySlot(list,len);

    if(indice!=-1)
    {
        list[indice].id = getIdEmployee(list,len);
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary=salary;
        list[indice].sector=sector;
        list[indice].isEmpty=1;

        printf("\nEmpleado ingresado con Exito!!.\n");
    }
    else
    {
        printf("\nNo hay mas espacio para nuevos empleados.\n");
    }

}

int findEmployeeById(eEmpleado* list, int len,int id)
{
    int esta = -1;

    for(int i = 0; i<len;i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            esta=i;
        }
    }

    return esta;


}

int removeEmployee(eEmpleado* list, int len, int id)
{
    int todoOk = -1;
    int esta;

    esta = findEmployeeById(list,len,id);

    if(esta!=-1)
    {
        list[esta].isEmpty=0;
        todoOk=1;
        printf("Empleado dado de baja.\n\n");
    }
    else
    {
        printf("\nEl empleado no se encuentra en nuestros registos.\n");
    }

    return todoOk;

}

void sortEmployees(eEmpleado* list, int len)
{
     eEmpleado auxEmpleado;

    for(int i = 0 ; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].sector>list[j].sector)
            {
                auxEmpleado=list[i];
                list[i]=list[j];
                list[j]=auxEmpleado;
            }
            else
            {
                if(list[i].sector==list[j].sector && (stricmp(list[i].lastName, list[j].lastName)==1))
                {
                    auxEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleado;
                }
            }
        }
}

}


void printEmployee(eEmpleado list)
{
    printf("%5d %12s %12s %10.2f %10d \n", list.id, list.name,list.lastName,list.salary, list.sector);
}


void printEmployees(eEmpleado* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %10s %10s  \n", "ID", "Nombre", "Apellido", "Salario", "Sector");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printEmployee(list[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.\n");

}

}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("1- Modificar nombre.\n2- Modificar apellido. \n3- Modificar sueldo. \n4- Modificar sector.\n5-Salir ");
    scanf("%d", &opcion);

    return opcion;

}

char preguntarSiEstaSeguro(char* msg, char* msgerror)
{
    char confirma;

    printf("%s", msg);
    fflush(stdin);
    confirma = tolower(getche());

    while(confirma!='s' && confirma!='n')
    {
        printf("%s", msgerror);
        fflush(stdin);
        confirma = tolower(getche());
    }

    return confirma;
}


void modifyEmployee(eEmpleado* list, int len)
{

    int id;
    int esta;
    int auxInt;
    float auxFloat;
    char auxChar[51];
    char seguir='s';


    printEmployees(list,len);

    printf("\n\nIngrese el ID del empleado que desea modificar:\n ");
    scanf("%d", &id);

    esta = findEmployeeById(list, len, id);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", id);
    }
    else
    {
        do
        {
            switch(menuModificar())
        {
        case 1 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del empleado s/n\n", "Error ingresar s/n \n")=='s')
            {
                utn_getCadena(auxChar,50,3,"Ingresar nuevo nombre : \n", "Error ingresar nombre valido : \n");
                strcpy(auxChar,list[esta].name);
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }

            break;
        case 2 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del empleado s/n\n", "Error ingresar s/n \n")=='s')
            {
                utn_getCadena(auxChar,50,3,"Ingresar nuevo apellido : \n", "Error ingresar apellido valido : \n");
                strcpy(auxChar,list[esta].lastName);
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }
            break;
        case 3 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del empleado s/n\n", "Error ingresar s/n \n")=='s')
            {
                utn_getFlotante(&auxFloat,3,"Ingresar nuevo sueldo : \n", "Error ingresar sueldo valido : \n", 0,150000);
                list[esta].salary=auxFloat;
                printf("Empleado modificado con exito!..\n\n");
                system("pause");
            }

            break;
        case 4 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del empleado s/n\n", "Error ingresar s/n \n")=='s')
            {
                 utn_getEntero(&auxInt,3,"Ingresar nuevo sector : \n", "Error ingresar sector valido : \n",0,5);
                list[esta].sector=auxInt;
                printf("Empleado modificado con exito!..\n\n");
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


}

int infoSueldos(eEmpleado* list, int len,float* pFloatProm,float* pFloatTotal, int* pIntCant)
{
    float acumulador=0;
    int contadorProm=0;
    int contador=0;
    int todoOk=-1;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            acumulador+=list[i].salary;
            contadorProm++;
        }

    }

    *pFloatTotal=acumulador;
    *pFloatProm=acumulador/contadorProm;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1 && list[i].salary>*pFloatProm)
        {
            contador++;
        }
    }

    *pIntCant = contador;


    if(pFloatProm!=NULL && pFloatProm!=NULL && pIntCant!=NULL)
    {
        todoOk=0;
    }

    return todoOk;
}


void hardCodearEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado empleados [13]= {
    {100, "juan", "perez",  19994 , 2,1},
    {101, "cristina", "ferrera", 6584, 2,1},
    {102, "thiago", "corta",39995 , 3,1},
    {103, "diego", "fernandez",45610 , 4,1},
    {104, "camila", "celano", 15550 , 1,1},
    {105, "federico", "callejeros", 28480, 1,1},
    {106, "nerea", "pereyra", 30000 , 2,1},
    {107, "matias", "hamie", 43000 , 5,1},
    {108, "dani", "class",  16000 , 4,1},
    {109, "sabrina", "nosee", 25000 , 1,1},
    {110, "victoria", "sanchez", 30000 , 2,1},
    {111, "noseqponer", "bastaaa",  4000, 4,1}};
    for(int i=0;i<tam;i++)
    {
        vec[i]= empleados[i];
    }

}



