#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//***********************************************************************
typedef struct{
    char nombre[60];
    int iteracion;
    char dni[11];
    char edad[3];
    int edadAux; //SE UTILIZA PARA EL GRÁFICO.
    int estado;
} persona;
//***********************************************************************
/** \brief Convierte la primer letra de un texto ingresado en mayúscula.
 * \param Texto ingresado.
 * \return Texto convertido a mayúscula en la primer letra de cada palabra.
 */
char valMinMayus(char texto[]);
//***********************************************************************
/**
 * \brief Verifica que el valor recibido sea sólo letras.
 * \param str array con el texto ha ser analizado.
 * \return Devuelve 1 si contiene sólo espacio o letras, y 0 si no lo es.
 */
int soloLetras(char str[]);
//***********************************************************************
/** \brief Verifica que el valor recibido sea sólo números.
 * \param str array con el entero.
 * \return Devuelve 1 si contiene sólo números.
 */
int soloNum(char str[]);
//***********************************************************************
/** \brief Busca por estado.
 * \param Array de la persona.
 * \param Máxima capacidad de iteraciones.
 * \return Devuelve -1.
 */
int buscarEspacioLibre(persona laPersona[], int arrayTam);
//***********************************************************************
#endif // FUNCIONES_H_INCLUDED


