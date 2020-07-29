#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Controller.h"
#include "bicicletas.h"

eBicicleta* bici_new(){
	return (eBicicleta*) malloc(sizeof(eBicicleta));
}

eBicicleta* bici_newParametros(char* idStr,char* nombre, char* tipo, char* tiempo){
	eBicicleta* bici=NULL;
	bici=bici_new();

	if(bici!=NULL && idStr!=NULL && nombre!=NULL && tipo!=NULL && tiempo!=NULL){

		if(bici_setId(bici, atoi(idStr)) == -1 ||
		   bici_setNombre(bici, nombre) == -1 ||
		   bici_setTipo(bici, tipo) == -1 ||
		   bici_setTiempo(bici, atoi(tiempo)) == -1)
		{
			bici_delete(bici);
			bici=NULL;
		}
	}
	return bici;
}

int bici_delete(eBicicleta* bici){
	int todoOk = -1;
	if(bici!=NULL){
		free(bici);
		bici=NULL;
		todoOk=0;
	}
	return todoOk;
}

//*****************************************
//************GETTERS Y SETTERS************
//*****************************************


int bici_setId(eBicicleta* bici,int id){
	int todoOk = -1;

	if(bici!=NULL && id>=0){
		bici->id_bike=id;
		todoOk=0;
	}
	return todoOk;
}

int bici_getId(eBicicleta* bici,int* id){
	int todoOk = -1;

	if(bici!=NULL && id!=NULL){
		*id = bici->id_bike;
		todoOk=0;
	}
	return todoOk;
}

int bici_setNombre(eBicicleta* bici,char* nombre){
	int todoOk = -1;

	if(bici!=NULL && nombre!=NULL){
		strcpy(bici->nombre, nombre);
		todoOk=0;
	}
	return todoOk;
}

int bici_getNombre(eBicicleta* bici,char* nombre){
	int todoOk = -1;

	if(bici!=NULL && nombre!=NULL){
		strcpy(nombre, bici->nombre);
		todoOk = 0;
	}
	return todoOk;
}


int bici_setTipo(eBicicleta* bici,char* tipo){
	int todoOk = -1;

	if(bici!=NULL && tipo!=NULL){
		strcpy(bici->tipo, tipo);
		todoOk = 0;
	}
	return todoOk;
}

int bici_getTipo(eBicicleta* bici,char* tipo){
	int todoOk = -1;

	if(bici!=NULL && tipo!=NULL){
		strcpy(tipo, bici->tipo);
		todoOk = 0;
	}
	return todoOk;
}

int bici_setTiempo(eBicicleta* bici,int tiempo){
	int todoOk = -1;

	if(bici != NULL){
		bici->tiempo=tiempo;
		todoOk=0;
	}
	return todoOk;
}

int bici_getTiempo(eBicicleta* bici,int* tiempo){
	int todoOk = -1;

	if(bici!=NULL && tiempo!=NULL){
		*tiempo = bici->tiempo;
		todoOk = 0;
	}
	return todoOk;
}

//*****************************************
//*****************************************
//*****************************************

int bici_print(LinkedList* pArrayListBicicleta, int index){
	int todoOk = -1;
	eBicicleta* bici;

	if(pArrayListBicicleta!=NULL && index>=0){
		bici=(eBicicleta*)ll_get(pArrayListBicicleta,index);
            if(bici!=NULL){

                printf("%3d     %20s  %20s     %3d \n", bici->id_bike,bici->nombre,bici->tipo,bici->tiempo);

                todoOk = 0;
            }
		}
		else{
			printf("Error\n");
		}

	return todoOk;
}

//**************RANDOM************
void* bici_setTiempoRandom(void* bici){
	eBicicleta* auxBici=NULL;

	if(bici!=NULL){
		auxBici=(eBicicleta*) bici;

		bici_setTiempo(auxBici, getTiempoRandom());
	}
	return auxBici;
}

int getTiempoRandom(){
    int random;
    //50 y 120
    random=rand()%(71)+50;

    return random;
}

