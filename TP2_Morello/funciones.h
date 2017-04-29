#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//***********************************************************************
typedef struct{
    char nombre[60];
    int iteracion;
    char dni[11];
    char edad[3];
    int edadAux; //SE UTILIZA PARA EL GR�FICO.
    int estado;
} persona;
//***********************************************************************
/** \brief Convierte la primer letra de un texto ingresado en may�scula.
 * \param Texto ingresado.
 * \return Texto convertido a may�scula en la primer letra de cada palabra.
 */
char valMinMayus(char texto[]);
//***********************************************************************
/**
 * \brief Verifica que el valor recibido sea s�lo letras.
 * \param str array con el texto ha ser analizado.
 * \return Devuelve 1 si contiene s�lo espacio o letras, y 0 si no lo es.
 */
int soloLetras(char str[]);
//***********************************************************************
/** \brief Verifica que el valor recibido sea s�lo n�meros.
 * \param str array con el entero.
 * \return Devuelve 1 si contiene s�lo n�meros.
 */
int soloNum(char str[]);
//***********************************************************************
/** \brief Busca por estado.
 * \param Array de la persona.
 * \param M�xima capacidad de iteraciones.
 * \return Devuelve -1.
 */
int buscarEspacioLibre(persona laPersona[], int arrayTam);
//***********************************************************************
#endif // FUNCIONES_H_INCLUDED


