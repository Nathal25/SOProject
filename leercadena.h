#ifndef __LEER_CADENA__
#define __LEER_CADENA__

#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 20
#define TAM_TOKEN 80

// Lee por teclado un maximo de 'int' caracteres en buffer 'char*'
int leer_de_teclado(int, char*);

// Recibe un 'char*' separado por espacios y devuelve un vector donde cada 
// posicion del vector es una de las palabras en 'char*' y tiene una ultima
// posicion con el valor NULL.
// Si se recibe en 'char*' = "hola mundo" esta funcion retorna un vector
// char** = { "hola", "mundo", NULL }
// Esta funcion es adecuada para que el valor retornado sea usado para las 
// funciones de la familia execv*
char** de_cadena_a_vector(char*);

// Esta funcion recibe una cadena toFind como argumento y se busca dicha cadena
// en 'pile'.
// Si la cadena no se encuentra se devuelve el valor de -1 de lo contrario se
// devuelve el indice donde se encontro dicha cadena.
int encontrar_cadena(char* toFind, char** pile);

#endif
