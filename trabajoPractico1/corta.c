#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "corta.h"


int obtenerMaximo (int x, int y, int z)
{
   int max;

   max=x;

    if(y>max && y>z)
    {
        max=y;
    }
    else
    {
        if(z>max)
        {
            max=z;
        }

    }

    return max;
}

int mostrarMenu()
{
    int opcion;




    printf("3- Calcular todas las operaciones.: \n");
    printf("4- Informar resultados. : \n");
    printf("5- Salir.\n");
    scanf("%d", &opcion);

    return opcion;

}

int thiagoSuma(int x, int y)
{

    return x + y;

}

int thiagoResta(int x, int y)
{

    return x - y;

}

float thiagoDivide(int x, int y)
{
    float division;
    division= (float) x / y;
    return division;
}

int thiagoMultiplica(int x, int y)
{

    return x*y;
}


double thiagoFactorial(int x)
{
   double factorial=1;

    for(;x>1;x--)
    {
        factorial=factorial*x;
    }
    return factorial;
}

int menuOperaciones()
{

    int opcion;

    system("cls");

    printf("1- Calcular la suma. (A+B): \n");
    printf("2- Calcular la resta. (A-B): \n");
    printf("3- Calcular la division. (A/B): \n");
    printf("4- Calcular la multiplicacion. (A*B): \n");
    printf("5- Calcular el factorial. (A!): \n");
    printf("6- Volver al menu principal.\n");
    scanf("%d", &opcion);

    return opcion;

}







