#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

char valMinMayus(char texto[])
{
    int i=0;
    strlwr(texto);
    while(texto[i]!='\0')
    {
        if(texto[0]!=' ')
        {
            texto[0]=toupper(texto[0]);
        }
        if((texto[i]==' ') && (texto[i+1]!=' '))
        {
            texto[++i]=toupper(texto[i]);
        }
        i++;
    }
    return 1;
}

int soloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
       {
           return 0;
       }
       i++;
   }
   return 1;
}

int soloNum(char str[])
{
   int i=0;
   while(str[i]!='\0')
   {
       if(!isdigit(str[i]))
       {
            return 0;
       }
       i++;
   }
   return 1;
}

int buscarEspacioLibre(persona laPersona[], int arrayTam)
{
    int i;
    for(i=0;i<arrayTam;i++)
    {
        if(laPersona[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

