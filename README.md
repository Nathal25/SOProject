# Proyecto Shell Remoto


## Descripción del Proyecto
El **Proyecto Shell Remoto** es una aplicación cliente/servidor desarrollada en C que permite a los usuarios ejecutar comandos en un computador remoto.  
El cliente envía los comandos al servidor, donde estos son ejecutados, y la respuesta se devuelve al cliente para ser mostrada en pantalla.

### Objetivos
Este proyecto busca que los estudiantes desarrollen habilidades en:
- Desarrollo de aplicaciones en **C** y gestión de procesos.
- Implementación del modelo cliente/servidor utilizando **sockets**.
- Documentación técnica mediante informes y presentación de resultados en video.

## Detalles del Funcionamiento
El cliente y el servidor se comunican a través de la red usando **sockets**, siguiendo estos pasos:

1. El **cliente** lee un comando ingresado por el usuario.
2. El cliente envía el comando al servidor mediante un socket.
3. El **servidor** recibe el comando y crea un proceso para ejecutarlo.
4. El servidor captura la salida del comando y la envía al cliente.
5. El cliente muestra la salida al usuario.
6. El ciclo se repite hasta que el usuario ingrese el comando `salida`, cerrando la conexión.

## Requisitos
- Lenguaje de programación **C**.
- Conexión en red entre el cliente y el servidor.
- Conocimientos de **sockets** y gestión de procesos en sistemas operativos.

## Entregables
El proyecto incluye los siguientes entregables:

1. **Código fuente** alojado en este repositorio.
2. **Informe técnico** que incluye:
   - Metodología de trabajo.
   - Problemas enfrentados y soluciones implementadas.
   - Documentación del protocolo de comunicación cliente/servidor.
3. **Video demostrativo** (máximo 10 minutos) que muestre:
   - El funcionamiento del proyecto.
   - Participación de todos los integrantes del grupo.

## Integrantes
El proyecto puede desarrollarse en grupos de **2 a 4 integrantes**. Recuerda incluir los nombres de los participantes en el informe.

## Recursos
- [Guía de aplicación cliente/servidor en C](https://www.geeksforgeeks.org/simple-client-server-application-in-c/)

## Fecha de Entrega
Definida en **Google Classroom el 6 de Enero del 2025**.

