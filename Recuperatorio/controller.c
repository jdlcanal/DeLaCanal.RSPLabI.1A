#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "bicicletas.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBicicleta){
	int todoOk=-1;
	FILE* pFile;

	pFile=fopen(path, "r");

	if(pFile!=NULL){
		if(parser_BiciFromText(pFile, pArrayListBicicleta) == 0){
			printf("El Archivo fue cargado exitosamente!!!\n");
			todoOk=0;
		}
		else{
			printf("Error al cargar!!!\n");
		}
	}
	else{
		printf("Error!!!!\n");
	}

	fclose(pFile);

    return todoOk;
}

int controller_ListBici(LinkedList* pArrayListBicicleta){
	int todoOk=-1;
	if(pArrayListBicicleta!=NULL){
        system("cls");
		printf("\n id_bike           nombre                   tipo      tiempo\n");
		printf("------------------------------------------------------------------------------------\n");

		for(int i=0;i<ll_len(pArrayListBicicleta);i++){
			bici_print(pArrayListBicicleta,i);
		}
		todoOk=0;
	}
	else{
		printf("Error!!!\n");
	}

    return todoOk;
}

int controller_setTiempo(LinkedList* pArrayListBicicleta){
	int todoOk=-1;

	pArrayListBicicleta=ll_map(pArrayListBicicleta, bici_setTiempoRandom);

	if(pArrayListBicicleta!=NULL){
		controller_ListBici(pArrayListBicicleta);
		todoOk=0;
	}

	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListBicicleta){
	int todoOk = -1;

	FILE* pFile;
	int auxId;
	char auxNombre[20];
	char auxTipo[20];
	int auxTiempo;
	eBicicleta* bici;

	if(pArrayListBicicleta != NULL && path != NULL){
		pFile=fopen(path, "w");
		if(pFile!=NULL){
			todoOk=0;
			for(int i = 1; i < ll_len(pArrayListBicicleta); i++){
				bici = ll_get(pArrayListBicicleta, i);
				if(!bici_getId(bici, &auxId) &&
				   !bici_getNombre(bici, auxNombre) &&
				   !bici_getTipo(bici, auxTipo) &&
				   !bici_getTiempo(bici, &auxTiempo))
				{
					fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre, auxTipo, auxTiempo);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}
	}

    return todoOk;
}

