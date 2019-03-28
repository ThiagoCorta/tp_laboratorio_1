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



    char seguir='s';

    do
    {
        if (bandera1==0)
        {
            printf("1- Ingresar 1er operando (A=X)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%0.f)\n", x);

        }

        if(bandera2==0)
        {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%0.f)\n", y);
        }

        if(bandera1==1 && bandera2==1)
        {
            bandera3==1;
        }

        switch(mostrarMenu())
        {
        case 1:
            x=primerOperando();
            bandera1=1;
            break;
        case 2:
            y=segundoOperando();
            bandera2=1;
            break;
        case 3:
            if(bandera3==1)
            {
                thiagoCalculaOperaciones(x,y);
                bandera4=1;
            }
            else
            {
                printf("No se ingreso ningun valor que calcular.");
            }
            break;

        case 4:
            if(bandera4==1)
            {
                thiagoMuestraResultados(x,y);
            }
            else
            {
                printf("No se hicieron los calculos.");
            }
            break;

        case 5:
            seguir='n';
            break;

        default:
            printf("Ingrese un numero valido");
            break;
        }





    }
    while(seguir=='s');

}












