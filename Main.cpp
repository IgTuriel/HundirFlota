#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "Jugador.h"
#include "Login.h"

void mostrarInstrucciones();

int main(void)
{
	Jugador* jugador;
	jugador = new Jugador();

	Login(jugador);
	jugador->generarTablero();
	jugador->imprimirTablero();

	Jugador* cpu;
	cpu = new Jugador();

	cpu->generarTablero();
	cpu->imprimirTablero();

	char str[2];
	int menu = 0;

	while(menu != 4) {
		printf("Selecciona qué quieres hacer:\n");
		printf("\n");
		printf("1: Instrucciones básicas\n");
		printf("2: Colocar mi flota\n");
		printf("3: Cambiar flota de la CPU\n");
		printf("4: Cerrar la aplicación\n");
		fflush(stdout);
		fgets(str, 2, stdin);
		sscanf(str, "%d", &menu);
		fflush(stdin);

		switch(menu) {
		case 1:
			mostrarInstrucciones();
			break;

		case 2:
			jugador->colocarFlota();
			break;

		case 3:

			break;

		case 4:
			printf("Has cerrado la aplicación.\n");
			break;

		default:
			printf("El número no coincide con ninguna opción del menú...\n");
			printf("\n");
			break;
		}
	}
}

void mostrarInstrucciones() {
	Jugador* predet;
	predet = new Jugador();
	predet->generarTablero();

	printf("\n");
	printf("Tu principal objetivo es hundir la flota rival antes de que él hunda la tuya\n");
	printf("Cada jugador dispondrá de un tablero 7x5, donde cada casilla será una coordenada.\n");
	printf("Un tablero vacío es así, y cada casilla es una coordenada letra-numero (ej: B3)\n");
	printf("\n");

	predet->imprimirTablero();

	printf("\n");
	printf("Cada jugador dispone de cuatro barcos que podrá colocar donde quiera:\n");
	printf("   - Uno de 1 casilla, uno de 2 casillas, y dos de 3 casillas.\n");
	printf("\n");
	printf("Estos barcos se representan por su número de casillas.\n");
	printf("Como ejemplo, si nosotros colocamos nuestro barco de 2 casillas en D1 y D2...\n");
	printf("\n");

	//predet->tablero[8][3] = '2';
	//predet->tablero[8][5] = '2';

	predet->imprimirTablero();

	printf("\n");
	printf("Las dos casillas con el '2' nos muestran que ahí está el barco.\n");
	printf("\n");
	printf("Los barcos con más de una casilla tienen que tener todas sus casillas adyacentes.\n");
	printf("Además, no se pueden colocar en diagonal, pero sí vertical u horizontalmente.\n");
	printf("Dos barcos pueden estar adyacentes siempre que ocupen casillas distintas.\n");
	printf("\n");
	printf("Antes de la partida, deberás colocar los 4 barcos. ¡Colocalos estrátegicamente!\n");
	printf("\n");
}
