#include "Lista.h"
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


typedef struct lista_iter {
	struct nodo* actual;
	struct nodo* anterior;
    lista_t* lista;
} lista_iter_t;


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

lista_t* lista_crear(void){
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
    nodo_t* nodo = crear_nodo(dato);

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
    nodo_t* nodo = crear_nodo(dato);

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
    if(lista_esta_vacia(lista)){
        return NULL;
    }

    nodo_t* nodo_aux =  lista->primero;
    void* dato_aux = lista->primero->dato;
    lista->primero = lista->primero->siguiente;

    if(!lista->primero->siguiente){
        lista->ultimo = NULL;
    }

    destruir_nodo(nodo_aux);
    lista->largo --;

    return dato_aux;

}

void *lista_ver_primero(const lista_t *lista){
    if(!lista_esta_vacia(lista)){
        return NULL;
    }

    return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista){
    if(!lista_esta_vacia(lista)){
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


/* *****************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/


 void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){
     nodo_t *actual = lista->primero;
     bool seguir = true;
     for(int i = 0; i < lista->largo; i++){
        if(seguir){
            seguir = visitar(actual->dato, extra);
        }
        actual = actual -> siguiente;
    }
 }


 /* *****************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/


lista_iter_t *lista_iter_crear(lista_t *lista){
    lista_iter_t *lista_iter = malloc(sizeof(lista_iter_t));
    if(!lista_iter)return NULL;       // Si malloc no me concede memoria, salgo
    lista_iter->lista = lista;
    lista_iter->actual = lista->primero;
    lista_iter->anterior = NULL;
    return lista_iter;
}


bool lista_iter_avanzar(lista_iter_t *iter){
    if(!iter->actual) return false;      // Si el actual es NULL (ultimo) devuelvo false
    iter->anterior = iter->actual;
    iter->actual = iter->actual->siguiente;
    return true;
}


void *lista_iter_ver_actual(const lista_iter_t *iter){
    if(!iter->actual) return NULL;       //Si estoy en el ultimo, devuelvo NULL
    return iter->actual->dato;
}


bool lista_iter_al_final(const lista_iter_t *iter){
    return (!(iter->actual));
}


void lista_iter_destruir(lista_iter_t *iter){
    free(iter);
}


bool lista_iter_insertar(lista_iter_t *iter, void *dato){
    nodo_t *nodo = crear_nodo(dato);
    if(!(nodo))return false;

    if(!iter->anterior)iter->anterior->siguiente = nodo;

    nodo->siguiente = iter->actual;
    iter->anterior = nodo;
    return true;
}


void *lista_iter_borrar(lista_iter_t *iter){
    nodo_t *aux_nodo = iter->actual->siguiente;
    void * aux_dato = iter->actual->dato;

    destruir_nodo(iter->actual);

    if(!iter->anterior)iter->anterior->siguiente = aux_nodo;
    iter->actual = aux_nodo;
    return aux_dato;
}
