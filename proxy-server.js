//Hace de puente entre el servidor y la página HTML, permite que la página haga de 'cliente'
const net = require('net');
const express = require('express');
const http = require('http');
const WebSocket = require('ws');

const PORT = 3000; // Puerto del servidor web
const SOCKET_PORT = 8080; // Puerto del servidor

// Crear aplicación Express
const app = express();
const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

// Servir archivos estáticos
app.use(express.static('public'));

// WebSocket para comunicación cliente-servidor
wss.on('connection', (ws) => {
    const clientSocket = new net.Socket();

    clientSocket.connect(SOCKET_PORT, '172.28.32.137', () => {
        console.log('Conectado al servidor C');
        ws.send('Conexión establecida con el servidor.');
    });    

    clientSocket.on('data', (data) => {
        ws.send(data.toString());
    });

    clientSocket.on('close', () => {
        ws.send('Conexión con el servidor C cerrada.');
        ws.close();
    });

    ws.on('message', (message) => {
        const command = message.toString().trim();
        console.log(`Comando recibido: ${command}`);

        if (command === 'salida') {
            console.log('Cliente solicitó desconexión.');
            ws.send('Conexión cerrada por solicitud del cliente.');
            ws.close(); // Cierra la conexión WebSocket
        } else {
            // Procesar otros comandos
            clientSocket.write(message + '\n');
            ws.send(`Comando ejecutado: ${command}`);
        }
    });

    ws.on('close', () => {
        console.log('Conexión con cliente cerrada.');
    });
});

// Iniciar servidor
server.listen(PORT,'0.0.0.0', () => {
    console.log(`Servidor web escuchando en http://localhost:${PORT}`);
});
