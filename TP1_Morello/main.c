#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Funciones.h"

int main()
{

    char seguir='s';
    int opcion=0;
    float x = 0;
    float y = 0;
    int bandera1 = 0;
    int bandera2 = 0;
    float sumar;
    float restar;
    float multiplicar;
    float dividir;
    long int varFactorial;
    while(seguir=='s')
    {
        system("cls");
        printf("BIENVENIDO A LA CALCULADORA VIRTUAL!\n");
        printf("\nElija una opcion:\n");

        if(bandera1==0)
        {
            printf("\n1- Ingresar 1er operando (A=X)\n");
        }
        if(bandera1==1)
        {
            printf("\n1- Ingresar 1er operando (A=%f)\n", x);
        }

        if(bandera2==0)
        {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }
        if(bandera2==1)
        {
            printf("2- Ingresar 2do operando (B=%f)\n", y);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\nUsted eligio la opcion numero: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%f",&x);
                bandera1=1;
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%f",&y);
                bandera2=1;
                break;
            case 3:
                sumar = suma(x,y);
                printf("\nEl resultado de la suma es: %f\n", sumar);
                getch();
            case 4:
                restar = resta(x,y);
                printf("\nEl resultado de la resta es: %f\n", restar);
                getch();
                break;
            case 5:
                while(y==0)
                {
                    printf("\nError. El segundo operando debe ser distinto a cero: ");
                    scanf("%f",&y);
                }
                dividir = division(x,y);
                printf("\nEl resultado de la division es: %f\n", dividir);
                getch();
                break;
            case 6:
                multiplicar = multiplicacion(x,y);
                printf("\nEl producto de la multiplicacion es: %f\n", multiplicar);
                getch();
                break;
            case 7:
                while(x<0)
                {
                    printf("Error. Ingrese un numero mayor o igual a cero: ");
                    scanf("%f", &x);
                }
                float c = (int)x;
                if(x!=c)
                {
                    printf("Error, no se pueden calcular numeros con decimales.");
                }
                else
                {
                varFactorial = factorial(x);
                printf("\nEl factorial del primer operando es: %ld\n", varFactorial);
                }
                getch();
                break;
            case 8:
                sumar = suma(x,y);
                restar = resta(x,y);
                dividir = division(x,y);
                    while(y==0)
                    {
                        printf("\nError. El segundo operando debe ser distinto a cero: ");
                        scanf("%f",&y);
                    }
                multiplicar = multiplicacion(x,y);
                while(x<0)
                {
                    printf("Error. Ingrese un numero mayor o igual a cero: ");
                    scanf("%f", &x);
                }
                if(x!=c)
                {
                    printf("Error, no se pueden calcular numeros con decimales.");
                }
                else
                {
                varFactorial = factorial(x);
                }
                printf("\nLos resultados de todas las operaciones son:\n Suma: %f\n Resta: %f\n Division: %f\n Multiplicacion: %f\n Factorial del 1er operando: %ld\n ", sumar, restar, dividir, multiplicar, varFactorial);
                getch();
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
