#include <iostream>
using namespace std;

#include "Jugador.h"

#include <stdio.h>
#include <stdlib.h>
#include <String.h>


Jugador::Jugador() {
	this->flotaColocada = false;
}

Jugador::Jugador(char* nomUsuario, char* contrasenya, bool flotaColocada)
: Usuario(nomUsuario, contrasenya) {
	this->flotaColocada = false;
}

void Jugador::setCasilla(int x, int y, char dato) {
	this->tablero[x][y] = dato;
}

void Jugador::generarTablero() {
	//este array es un tablero predeterminado (vacio)
	char tableroLleno[12][18] = {
		' ', ' ', ' ', '1', ' ', '2', ' ', '3', ' ', '4', ' ', '5', ' ', '6', ' ', '7', ' ', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0',
		'A', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0',
		'B', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0',
		'C', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0',
		'D', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0',
		'E', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\0',
		' ', ' ', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '\0'
	};

	//hacemos que el tablero recibido sea como el definido arriba
	for(int i=0;i<12;i++) {
		for(int j=0;j<18;j++) {
			this->tablero[i][j] = tableroLleno[i][j];
		}
	}
}

void Jugador::colocarFlota() {
	if(this->flotaColocada) {
		printf("Tu flota ya está colocada.\n");

		printf("¿Quieres resetear las posiciones de tu flota? (S/N):");
		char opcion[2];
		char c;

		do {
		fflush(stdout);
		fgets(opcion, 2, stdin);
		sscanf(opcion, "%c", &c);
		fflush(stdin);
		} while(c != 'S' && c != 'N');

		if(c == 'S' || c == 's') {
			this->generarTablero();
			this->flotaColocada = false;
			printf("Tu flota ha sido reseteada. Puedes volver a colocarla desde el menú.\n");
		}
		printf("\n");
		return;
	}

	bool barcoColocado[4] = {false, false, false, false};
	int barcos3 = 0;

	this->imprimirTablero();
	printf("\n");

	while(!barcoColocado[0] || !barcoColocado[1] || !barcoColocado[2] || !barcoColocado[3]) {

		printf("Barcos por colocar:\n");
		printf("  - ");
		if(!barcoColocado[0]) printf("Barco de 1 / ");
		if(!barcoColocado[1]) printf("Barco de 2 / ");
		if(!barcoColocado[2]) printf("Barco de 3 / ");
		if(!barcoColocado[3]) printf("Barco de 3 / ");
		printf("\n\n");

		printf("Selecciona qué barco quieres colocar (1, 2, 3):\n");

		char str[2];
		int barco = 0;

		fflush(stdout);
		fgets(str, 2, stdin);
		sscanf(str, "%d", &barco);
		fflush(stdin);

		switch(barco) {
		case 1:
			if(!barcoColocado[0]) {
				this->colocarBarco1();
				this->imprimirTablero();
				barcoColocado[0] = true;
			}
			break;

		case 2:
			if(!barcoColocado[1]) {
				this->colocarBarco2();
				this->imprimirTablero();
				barcoColocado[1] = true;
			}
			break;

		case 3:
			if(!barcoColocado[2]) {
				this->colocarBarco3();
				this->imprimirTablero();
				barcoColocado[2] = true;
			}
			else {
				this->colocarBarco3();
				this->imprimirTablero();
				barcoColocado[3] = true;
			}
			break;

		default:
			printf("No has introducido una opción correcta.\n\n");
			break;
		}
	}

	this->flotaColocada = true;
}

void Jugador::colocarBarco1() {
	Coordenada coord = this->comprobarCoordenada();
	this->setCasilla(coord.x, coord.y, '1');
	printf("¡Barco de 1 colocado!\n\n");
}

void Jugador::colocarBarco2() {
	bool seguirBucle = true;

	do {
	Coordenada coord1 = this->comprobarCoordenada();
	Coordenada coord2 = this->comprobarCoordenada();

	if(coord1.x == coord2.x) {
		if(coord1.y == coord2.y + 2 || coord1.y == coord2.y - 2) {
			seguirBucle = false;
		}
	}

	if(coord1.y == coord2.y) {
		if(coord1.x == coord2.x + 2 || coord1.x == coord2.x - 2) {
			seguirBucle = false;
		}
	}

	//si salimos del bucle, podemos colocar el barco en esas posiciones
	if(!seguirBucle) {
		this->setCasilla(coord1.x, coord1.y, '2');
		this->setCasilla(coord2.x, coord2.y, '2');
		break;
	}

	//si llegamos a este punto, las dos coordenadas no son compatibles
	printf("Las coordenadas elegidas no son compatibles.\n");
	printf("Vuelve a introducir otras dos coordenadas.\n\n");

	} while(seguirBucle);

	printf("¡Barco de 2 colocado!\n\n");
}

void Jugador::colocarBarco3() {
	bool seguirBucle = true;
	int aux = 0;
	do {
		if(aux > 0) {
			printf("Las coordenadas elegidas no son compatibles.\n");
			printf("Vuelve a introducir todas las coordenadas.\n\n");
		}
		aux++;

		Coordenada coord1 = this->comprobarCoordenada();
		Coordenada coord2 = this->comprobarCoordenada();
		Coordenada coord3 = this->comprobarCoordenada();

		if(coord1.x == coord2.x && coord1.y == coord2.y) continue;
		if(coord1.x == coord3.x && coord1.y == coord3.y) continue;
		if(coord2.x == coord3.x && coord2.y == coord3.y) continue;

		if(coord1.x == coord2.x) {
			if(coord1.y == coord2.y + 2 || coord1.y == coord2.y - 2) {
				if(coord3.x != coord1.x) continue;

				else if(coord3.y == coord1.y + 2 || coord3.y == coord1.y - 2
						|| coord3.y == coord2.y + 2 || coord3.y == coord2.y - 2)
				{
					seguirBucle = false;
				}
			}
			else if(coord1.y == coord2.y + 4 || coord1.y == coord2.y - 4) {
				if(coord3.x != coord1.x) continue;

				else if((coord3.y == coord1.y + 2 || coord3.y == coord1.y - 2) &&
						(coord3.y == coord2.y + 2 || coord3.y == coord2.y - 2))
				{
					seguirBucle = false;
				}
			}
			else continue;
		}

		if(coord1.y == coord2.y) {
			if(coord1.x == coord2.x + 2 || coord1.x == coord2.x - 2) {
				if(coord3.y != coord1.y) continue;

				else if(coord3.x == coord1.x + 2 || coord3.x == coord1.x - 2
						|| coord3.x == coord2.x + 2 || coord3.x == coord2.x - 2)
				{
					seguirBucle = false;
				}
			}
			else if(coord1.x == coord2.x + 4 || coord1.x == coord2.x - 4) {
				if(coord3.y != coord1.y) continue;

				else if((coord3.x == coord1.x + 2 || coord3.x == coord1.x - 2) &&
						(coord3.x == coord2.x + 2 || coord3.x == coord2.x - 2))
				{
					seguirBucle = false;
				}
			}
			else continue;
		}

		if(!seguirBucle) {
			this->setCasilla(coord1.x, coord1.y, '3');
			this->setCasilla(coord2.x, coord2.y, '3');
			this->setCasilla(coord3.x, coord3.y, '3');
			break;
		}

	} while(seguirBucle);

	printf("¡Barco de 3 colocado!\n\n");
}

Coordenada Jugador::comprobarCoordenada() {
	//en este método solo podrás salir si eliges una coordenada vacía
	Coordenada coord;
	char letra;
	int num;
	bool coordPosible = false;

	while(!coordPosible) {
		printf("Introduce la coordenada letra-número donde colocar tu barco (ej: A2):\n");
		char str[3];

		int fila;
		int columna = 3; //la primera columna con casillas es la 3

		fflush(stdout);
		fgets(str, 3, stdin);
		sscanf(str, "%c%d", &letra, &num);
		fflush(stdin);

		if(num < 1 || num > 7) {
			printf("Coordenada inexistente. Vuelva a intentarlo.\n");
			continue;
		}
		if(letra != 'a' && letra != 'b' && letra != 'c' && letra != 'd' && letra != 'e') {
			printf("Coordenada inexistente. Vuelva a intentarlo.\n");
			continue;
		}

		for(int i=1;i<num;i++) {
			columna += 2;
		}							//Aquí ya se en qué columna del array coloco el barco

		if(letra == 'a') fila = 2;
		else if(letra == 'b') fila = 4;
		else if(letra == 'c') fila = 6;
		else if(letra == 'd') fila = 8;
		else if(letra == 'e') fila = 10;   //Aquí ya se en qué fila del array coloco el barco

		if(this->tablero[fila][columna] == ' ') {
			coordPosible = true;
				//solo llegará aquí si en la coordenada es posible colocar el barco
			coord.x = fila;
			coord.y = columna;
			return coord;
		}

		else {
			printf("Esta coordenada ya está ocupada por otro barco.\n");
			continue;
		}
	}
}

void Jugador::imprimirTablero() const {
	for(int i=0;i<12;i++) {
		for(int j=0;j<18;j++) {
			printf("%c", this->tablero[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

