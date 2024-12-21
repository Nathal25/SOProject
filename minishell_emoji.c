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
    if (strcmp("salir",vector_cadenas[0]) == 0) {  //strcmp = string compare
      printf("Gracias por usar mi dummy shell %s%s%s\n",SMILE,WINK,COLOMBIA);
      exit(0);
    }
    pid = fork();
    assert(pid >= 0);
    if (pid == 0) {
      int status = execvp(vector_cadenas[0], vector_cadenas);
      exit(status);
    } else {
      int status;
      int _pid;
      _pid = wait(&status);
      if (_pid != pid) {
        printf("Terminacion de proceso (%d) no esperado. Se esperaba el proceso %d\n",_pid, pid);
        continue;
      }
      if (WIFEXITED(status)) {
        int _status = WEXITSTATUS(status);
        if ( _status != 0) {
          printf("[ERROR] Proceso '%s' termino con status %d\n",vector_cadenas[0],_status);
        }
      }
    }
  }
  exit(0);
}
