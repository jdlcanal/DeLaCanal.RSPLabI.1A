#include "LinkedList.h"
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayListBici
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_BiciFromText(FILE* pFile,LinkedList* pArrayListBici);
