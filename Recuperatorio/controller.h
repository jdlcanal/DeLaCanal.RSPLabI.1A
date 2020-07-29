#include "LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
/** \brief Carga los datos desde el archivo csv
 *
 * \param path, lista de ll
 * \return -1 error, 0 todoOk
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBicicleta);
/**
 * \brief Lista los datos
 * \param pArrayListBicicleta LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_ListBici(LinkedList* pArrayListBicicleta);
/**
 * \brief Asigna los datos del tiempo de manera aleatoria
 * \param pArrayListBicicleta LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_setTiempo(LinkedList* pArrayListBicicleta);
/**
 * \brief Guarda los datos en el archivo bicicletasGuardadas.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListBicicleta LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBicicleta);
