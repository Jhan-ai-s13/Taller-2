/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char abortar[4] = {'q', 'u', 'i', 't'};
  char **vector;
  int i, coincidencias;
  pid_t pid;

  while(1) {
          coincidencias = 0;
          printf("> ");
          leer_de_teclado(BUFSIZ,comando);
          
          for(int m=0;m<5;m++){
              if(comando[m]==abortar[m]) coincidencias += 1;
          }
          
          if(coincidencias==4){
              break;
          }
          
          pid = fork();
          if (pid < 0) {
                  printf("No pude crear un proceso\n");
                  return 2;
          } else if (pid == 0) {
                vector = de_cadena_a_vector(comando);
                execvp(vector[0],vector);
          } else {
                  wait(NULL);
                  return 0;
          }
  }


}
