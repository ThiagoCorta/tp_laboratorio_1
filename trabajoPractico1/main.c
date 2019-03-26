#include <stdio.h>
#include <stdlib.h>
#include "corta.h"


int main()
{
    float x;
    float y;
    float resultado1;
    float resultado2;
    float resultado3;
    float resultado4;
    float resultado5;

    char seguir='s';

    do
    {
        switch(mostrarMenu())
        {
            case 1:
                printf("Ingresar el 1er operando: ");
                fflush(stdin);
                scanf("%f", &x);
                break;
            case 2:
                printf("Ingresar el 2do operando: ");
                fflush(stdin);
                scanf("%f", &y);
                break;
            case 3:
                switch(menuOperaciones())
                {
                    case 1:
                        resultado1=thiagoSuma(x,y);
                        fflush(stdin);
                        break;
                    case 2:
                        resultado2=thiagoResta(x,y);
                        fflush(stdin);
                        break;
                    case 3:
                        resultado3=thiagoDivide(x,y);
                        fflush(stdin);
                        break;
                    case 4:
                        resultado4=thiagoMultiplica(x,y);
                        fflush(stdin);
                        break;
                    case 5:
                        resultado5=thiagoFactorial(x);
                        fflush(stdin);
                        break;
                    default:
                        printf("Ingresar una opcion valida..");
                        fflush(stdin);
                        break;
                }
                break;
                    case 4:
                        printf("1- El resultado de (A+B) es : %.0f\n", resultado1);
                        printf("2- La resta de (A-B) es : %.0f\n", resultado2);
                        printf("3- La division de (A/B) es : %.2f\n", resultado3);
                        printf("4- La multiplicacion de (A*B) es : %.0f\n", resultado4);
                        printf("5- El factorial de (A!) es : %.0f\n", resultado5);
                        system("pause");
                        fflush(stdin);
                        break;

                    case 5:
                        seguir='n';
                        fflush(stdin);

        }

    }while(seguir=='s');

}












