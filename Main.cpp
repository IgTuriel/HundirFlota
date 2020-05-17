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
		printf("Selecciona qu� quieres hacer:\n");
		printf("\n");
		printf("1: Instrucciones b�sicas\n");
		printf("2: Colocar mi flota\n");
		printf("3: Cambiar flota de la CPU\n");
		printf("4: Cerrar la aplicaci�n\n");
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
			printf("Has cerrado la aplicaci�n.\n");
			break;

		default:
			printf("El n�mero no coincide con ninguna opci�n del men�...\n");
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
	printf("Tu principal objetivo es hundir la flota rival antes de que �l hunda la tuya\n");
	printf("Cada jugador dispondr� de un tablero 7x5, donde cada casilla ser� una coordenada.\n");
	printf("Un tablero vac�o es as�, y cada casilla es una coordenada letra-numero (ej: B3)\n");
	printf("\n");

	predet->imprimirTablero();

	printf("\n");
	printf("Cada jugador dispone de cuatro barcos que podr� colocar donde quiera:\n");
	printf("   - Uno de 1 casilla, uno de 2 casillas, y dos de 3 casillas.\n");
	printf("\n");
	printf("Estos barcos se representan por su n�mero de casillas.\n");
	printf("Como ejemplo, si nosotros colocamos nuestro barco de 2 casillas en D1 y D2...\n");
	printf("\n");

	//predet->tablero[8][3] = '2';
	//predet->tablero[8][5] = '2';

	predet->imprimirTablero();

	printf("\n");
	printf("Las dos casillas con el '2' nos muestran que ah� est� el barco.\n");
	printf("\n");
	printf("Los barcos con m�s de una casilla tienen que tener todas sus casillas adyacentes.\n");
	printf("Adem�s, no se pueden colocar en diagonal, pero s� vertical u horizontalmente.\n");
	printf("Dos barcos pueden estar adyacentes siempre que ocupen casillas distintas.\n");
	printf("\n");
	printf("Antes de la partida, deber�s colocar los 4 barcos. �Colocalos estr�tegicamente!\n");
	printf("\n");
}
