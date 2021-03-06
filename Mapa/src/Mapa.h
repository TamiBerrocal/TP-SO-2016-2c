/*
 * Mapa.h
 *
 *  Created on: 30/8/2016
 *      Author: utnso
 */

#ifndef MAPA_H_
#define MAPA_H_
#include "socket.h"
#include <pkmn/battle.h>
#include <pkmn/factory.h>

/* Definición de estructuras */

typedef struct mapa {
	int TiempoChequeoDeadlock;
	int Batalla;
	char* Algoritmo;
	int Quantum;
	int Retardo;
	char* IP;
	char* Puerto;
} t_mapa_config;

typedef struct entrenador {
	char id;
	char idPokenestActual;
	char* nombre;
	int faltaEjecutar;
	int utEjecutadas;
	socket_t* socket;
	t_ubicacion ubicacion;
	time_t fechaIngreso;
} t_entrenador;

typedef struct pokenest {
	char* tipo;
	t_ubicacion ubicacion;
	char id;
	int cantidad;
	t_list* metadatasPokemones;
} t_mapa_pokenest;

typedef struct recursosEntrenador {
	char id;
	t_list* recursos;
} t_recursosEntrenador;

typedef struct pokemonEntrenador {
	char* nombre;
	int nivel;
	char idEntrenador;
	t_pokemon* pokemon;
} t_pokemonEntrenador;

typedef struct metadataPokemon {
	char* rutaArchivo;
	int nivel;
	char entrenador;
	char id;
} t_metadataPokemon;

typedef struct estructuraPlanificador{
	int index;
	int faltante;
}t_estructuraPlanificador;

/* Constantes */

// Ruta al archivo de log
#define LOG_FILE_PATH ".log"
// Nombre del archivo de metadata
#define METADATA "metadata"


/* Declaración de funciones */

void encolarEntrenador(t_entrenador* entrenador);
void reencolarEntrenador(t_entrenador* entrenador);
void calcularFaltante(t_entrenador* entrenador);
void insertarAlFinal(t_entrenador* entrenador, t_queue* cola);
void realizar_movimiento(t_list* items, t_entrenador personaje, char * mapa);
t_ubicacion calcularMovimiento(t_ubicacion ubicacionActual, t_ubicacion ubicacionFinal);
ITEM_NIVEL* _search_item_by_id(t_list* items, char id);
t_ubicacion buscarPokenest(t_list* lista, char pokemon);
t_list* cargarObjetivos();
t_list* cargarPokenests();
t_mapa_pokenest leerPokenest(char* metadata);
int cargarConfiguracion(t_mapa_config* structConfig);
void aceptarConexiones();
void eliminarEntrenador(t_entrenador* entrenador);
t_list* algoritmoDeteccion();
void eliminarRecursosEntrenador(t_recursosEntrenador* recursosEntrenador);
void liberarMemoriaAlocada();
void eliminarEntrenadorMapa(t_entrenador* entrenadorAEliminar);
void signal_handler();
void signal_termination_handler(int signum);
void chequearDeadlock();
t_pokemonEntrenador* obtenerPokemonMayorNivel(t_entrenador* entrenador);
t_pokemonEntrenador* obtenerEntrenadorAEliminar(t_list* entrenadoresConPokemonesAPelear);
int obtenerCantidadRecursos(char* nombrePokemon, char* rutaPokenest, t_list* metadatasPokemones);
void liberarRecursosEntrenador(t_entrenador* entrenador);
void capturarPokemon(t_entrenador* entrenador);
void desbloquearJugadores();
void actualizarMatriz(t_list* matriz, t_entrenador* entrenador, int aumentar, pthread_mutex_t* mutex);
void informarEstadoCola(char* nombreCola, t_list* cola);
time_t obtenerFechaIngreso();
void informarEstadoRecursos();
char* obtenerNombrePokemon(char idPokemon);
void eliminarPokemonEntrenador(t_pokemonEntrenador* entrenador);
void eliminarRecurso(t_mapa_pokenest* recurso);
t_entrenador* tomarEntrenadorAEjecutar(char* algoritmo);
int informarResultadoBatalla(t_pokemonEntrenador* ganador, t_pokemonEntrenador* perdedor);

#endif /* MAPA_H_ */
