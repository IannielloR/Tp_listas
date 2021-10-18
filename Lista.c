#include "lista.h"
#include <stdlib.h>

typedef struct nodo{
    void* dato;
    struct nodo* siguiente;
}nodo_t;

typedef struct lista{
    struct nodo* primero;
    struct nodo* ultimo;
    size_t largo;
}lista_t;

nodo_t* crear_nodo(void* dato){

    nodo_t* nodo = malloc(sizeof(nodo_t));

     if (nodo == NULL) {

         return NULL;

    }

    nodo->dato = dato;
    nodo->siguiente = NULL;

    return nodo;
}

void destruir_nodo(nodo_t* nodo){
    free(nodo);
}

/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void){
    lista_t* lista = malloc(sizeof(lista_t));

    if (lista == NULL) {

        return NULL;
        
    }

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->largo = 0;

    return lista;
}

bool lista_esta_vacia(const lista_t *lista){
    return !lista->primero || !lista->ultimo || lista->largo == 0;
}

bool lista_insertar_primero(lista_t *lista, void *dato){
    nodo_t* nodo = crear_nodo(valor);

    if (!nodo){
        return false;
        }

    if(!lista_esta_vacia(lista)){
        nodo->siguiente = lista->primero;
    }else{
        lista->ultimo = nodo;
    }

    lista->primero = nodo;
    lista->largo ++;
    return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){
    nodo_t* nodo = crear_nodo(valor);

    if (!nodo){
        return false;
        }

    if(lista_esta_vacia(lista)){
        lista->primero = nodo;

    }else{
        lista->ultimo->siguiente = nodo;
    }

    lista->ultimo = nodo;
    lista->largo ++;

    return true;
}

void *lista_borrar_primero(lista_t *lista){
    if(lista_esta_vacia){
        return NULL;
    }

    nodo_t* nodo_aux =  lista->primero;
    void* dato_aux = lista->primero->dato;
    lista->primero = lista->primero->siguiente;

    if(!lista->primero->siguiente){
        lista->ultimo = NULL;
    }

    destruir_nodo(nodo);
    lista->largo --;

    return dato;

}

void *lista_ver_primero(const lista_t *lista){
    if(!lista_esta_vacia){
        return NULL;
    }

    return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista){
    if(!lista_esta_vacia){
        return NULL;
    }

    return lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista){
    return lista->largo;
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)){

    while(!lista_esta_vacia(lista)){
        void* dato = lista_borrar_primero(lista);
        if(destruir_dato){
            (*destruir_dato)(dato);
        }
    }
    free(lista);
}