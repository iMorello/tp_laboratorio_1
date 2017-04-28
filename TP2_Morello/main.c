#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define I 3

int main()
{
    persona laPersona[I];
    persona auxiliar;
    int j=0;
    int x;
    char texto[60];
    int dni=0;
    int edad=0;
    int flagMatch=0;
    int continuar;
    int espVacio;
    //**************
    //VARIABLES DEL GRÁFICO DE EDADES.
    int graf[3][20];
    int cont1=0;
    int cont2=0;
    int cont3=0;
    //**************
    char seguir='s';
    char opcionChar[2];
    int opcion=0;

    //SE INICIALIZAN LOS ESTADOS EN 0.
    for(j=0; j<I; j++)
    {
        laPersona[j].estado=0;
    }

    //MENÚ.
    while(seguir=='s')
    {
        system("cls");
        printf("Trabajo Practico 2 - Ignacio Morello.\n\nELIJA UNA OPCION: \n\n1- Agregar persona.\n2- Borrar persona.\n3- Imprimir lista ordenada por nombre.\n4- Imprimir grafico de edades.\n5- Modificar datos de usuario.\n6- Salir.\n\nUsted eligio la opcion: ");
        scanf("%s",opcionChar);
        //VALIDACIÓN DE MENÚ.
        while(!soloNum(opcionChar))
        {
            printf("\nError: Caracter invalido.\nIngrese una opcion correcta: ");
            scanf("%s",opcionChar);
        }
        opcion=atoi(opcionChar);
        while(opcion<1 || opcion>6)
        {
            printf("\nError: Opcion no habilitada.\nElija una opcion del 1 al 6: ");
            scanf("%s",opcionChar);
            opcion=atoi(opcionChar);
        }
        //********************************************************************
        switch(opcion)
        {
            case 1:
                espVacio=buscarEspacioLibre(laPersona,I);
                if(espVacio==-1)
                {
                    printf("\nNo hay lugar disponible para carga de datos. Elija otra opcion.\n");
                    system("pause");
                    break;
                }
                for(j=0; j<I; j++)
                {
                    if(laPersona[j].estado==0)
                    {
                        printf("\nIngrese el nombre completo de la persona: ");
                        fflush(stdin);
                        gets(texto);
                        //VALIDACIÓN DE NOMBRE.
                        while(!soloLetras(texto))
                        {
                            printf("\nError: Caracteres invalidos.\nIngrese el nombre completo de la persona: ");
                            fflush(stdin);
                            gets(texto);
                        }
                        valMinMayus(texto);
                        strcpy(laPersona[j].nombre, texto);

                        //********************************************************************
                        printf("Ingrese el DNI de la persona: ");
                        scanf("%s",laPersona[j].dni);
                        //VALIDACIÓN DE DNI.
                        while(!soloNum(laPersona[j].dni))
                        {
                            printf("\nError: Caracteres invalidos.\nIngrese un DNI correcto: ");
                            scanf("%s",laPersona[j].dni);
                        }
                        dni=atoi(laPersona[j].dni);
                        while(dni<2000000 || dni>999999999)
                        {
                            printf("\nError: DNI invalido.\nIngrese un DNI correcto: ");
                            scanf("%s",laPersona[j].dni);
                            dni=atoi(laPersona[j].dni);
                        }

                        //********************************************************************
                        printf("Ingrese la edad de la persona: ");
                        scanf("%s",laPersona[j].edad);
                        //VALIDACIÓN DE EDAD.
                        while(!soloNum(laPersona[j].edad))
                        {
                            printf("\nError: Caracteres invalidos.\nIngrese una edad correcta: ");
                            scanf("%s",laPersona[j].edad);
                        }
                        edad=atoi(laPersona[j].edad);
                        laPersona[j].edadAux=atoi(laPersona[j].edad); //PARA EL GRÁFICO.
                        while(edad<1 || edad>99)
                        {
                            printf("\nError: Numero no valido.\nIngrese la edad correcta: ");
                            scanf("%s",laPersona[j].edad);
                            edad=atoi(laPersona[j].edad);
                        }
                        //UNA VEZ CARGADOS LOS DATOS, CONVIERTE EL ESTADO A 1.
                        laPersona[j].estado=1;
                        break;
                    }
                }
                break;

            case 2: //BORRAR PERSONA.
                printf("\nIngrese numero de DNI de la persona que desea borrar: ");
                scanf("%d",&dni);
                for(j=0; j<I; j++)
                {
                    int dniAux=atoi(laPersona[j].dni);
                    if(laPersona[j].estado==1 && dni==dniAux)
                    {
                        printf("\nNOMBRE: %s.\nEDAD: %s.\nDNI: %s.\n\n\nSi desea dar de baja los datos de esta persona, presione '1': ", laPersona[j].nombre, laPersona[j].edad, laPersona[j].dni);
                        scanf("%d",&continuar);
                        if(continuar==1)
                        {
                            printf("Usuario borrado de forma exitosa.\n");
                            laPersona[j].estado = 0;
                        }
                        else
                        {
                            if(continuar!=1)
                            {
                                printf("\nAccion cancelada.\n\n");
                            }
                        }
                        flagMatch=1;
                        break;
                    }
                }
                if(flagMatch!=1)
                {
                    printf("\nDNI inexistente.\n\n");
                }
                system("pause");
                break;

            case 3: //ORDENAMIENTO POR NOMBRE.
                printf("\nORDEN POR NOMBRE:\n");
                for(j=0; j<I-1; j++)
                {
                    if(laPersona[j].estado==1)
                    {
                        for(x=j+1; x<I; x++)
                        {
                            if(laPersona[x].estado==1)
                            {
                                if(strcmp(laPersona[x].nombre,laPersona[j].nombre)<0)
                                {
                                    //BURBUJEO.
                                    auxiliar=laPersona[x];
                                    laPersona[x]=laPersona[j];
                                    laPersona[j]=auxiliar;
                                }
                            }
                        }
                    }
                }
                for(j=0; j<I; j++)
                {
                    if(laPersona[j].estado!=0)
                    {
                        printf("\n%s\tDNI: %s.\tEdad: %s.\n", laPersona[j].nombre, laPersona[j].dni, laPersona[j].edad);
                    }
                }
                system("pause");
                break;

            case 4: //ORDENA CON UN GRÁFICO POR EDAD.
                cont1=0;
                cont2=0;
                cont3=0;
                for(j=0;j<I;j++)
                {
                    graf[0][j]=' ';
                    graf[1][j]=' ';
                    graf[2][j]=' ';
                }
                for(j=0;j<I;j++)
                {
                    if(laPersona[j].edadAux<19)
                    {
                        cont1++;
                    }
                    if((laPersona[j].edadAux>=19)&&(laPersona[j].edadAux<=35))
                    {
                        cont2++;
                    }
                    if(laPersona[j].edadAux>35)
                    {
                        cont3++;
                    }
                }

                for(j=0;j<I;j++)
                {
                    if(j<cont1)
                    {
                        graf[0][j]='*';
                    }
                    if(j<cont2)
                    {
                        graf[1][j]='*';
                    }
                    if(j<cont3)
                    {
                        graf[2][j]='*';
                    }
                }

                for(j=I-1;j>=0;j--)
                {
                    printf("%c\t%c\t%c\n", graf[0][j], graf[1][j], graf[2][j]);
                }
                printf("<18\t19a35\t>35\n");
                system("pause");
                break;

            case 5: //MODIFICACIÓN DE DATOS.
                printf("\nIngrese numero de DNI de la persona que desea modificar: ");
                scanf("%d",&dni);
                for(j=0; j<I; j++)
                {
                    int dniAux=atoi(laPersona[j].dni);
                    if(laPersona[j].estado==1 && dni==dniAux)
                    {
                        printf("\nNOMBRE: %s.\nEDAD: %s.\nDNI: %s.\n\n\nSi desea modificar los datos de esta persona, presione '1': ", laPersona[j].nombre, laPersona[j].edad, laPersona[j].dni);
                        scanf("%d",&continuar);
                        if(continuar==1)
                        {
                            printf("\nIngrese el nuevo nombre: ");
                            fflush(stdin);
                            gets(texto);
                            //SE VALIDA NUEVAMENTE EL NOMBRE.
                            while(!soloLetras(texto))
                            {
                                printf("\nError: Caracteres invalidos.\nIngrese el nuevo nombre completo de la persona: ");
                                fflush(stdin);
                                gets(texto);
                            }
                            valMinMayus(texto);
                            strcpy(laPersona[j].nombre, texto);

                            //********************************************************************
                            printf("Ingrese la nueva edad: ");
                            scanf("%s",laPersona[j].edad);
                            //SE VALIDA LA EDAD NUEVAMENTE.
                            while(!soloNum(laPersona[j].edad))
                            {
                                printf("\nError: Caracteres invalidos.\nIngrese una edad correcta: ");
                                scanf("%s",laPersona[j].edad);
                            }
                            edad=atoi(laPersona[j].edad);
                            while(edad<1 || edad>100)
                            {
                                printf("\nError: Numero no valido.\nIngrese la edad correcta: ");
                                scanf("%s",laPersona[j].edad);
                                edad=atoi(laPersona[j].edad);
                            }
                            //********************************************************************
                            printf("\nLos datos se modificaron de forma exitosa.\n");
                        }
                        else
                        {
                            if(continuar!=1)
                            {
                                printf("\nAccion cancelada.\n\n");
                            }
                        }
                        flagMatch=1;
                        break;
                    }
                }
                if(flagMatch!=1)
                {
                    printf("\nDNI inexistente.\n\n");
                }
                system("pause");
                break;

            case 6: //SALIR.
                seguir = 'n';
                break;
        }
    }
    return 0;
}
