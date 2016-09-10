/*
 * socket.h
 *
 *  Created on: 30/8/2016
 *      Author: utnso
 */

#ifndef UTILITY_LIBRARY_SOCKET_H_
#define UTILITY_LIBRARY_SOCKET_H_

/* Definición de estructuras */

// Estructura socket
typedef struct socket {
	int descriptor;
	char* error;
} socket_t;

/* Declaración de funciones */

// Crea un puntero a una estructura socket
// Reserva memoria para el descriptor de socket, no así para el texto explicativo del error
socket_t* nuevoSocket();

// Libera la memoria reservada para una estructura socket
void eliminarSocket(socket_t* socket_s);

// Crea una entidad servidor a la cual le asocia el número de IP y el número de puerto
// indicados como argumentos durante la invocación
// Devuelve una estructura conformada por:
// -- el descriptor del socket que permitirá la intercomunicación del servidor; su valor será
// distinto a 0 en caso de una finalización exitosa
// -- el texto explicativo del error que se ha producido en caso contrario
socket_t* crearServidor(char* ip, char* puerto);

// Pone en escucha de conexiones a un servidor
int escucharConexiones(socket_t servidor, int cantidadMaximaConexiones);

// Acepta la conexión de un cliente
socket_t* aceptarConexion(socket_t servidor);

// Conecta a un cliente al servidor indicado durante la invocación
socket_t* conectarAServidor(char* ip, char* puerto);

#endif /* UTILITY_LIBRARY_SOCKET_H_ */