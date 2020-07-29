#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "bicicletas.h"
#include <time.h>

int menu();

int main()
{
    char seguir='s';
    char confirm;

    LinkedList* lista = ll_newLinkedList();
    if(lista==NULL){
        printf("No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    do{
        switch(menu())
        {
            case 1:
                if(ll_isEmpty(lista)==0){
                    printf("ERROR!!! Ya cargaste los datos!!!\n\n");
                }
                else{
                    controller_loadFromText("bicicletas.csv",lista);
                }
                break;
            case 2:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_ListBici(lista);
                }
                break;
            case 3:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_setTiempo(lista);
                }
                break;
            case 4:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{

                }
                break;
            case 5:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{

                }
                break;
            case 6:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_saveAsText("bicicletasGuardadas.csv",lista);
                }
                break;
            case 7:
                printf("Esta seguro que desea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    seguir='n';
                    printf("Adios!! \n\n");
                }
                break;
            default:
                printf("ERROR!!! INGRESE UNA OPCION VALIDA!!!\n\n");
                break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
/** \brief Menu general del programa
 *
 * \return int
 *
 */

int menu(){
    int opcion;

    system("cls");
    printf("Bienvenido!!!\n");
    printf("1. Cargar Archivo\n");
    printf("2. Imprimir Lista\n");
    printf("3. Asignar Tiempos\n");
    printf("4. Filtrar por Tipo(No llegue a hacerlo)\n");
    printf("5. Mostrar Posiciones(No llegue a hacerlo)\n");
    printf("6. Guardar Archivo\n");
    printf("7. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

