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

float thiagoSuma(float x, float y)
{

    return x + y;

}

float thiagoResta(float x, float y)
{

    return x - y;

}

float thiagoDivide(float x, float y)
{
   return x/y;
}

float thiagoMultiplica(float x, float y)
{

    return x*y;
}


float thiagoFactorial(float x)
{
   float factorial=1;

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







