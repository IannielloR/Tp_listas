#include "Lista.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRUEBA_VOLUMEN 10000
#define NUM_PRUEBAS 6

/*
Prueba de algunos elementos
*/
void pruebas_algunos_elementos(){
    printf("\nINICIO DE PRUEBAS DE ALGUNOS ELEMENTOS\n");

    /*Creo una cola*/
    lista_t* lista = lista_crear();

    /*Elementos y el tamaño*/
    int elementos[] = {20, 30, 10, 40, 50, 60};

    /*Pruebo si la cola se comporta correctamente en las condiciones bordes*/
    print_test("Crea lista", lista != NULL);

    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));
    
    /*Pruebo insertar los elementos al principio*/
    for(size_t i=0; i < NUM_PRUEBAS; i++){

        printf("nro: %d\n", elementos[i]);
        print_test("Insertamos el elemento", lista_insertar_primero(lista, &elementos[i]));
        print_test("El primer numero es correcto", lista_ver_primero(lista) == &elementos[i]); 
    }

    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[5]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[0]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 6);
    print_test("Borrar primero es correcto", lista_borrar_primero(lista) == &elementos[5]);
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[4]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[0]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 5);


    /*Pruebo insertar los elementos al final*/
    for(size_t i=0; i < NUM_PRUEBAS; i++){

        printf("nro: %d\n", elementos[i]);
        print_test("Insertamos el elemento", lista_insertar_ultimo(lista, &elementos[i]));
        print_test("El ultimo numero es correcto", lista_ver_ultimo(lista) == &elementos[i]); 
    }

    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[4]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[5]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 11);
    print_test("Borrar primero es correcto", lista_borrar_primero(lista) == &elementos[4]);
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[3]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[5]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 10);

    /*Probamos destruir la lista*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

}

/*
Pueba de elemnto NULL
*/
void pruebas_null(){
    printf("\nINICIO DE PRUEBAS DE NULL\n");

    /*Creo una cola*/
    lista_t* lista = lista_crear();

    /*Pruebo si la cola se comporta correctamente en las condiciones bordes*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));
    
    /*Pruebo si encola correctamente*/
    print_test("Insertar NULL es true", lista_insertar_primero(lista, NULL));

    /*Pruebo la cola ahora que esta encolada*/
    print_test("La lista esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == NULL);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == NULL);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 1);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos destruir la cola*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

}

/*
Prueba de volumen
 */
 void pruebas_volumen(){
    printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");

    /*Creo una cola*/
    lista_t* lista = lista_crear();

    /*Pruebo si la cola se comporta correctamente en las condiciones bordes*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Pruebo si encola correctamente*/
    size_t i;

    for(i = 0; i < NUM_PRUEBA_VOLUMEN; i++){
        
        print_test("Insertamos el elemento", lista_insertar_primero(lista, &i));
        print_test("El primer numero es correcto", lista_ver_primero(lista) == &i); 
    }

    /*Pruebo la cola ahora que esta encolada*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &i);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == 0);
    print_test("El largo de la lista es correcto", lista_largo(lista) == NUM_PRUEBA_VOLUMEN);

    /*Desencolamos*/

    while(!lista_esta_vacia(lista)){

        print_test("Desencolo y es true", lista_borrar_primero(lista) == &i);

        i--;

        if(!lista_esta_vacia(lista)){
            print_test("El primero numero es true", lista_ver_primero(lista) == &i); 
        }
    }

    /*Pruebo la cola desencolada*/
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos destruir la cola*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

 }

void destruir_aux(void* dato){
    lista_destruir(dato, NULL);
}

/*
Prueba de destruccion de colas encoladas
 */

void prueba_destruir(){

    /*Creo una cola*/
    lista_t* lista = lista_crear();


    /*Pruebo si la cola se comporta correctamente en las condiciones bordes*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));
    

    /*Pruebo encolar los elementos*/
    print_test("Insertamos el elemento", lista_insertar_primero(lista, lista_crear()));
    print_test("Insertamos el elemento", lista_insertar_ultimo(lista, lista_crear()));

    /*Pruebo la cola ahora que esta encolada*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 2);

    /*Probamos destruir la cola*/
    lista_destruir(lista, destruir_aux);
    print_test("Lista destruida", true);
}

void pruebas_lista_estudiante() {
    pruebas_algunos_elementos();
    pruebas_null();
    pruebas_volumen();
    prueba_destruir();
}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
