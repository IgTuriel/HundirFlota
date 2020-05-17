#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Jugador.h"
#include "Login.h"

void Login(Jugador* jugador) {

	printf("¡Bienvenido al hundir la flota! ¿tienes una cuenta? (S/N)\n");

	char opcion[2];
	char c;

	do {
	fflush(stdout);
	fgets(opcion, 2, stdin);
	sscanf(opcion, "%c", &c);
	fflush(stdin);
	} while(c != 'S' && c != 'N');

	if(c == 'S' || c == 's') {
		iniciarSesion(jugador);
	}
	if(c == 'N' || c == 'n') {
		registrarUsuario();
		Login(jugador);
	}
}

void registrarUsuario() {

	char str[20];
	char* nomUsuario;

	do{
		FILE* Usuarios;
		Usuarios = fopen("Usuarios.txt", "r");
		if(Usuarios == NULL) {
			printf("No existe el archivo.\n");
		}

		printf("Introduce un nombre de usuario:\n");

		fflush(stdout);
		fgets(str, 20, stdin);
		nomUsuario = (char*) malloc(strlen(str)+1 * sizeof(char));
		sscanf(str, "%s", nomUsuario);
		fflush(stdin);

		char userPass[50];
		int n;

		while(fgets(userPass, 50, Usuarios) != NULL) {
			n = strncmp(nomUsuario, userPass, strlen(nomUsuario));
			if(n == 0) {
				printf("Este nombre de usuario ya esta cogido, prueba con otro.\n");
				fclose(Usuarios);
				break;
			}
		}

		if(n!=0) {
			printf("¡El nombre de usuario esta disponible!\n");
			fclose(Usuarios);
			break;
		}
	}while(1 == 1);

	//Si salimos del bucle, el usuario ha introducido un nomUsuario que no está cogido
	printf("Ahora, introduce tu contrasenya:\n");
	char string[20];

	fflush(stdout);
	fgets(string, 20, stdin);
	char* contra = (char*) malloc(strlen(string)+1 * sizeof(char));
	sscanf(string, "%s", contra);
	fflush(stdin);

	FILE* f = fopen("Usuarios.txt", "a");

	fprintf(f, "%s", nomUsuario);
	fprintf(f, ";");
	fprintf(f, "%s\n", contra);

	fclose(f);

	printf("¡Ya has sido registrado!\n");
	printf("Tu usuario es: %s y tu contrasenya es: %s\n\n", nomUsuario, contra);
}

void iniciarSesion(Jugador* jugador) {

	char str[25];
	char* nomUsuario;
	char string[25];
	char* contrasenya;

	do {
		FILE* Usuarios = fopen("Usuarios.txt", "r");
		printf("Introduce tu nombre de usuario:\n");

		fflush(stdout);
		fgets(str, 25, stdin);
		nomUsuario = (char*) malloc(strlen(str)+1 * sizeof(char));
		sscanf(str, "%s", nomUsuario);
		fflush(stdin);

		char userPass[50];
		int n;
		int n2;

		while(fgets(userPass, 50, Usuarios) != NULL) {
			n = strncmp(nomUsuario, userPass, strlen(nomUsuario));

			if(n == 0) {
				printf("Ahora, introduce tu contrasenya:\n");

				fflush(stdout);
				fgets(string, 25, stdin);
				contrasenya = (char*) malloc(strlen(string)+1 * sizeof(char));
				sscanf(string, "%s", contrasenya);
				fflush(stdin);

				n2 = strncmp(contrasenya, userPass + strlen(nomUsuario) + 1, strlen(contrasenya));
				if(n2 == 0) {
					break;
				}
				else {
					printf("Contrasenya incorrecta.\n");
					break;
				}
			}
		}
		if(n2 == 0) {
			fclose(Usuarios);
			break;
		}

		if(n!=0) {
			printf("El nombre de usuario introducido no existe. Prueba otra vez.\n");
			fclose(Usuarios);
			continue;
		}

	}while(1 == 1);

	printf("¡Bienvenido, %s!\n", nomUsuario);

	jugador->setNomUsuario(nomUsuario);
	jugador->setContrasenya(contrasenya);
	//jugador->flotaColocada = false;
}
