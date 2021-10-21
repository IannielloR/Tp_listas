#ifndef _LISTA_H
#define _LISTA_H

#include <stdlib.h>
#include <stdbool.h>


/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La lista está planteada como una cola de punteros genéricos. */
typedef struct lista lista_t;

typedef struct lista_iter lista_iter_t;


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Destruye la lista.
// Pre: la lista fue creada.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

// Devuelve verdadero si la lista no tiene elementos, false en caso contrario.
// Pre: la lista fue creada.
//Post: se devuelve true si la lista no tiene elementos, de lo contrario devuelve false
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista, quedando el mismo como primero
// Pre: la lista fue creada.
//Post: se agregó un nuevo elemento a la lista, se encuentra al principio de la lista
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista, quedando el mismo como ultimo
// Pre: la lista fue creada.
//Post: se agregó un nuevo elemento a la lista, se encuentra al final de la lista
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Borra el primer elemento de la lista. Si la lista tiene elementos, se borra el
// primero de la lista, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

// Devuelve el largo de la lista
// Pre: la lista fue creada.
// Post: se devolvió la cantidad de elementos de la lista
size_t lista_largo(const lista_t *lista);

/* *****************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/


// Recorre toda la lista aplicando la funcion visitar, si esta no retorna false, a cada
// elemento. Puede utilizar un dato extra.
// Pre: la lista fue creada, y visitar devuelve un booleano.
// Post: la funcion se aplicara a todos los elementos mientras no devuelva false.
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

 /* *****************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

// Crea el iterador, que apuntara al primer elemento de la lista, si falla devuelve NULL.
// Pre: la lista fue creada.
// Post: se creo el iterador.
lista_iter_t *lista_iter_crear(lista_t *lista);

// El iterador apuntara al siguiente elemento y devuelve false. Si estuviese 
// al final, devuelve false.
// Pre: el iterador fue creado.
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el valor del elemento actual, si estuviese al final, devuelve false.
// Pre: el iterador fue creado.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Si el iterador apunta al final, devuelve true, caso contrario, devuelve false.
// Pre: el iterador fue creado.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
void lista_iter_destruir(lista_iter_t *iter);

// Inserta el nuevo elemento a la lista, detras del elemento actual.
// Pre: el iterador fue creado.
// Post: se añadio un nuevo elemento a la lista y el iterador apuntara a este mismo.
// Se modifico la lista
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Elimina el elemento actual de la lista, y el iterador apuntara al siguiente.
// Pre: el iterador fue creado.
// Post: se elimino el elemento de la lista y el iterador apuntara al siguiente.
// Se modifico la lista
void *lista_iter_borrar(lista_iter_t *iter);

/* *****************************************************************
 *                    PRUEBAS PARA LA LISTA
 * *****************************************************************/
void pruebas_lista_estudiante(void);

#endif  // _LISTA_H

