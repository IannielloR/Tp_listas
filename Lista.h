#ifndef _LISTA_H
#define _LISTA_H

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
 void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

 /* *****************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

lista_iter_t *lista_iter_crear(lista_t *lista);
bool lista_iter_avanzar(lista_iter_t *iter);
void *lista_iter_ver_actual(const lista_iter_t *iter);
bool lista_iter_al_final(const lista_iter_t *iter);
void lista_iter_destruir(lista_iter_t *iter);
bool lista_iter_insertar(lista_iter_t *iter, void *dato);
void *lista_iter_borrar(lista_iter_t *iter);

/* *****************************************************************
 *                    PRUEBAS PARA LA LISTA
 * *****************************************************************/
void pruebas_lista_estudiante(void);

#endif  // _LISTA_H
