#include "LinkedList.h"
#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;



#endif // BICICLETAS_H_INCLUDED

/**
 * \brief Pide memoria con malloc
 * \param
 * \return Retorna un puntero a eBicicleta
 */
eBicicleta* bici_new();
/**
 * \brief Llama a los setters que cargan los campos
 * \param idStr, cadena de caracteres de id
 * \param nombre, cadena de caracteres de nombre
 * \param tipo, cadena de caracteres de tipo
 * \param tiempo, cadena de caracteres de tiempo
 * \return Retorna un puntero a eBicicleta
 */
eBicicleta* bici_newParametros(char* idStr,char* nombre, char* tipo, char* tiempo);
/**
 * \brief Elimina una bicicleta
 * \param  puntero a bicicleta
 * \return -1 en caso de error, o 0 en caso de exito
 */
int bici_delete(eBicicleta* bici);

/**
 * \brief Valida y carga el id en el campo
 * \param bici, puntero a eBicicleta
 * \param id, id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int bici_setId(eBicicleta* bici,int id);
/**
 * \brief Carga el id en el puntero que se pase por parametros
 * \param bici, puntero a eBicicleta
 * \param id, puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int bici_getId(eBicicleta* bici,int* id);

/**
 * \brief Valida y carga el nombre en el campo nombre
 * \param bici, puntero a eBicicleta
 * \param nombre, cadena de caracteres de nombre a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int bici_setNombre(eBicicleta* bici,char* nombre);
/**
 * \brief Carga el nombre en el puntero que pasemos por parametros
 * \param bici, puntero a eBicicleta
 * \param nombre, cadena de caracteres en la que la funcion cargara el nombre
 * \return -1 en caso de error, o 0 en caso de exito
 */
int bici_getNombre(eBicicleta* bici,char* nombre);

int bici_setTipo(eBicicleta* bici,char* tipo);
int bici_getTipo(eBicicleta* bici,char* tipo);

int bici_setTiempo(eBicicleta* bici,int tiempo);
int bici_getTiempo(eBicicleta* bici,int* tiempo);

int bici_print(LinkedList* pArrayListBicicleta, int index);

void* bici_setTiempoRandom(void* bici);
int getTiempoRandom();

int bici_filtrarTipo(void* bici);

int menuFilter();
