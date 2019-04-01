#include <stdio.h>
#include <stdlib.h>
#include "corta.h"


int main()
{
    //Declaro las variables y si es necesario las inicializo.
    int x;
    int y;
    int bandera1=0;
    int bandera2=0;
    int bandera3=0;
    int bandera4=0;
    int opcion;
    char seguir='s';

    //Iteraciones hasta que la persona decida salir.
    do
    {
        //Menu de opciones.
        // Uso de la primer bandera para poder actualizar los valores ingresados.
        system("cls");
        if (bandera1==0)
        {
            printf("1- Ingresar 1er operando (A=X)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%d)\n", x);

        }

        // Uso de la segunda bandera para poder actualizar los valores ingresados.
        if(bandera2==0)
        {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n", y);
        }

        printf("3- Calcular las operaciones.\n");

        // Un switch para actualizar los valores cuando el usuario ingresa las opciones.
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
            printf("    A- Calcular la suma (%d+%d): \n", x, y);
            printf("    B- Calcular la resta (%d-%d): \n", x, y);
            printf("    C- Calcular la division (%d/%d): \n", x, y);
            printf("    D- Calcular la multiplicacion (%d*%d): \n", x, y);
            printf("    E- Calcular el factorial de (%d!): \n", x);
            printf("    F- Calcular el factorial de (%d!) : \n", y);
            break;
        }
        printf("4- Mostrar las operaciones\n");

        // Una ves que ingresaron valores, calcularon las operaciones, si ingresa opcion 4 se muestran los resultados.
        if(bandera4==1)
        {
            printf("    A- El resultado de (%d+%d) es: %d \n", x, y, thiagoSuma(x,y));
            printf("    B- El resultado de (%d-%d) es: %d \n", x, y, thiagoResta(x,y));
            if(y==0)
            {
                printf("    C- No se puede dividir por cero.\n");
            }
            else
            {
                printf("    C- El resultado de (%d/%d) es: %.2f\n", x, y, thiagoDivide(x,y));
            }
            printf("    D- El resultado de (%d*%d) es: %d \n", x, y, thiagoMultiplica(x,y));
            if(x>=0)
            {
                printf("    E- El factorial de (%d!) es: %.0f \n", x, thiagoFactorial(x));

            }
            else
            {
                printf("    No se puede calcular el factorial de numeros negativos.\n");
            }
            if(y>=0)
            {
                printf("    F- El factorial de (%d!) es: %.0f \n", y, thiagoFactorial(y));
            }
            else
            {
                printf("    No se puede calcular el factorial de numeros negativos.\n");
            }

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

        //Si x e y tienen valores cargados, aparece la opcion de ingresar nuevos operandos.
        if(bandera1==1 && bandera2==1)
        {
            printf("6- Ingresar nuevos operandos.\n");
        }

        //Scaneo la opcion ingresada.
        scanf("%d", &opcion);
        system("cls");

        //Switch con las opciones y dandole uso a las banderas.
        switch(opcion)
        {
        case 1:
            //Pido el operando x
            printf("Ingrese el primer operando:\n");
            scanf("%d", &x);

            bandera1=1;
            break;
        case 2:
            //Pido el operando y
            printf("Ingrese el primer operando:\n");
            scanf("%d", &y);

            bandera2=1;
            bandera3=0;
            break;
        case 3:
            //Si no ingreso operandos no se pueden calcular las operaciones.
            if(bandera1==1 && bandera2==1)
            {
                bandera3=1;
            }
            else
            {
                printf("Debe ingresar los operando.\n\n");
                system("pause");
            }

            break;
        case 4:
            // Si no se ingresaron operandos y calcularon las operaciones, no se puede mostrar los resultados.
            if(bandera1==1 && bandera2==1 && bandera3==1)
            {
                bandera4=1;
            }
            else
            {
                printf("Primero se deben calcular las operaciones.\n\n");
                system("pause");
            }


            break;
        case 5:
            seguir='n';
            break;
        case 6:
            //En el caso 6 declaro todas las banderas en 0 para ingresar y calcular nuevos operandos.
            bandera1=0;
            bandera2=0;
            bandera3=0;
            bandera4=0;
            break;

        default:
            //Si no ingresa una opcion del menu valida, aparece este mensaje y te pide que ingreses uno valido.
            printf("Ingrese una opcion valida.\n\n");
            system("pause");
            break;
        }

    }while(seguir=='s');

    return 0;

}















