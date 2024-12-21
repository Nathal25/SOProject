#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include "leercadena.h"

#define SMILE "\U0001f600"
#define WINK "\U0001f609"
#define COLOMBIA "\U0001f1f4"

#define MAX 100

int main(int argc, char* argv[]) {
  char **vector_cadenas;
  char cadena[MAX];

  while (1) {
	pid_t pid;
	printf("> ");
	leer_de_teclado(MAX, cadena);
	if (strlen(cadena) == 0) {
	  printf("\?");
	  continue;
	}
	vector_cadenas = de_cadena_a_vector(cadena);
    int i = 0;
    printf("Cadenas digitadas\n");
    for (; vector_cadenas[i]; i++) {
        printf("\t%s\n",vector_cadenas[i]);
    }
    printf("\n");
  }
  exit(0);
}
