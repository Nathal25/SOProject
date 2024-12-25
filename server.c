#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <assert.h>

#define PORT 8080   //Puerto al que se conecta
#define MAX 1024    //Máximo de caracteres permitidos

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX] = {0};
    
    //Creción del socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    assert(server_fd >= 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //Enlaza el socket
    assert(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) >= 0);
    assert(listen(server_fd, 3) >= 0);

    printf("Servidor esperando conexiones en el puerto %d...\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        assert(new_socket >= 0);

        printf("Cliente conectado.\n");

        while (1) {
            int bytes_read = read(new_socket, buffer, MAX);
            if (bytes_read <= 0) break;

            buffer[bytes_read] = '\0';
            printf("Comando recibido: %s\n", buffer);

            //Crea proceso para ejecutar el comando
            pid_t pid = fork();
            assert(pid >= 0);

            if (pid == 0) { //Proceso hijo
                dup2(new_socket, STDOUT_FILENO);
                dup2(new_socket, STDERR_FILENO);
                char *args[] = {"/bin/sh", "-c", buffer, NULL};
                execvp(args[0], args);
                exit(1);
            } else { // Proceso padre
                wait(NULL);
                write(new_socket, "\n", 1); // Enviar nueva línea para marcar el final
            }
            if (strcmp(buffer, "salida") == 0) {
                printf("Cliente desconectado por solicitud.\n");
                close(new_socket); //Cierra el socket del cliente
                break; //Fin del bucle
            }
        }
        close(new_socket);
    }
    close(server_fd);
    return 0;
}