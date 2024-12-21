#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>

#define PORT 8080
#define MAX 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX] = {0};

    // Crear socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    assert(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) > 0);

    // Conectar al servidor
    assert(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) >= 0);

    printf("Conectado al servidor. Escribe 'salir' para terminar.\n");

    while (1) {
        printf("> ");
        fgets(buffer, MAX, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remover nueva línea

        send(sock, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "salir") == 0) break;

        int bytes_read = read(sock, buffer, MAX);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("%s", buffer);
        }
    }
    close(sock);
    return 0;
}