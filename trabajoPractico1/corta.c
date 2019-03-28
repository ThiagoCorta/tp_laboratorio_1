#include <stdio.h>
#include <stdlib.h>
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

int thiagoSuma(float x, float y)
{

    return x + y;

}

int thiagoResta(float x, float y)
{

    return x - y;

}

float thiagoDivide(float x, float y)
{

   float division;


   if(y==0)
   {
       printf("No se puede dividir por cero.\n");
   }
   else
   {
       division=(float)x/y;
   }

    return division;
}

float thiagoMultiplica(float x, float y)
{

   float multiplicacion;



   if(y==0)
   {
       printf("No se puede multiplicar por cero.\n");
   }
   else
   {
       multiplicacion=x*y;
   }

    return multiplicacion;
}


int thiagoFactorial(float x)
{
   int factorial=1;

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

int primerOperando ()
{
    int x;
    printf("Ingrese el primer operando:\n");
    while(scanf("%d", &x) !=1)
    {
        printf("Error, vuelva a ingresar el numero \n");
        fflush(stdin);
    }

    return x;

}

int segundoOperando ()
{
    int y;
    printf("Ingrese el segundo operando:\n");
    while(scanf("%d", &y) !=1)
    {
        printf("Error, vuelva a ingresar el numero \n");
        fflush(stdin);
    }

    return y;

}

void thiagoCalculaOperaciones(float x, float y)
{
    thiagoSuma(x,y);
    thiagoResta(x,y);
    thiagoDivide(x,y);
    thiagoMultiplica(x,y);
    thiagoFactorial(x);
}

void thiagoMuestraResultados(float x, float y)
{
    printf("1- El resultado de a + b : %.0f" , thiagoSuma(x,y));
    printf("1- El resultado de a - b : %.0f", thiagoResta(x,y));
    printf("1- El resultado de a / b : %.0f", thiagoDivide(x,y));
    printf("1- El resultado de a * b : %.0f", thiagoMultiplica(x,y));
    printf("1- El resultado de a! : %.0f",thiagoFactorial(x));

}




