#include <stdio.h>
#include <stdlib.h>
#include "corta.h"


int main()
{
    float x;
    float y;
    int bandera1=0;
    int bandera2=0;
    int bandera3=0;
    int bandera4=0;
    int opcion;
    char seguir='s';

    do
    {

        system("cls");
        if (bandera1==0)
        {
            printf("1- Ingresar 1er operando (A=X)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n", x);

        }

        if(bandera2==0)
        {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", y);
        }

        printf("3- Calcular las operaciones.\n");


        switch(bandera3)
        {
        case 0:
            printf("    A- Calcular la suma (A+B): \n");
            printf("    B- Calcular la resta (A-B): \n");
            printf("    C- Calcular la division (A/B): \n");
            printf("    D- Calcular la multiplicacion. (A*B): \n");
            printf("    E- Calcular el factorial.(A!): \n");
            printf("    F- Calcular el factorial de (B!) : \n");
            break;

        case 1:
            printf("    A- Calcular la suma (%.2f+%.2f): \n", x, y);
            printf("    B- Calcular la resta (%.2f-%.2f): \n", x, y);
            printf("    C- Calcular la division (%.2f/%.2f): \n", x, y);
            printf("    D- Calcular la multiplicacion (%.2f*%.2f): \n", x, y);
            printf("    E- Calcular el factorial de (%.2f!): \n", x);
            printf("    F- Calcular el factorial de (%.2f!) : \n", y);
            break;
        case 2:
            printf("Se calcularon todas las operaciones.\n");
            system("pause");
            break;
        }
        printf("4- Mostrar las operaciones\n");

        if(bandera4==1)
        {
            printf("    A- Calcular la suma. (%.2f+%.2f): %.2f \n", x, y, thiagoSuma(x,y));
            printf("    B- Calcular la resta. (%.2f-%.2f): %.2f \n", x, y, thiagoResta(x,y));
            printf("    C- Calcular la division. (%.2f/%.2f): %2.f\n", x, y, thiagoDivide(x,y));
            printf("    D- Calcular la multiplicacion. (%.2f*%.2f): %2.f \n", x, y, thiagoMultiplica(x,y));
            printf("    E- Calcular el factorial de (%.2f!) : %.2f \n", x, thiagoFactorial(x));
            printf("    F- Calcular el factorial de (%.2f!) : %.2f \n", y, thiagoFactorial(y));
        }
        else
        {
            printf("    A- El resultado de (A+B) es: r\n");
            printf("    B- El resultado de (A-B) es: r\n");
            printf("    C- El resultado de (A/B )es: r\n");
            printf("    D- El resultado de (A*B) es: r\n");
            printf("    E- El factorial de (A!) es: r\n");
            printf("    F- El factorial de (B!) es: r\n");
        }
        printf("5- Salir \n");

        if(bandera1==1 && bandera2==1)
        {
            printf("6- Ingresar nuevos operandos.\n");
        }


        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            printf("Ingrese el primer operando:\n");
            scanf("%f", &x);

            bandera1=1;
            break;
        case 2:
            printf("Ingrese el primer operando:\n");
            scanf("%f", &y);

            bandera2=1;
            bandera3=0;
            break;
        case 3:
            bandera3=1;
            break;
        case 4:
            if(bandera3==1)
            {
                bandera4=1;
            }
            else
            {
                printf("Primero se deben calcular las operaciones.\n\n\n");
                system("pause");
            }

            break;
        case 5:
            seguir='n';
            break;
        case 6:
            bandera1=0;
            bandera2=0;
            bandera3=0;
            bandera4=0;
            break;

        default:
            printf("Ingrese una opcion valida.\n\n");
            system("pause");
            break;
        }

    }while(seguir=='s');

    return 0;
}
















