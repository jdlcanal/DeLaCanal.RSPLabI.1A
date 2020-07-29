#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "bicicletas.h"

int parser_BiciFromText(FILE* pFile,LinkedList* pArrayListBici){
	int todoOk = -1;
	eBicicleta* bici;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];

	if(pFile!=NULL && pArrayListBici!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
		do{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4){

				bici=bici_newParametros(id, nombre, tipo, tiempo);

				if(bici!=NULL){
					ll_add(pArrayListBici, bici);
					todoOk=0;
				}
			}
			else{
				break;
			}

		}while(feof(pFile)==0);
	}

    return todoOk;
}
