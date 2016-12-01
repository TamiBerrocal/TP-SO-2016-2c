/*
 * Entrenador.h
 *
 *  Created on: 30/8/2016
 *      Author: utnso
 */

#ifndef ENTRENADOR_H_
#define ENTRENADOR_H_
#include <commons/collections/list.h>
#include "socket.h"

/* Definición de estructuras */

typedef struct ciudadObjetivos {
	char* Nombre;
	char** Objetivos;
} t_ciudad_objetivos;

typedef struct entrenador {
	char* Nombre;
	char* Simbolo;
	t_list* CiudadesYObjetivos;
	int Vidas;
} t_entrenador_config;

typedef struct metadataPokemon {
	char* rutaArchivo;
	int nivel;
	char* ciudad;
} t_metadataPokemon;


/* Constantes */

// Ruta al archivo de log
#define LOG_FILE_PATH "entrenador.log"
// Nombre del archivo de metadata
#define METADATA "metadata"


/* Declaración de funciones */

int cargarConfiguracion(t_entrenador_config* structConfig);
socket_t* conectarAMapa(char* ip, char* puerto);
void solicitarUbicacionPokeNest(socket_t* mapa_s, char idPokeNest, t_ubicacion* ubicacionPokeNest);
direccion_t calcularMovimiento(t_ubicacion ubicacionEntrenador, t_ubicacion ubicacionPokeNest, char* ejeAnterior);
void solicitarDesplazamiento(socket_t* mapa_s, t_ubicacion* ubicacion, t_ubicacion ubicacionPokeNest, char* ejeAnterior);
void solicitarCaptura(socket_t* mapa_s, int* victima, char* objetivo);
void signal_handler();
void signal_termination_handler(int signum);
void obtenerDatosConexion(char* nombreCiudad);

#endif /* ENTRENADOR_H_ */
