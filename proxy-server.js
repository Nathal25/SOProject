const net = require('net');
const express = require('express');
const http = require('http');
const WebSocket = require('ws');

const PORT = 3000; // Puerto del servidor web
const SOCKET_PORT = 8080; // Puerto del servidor C

// Crear aplicación Express
const app = express();
const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

// Servir archivos estáticos
app.use(express.static('public'));

// WebSocket para comunicación cliente-servidor
wss.on('connection', (ws) => {
    const clientSocket = new net.Socket();

    clientSocket.connect(SOCKET_PORT, '127.0.0.1', () => {
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
        if (message === 'salir') {
            clientSocket.end();
        } else {
            clientSocket.write(message + '\n');
        }
    });

    ws.on('close', () => {
        clientSocket.destroy();
    });
});

// Iniciar servidor
server.listen(PORT, () => {
    console.log(`Servidor web escuchando en http://localhost:${PORT}`);
});

