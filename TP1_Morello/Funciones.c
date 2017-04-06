#include "Funciones.h"

float suma(float a, float b)
{
    float resultado;
    resultado = a+b;
    return resultado;
}

float resta(float a, float b)
{
    float resultado;
    resultado = a-b;
    return resultado;
}

float multiplicacion(float a, float b)
{
    float resultado;
    resultado = a*b;
    return resultado;
}

float division(float a, float b)
{
    float resultado;
    resultado = a/b;
    return resultado;
}

long int factorial(long int a)
{
    long int resultado = 1;
    long int i;
    for(i=a;i>0;i--)
    {
        resultado = resultado*i;
    }
    return resultado;
}
